/* DarK ArenA ArchetypE */

inherit "/players/snow/dark/base.c";
#include "/players/snow/dark/defs.h"
#include "/players/snow/closed/cyber/color.h"
 
init()  {
 ::init();
  if(TP->is_player() && TP->query_level() < 15) {
    tell_object(TP, BOLD+"\tSnow tells you: This area is too dangerous for you.\n"+
          "\n\tYou are gently moved back.\n"+OFF);
    move_object(TP,"/players/snow/gate.c");
    }
  add_action("dark_cmds","dark");
  add_action("dark_voice","dvoice");
  if(TP->query_level() > 50) add_action("check_count","count");
  if(TP->query_level() > 60) add_action("do_create","create");
  TP->set_fight_area();
  if(!present("undead") && random(100) < APPEAR) {
    random_creation(); }
         }

exit() { TP->clear_fight_area(); }
realm() { return "NT"; }
query_darena() { return "boo"; }
