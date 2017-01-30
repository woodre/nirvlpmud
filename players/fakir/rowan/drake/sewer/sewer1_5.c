
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg) {
     extra_reset();
     return;
   }
   set_light(0);
   set_short("Sewer under Drakeshore");
   set_long("You are in the sewer system under Drakeshore.\n"+
"This part of the tunnel seems to serve as some sort of common room.\n"+
"Tables, chairs, and many things you can't recognize lay cluttered about\n"+
"the room. Off towards the corner you see bones stacked in a pile almost\n"+
"three feet high. A small arch to the east is covered by a thick curtain.\n");
   add_item("chairs","These are nothing more than boxes with crude back\n"+
            "supportes nailed on.");
   add_item("tables","As you brush up against the table it starts to\n"+
            "precariously. Other than that you find nothing special.");
   add_item("bones","You identify many of the bones to be human, but there\n"+
                    "are some ogre, goblin, and bugbear skulls mixed in.");
   add_item("curtain","It's nothing more than a hide from some hideous\n"+
                      "monster you'd rather not run into if it was alive.");
   add_exit("south","/players/molasar/rowan/drake/sewer/sewer1_4");
   extra_reset();
}

extra_reset() {
   object bear;
   int i;
   if(!present("bugbear")) {
     i = 0;
     while(i < 5) {
       bear = clone_object("players/molasar/rowan/monsters/wand/bugbear");
       move_object(bear, this_object());
       i++;
     }
   }
}

init() {
   add_action("east","east");
   ::init();
}

east() {
   if(present("bugbear")) {
     write("A large bugbear blocks your way.\n");
     return 1;
   }
   this_player()->move_player("east#"+
                      "players/molasar/rowan/drake/sewer/sewer1_6");
   return 1;
}

