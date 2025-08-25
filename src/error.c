void print_error(char errMsg)
{
    write(2, errMsg, strlen(errMsg));
    exit(1);
}