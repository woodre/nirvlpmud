#include "/players/cosmo/closed/ansi.h"

id(str) {
    return str == "sign" || str == "note";
}

long() {
    say(call_other(this_player(), "query_name") +
        " studies the sign.\n");
    write("\nThe sign bears an important message for all adventurers:\n"
     +YEL+"\tDue to federal budget cuts, many of the museums,\n"
         +"\texhibits, departments, and other buildings\n"
         +"\tin the DC area have been temporarily closed.\n"
         +"\tThey will slowly re-open as more funds become\n"
         +"\tavailable.  Thank you for your patience and\n"
         +"\tunderstanding during this difficult time.\n"
         +"\t\t\t -- The Management"+NORM+"\n");
}

short() {
    return ("A "+MAG+"small sign"+NORM+" posted firmly in the ground");
}

get() {
    write("You can't take the sign.\n");
    return 0;
}

init() {
    add_action("read","read");
}

read(str) {
    if (str == 0 || str != "sign") {
       notify_fail("Try <read sign>\n");
       return 0;
    }
    say(call_other(this_player(), "query_name") +
        " studies the sign.\n");
    write("\nThe sign bears an important message for all adventurers:\n"
     +YEL+"\tDue to federal budget cuts, many of the museums\n"
         +"\texhibits, departments, and other buildings\n"
         +"\tin the DC area have been temporarily closed.\n"
         +"\tThey will slowly re-open as more funds become\n"
         +"\tavailable.  Thank you for your patience and\n"
         +"\tunderstanding during this difficult time.\n"
         +"\t\t\t -- The Management"+NORM+"\n");
    return 1;
}
