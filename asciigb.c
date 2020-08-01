#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

const char *sOne[14] = {
    "    #   ",
    "   ##   ",
    "  # #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    "    #   ",
    " #######"
};

const char *sTwo[14] = {
    "  ##### ",
    " #     #",
    " #     #",
    "       #",
    "      # ",
    "     #  ",
    "    #   ",
    "   #    ",
    "  #     ",
    " #      ",
    " #      ",
    " #      ",
    " #      ",
    " #######"
};

const char *sThree[14] = {
    "  ####  ",
    " #    # ",
    "       #",
    "       #",
    "       #",
    "      # ",
    "    ##  ",
    "      # ",
    "       #",
    "       #",
    "       #",
    "       #",
    " #    # ",
    "  ####  "
};

const char *sFour[14] = {
    "     #  ",
    "    ##  ",
    "    ##  ",
    "   # #  ",
    "   # #  ",
    "  #  #  ",
    "  #  #  ",
    " #   #  ",
    " #   #  ",
    " #######",
    "     #  ",
    "     #  ",
    "     #  ",
    "    ### "
};

const char** ss[] ={
    sOne, sTwo, sThree, sFour
};

const char *sDot[14] = {
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    " ## ",
    " ## "
};

const char *sFailed[14] = {
    "          #                #     ",
    "      #   #         #####  #     ",
    "      #   #         #   #  #     ",
    "      #########     # # #  ######",
    "     #    #         # # #  #  #  ",
    "     #    #         # # # ##  #  ",
    "          #         # # ## #  #  ",
    "    #############   # # #  #  #  ",
    "          #         # # #   # #  ",
    "         # #        # # #    #   ",
    "        #   #        # #     #   ",
    "       #     #       #  #   # #  ",
    "      #       #     #      #   # ",
    "    ##         #   #     ##     #",
};

const char *sSuccess[14] = {
    "          #                 #    ",
    "          #   #             #    ",
    "          #    #   ######   #    ",
    "     ############     #     #    ",
    "     #     #          #  ########",
    "     #     #          #     #   #",
    "     ####  #          #     #   #",
    "     #  #   #  #      # #   #   #",
    "     #  #   # #       ##   #    #",
    "     #  #    #        #    #    #",
    "     #  #   # #      #    #     #",
    "    #  ##  #  #    #     #      #",
    "    #     #    ##       #    # # ",
    "   #            #      #      #  " 
};
                                                                                
const char *sLost[14] = {
    "            ##            #      ",
    "        ####           #  #      ",
    "      ##  #            #  #      ",
    "          #           #########  ",
    "     ###########      #   #      ",
    "          #          #    #      ",
    "          #               #      ",
    "   ##############  ##############",
    "          #               #      ",
    "         #                #      ",
    "        #                # #     ",
    "       #      #         #   #    ",
    "      ###########      #     #   ",
    "                #    #         # "
};

                                                                                
const char *sClearDisk[14] = {
    "   #      #             #                               #",
    "    # #########          #        ##### ########     ########",
    "    #     #         ############    #      #         #  #   #       ####",
    "       #######      #          #    #   #######      #   #  #      #    #",
    "  #       #        #   #   #  #     #   #  #  #   ##############   #    #",
    "   # ###########      #     #       #   #######      #  #   #           #",
    "                     #       #     #### #  #  #      #   #  #           #",
    "    #  #######      # ####### #   ##  # #  #  #     #       #          #",
    "    #  #     #           #       # #  # #######    #       ##         #",
    "   #   #######           #         #  #    #        ##########        #",
    "   #   #     #           #         #  #  # #        #  #  #  #",
    "  #    #######           #         ####   #         #  #  #  #        #",
    "  #    #     #           #               #  #       #  #  #  #        #",
    "       #    ##     #############       ##     ##  ##############"
};

