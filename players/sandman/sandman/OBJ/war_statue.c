id(str) { return str == "statue" || str == "viking statue"; }

short() {
   return "A statue";
}

long() {
   write("A finely crafted marble statue of a powerfull viking warrior.\n");
}

init() {
   add_action("touch", "touch");
}

touch(str) {
   if(str != "statue") {
      return 1;
   }
   write("The statue shudders, and splits in half!!!!!\n\n");
   write("A deadly warrior emerges from within, he looks pissed!\n");
   move_object(clone_object("players/sandman/MONSTERS/warrior"), environment(this_object()));
   destruct(this_object());
   return 1;
}
