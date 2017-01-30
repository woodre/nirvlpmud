inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 10

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Somewhere in the Mountains of Ilstkarn";
  long_desc=
  "You have wandered deep into the Ilskarken Mountains.  Tall jagged peaks\n"+
  "thrust defiantly into the sky.  The ageless mountains cast deep\n"+
  "impenatrable shadows across the uneven ground.  A bone chilling wind\n"+
  "cuts mercilessly at your skin.\n";
  dest_dir=({
	"/players/pavlik/ilstkarn/path5", "northwest",
	"/players/pavlik/ilstkarn/path2", "east",
  });
  if(!present("syrian_blacksmith", this_object())) {
	move_object(clone_object("players/pavlik/monsters/ilstkarn/syrian_blacksmith"),
	this_object());
  }
  if(!present("tatzlwurm", this_object())) {
	move_object(clone_object("players/pavlik/monsters/ilstkarn/tatzlwurm"),
	this_object());
  }
}

init() {
  ::init();
}

query_ilstkarn(){ return "path5a"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
