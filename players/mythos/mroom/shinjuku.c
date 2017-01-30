inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Shinjuku Station>> ";
    long_desc =
    "                      Shinjuku\n"+
    "This is the area of enterainment.  Kabuki-cho is just\n"+
    "around the corner- the place where if one wants fun, one\n"+
    "will find it.  Often there are bands playing here...\n";
  items = ({
    "ikebukuro","Head to the international hook up",
    "tokyo","The center of the city",
    "ginza","Shopping center!",
    "akihabara","Cybertech city!",
    "roppongi","The place of people",
    "beyond","nnnn",
  });

  dest_dir = ({
    "/players/mythos/mroom/ikebukuro.c","ikebukuro",
    "/players/mythos/mroom/akihabara.c","akihabara",
    "/players/mythos/mroom/tokyo.c","tokyo",    
    "/players/mythos/mroom/roppongi.c","roppongi",
 /* "/players/mythos/mroom/quad.c", "beyond",   */
  });
} }
