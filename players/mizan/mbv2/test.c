get() { return 1; }

id(str) { return str == "roomid"; }

init() { add_action("roomid", "roomid"); }

roomid()
{
	object room;
	room = environment(this_player());
	write(object_name(room) + "\n");
}
