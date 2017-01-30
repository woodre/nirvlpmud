inherit "room/room";
object quit;
reset(arg) {
quit=clone_object("/players/dragnar/rooms/quit.c");
move_object(quit, this_object ());
	if(arg) return;
set_light(1);
short_desc=("A dark hallway");
long_desc=
"As you enter the room you feel the floor drop beneith you.\n";
items=
({"sign","A sign that reads, get out",
});
dest_dir=
({
"players/dragnar/rooms/roomC.c","north",
"players/dragnar/rooms/entrance.c","death",
});
}
