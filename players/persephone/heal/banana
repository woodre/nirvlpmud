#include "/players/persephone/rooms.h"
id(str) { return str == "soda";}
short() { return "A Testube full of Soda";}
long() { write("It looks like it is Womble Berry flavoured yum.\n");
return 1;
}
get() { return 1; }
drop() { return 0; }
query_value() { return 100; }
init() {
 add_action("drink","drink");
}
drink() {
 say(CAPTPLNM + " drinks a testube full of pop and seems to enjoy it\n");
 write("You drink some soda pop and feel slightly refreshed\n");
 TPL->heal_self(5);
 destruct(this_object());
return 1;
}

