inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Stone wall");
  long_desc=
    "This is the southeast corner of the stone structure.\n"+
    "Off in the distance yousee nothing but thick jungle.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room53.c", "north",
      "/players/bagera/jungle/room61.c", "southeast",
      "/players/bagera/jungle/room60.c", "west"
   });
}
