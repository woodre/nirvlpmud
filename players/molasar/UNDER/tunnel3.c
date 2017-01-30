
reset(arg) {
     if(!arg)
       set_light(0);
     extra_reset();
}

object orc, sword;
int i;

extra_reset() {
     i = 0;
     if(!present("orc")) {
       while(i < 3) {
         i += 1;
         orc = clone_object("players/molasar/MONSTERS/orc_guard");
         sword = clone_object("players/molasar/WEAPONS/sword");
         transfer(sword, orc);
         move_object(orc, this_object());
         call_other(orc,"init_command","wield sword");
       }
     }
}

init() {
     add_action("down","down");
     add_action("west","west");
     add_action("north","north");
}

north() {
     call_other(this_player(),"move_player",
                    "north#players/molasar/UNDER/tunnel2");
     return 1;
}

down() {
     if(present("orc")) {
       write("An orc bars your way!\n");
       return 1;
     }
     call_other(this_player(),"move_player",
                    "down#players/molasar/UNDER/tunnel10");
     return 1;
}

west() {
     if(present("orc")) {
       write("An orc bars your way.\n");
       return 1;
     }
     call_other(this_player(),"move_player",
                    "west#players/molasar/UNDER/tunnel4");
     return 1;
}

short() { return "A guards post"; }

long() {
     write("This is an area used by the orcs to guard the entrance.\n");
     write("Numerous assorts of junk and looted items cover the floor,\n");
     write("mostly valueless costume jewelry.\n");
     write("   There are three obvious exits:  north, west, and down\n");
}


