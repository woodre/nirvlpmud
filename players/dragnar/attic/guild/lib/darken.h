#include "/players/dragnar/guild/defs/def.h"
darken() {
	object scar;
	write("You darken your mark of shardak with a knife.\n");
	destruct(present("shardak_mark",this_player()));
	scar=clone_object("/players/dragnar/guild/slave.c");
	move_object(scar, this_player());
	return 1; }
