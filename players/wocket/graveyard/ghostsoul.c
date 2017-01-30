#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";
int charges;
int touched;

reset(arg) {
  if(arg) return; /* added arg return -verte */
    set_id("ghost_soul");
    set_alias("soul");
    set_short(BOLD+"A ghost's soul"+NORM);
set_long("This is the pure soul of a lost ghost.  You must only 'grasp_soul'\nto regain its energy.  If the soul is untarnished perhasp it could even\nbe 'cash'ed in.\n");
    set_weight(0);
    set_value(700);
charges = 4;
}

init(){
    add_action("graspsoul","grasp_soul");
    add_action("cash","cash");
}

graspsoul(){
charges--;
touched = 1;
this_player()->add_spell_point(43);
write(BOLD+"As you grasp the pure soul, energy fills you.\n"+NORM);
say(this_player()->query_name()+" grasps the soul of a lost ghost.\n");
if(charges == 0){
    write("The soul disapates.\n");
    destruct(this_object());
}
return 1;
}

cash(string str){
int amount;
if(str != ("soul" || "ghost_soul" ) ){
  notify_fail("What would you like to cash?\n");
   return 0;
}
if(touched == 1){
write("The soul has been tarnished.\n");
return 1;
}
amount = 3000 + random(1500);
write("You cash in your "+BOLD+"ghost soul"+NORM+" for "+amount+" coins.\n");
say(this_player()->query_name()+" cashes in a soul.\n");
this_player()->add_money(amount);
destruct(this_object());
return 1;
}
