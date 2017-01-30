#include "ansi.h"
#define FILE "/players/illarion/temp"


void reset(int arg) {

write_file(FILE,
HIC+"*"+CYN+"--------------------------------------------"+HIC+"*\n"+
CYN+"|                                            |\n"+
"|   "+HIR+"|_|"+NORM+"                                      "+CYN+"|\n"+
"|   "+HIR+"| |IGHLANDER"+NORM+": \"There can be only one\"    "+CYN+"|\n"+
"|    "+HIY+"_"+NORM+"                                       "+CYN+"|\n"+
"|   "+HIY+"|_)  ,"+NORM+"                                   "+CYN+"|\n"+
"|   "+HIY+"|  OKEMON"+NORM+": \"Gotta catch 'em all\"         "+CYN+"|\n"+
"|                                            "+CYN+"|\n"+
HIC+"*"+CYN+"--------------------------------------------"+HIC+"*\n"+NORM+
"     From the village green: 4w,6n,2u,1e\n");
     
}
