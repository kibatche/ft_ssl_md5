#include "ft_ssl.h"

extern programm_info p_info;
extern hash_function h_functions[NUMBER_OF_HASH_FUNCTIONS];
extern char *message;

void parse_hash_mode(char *hash_mode)
{
    if (strcmp(hash_mode, MD5_STRING) == 0)         p_info.hash_mode = MD5_HASH_MODE;
    else if (strcmp(hash_mode, SHA256_STRING) == 0) p_info.hash_mode = SHA256_HASH_MODE;
    else print_error(ERR_USAGE);
}

char *parse_stdin()
{
    char buf[2];
    char *tmp;
    char *to_hash = ft_strdup("");
    int ret = 0;

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

char *read_file(int fd)
{
    unsigned int len = 0;
    char *to_hash = NULL;

    len = lseek(fd, 0, SEEK_END);
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

char *parse_file(char *path)
{
    char *to_hash = NULL;
    char *cwd;
    char *full_path;
    unsigned int len_read = 0;

    if (access(path, R_OK) == 0)
    {
        int fd = open(path, O_RDONLY);
        if (fd == -1) print_error("open failed.");
        to_hash = read_file(fd);
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
        if (fd == -1) print_error("open failed.");
        REEF(full_path);
        to_hash = read_file(fd);
        close(fd);
        return to_hash;
    }
    else
    {
        REEF(full_path);
        print_error("No such file or directory.");
    }
    return NULL;
}

enum PARSING_STATE file_state_parsing(char *token)
{
    message = parse_file(token);
    fflush(NULL);
    h_functions[p_info.hash_mode]();
    return FILE_STATE;
}

enum PARSING_STATE string_state_parsing(char *token)
{
    message = ft_strdup(token);
    h_functions[p_info.hash_mode]();
    return NO_STATE;
}

enum PARSING_STATE no_state_parsing(char *token)
{
    if (strcmp(token, "-p") == 0)
    {
        if (p_info.print_stdin_option == true) print_error(ERR_USAGE);
        p_info.print_stdin_option = true;
        message = parse_stdin();
        h_functions[p_info.hash_mode]();
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
    message = parse_file(token);
    h_functions[p_info.hash_mode]();
    return FILE_STATE;
}

void parse_arg(int ac, char **av)
{
    enum PARSING_STATE parsing_state = NO_STATE;
    int i = 1;

    if (ac == 1) print_error(ERR_USAGE);
    parse_hash_mode(av[1]);
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
}
