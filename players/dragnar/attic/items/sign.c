#include "/players/dragnar/closed/color.h"

id(str) { return str == "sign"; }

reset () {}

short() {
   return "A" + RED + BLINK + " warning" + WHI + NOSTYLE+ " sign";
}

long() {
   write(
    "It looks new, which seems odd in this place of decay.  It has some\n"+
    "writing on it in the color of blood, perhaps you could" + GRE + " 'read' " + WHI + "it?\n");
   return 1;
}

init() {
   add_action("read","read");
}

status
read(string str) {
	if( !str ) {
        write( "What do you want to read?\n");
        return 1;
	}
   write(
"\nThis area is full of chaos.  The world has been turned into a wasteland\n" +
"with great destruction.  There are no enforcers here, no rules to play\n" +
"by.  The only thing that matters here is survival.  Anyone can attack\n" +
"anyone here regardless of level or whether or not player kill is set.  There\n" +
"are many adventures here in the future, but your life will be taken if\n" +
"you are weak.\n");
   return 1;
}

get() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
