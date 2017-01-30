id(str) { return str == "statue"; }

short() {
   return "A Beautiful Marble Statue";
}

long() {
   write("A 30 ft. high grey marble statue. The statue is of a stately\n");
   write("mysterious looking young woman. A secret smile plays across her\n");
   write("angelic face. Her eyes follow you as you walk by, almost as if she\n");
   write("were somehow still alive. At the bottom of the statue is a plaque.\n");
}

init() {
   add_action("look","look");
   add_action("look","l");
   add_action("read","read");
   add_action("pray","kneel");
}

look(str) {
   if(str == "at plaque") {
      write("At the base of the statue is a metallic plaque made of some\n");
      write("unearthly metal that glows with an inner light.\n");
      write("Maybe you should 'read plaque'.\n");
      return 1;
   }
}

read(str) {
   if(str == "plaque") {
      cat("/players/sandman/plaque1.c");
      return 1;
   }
}

pray(str) {
   if(str == "before statue") {
      if(this_player()->query_ghost() == 0) {
         write("A feeling of well being washes over you.\n");
         return 1;
      }
     write("The statue comes to life and blesses you!!!\n");
     write("You feel yourself become more solid.\n");
     write("You also feel a little bit richer.\n");
     say("The statue comes to life and blesses "+this_player()->query_real_name());
     this_player()->remove_ghost();
     this_player()->add_money(100);
     return 1;
   }
}

get() {
   write("The statue is too massive to pick up.\n");
   return 0;
}
