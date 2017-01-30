inherit "obj/clean";

id(str) {
   return str == "potion" || str == "green potion";
}

short() { return "bubbling green potion"; }

long() {
   write("A small glass vial filled with a green liquid.\n");
}

get() { return 1; }

value() { return 100; }

init() {
   add_action("drink","drink");
}

drink(str) {
   if(str == "potion") {
      write("You swallow the potion, and feel it burn in your stomach.\n");
      write("You feel the poison rotting inside you.\n");
      this_player()->hit_player(20);
      destruct(this_object());
      return 1;
    }
}
