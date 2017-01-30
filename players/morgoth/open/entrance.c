inherit "room/room";

reset(arg)
{
if(!present("guard")) {
move_object(clone_object("/players/morgoth/MONSTERS/entrance_guard.c"),this_object());
}
    if (arg) return;
    set_light(1);
    short_desc = "Morgoth's Realm";
    long_desc = "The realm of Morgoth, The Dark One.\n" +
    " \n"+
    "The forest beyond is forbidding and gloomy.\n" +
    "The trees are twisted and gnarled. Most uninviting.\n" +
    "A sense of doom permeates the very air.\n" +
    " \n" +
    " \n";    
    dest_dir = 
    ({
        "players/morgoth/CASTLE/blue1", "east",
        "players/morgoth/CASTLE/pen_lane1", "west",
        "players/morgoth/CASTLE/platform", "north",
        "room/plane7","out",
    });
}
move(str) {
  if(present("guard", this_object()))
    write("The guard blocks your path !!\n");
  else ::move(str);
  return 1;
}
