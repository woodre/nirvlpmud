inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc="The Entrance to Reese";
  long_desc=
"This is a pleasant little road heading south toward the town of Reese.\n"+
"The sides of the road are covered with plush fields of grass dotted by\n"+
"an occasional flower.  There is a sign nearby.\n";
  items=({
     "sign","The sign reads:\n\nWelcome to Reese!\n\n"+
     "Seek out Maldune for the story of the town and prepare yourself for\n"+
     "some strange happenings",
     "fields",
     "The fields are green and stretch as far as the eye can see\n",
     "flower",
     "The flowersare just normal little smelly flowers.\n",
    });
  dest_dir=({
     "/players/grimm/q/dock", "north",
     "/players/grimm/q/r/1/r4", "south",
    });
}
