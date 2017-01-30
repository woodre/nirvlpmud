/* DarK ArenA ArchetypE */

inherit "/players/snow/dark/base.c";
#include "/players/snow/dark/defs.h"
#include "/players/snow/closed/cyber/color.h"
 
init()  {
 ::init();
  if(!this_player()) return;
  if(!TP->is_player()) return;
  if(this_player())
  if(TP->is_player() && TP->query_level() < 15) {
    tell_object(TP, BOLD+"\tSnow tells you: This area is too dangerous for you.\n"+
          "\n\tYou are gently moved back.\n"+OFF);
    move_object(TP,"/players/snow/gate.c");
   return 1;
    }
  add_action("dark_cmds","dark");
  add_action("dark_voice","dvoice");
  if(TP->query_level() > 50) add_action("check_count","count");
  if(TP->query_level() > 60) add_action("do_create","create");
  TP->set_fight_area();
  if(TP->is_player()) {
  if(!present("undead") && random(100) < APPEAR) {
    call_out("random_creation",3); }
  }
         }

exit() { if(this_player()) TP->clear_fight_area(); }
realm() { return "NT"; }
query_darena() { return "boo"; }
gravesite() { return "YES"; }
