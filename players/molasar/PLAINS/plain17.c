
reset(arg) {
     if(arg) return;
     set_light(1);
     extra_reset();
}

object naut, money, amulet;

extra_reset() {
     if(!present("naut")) {
       naut = clone_object("players/molasar/MONSTERS/naut");
       money = clone_object("obj/money");
       money->set_money(250+random(250));
       amulet = clone_object("players/molasar/MAGIC/amul_tele");
       move_object(money, naut);
       transfer(amulet, naut);
       transfer(naut, this_object());
     }
}

short() { return "A large open plain"; }

long() {
   write("You are in a large open plain.  Paths lead in all directions.\n");
   write("   There are four obvious exits:  north, south, east, and west\n");
}

init() {
     add_action("north","north");
     add_action("south","south");
     add_action("east","east");
     add_action("west","west");
}

north() {
     this_player()->move_player("north#players/molasar/PLAINS/plain18");
     return 1;
}

south() {
     this_player()->move_player("south#players/molasar/PLAINS/plain16");
     return 1;
}

east() {
     this_player()->move_player("east#players/molasar/PLAINS/plain12");
     return 1;
}

west() {
     this_player()->move_player("west#players/molasar/PLAINS/plain20");
     return 1;
}

