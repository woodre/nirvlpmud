#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Khazad Naggrund"+NORM+"("+HIK+"Main Hold"+NORM+")");
   set_long("\
  Finely carved walls stand about five feet in height forcing all\n\
but the shortest of creatures to walked hunched down.  Though the\n\
ceiling is low the width is wide enough to banish any feelings of\n\
confinement.  To the north the sounds of activitiy give one the\n\
notion of some sort of civilization, while to the south remains\n\
the ruins of the hold\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "walls", "They are well made adn quite stable",
         "ceiling", "It is smooth to the touch and flat",
         });
   dest_dir = ({
         "players/khrell/area/underways/undermdh2.c", "out",
         "players/khrell/area/dwarf/rm2.c", "north"});
   return 1; }      
