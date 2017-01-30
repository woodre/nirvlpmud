#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";

reset(){
    set_id("ruby");
    set_short(RED+"A large ruby"+NORM);
  set_long("This is a very large ruby.  As it sparkles in the sun you realize you\nwould probably get more money if you 'cash'ed it in with a jeweller.\n");
    set_weight(1);
    set_value(1000);
}

init(){
    add_action("cash","cash");
}

int cash(string str){
int amount;
if (!str || str != "ruby"){
notify_fail("What would you like to cash?\n");
return 0;
}
if(!present("jeweller",environment(this_player()))){
  notify_fail("There is noone here who seems to be interested in buying a ruby.\n");
  return 0;
}
write("The jeweller says: This is a very fine ruby indeed.  Would you be willing\n  to part with it?\n");
say(this_player()->query_name()+" trades away "+this_player()->query_possessive()+" ruby.\n");
amount = 3000+random(501);
write("You cash in your "+RED+"ruby"+NORM+" for "+amount+" coins.\n");
say(this_player()->query_name()+" cashes in a ruby.\n");
this_player()->add_money(amount);
destruct(this_object());
return 1;
}
