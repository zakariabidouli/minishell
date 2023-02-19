#include "minishell.h"

char    *here_doc(char *input, char *command)
{
    char    *line;
    char    *tmp;
    char    *tmp2;
    int     fd;
    pid_t   pid;

    // printf("heredoc: [%s]\n", command);
    fd = open("heredoc.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("Error: Failed to open file");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        line = readline("heredoc> ");
        if (strcmp(line, command) == 0)
            break ;
        tmp = ft_strjoin(line, "\n");
        tmp2 = ft_strjoin(tmp, input);
        write(fd, tmp2, strlen(tmp2));
        free(tmp);
        free(tmp2);
    }
    // close(fd);
    return ("heredoc.txt");
}
