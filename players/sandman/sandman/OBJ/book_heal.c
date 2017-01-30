id(str) { return str == "book of healing" || str == "book"; }

init() {
   add_action("read","read");
   add_action("albazar","albazar");
}

read(str) {
   if(!str) {
     write("Try read book\n");
     return 1;
   }
   if(str == "book" || str == "book of healing") {
   write("You open up the tattered ancient book and glance at it's\n");
   write("wonderous spells. One spell stands out hovever, you begin to\n");
   write("read it more carefully:\n");
   write("\n");
   write("       Methode of healing potion creation\n");
   write("\n");
   write(" To create a magical potion of healing you must but enter\n");
   write(" the magical word 'albazar' which in the language of the wise\n");
   write(" means 'to make whole'. But be carefull, only the very wise have\n");
   write(" a chance to suceed with this spell.\n");
   return 1;
   }
}

albazar() {
   object me,potion;
   me = this_player();
   if(random(21) > me->query_attrib("int")) {
      write("You try to cast the spell, but are not intelligent enough.\n");
      write("The book crumbles to dust in your hand.\n");
      destruct(this_object());
      return 1;
   }
   write("You say the magik word, and WAH LA! You now have a heal potion.\n");
   potion = clone_object("players/sandman/OBJ/healing_potion");
   move_object(potion,this_player());
   destruct(this_object());
   return 1;
}

get() {
    return 1;
}

long() {
   write("An ancient tattered book of healing. Perhaps you should\n");
   write("'read book'.\n");
}

short() {
   return "Book of Healing";
}

