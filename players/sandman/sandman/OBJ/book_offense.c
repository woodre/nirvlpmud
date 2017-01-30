id(str) { return str == "book" || str == "book of offense"; }

init() {
   add_action("read","read");
   add_action("blitzen","blitzen");
}

read(str) {
   if(str == "book" || "book of offense") {
   write("The ancient book tells of the most powerfull of spells. In the\n");
   write("book's wonderous pages you read of a spell that creats a scroll\n");
   write("that can be used to cast a lightning bolt upon a foe. To create\n");
   write("you must simply enter the word 'blitzen' which in the ancient\n");
   write("tounge means lightning.\n");
   return 1;
   }
}

blitzen() {
   object treasure;
   if(random(21) > this_player()->query_attrib("int")) {
      write("You are not wise enough to cast this spell.\n");
      write("With a flash, the book crumbles to dust.\n");
      destruct(this_object());
      return 1;
   }
   write("There is a rumble of thunder, and you find the book gone, and a\n");
   write("scroll in your hand.\n");
   treasure = clone_object("players/sandman/OBJ/lightning_scroll");
   move_object(treasure,this_player());
   destruct(this_object());
   return 1;
}

get() {
   return 1;
}

query_weight() {
   return 1;
}

long() {
   write("An old dusty book.\n");
}

short() {
   return "book of offense";
}
