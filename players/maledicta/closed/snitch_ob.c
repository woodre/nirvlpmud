inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define USER environment()

int current;

reset (arg) {
if(arg) return;
  set_id("snitch");
  set_short(HIY+"~"+HIW+"o"+HIY+"~"+NORM+" (dormant)");
  set_long(
  "  This is a small golden ball with smooth grooves and etchings\n"+
  "along its surface.  It fits easily in the palm of your hand.\n"+
  "You see two protrusions that might allow you to 'activate' it.\n");
  set_weight(1);
  set_value(0);
  }

init(){
  ::init();
  add_action("activate", "activate");
  }

activate(str){
 if(environment() != this_player()) return;
 if(!str){ write("activate what?\n"); return 1; }
 if(str == "snitch"){
  write("You push on the two small golden protrusions and two\n"+
        "silver wings lash out and begin to buzz.\n"+
        "The snitch flies into the air!\n");
  tell_room(environment(USER),
  USER->query_name()+" activates the snitch!\n",({USER}));
  move_object(clone_object("/players/maledicta/closed/snitch.c"), environment(USER));
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
  }
write("activate what?\n");
return 1;
}