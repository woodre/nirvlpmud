#include "/players/persephone/rooms.h"
id(str) { return str == "tea";}
short() { return "A Long Glass of Iced Tea";}
long() { write("This Glass of ice tea looks so refreshing with the lemon garnish.\n");
return 1;
}
get() { return 1; }
drop() { return 0; }
query_value() { return 500; }
init() {
 add_action("drink","drink");
}
drink() {
 say(CAPTPLNM + " slams down the Iced Tea in one hit.\n");
 write("You slam down the Iced Tea and feel extremely refreshed\n");
 TPL->heal_self(30);
 destruct(this_object());
return 1;
}

