#include "ft_ssl.h"

extern programm_info p_info;
extern char *message;

bool is_an_hash_was_printed = false;
bool a_file_was_parsed = false;
char *current_processed_filename;


void parse_hash_mode(char *hash_mode)
{
    int i = 0;
    ssl_config ssl_conf[] = {{&md5_sum, MD5_STRING}, {&sha256_sum, SHA256_STRING}, {NULL, NULL}};

    while (ssl_conf[i].fun != NULL)
    {
        if (ft_strcmp(hash_mode, ssl_conf[i].fun_name) == 0)
        {
            p_info.ssl_conf = &ssl_conf[i];
            return;
        }
        i++;
    }
    print_error(ERR_USAGE);
}

char *parse_stdin()
{
    char buf[2];
    char *tmp = NULL;
    char *to_hash = ft_strdup("");
    int ret = 0;

    ft_bzero(buf, 2);
    if (to_hash == NULL)    print_error(ERR_MALLOC);
    while ((ret = read(STDIN_FILENO, buf, 1)) > 0)
    {
        tmp = ft_strjoin(to_hash, buf);
        REEF(to_hash);
        to_hash = ft_strdup(tmp);
        free(tmp);
    }
    if (ret == -1)
    {
        REEF(to_hash);
        REEF(tmp);
        return NULL;
    }
    return to_hash;
}

char *read_file(int fd, unsigned int **filelen)
{
    unsigned int len = 0;
    char *to_hash = NULL;

    len = lseek(fd, 0, SEEK_END);
    **filelen = len;
    lseek(fd, 0, SEEK_SET);//reset the pointer
    to_hash = malloc(sizeof(char) * (len + 1));
    if (to_hash == NULL)
    {
        close(fd);
        print_error(ERR_MALLOC);
    }
    if (read(fd, to_hash, len) == -1)
    {
        REEF(to_hash);
        close(fd);
        print_error(ERR_MALLOC);
    }
    to_hash[len] = '\0';
    return to_hash;
}

char *parse_file(char *path, unsigned int *filelen)
{
    char *to_hash = NULL;
    char *cwd = NULL;
    char *full_path = NULL;

    if (access(path, R_OK) == 0)
    {
        int fd = open(path, O_RDONLY);
        if (fd == -1)
        {
            int err = errno;
            ft_putstr_fd(path, 2);
            ft_putstr_fd(": ", 2);
            ft_putendl_fd(strerror(err), 2);
            return NULL;
        }
        to_hash = read_file(fd, &filelen);
        close(fd);
        return to_hash;
    }
    cwd = getcwd(NULL, 0);
    if (cwd == NULL) print_error("cwd failed.");
    full_path = malloc(sizeof(char) * ft_strlen(cwd) + 1 + ft_strlen(path) + 1);
    if (full_path == NULL)
    {
        REEF(cwd);
        print_error(ERR_MALLOC);
    }
    full_path =  ft_strcat(full_path, cwd);
    REEF(cwd);
    full_path = ft_strcat(full_path, "/");
    full_path = ft_strcat(full_path, path);
    if (access(full_path, R_OK) == 0)
    {
        int fd = open(path, O_RDONLY);
        if (fd == -1)
        {
            REEF(full_path);
            int err = errno;
            ft_putstr_fd(path, 2);
            ft_putstr_fd(": ", 2);
            ft_putendl_fd(strerror(err), 2);
            return NULL;;
        }
        REEF(full_path);
        to_hash = read_file(fd, &filelen);
        close(fd);
        return to_hash;
    }
    int err = errno;
    ft_putstr_fd(path, 2);
    ft_putstr_fd(" : ", 2);
    ft_putendl_fd(strerror(err), 2);
    REEF(full_path);;
    return NULL;
}

enum PARSING_STATE file_state_parsing(char *token)
{
    unsigned int filelen = 0;//we need that because binary files can contain \0. Not suitable with char *.
    message = parse_file(token, &filelen);
    a_file_was_parsed = true;
    if (message == NULL)
        return FILE_STATE;
    current_processed_filename = token;
    p_info.handle_mode = FILE_HANDLE_MODE;
    (*p_info.ssl_conf->fun)(filelen);
    return FILE_STATE;
}

enum PARSING_STATE string_state_parsing(char *token)
{
    message = ft_strdup(token);
    p_info.handle_mode = STRING_HANDLE_MODE;
    (*p_info.ssl_conf->fun)(ft_strlen(message));
    is_an_hash_was_printed = true;
    return NO_STATE;
}

enum PARSING_STATE no_state_parsing(char *token)
{
    if (strcmp(token, "-p") == 0)
    {
        if (p_info.print_stdin_option == true) print_error(ERR_USAGE);
        p_info.print_stdin_option = true;
        p_info.handle_mode = STDIN_COMMAND_LINE_HANDLE_MODE;
        message = parse_stdin();
        (*p_info.ssl_conf->fun)(ft_strlen(message));
        is_an_hash_was_printed = true;
        return NO_STATE;
    }
    if (strcmp(token, "-q") == 0)
    {
        if (p_info.quiet_option == true)  print_error(ERR_USAGE);
        p_info.quiet_option = true;
        return NO_STATE;
    }
    if (strcmp(token, "-s") == 0)
    {
        if (p_info.string_option == true) print_error(ERR_USAGE);
        p_info.string_option = true;
        return STRING_STATE;
    }
    if (strcmp(token, "-r") == 0)
    {
        if (p_info.reverse_option == true)  print_error(ERR_USAGE);
        p_info.reverse_option = true;
        return NO_STATE;
    }
    return file_state_parsing(token);
}

void stdin_state_parsing()
{
    message = parse_stdin();
    if (message)
    {
        p_info.handle_mode = STDIN_ONLY_HANDLE_MODE;
        (*p_info.ssl_conf->fun)(ft_strlen(message));
        is_an_hash_was_printed = true;
    }
    else
    {
        print_error(ERR_USAGE);
    }
}


void parse_arg(int ac, char **av)
{
    enum PARSING_STATE parsing_state = NO_STATE;
    int i = 1;

    if (ac == 1) print_error(ERR_USAGE);
    parse_hash_mode(av[1]);
    if (ac == 2)
    {
        stdin_state_parsing();
    }
    while (++i < ac)
    {
        switch (parsing_state)
        {
        case NO_STATE:
            parsing_state = no_state_parsing(av[i]);
            break;
        case STRING_STATE:
            parsing_state = string_state_parsing(av[i]);
            break;
        case FILE_STATE:
            parsing_state = file_state_parsing(av[i]);
            break;
        default:
            print_error("Wrong state.");
            break;
        }
    }
    if (parsing_state == STRING_STATE)//it mean's that the last token was -s without providing a string
        print_error(ERR_USAGE);
    if (is_an_hash_was_printed == false && a_file_was_parsed == false)//this is to handle stdin only mode with -q or -r
        stdin_state_parsing();
}
