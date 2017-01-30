short() { return 0; }
long() { return 0; }
id(str) { return 0; }
int x;

reset(arg) {
set_heart_beat(1);
	if(!arg) x=0;
}
init() {
	add_action("dig","dig");
	}
dig() {
	object user, ghost;
	x = x+1;
	user=this_player();
	if(x > 4) {
	write("All of the graves are empty.\n");
	return 1;
	}
	tell_object(user, "You begin to dig in the dirt to no avail.\n\n" +
"Then you notice some dirt move.\n" +
"All of a sudden a rotten hands shoves it way from the grave! A corpse\n" +
"throws away the dirt and crawls from his grave to stand in front of you.\n");
	ghost=clone_object("/players/dragnar/WasteLands/mons/corpse.c");
	move_object(ghost, environment(this_player()));
	return 1;
}
