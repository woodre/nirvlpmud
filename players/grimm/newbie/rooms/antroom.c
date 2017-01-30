inherit "room/room";
object ant;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Ant Hill";
    long_desc = 
        "This is a large ant hill.  Ants are continuously flowing out of\n"+
        "the mouth of it.\n";
    dest_dir = 
        ({
         "players/grimm/newbie/rooms/room7","north",
       });
}

init() {
  if(!present("ant")) {
    ant = clone_object("/players/grimm/newbie/monsters/redant");
    move_object(ant,this_object());
    ant = clone_object("/players/grimm/newbie/monsters/sugarant");
    move_object(ant,this_object());
    ant = clone_object("/players/grimm/newbie/monsters/fireant");
    move_object(ant,this_object());
  }
  add_action("north","north");
}

north() {
  this_player()->move_player("north#/players/grimm/newbie/rooms/room7");
  return 1;
}
