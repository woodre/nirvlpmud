inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("A cave");
  long_desc=
"The light fades as you enter the cave. It's dim inside, the only\n"+
"light is what pours in from outside. An unpleasant animal odor\n"+
"wafts by your nose. You think you see something flicker out of\n"+
"the corner of your eye. You can hear something off in the distance.\n";
  dest_dir=
  ({
   "/players/bagera/jungle/room17.c", "north",
   "/players/bagera/jungle/cave2.c", "south"
    });
  }
