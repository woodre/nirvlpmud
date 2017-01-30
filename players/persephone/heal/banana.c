#include "/players/persephone/rooms.h"
id(str) { return str == "banana";}
short() { return "A Bunch of Bananas";}
long() { write("These bananas look all golden and ripe for eating.\n");
return 1;
}
get() { return 1; }
drop() { return 0; }
query_value() { return 250; }
init() {
 add_action("drink","eat");
}
drink() {
 say(CAPTPLNM + " greedily scarfs down a bunch of bananas\n");
 write("You greedily eat a bunch of yummy bananas and feel slightly better\n");
 TPL->heal_self(15);
 destruct(this_object());
return 1;
}

