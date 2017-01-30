inherit "room/room";

void
init() {
    ::init();
    this_player()->set_fight_area();
}

reset(int arg) {
    object digger;
    if (!present("digger", this_object())) {
	digger = clone_object("/players/dragnar/WasteLands/mons/grave");
	move_object(digger, this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc = ("Graveyard Entrance");
    long_desc =
"Here you see many graves that seem to be just recently dug.  There is\n" +
"nothing but mounds of dirt to even show that there are graves here.  It\n" +
"looks like someone was in a hurry to dig these...like a lot of them\n" +
"had to be done in a short time.\n";
    dest_dir = ({
	"players/dragnar/WasteLands/rooms/grave1","east",
	"players/dragnar/WasteLands/rooms/grave2","west",
	"players/dragnar/WasteLands/rooms/grave3","north",
	"players/dragnar/WasteLands/rooms/room_road1","south",
    });
}
