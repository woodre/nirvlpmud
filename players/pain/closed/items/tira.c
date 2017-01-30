#include "/players/pain/color.h"

init() {
add_action("tira", "tira");
}
drop() { return 1; }
get() { return 1; }

tira() {
object ob;

ob = present("tira",environment(this_player()));
ob->set_title("the "+BLUE+"Angel of Illusions"+END);
write("done");
return 1;
}
