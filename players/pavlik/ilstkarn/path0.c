inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 10

reset(arg) {
  if(arg) {
	return;
  }
  set_light(1);
  short_desc="Somewhere in the Mountains of Ilstkarn";
  long_desc=
  "You have wandered deep into the Ilskarken Mountains.  Tall jagged peaks\n"+
  "thrust defiantly into the sky.  The winding mountain trail deadends\n"+
  "at the mouth of a yawning chasm.  You glance nervously down and can see\n"+
  "no bottom to the gaping pit.\n";
  dest_dir=({
	"/players/pavlik/null", "south",
  });
  if(!present("kreeg", this_object())) {
	move_object(clone_object("players/pavlik/monsters/ilstkarn/storm_giant"),
	this_object());
  }
}

query_ilstkarn(){ return "path0"; }
realm(){ return "NT"; }
query_no_teleport(){ return 1; }

init() {
  ::init();
  add_action("go_away","south");
}

go_away(){
  if(call_other(this_player(), "query_attrib", "str") < random(40)){
	write("\n"+
	"YOU SLIP AND FALL INTO THE CHASM!!!!!!!!!\n"+
	"\n"+
	"You feel very weak as your badly damaged body falls to the ground to die.\n"+
	"\n"+
	"You die.\n"+
	"You have a strange feeling.\n"+
	"You can see your own dead body from above.\n"+
	"\n"+
	"setting hit points to 1/3 max....\n"+
	"\n");
	say(capitalize(this_player()->query_real_name())+
	" slips and falls to his death!\n");
	move_object(this_player(), "players/pavlik/ilstkarn/path0a");
	return 1;
  }
  this_player()->move_player("up#players/pavlik/ilstkarn/path3");
  return 1;
}


okay_follow() { return 1; }
