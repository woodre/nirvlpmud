inherit "room/room";
object toilet;
init() {
	::init();
}
reset(arg) {
	toilet=clone_object("/players/emerson/mons/ftoilet.c");
	move_object(toilet, this_object());
	if(arg) return;
set_light(1);
short_desc=("A bathroom stall");
long_desc=
"As you enter the stall you are almost overcome by the fumes\n"+
"that have lingered behind from the last occupant. There is a toilet\n"+
"here, also known as a john. Maybe there is something in it... =P\n",
items=
({
"john","It looks like there is something nasty in the toilet... =P",
});
dest_dir=
({
"players/emerson/rooms/fbath.c","exit",
});
}
