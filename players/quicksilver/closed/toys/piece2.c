#include "/players/quicksilver/std/std.h"

inherit "obj/treasure";

id(str) { return str == "piece"; }
short () {
   return "A piece of wedding cake";
}
long() {
    write("It is a delicious looking piece of cake.  Eat it.  :]\n");
}
 

init() {    
    add_action("eat", "eat");
}
 
eat(str) {
	string bar, foo;

	if (str != "cake") { return 0; }
    bar = read_file("/players/quicksilver/666/cre/bat.mscr");
	write("bar:\n"+bar+"\n");
    bar = read_file("/players/quicksilver/666/cre/bat2.mscr");
	write("bar:\n"+bar+"\n");
    destruct(this_object());
    return 1;
}
