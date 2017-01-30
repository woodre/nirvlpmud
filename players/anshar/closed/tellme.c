#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
inherit "/obj/treasure";
short() { return "A magical gem"; }

long() { write("    A magical gem with which to talk to Anshar. 'wtell <msg>' to talk.\n"+
               "    'wtelle <msg>' to emote.\n"); }

id(str) { return str == "gem"; }

init() {
        add_action("wtell", "wtell");
        add_action("wtelle", "wtelle");
}

wtell(str) {
    object plyr;
    string myname;
    if (!str) {
	write("Tell Anshar what?\n");
	return 1;
    }
    myname = capitalize(this_player()->query_real_name());
    plyr = find_living("anshar");
    if(!plyr) { write("Anshar is not on now.\n"); return 1; }
    plyr->add_tellhistory(myname + " tells you: " + str);
    tell_object(plyr, myname + " tells you: " +GRN+str+NORM+ "\n");
    write("You tell Anshar " +GRN+str+NORM+ "\n");
    return 1;
}
wtelle(str) {
    object plyr;
    string myname;
    if (!str) {
	write("Emote what to Anshar?\n");
	return 1;
    }
    myname = capitalize(this_player()->query_real_name());
    plyr = find_living("anshar");
    tell_object(plyr, myname + " " +GRN+str+NORM+ ".\n");
    if(!plyr) { write("Anshar is not on now.\n"); return 1; }
    write("You emote " +GRN+str+NORM+ " to Anshar.\n");
    return 1;
}
drop(){
 destruct(this_object());
 return 1;}

