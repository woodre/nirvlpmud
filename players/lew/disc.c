#include "obj/junk_only.c"
inherit "obj/weapon";

reset(arg) {
    if(!arg) {
      set_id("disc");
      set_short("A Tron disc");
    set_long("This is a Tron disc.  Type Tron to throw it at another player.\n");
     set_weight(2);
     set_value(100);
     set_class(15);
}
}
init() {
  ::init();

    add_action("hit","Tron");
}
hit(str) {
    object target;
    target=find_player(str);
    if(!target) { write("Player not on.\n"); return 1; }
   if(target->query_level() >20) { write("I don't think so.\n");
   return 1; }
    chan_msg(capitalize(find_player(str)->query_real_name())+" is struck down by a Tron disc.\n");
   tell_object(target, "THWAP!  You are hit in the head with a Tron disc.\n"+
                       "You see the disc return to "+capitalize(this_player()->query_real_name())+".\n");
    say(capitalize(this_player()->query_real_name())+" draws back an arm and lets go of a Tron disc.\n");
   return 1;
}
