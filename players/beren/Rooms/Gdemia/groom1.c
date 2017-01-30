inherit "room/room";

reset(arg) {
  if(arg) return;
    set_light(1);
    short_desc = "Gdemia Domain";
    long_desc =
"You 've just entered the domain of Gdemia. You know nothing\n"+
"about it except that Gdemia live in Great Cavern. You can see\n"+
"it to the west.\n";
    dest_dir = ({"players/beren/Rooms/hall.c", "southeast",
		 "players/beren/Rooms/Gdemia/groom2", "west"});
}
