inherit "room/room";
int i;

init() {
   ::init();
   add_action("slide","slide");
   add_action("swing","swing");
}

slide() {
   write("You climb up the big slide, and slip quickly to the ground\n");
   write("Boy was that FUN!\n\n");
   return 1;
}

swing() {
   write("You sit on the seat, and swing higher, and higher until finally\n");
   write("your turn is over. You get off feeling a bit better.\n");
   return 1;
}

reset(arg) {
   if(!present("rat")) {
      for(i=0;i<5;i++) {
        move_object(clone_object("players/sandman/MONSTERS/child"), this_object());
      }
   }
   if(!arg) {
      set_light(1);
      short_desc="A playground [ne]";
      long_desc="This is a playground filled with little kids. They are\n"+
                "yelling and scretching as they slide down the slide, and\n"+
                "swing on the swings.\n";
      dest_dir=
      ({
        "players/sandman/DAYDREAM/gpath1", "northeast"
      });
   }
}
