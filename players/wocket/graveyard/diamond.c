#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";

reset(){
    set_id("diamond");
    set_short(HIC+"A large diamond"+NORM);
    set_long("This is a very large diamond.  As it sparkles in the sun you realize\nyou would probably get more money if you 'cash'ed it with a jeweler.\n");
    set_weight(1);
    set_value(1000);
}

init(){
    add_action("cash","cash");
}

int cash(string str){
int amount;
if (!str || str != "diamond"){
notify_fail("What would you like to cash?\n");
return 0;
}
if(!present("jeweller",environment(this_player()))){
  notify_fail("There is no one here who seems to be interested in buying a diamond.\n");
  return 0;
}
write("The jeweller says: This is a very fine diamond indeed.  Would you be willing\n  to part with it?\n");
say(this_player()->query_name()+" trades away "+this_player()->query_possessive()+" diamond.\n");
amount = 4500+random(501);
write("You cash in your "+HIC+"diamond"+NORM+" for "+amount+" coins.\n");
say(this_player()->query_name()+" cashes in a diamond.\n");
this_player()->add_money(amount);
destruct(this_object());
return 1;
}
