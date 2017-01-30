#include "/players/maledicta/ansi.h"
#include "/players/maledicta/weapon/define.h"


main(object user, object wep, string name, string short){ 
if(!ATT) return 0;
if(!present(ATT, environment(USER))) return 0;
if(ATT->is_player()) return 0;
if(ATT && ATT->query_hp() > 50) return 0;
if((ATT->query_hp()*10)/(ATT->query_mhp()) > 1) return 0;
    
tell_object(USER,
BOLD+"Your "+name+" calls down the power of Death..."+NORM+"\n");
tell_room(environment(USER),
HIR+"    .o oOOOOOOOo                                            OOOo\n");
tell_room(environment(USER),
"    Ob.OOOOOOOo  OOOo.      oOOo.                      .adOOOOOOO\n"+
"    OboO\"\"\"\"\"\"\"\"\"\"\"\".OOo. .oOOOOOo.    OOOo.oOOOOOo..\"\"\"\"\"\"\"\"\"'OO\n");
tell_room(environment(USER),
"    OOP.oOOOOOOOOOOO \"POOOOOOOOOOOo.   `\"OOOOOOOOOP,OOOOOOOOOOOB'\n"+
"    `O'OOOO'     `OOOOo\"OOOOOOOOOOO` .adOOOOOOOOO\"oOOO'    `OOOOo\n");
tell_room(environment(USER),
"    .OOOO'            `OOOOOOOOOOOOOOOOOOOOOOOOOO'            `OO\n"+
"    OOOOO                 '\"OOOOOOOOOOOOOOOO\"`                oOO\n");
tell_room(environment(USER),
"   oOOOOOba.                .adOOOOOOOOOOba               .adOOOOo.\n"+
"  oOOOOOOOOOOOOOba.    .adOOOOOOOOOO@^OOOOOOOba.     .adOOOOOOOOOOOO\n");
tell_room(environment(USER),
" OOOOOOOOOOOOOOOOO.OOOOOOOOOOOOOO\"`  '\"OOOOOOOOOOOOO.OOOOOOOOOOOOOO\n"+
" \"OOOO\"       \"YOoOOOOMOIONODOO\"`  .   '\"OOROAOPOEOOOoOY\"     \"OOO\"\n");
tell_room(environment(USER),
"    Y           'OOOOOOOOOOOOOO: .oOOo. :OOOOOOOOOOO?'         :`\n"+
"    :            .oO%OOOOOOOOOOo.OOOOOO.oOOOOOOOOOOOO?         .\n"+
"    .            oOOP\"%OOOOOOOOoOOOOOOO?oOOOOO?OOOO\"OOo\n");
tell_room(environment(USER),
"                 '%o  OOOO\"%OOOO%\"%OOOOO\"OOOOOO\"OOO':\n"+
"                      `$\"  `OOOO' `O\"Y ' `OOOO'  o             .\n");
tell_room(environment(USER),
"    .                  .     OP\"          : o     .\n"+
"                              :\n"+
"                              ."+NORM+"\n");


    ATT->heal_self(-(ATT->query_hp()));
    ATT->hit_player(500);
return 0;
}

