#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
set_id("potion");
set_short("A mystical potion");
set_long("A elongated flask holding a mystical potion.  The glass sparkles as\n"+
"the fluid inside swirls its magenta tenticals.  You may wish\n"+
"to 'drink' the potion.\n");
set_value(10000);
set_weight(1);
}
init(){
  add_action("drink","drink");
}

drink(string str){
  if(!str || str != "potion"){
    notify_fail("What would you like to drink?\n");
    return 0;
  }
write("You drink the magical potion.\nThe fluid rushes through your veins refreshing you.\nYou smash the empty flask.\n");
say(this_player()->query_name()+" drinks a potion.\n");
this_player()->heal_self(1000);
call_other(this_player(),"drink_alcohol",-1000);
call_other(this_player(),"drink_soft",-1000);
call_other(this_player(),"eat_food",-1000);
destruct(this_object());
this_player()->recalc_carry();
return 1;
}
