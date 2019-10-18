#include "Map.h"

void MapSelect() {

    int selected = 0;
    
    printf("[*] MapSelect Function\n");

    while(1) {
        if(GetAsyncKeyState(VK_LEFT) & 0x8000 && selected+1 < map.countriesNum) { //left
            selected++;
            MapRender(selected);
        } else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 && selected > 0) {  // right 
            selected--;
            MapRender(selected);
        } else if(GetAsyncKeyState(VK_RETURN) & 0x8000) {
            startBattle(selected);
            break;
        }
    }
}

void MapRender(int selected) {
    printf("[*] MapRender Function\n");

    char mapString[100001] = "##################################################################\n#     #                                   #                      #\n#      #                                 #                       #\n#   @   #                               #                        #\n#        #                    ##########                         #\n#         #        C         #                                   #\n############                #                                    #\n#          #               #                                     #\n#         #               #                                      #\n#        #               #                                       #\n#       # #             #                      A                 #\n#          #           #                                         #\n#           ############                                         #\n#              #         #                                       #\n#     E       #           #                                      #\n#             #            #                                     #\n#            #              #                                    #\n#           #                ################################### #\n#          #                #                                   ##\n#         #                #                                     #\n#         #       D       #                                      #\n#         #              #                                       #\n#         #             #                   B                    #\n#        #             #                                         #\n#       #             #                                          #\n#      #              #                                          #\n#     #               #                                          #\n#     #               #                                          #\n##################################################################\n";

    switch(selected) {
        case 1:
            mapString[9*69 + 46] = '[';
            mapString[9*69 + 46 + 2] = ']';
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
    system("cls");
    puts(mapString);

}

void startBattle(int selected) {

}