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
  "You have wandered deep into the Ilskarken Mountains.  The howling\n"+
  "mountain winds which have cut into the mountain's side since time\n"+
  "forgotten have created a smooth niche in which you can seek some\n"+
  "shelter.  The narrow mountain trail also continues around the cliffside.\n";

  dest_dir=({
	"/players/pavlik/ilstkarn/path"+random(REALMSIZE), "southeast",
	"/players/pavlik/ilstkarn/secret_entrance", "enter",
  });

  if(!present("basalisk", this_object())) {
	move_object(clone_object("players/pavlik/ilstkarn/monsters/basalisk"),
	this_object());
  }
}

query_ilstkarn(){ return "niche"; }
realm(){ return "NT"; }
query_nofollow(){ return 1; }

