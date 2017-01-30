inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 10

reset(arg) {
  if(arg) {
	POR->create_monster(this_object());
	return;
  }
  set_light(1);
  short_desc="Somewhere in the Mountains of Ilstkarn";
  long_desc=
  "You have wandered deep into the Ilskarken Mountains.  Tall jagged peaks\n"+
  "thrust defiantly into the sky.  The ageless mountains cast deep\n"+
  "impenatrable shadows across the uneven ground.  A bone chilling wind\n"+
  "cuts mercilessly at your skin.\n";
  dest_dir=({
	"/players/pavlik/ilstkarn/path4", "northeast",
	"/players/pavlik/ilstkarn/path2", "west",
	"/players/pavlik/ilstkarn/path3", "northwest",
	"/players/pavlik/ilstkarn/enter", "south",
  });
  POR->create_monster(this_object());
}

query_ilstkarn(){ return "path1"; }
realm(){ return "NT"; }

init(){
  ::init();
  if(this_player()->is_player() && !random(4)) { 
	POR->create_monster(this_object());
  }
  add_action("south","south");
}

south() {
  int i;
  i = random(7);
  if(random(10) > 7) {
	this_player()->move_player("south#players/pavlik/ilstkarn/path"+i);
  }
  else {
	this_player()->move_player("south#players/pavlik/ilstkarn/enter");
  }
  return 1;
}


okay_follow() { return 1; }
