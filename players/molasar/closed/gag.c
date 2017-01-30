
/*
 * GAG
 * Prevents players from executing commands.
 * Won't work on wizzes...
 */

string placer;

set_placer(p) { placer = p; }

id(str) { return str == "gag"; }

short() { return "A gag placed by "+capitalize(placer); }

long() {
   write("You see nothing special.\n");
}

init() {
   add_action("nope"); add_xverb("");
}

nope() {
   if(!living(environment(this_object()))) {
     destruct(this_object());
     return 1;
   }
   if(this_player() && this_player()->query_level() >= 21) {
     destruct(this_object());
     return 1;
   }
   write("I'm afraid you can't do that.\n");
   return 1;
}

