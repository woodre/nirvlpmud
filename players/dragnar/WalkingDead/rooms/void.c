inherit "room/room";

reset(arg) {

  if(arg) return;
  
  short_desc = "WalkingDead Void";
  long_desc="You are in a void, there is nothing here but the lack of anything.\n";
  set_light(1);
  dest_dir=({
    "/room/church","leave",
  });
}

init() {
	::init();
}