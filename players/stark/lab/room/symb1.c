inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="City Center";
  long_desc=
"   Tall buildings rise high above you.  Revolving doors shuffle people \n"+
"in and out of these structures of glass and concrete.  Cars rush \n"+
"quickly past on the asphalt roadway.  The sidewalk you currently stand \n"+
"upon is also occupied by a small village of people trying to get one \n"+
"way or another.\n";

  items=({
  });

  dest_dir=({
    "/players/stark/lab/room/symb2","north",
  });
}

init() {
  ::init();
  add_action("search","search");
}

search(str) {
  write("One building door seems stand out from the rest..\n");
  return 1;
}

