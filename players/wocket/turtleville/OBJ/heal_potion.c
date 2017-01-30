inherit "obj/treasure.c";
#include "/players/wocket/closed/ansi.h"

reset(arg){
  if(arg) return;
set_id("potion");
set_alias("full heal");
set_short(MAG+"A mystical potion of full healing"+NORM);
set_long("An elongated flask holding a mystical potion.  The glass sparkles as\n"+
"the fluid inside swirls its magenta tenticles.  You may wish\n"+
"to 'drink' the potion.\n");
set_value(17000);
set_weight(1);
}
init(){
  add_action("drink","drink");
}

drink(string str){
if(!str || (str != "potion" && str != "full heal")){
    notify_fail("What would you like to drink?\n");
    return 0;
  }
write("You drink the magical potion.\nThe fluid rushes through your veins refreshing you.\nYou smash the empty flask.\n");
this_player()->heal_self(1000);
say(this_player()->query_name()+" drinks a potion.\n");
call_other(this_player(),"drink_alcohol",-1000);
call_other(this_player(),"drink_soft",-1000);
call_other(this_player(),"eat_food",-1000);
destruct(this_object());
this_player()->recalc_carry();
return 1;
}

/* Made unstorable 5/99 -Snow */
/* Make save, jan-03 -Bp
query_save_flag() { return 1; }
*/
