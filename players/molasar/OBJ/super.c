
id(str) { return str == "superheal" || str == "super"; }

short() { return "A superhealer"; }

long() {
   write("A superhealer.\n");
}

init() {
   if(this_player()->query_level() < 21) { return 1; }
   add_action("superheal","superheal");
}

superheal() {
   this_player()->heal_self(1000000000);
   write("You've been superhealed!\n");
   return 1;
}

get() {
   if(this_player()->query_level() > 21) { return 1; }
   return 0;
}

