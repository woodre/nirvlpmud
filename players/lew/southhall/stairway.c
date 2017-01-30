
inherit "room/room";

reset(arg) {
  if(!arg) {

    set_light(1);
    short_desc="A stairway";
    long_desc=
"As you enter the stairway you see the door to second south."+
"Not that it matters, 'cause second floor sucks.  You hear the\n"+
"distinct soud of singing coming from third floor.  You wonder to\n"+
"yourself. How could anyone be singing in this dismal place?\n"+
"You should check it out.\n";

    dest_dir= ( {
      "players/lew/southhall/thirdfloor", "up",
      "players/lew/southhall/firstfloor", "down",
    } );
}
}
