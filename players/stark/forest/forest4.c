inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A dimly lit forest";
  long_desc=
"   Water trickles and babbles along its trip to the east.  Soft sand \n"+
"gives way after a small bit of pressure.  A carcass of once mighty \n"+
"tree connects the two edges of the river.  Trees loom high above, \n"+
"closing in a stream of light.  To the east a large boulder drinks in \n"+
"the stream.  The walls of the stream close in around the high rock.\n";

  items=({
"water",
"Water flows eastward in this stream",
"sand",
"Finely ground grey sand lines the floor of the stream",
"carcass",
"A large tree crosses the stream to the west",
"tree",
"A large tree crosses the stream to the west",
"trees",
"Trees blank out the sky on both sides of the stream",
"boulder",
"The stream flows under a large boulder.  The hole looks large enough to allow you to climb down it",
"rock",
"The stream flows under a large boulder.  The hole looks large enough to allow you to climb down it"
  });

  dest_dir=({
    "/players/stark/forest/forest3","hop",
  });
}   

init() {
  ::init();
  add_action("search","search");
  add_action("climb","climb");
}

search(str) {
if(str == "boulder"){
 write("The stream flows under a large boulder, the hole looks large enough to allow you to climb down it.");
 return 1;}
write("You search the stream and find a large boulder of intrest.\n");
return 1;}

climb() {
  write("You climb down into the boulder.\n");
  this_player()->move_player("into the stream#/players/stark/forest/water");
  return 1;
}
