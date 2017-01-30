
reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object lady;
   if(!present("morgana")) {
     lady = clone_object("players/molasar/rowan/drake/obj/morgana");
     move_object(lady, this_object());
   }
}

realm() { return "NT"; }

id(str) { return str == "shackles"; }

short() { return "Dungeon Cell"; }

long(str) {
   if(str == "shackles") {
     write("These shackles were made to fit around the wrists and ankles\n");
     write("of the prisoner, immobilizing them.\n");
     if(present("morgana")) {
       write("The old wench is securely fastened in them.\n");
       write("After giving them a thorough look you don't think you'll\n");
       write("have any trouble <remove>ing them.\n");
     }  
     return 1;
   }
   write("This cell seems to be in very good repair. There is no leakage\n");
   write("of water or cracks in the walls. A pair of shackles are\n");
   write("fastened to the northern wall.\n");
   write("     There are two obvious exits: south\n");
}

init() {
   add_action("south","south");
   add_action("remove","remove");
}

remove(str) {
   if(!str || !present("morgana"))
     return;
   present("morgana")->remove_shackles();
   return 1;
}

south() {
   this_player()->move_player("south#"+
                              "players/molasar/rowan/drake/mansion/dungeon");
   return 1;
}


