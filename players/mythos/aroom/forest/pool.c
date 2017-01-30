#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("unicorn")) {
    move_object(clone_object("/players/mythos/amon/forest/unicorn.c"),this_object());
  }
  if(!present("jinro") && random(3) == 0) {
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/jinro.c"),
      this_object());
  }
  if(!arg) {
  set_light(1);
    short_desc = "Forest Magic Pool";
    long_desc =
    "Unlike the rest of the forest, this place is lit with a\n"+
    "faerie light.  There is something odd here, a pool of\n"+
    "of shimmering water is here- and a one hornied beast- the Unicorn.\n";
  items = ({
    "south","The entrance to the forest can be seen",
    "north","The forest goes on and on",
    "east","The forest streches far as one can see",
    "west","You notice a dark path to the west",
    "pool","The pool is very odd.  You think you could 'dip' something in it",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/forest4.c", "east",
    "/players/mythos/aroom/forest/forest3.c","south",
    "/players/mythos/aroom/forest/pathway.c","west",
    "/players/mythos/aroom/forest/forest6.c","north",
  });
} }

init() {
  ::init();
  add_action("dip","dip");
}

dip() {
  object ob,ob2;
    ob = present("horni",this_player());
      if(!present("horni",this_player())) {
        write("Nothing Happens.\n");
      return 1;
      }
      if(present("horni",this_player())) {
      destruct(ob);
      write("You dip the horn into the pool...\n"+
        "There is a brilliant "+HIB+"FLASH"+NORM+" of light and you \n"+
        "draw out a blade of magic.\n");
      say("You see a brilliant FLASH.\n");
    say("You see "+this_player()->query_name()+" draw a "+HIB+"BLADE"+NORM+
    " of glowing blue from the pool.\n");
      ob2 = clone_object("/players/mythos/awep/forest/bane.c");
      move_object(ob2, this_player());
      write_file("/players/mythos/logs/ob",ctime(time())+"\t"+
      this_player()->query_real_name()+"\t\t"+this_player()->query_level()+"\tbane\n");       
      return 1;
      }
return 1;
}