const char *sClearData[29] = {
    "   ### ###    #    ####    #          #     ##          #",
    "   # # # #    #    #  #   # #       ##   ###            #",
    "   # # # #  # #    # #   #   #      #    #        ##############",
    "   # # # #  # #    ###  #     #     #### #            #",
    "   # # # #  # #    # # # ##### #    #  # #######     ########",
    "  ######### # #    #  #    #        #  # #   #      # #     #",
    "   # # # #  # #    ###  #######     #### #   #     #  #######",
    "   # # # #  # #    #       #        #    #   #    #   #     #",
    "   # # # #    #    #    #  # #      #    #   #        #######",
    "   # # # #    #    #   #   #  #    #    #    #        #     #",
    "  #  # # #   ##    #      ##      #   #      #        #    ##",
    "",
    "    # # #  #        #   #######",
    "     ###   #        #   #     #     ####",
    "  ######## #####  ##### #######    #    #",
    "     ###  #   #     #   #          #    #",
    "    # # ###   #     ##  #   #           #",
    "   #  #  # #  #    ##   # #####        #",
    "     #     #  #    ##   #   #          #",
    "   ####### #  #   # #   #   #         #",
    "     #  #  #  #     #   # #####       #",
    "    ## #    ##      #  #  #   #",
    "     ##    #  #     #  #  #   #       #",
    "    #  #  #    #   ## #   #####       #"
};

const char *sOk[9] = {
    "   ###   ###   ##",
    "  #   #   #   #  ",
    " #     #  # #    ",
    " #     #  ##     ",
    " #     #  ###    ",
    " #     #  #  #   ",
    " #     #  #   #  ",
    "  #   #   #    # ",
    "   ###   ###   ##",
};

#define arraysize(x) (sizeof(x)/sizeof((x)[0]))

int main(int argc, char **argv)
{
    int c, big, small, i, x;
    char line[128];
    const char **b, **s;
    if (argc < 2) return -1;

    if (strncasecmp("-f", argv[1], 2) == 0) {
        big = -1;
        small = -1;
        if (argc > 2) {
            if (argv[2][1] == '.') {
                if ((argv[2][0] >= '1') && (argv[2][0] <= '4')) {
		    big = argv[2][0] - '1'; 
                }
                if ((argv[2][2] >= '1') && (argv[2][2] <= '4')) {
		    small = argv[2][2] - '1'; 
                }
	        x = arraysize(ss);
	        if ((big >= 0) && (big <= x) && (small >= 0) && (small <= x)) {
                    b = ss[big];
                    s = ss[small];

                    printf("\n");
                    printf("\n");
                    for (i=0; i < 14; i++) {
                        strcpy(line, b[i]);
                        strcat(line, sDot[i]);
                        strcat(line, s[i]);
                        strcat(line, sFailed[i]);

                        printf(line);
                        printf("\n");
                    }
                    printf("\n");
                    printf("\n");
		    return 0;
                }
            } else {
                printf("\n");
                printf("\n");
                for (i=0; i < 14; i++) {
                    printf(sFailed[i]);
                    printf("    %s\n", argv[2]);
                }
                printf("\n");
                printf("\n");
		return 0;
            }
        }
        printf("\n");
        printf("\n");
        for (i=0; i < 14; i++) {
            printf(sFailed[i]);
            printf("\n");
        }
        printf("\n");
        printf("\n");
    } else if (strncasecmp("-l", argv[1], 2) == 0) {
        printf("\n");
        printf("\n");
        for (i=0; i < 14; i++) {
            printf(sLost[i]);
	    if (argc > 2) printf("    %s\n", argv[2]);
            else printf("\n"); }
        printf("\n");
        printf("\n");
    } else if (strncasecmp("-s", argv[1], 2) == 0) {
        printf("\n");
        printf("\n");
        for (i=0; i < 14; i++) {
            printf(sSuccess[i]);
            printf("\n");
        }
        printf("\n");
        printf("\n");
    } else if (strncasecmp("-d", argv[1], 2) == 0) {
        initscr();
        for (i=0; i < 14; i++) {
            mvaddstr(i+4, 0, sClearDisk[i]);
        }
        mvaddstr(i+4, 0, "(Y/N)?");
	echo();
        c = getch();
	endwin();
	return ((c == 'y') || (c == 'Y')) ? 0:1;
    } else if (strncasecmp("-v", argv[1], 2) == 0) {
        printf("asciigb v1.1 2018/9/1 Scotex Systems\n");
    } else {
        printf("Usage: asciigb -s|-f [1.4]\n");
    }
    return 0;
}
      
