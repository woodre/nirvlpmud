#include "/players/pain/color.h"

init() {
add_action("chrys", "chrys");
}
drop() { return 1; }
get() { return 1; }

chrys() {
object ob;

ob = present("kain",environment(this_player()));
ob->set_pretitle("Hurt me, Spank me, I want to feel ->"+RED+"Pain"+END+"<-");
write("done");
return 1;
}
