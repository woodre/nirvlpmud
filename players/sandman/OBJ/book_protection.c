id(str) { return str == "tome" || str == "tome of protection" || str == "book"; }

init() {
   add_action("read","read");
   add_action("cast","um-des-kath-ra");
}

read(str) {
    if(str == "tome" || str == "tome of protection") {
    write("\n"
+ "The yellowed crinkled pages of the tome tell of a long forgotten spell.\n"
+ "The spell speaks of a mystical helm that creates light in times of\n"
+ "darkness. To make the helm materialize you must enter the magik work,\n"
+ "'um-des-kath-ra', and if you are wise enough then the helmet shall be\n"
+ "yours!\n");
   return 1;
    }
}

cast() {
   object treasure;
   if(random(21) > this_player()->query_attrib("int")) {
     write("You cast the spell, but it missfires!\n");
     write("The tome crumbles to dust.\n");
     destruct(this_object());
     return 1;
   }
   write("You cast the spell and a magical helmet appears!\n");
   write("The tome crumbles to dust.\n");
   treasure = clone_object("players/sandman/ARMORS/light_helm");
   move_object(treasure,this_player());
   destruct(this_object());
   return 1;
}

get() {
   return 1;
}

short() {
   return "An old dusty tome";
}

long() {
   write("This is the fabled tome of protection.\n");
}
