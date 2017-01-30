id(str) { str == "healing potion" || str == "potion"; }

short() {
   return "healing potion";
}

long() {
   write("A fragile glass flask filled with a bubbling green liquid.\n");
}

init() {
   add_action("drink","drink");
}

drink() {
   write("You drink the potion, and all of a sudden feel alot better!\n");
   say(capitalize(this_player()->query_real_name())+" drinks a green potion\n");
   this_player()->heal_self(20);
   destruct(this_object());
   return 1;
}

get() {
   return 1;
}
