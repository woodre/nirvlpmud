#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";               
             
reset(){
set_id("totem");              
set_short("A totem pole");
set_long(YEL+"    __       __     \n"+
        "  ,oOOOo. .oOOOo,   \n"+  
        "  o''OO'"+GRN+"@ @"+YEL+"`OO''o   \n"+
    "  '."+NORM+"  /|| ||\\   "+YEL+".'   \n"+
 NORM+"       |\\"+YEL+"v"+NORM+"/|        \n"+
    BOLD+"        {"+NORM+RED+"~"+NORM+BOLD+"}         \n"+
    "         \"          \n"+NORM);
}
