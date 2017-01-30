inherit "room/room";

reset(arg){
  if(!present("man"))  {
    move_object(clone_object("/players/mythos/prac/man.c"),this_object());
  }

  if(!arg){
    set_light(1);
    short_desc="Dread";
    long_desc=
      "The place is dimly light.  All you can see is a small\n"+
      "man standing in the center of the room.  There is a definate smell-\n"+
      "rather bad, like that of rotten eggs.  To the south is a portal.\n";

    items=({
    "ground","Dirty and Dusty",
    "portal","A portal which leads who knows where",
    });

    dest_dir=({
    "/players/mythos/castle.c","portal",
    });
  }
}
