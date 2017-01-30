#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure";

reset(){
    set_id("aturtleshell");
    set_alias("shell");
    set_short(GRN+"a turtle's shell"+NORM);
    set_long("This is a turtle's shell.  If shaped by a skilled smith it has\n"+
    "many protective uses.  If all else fails you can always 'cash' it in.\n");
    set_long("This is a turtle's shell.  It has many protective uses if used by\n"+
    "someone skilled shaping it.  If all else fails you can always 'cash' it in.\n");
    set_weight(1);
    set_value(random(200));
}

init(){
    add_action("cash","cash");
}

int cash(string str){
int amt;
if(!str || str != "shell"){
    notify_fail("What would you like to cash?\n");
    return 0;
}
amt = 850;
write("You cash in your shell for 850 coins.\n");
this_player()->add_money(amt);
destruct(this_object());
this_player()->recalc_carry();
return 1;
}
