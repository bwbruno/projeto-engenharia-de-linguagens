// Reference: https://linux.die.net/man/3/getopt

#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for exit */
#include <string.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    while (1)
    {
        int c;
        int option_index = 0;
        static struct option long_options[] = {
            {"input", required_argument, 0, 'i'},
            {"output", required_argument, 0, 'o'},
            {"dump-symboltable", required_argument, 0, 't'},
            {"dump-stack", required_argument, 0, 's'},
            {0, 0, 0, 0}
        };

        c = getopt_long(argc, argv, "t:s:o:i:", long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
            case 'i':
                printf("option %c with value '%s'\n", c, optarg);
                break;

            case 'o':
                printf("option %c with value '%s'\n", c, optarg);
                break;

            case 't':
                printf("option %c with value '%s'\n", c, optarg);
                break;

            case 's':
                printf("option %c with value '%s'\n", c, optarg);
                fclose(fopen("file.txt", "w"));
                break;

            case '?':
                break;

            default:
                printf("?? getopt returned character code 0%o ??\n", c);
            }
    }

    if (optind < argc)
    {
        printf("non-option ARGV-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }

    char *dumpfile = NULL;
    dumpfile = "testing";
    dumpfile ? printf("true(%s)\n", dumpfile) : printf("false\n");

    exit(EXIT_SUCCESS);
}