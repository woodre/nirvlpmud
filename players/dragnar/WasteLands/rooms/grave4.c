inherit "room/room";

int digs;

init() {
    ::init();
    add_action("cmd_dig", "dig");
    this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->clear_fight_area();
}
cmd_dig() {
    object ghost;

/* digs set at random(3) from 4  -Snow */
    if (++digs > 1 + random(3)) {
	write("All of the graves are empty.\n");
	return 1;
    }
    write(
"You begin to dig in the dirt to no avail.\n\n" +
"Then you notice some dirt move.\n" +
"All of a sudden a rotten hand shoves it way from the grave!  A corpse\n" +
"throws away the dirt and crawls from his grave to stand in front of you.\n");
    ghost = clone_object("/players/dragnar/WasteLands/mons/corpse");
    move_object(ghost, environment(this_player()));
    return 1;
}

reset(arg) {
    if (digs > 1) digs = 0;

    if (arg) return;
    set_light(1);
    short_desc=("Graveyard");
    long_desc=
"This is the second isle in the graveyard.  The grave you are standing\n" +
"near looks so fresh you wonder what you would find if you were to dig.\n",
    dest_dir=({
	"players/dragnar/WasteLands/rooms/grave3","west",
	"players/dragnar/WasteLands/rooms/grave1","south",
	});
}
gravesite() {
    return "YES";
}
