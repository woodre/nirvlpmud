#include "/players/wocket/closed/ansi.h"

inherit "obj/treasure";

reset(arg){
    set_id("winvite");
    set_alias("invitation");
    set_short("A wedding invitation");
    set_long("\n"+
BOLD+"                    @"+GRN+"}-,-`---"+YEL+"   _\\|O|/_   "+GRN+"---,-`-{"+NORM+BOLD+"@\n"+NORM+
"\n"+
BOLD+"                         "+
YEL+"You have been invited\n"+NORM+
BOLD+"                             "+
YEL+"to the wedding\n"+NORM+
BOLD+"                                   "+
YEL+"of\n"+NORM+
BOLD+"\n                          "+
"  "+
BLU+"Kristin and Oofle\n"+NORM+
"\n\n"+
BOLD+"                    "+
YEL+"You must "+NORM+"'"+BOLD+"rsvp"+NORM+"'"+YEL+BOLD+" your invitation\n"+NORM+
BOLD+"                    "+
YEL+"to arrive promptly at the church\n"+NORM+
"                     "+
"note:  this will cost 10 sp\n"+
"\n"+
BOLD+"                    @"+GRN+"}-,-`---"+YEL+"   ~/|O|\\~   "+GRN+"---`-,-{"+NORM+BOLD+"@\n"+NORM+
    "");
    set_read("You read the back of the card.  You are satisfied to know that this carries the Wockmark(tm)\n");
}

init(){
    add_action("rsvp","rsvp");
}

int rsvp(){
if(environment(this_player())->query_realms() == "NT"){
    notify_fail("The warping of space prevents you.\n");
return 0;
}

    say(this_player()->query_name()+" has accepted a wedding invitation.\n");
    write("You have accepted the wedding invitation.\n");
    move_object(this_player(),"/room/sea_bottom.c");
    say(this_player()->query_name()+" has entered and claims a seat.\n");
    this_player()->add_spell_point(-10);
    destruct(this_object());
    return 1;
}
