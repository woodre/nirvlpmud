inherit "/room/room.c";

int found;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Nest";
  long_desc=
"  A large walnut tree sits in the middle of Strawberry Fields.  A\n\
bird's nest is cradled higher up in the tree.\n";
  items=({
    "tree", "The walnut tree has a bird's nest in it",
    "nest", "You think you see something in the nest, but you can't\n"+
            "tell from here",
  });
  dest_dir = ({
    "/players/morgoth/CASTLE/field3","west",
  });
}

void init() {
  ::init();
  add_action("cmd_climb","climb");
}

int cmd_climb(string str) {
  if(str!="tree") {
    write("Climb what?\n");
    return 1;
  }
  if(random((int)this_player()->query_attrib("ste")) < 8) {
    write("You try to climb the tree, but fall on your butt.\n");
    say((string)this_player()->query_name()+" tries to climb the tree and fails.\n");
    return 1;
  }
  say((string)this_player()->query_name()+" climbs up into the tree and searches the nest.\n");
  if(found) {
    write("You climb up the tree and search the nest, but find nothing there.\n");
    return 1;
  }
  write("You find a jade figurine in the nest.\n");
  move_object(clone_object("/players/morgoth/OBJ/figurine.c"),this_player());
  this_player()->add_weight(1);
  found=1;
  return 1;
}


query_temp() { return 2; }
