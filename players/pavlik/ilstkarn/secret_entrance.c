inherit "room/room";
#define POR "/players/pavlik/ilstkarn/ilstkarn_portal.c"
#define REALMSIZE 10

int door_locked;
int closing;

reset(arg) {
  if(arg) {
	return;
  }
  set_light(1);
  short_desc="On a Mountain Side";
  long_desc=
  "You have to crouch down some to fit inside this small mountainside\n"+
  "niche.  The walls are worn and smooth after centuries of erosion.\n"+
  "Strange markings cover the inner-most wall of the little cave.\n";
  items=({
	"markings",
	"The surface of the smooth wall has been covered with strange markings.\n"+
	"They do not make any sense to you, but after staring at them long enough\n"+
	"you think you can recognize the pattern of a key",
  });
  dest_dir=({
	"/players/pavlik/ilstkarn/cliff_niche", "exit",
  });
  door_locked = 1;
  closing = 0;
}

query_ilstkarn(){ return "secret"; }
realm(){ return "NT"; }
query_no_teleport(){ return 1; }
query_nofollow(){ return 1; }

init() {
  ::init();
  add_action("unlock","unlock");
  add_action("enter","enter");
}

unlock(str) {
  int i;

  if(str != "wall" && str != "markings" && str != "door") {
	return 0;
  }

  if(!door_locked) {
	write("The secret door is already open.\n");
	return 1;
  }

  if(!present("fortress_key", this_player())) {
	write("You do not have the key!\n");
	return 1;
  }

  write("You hold the mystic key against the smooth wall of the cave.\n");
  say(capitalize(this_player()->query_name())+" inserts a key into the "+
  "smooth cavern wall.\n");
  tell_room(this_object(), "\n"+
  "There is a faint 'click' and the cavern wall opens!!!\n"+
  "You can now enter the Arcydian Fortress!\n\n");

  /* make sure we get rid of the key */
  destruct(present("fortress_key", this_player()));

  write_file("/players/pavlik/ilstkarn/LOG",
  capitalize(this_player()->query_real_name())+" has unlocked the secret door. ["+ctime()+"]\n");

  door_locked = 0;
  return 1;
}

enter() {
  if(door_locked) {
	return 0;
  }

  this_player()->move_player("into the Fortress#players/pavlik/ilstkarn/fort_enter");

  /*
   * make sure the door closes and looks after a short time
   * notice the door doesn't start to close until after someone enters
   */
  if(closing == 0) {
	call_out("close_door", 50+random(250));
	closing = 1;
  }

  return 1;
}

close_door() {
  tell_room(this_object(),
  "The secret entrance to the Fortress slides shut and locks.\n");
  closing = 0;
  door_locked = 1;
}

