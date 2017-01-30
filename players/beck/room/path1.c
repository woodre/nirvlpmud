inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("???");
long_desc=
"You are on a small path in a dense hardwood forest.  Only isolated\n"+
"beams of light reach you.  As you stare down it you realize the path\n"+
"continues for quite some distance, but is somewhat overgrown from disuse.\n"+
"To the north the path widens out into a road and leads to more open land.\n"+
"Out of the corner of your eye you spy some light to the west.\n"+
"On closer inspection you notice the outline of a small castle.\n"+
"",
items=
({
});
dest_dir=
({
"players/beck/room/road1.c","north",
});
}
init(){
::init();
add_action("west","west");
}
west(arg){
call_other(this_player(),"move_player","west#/players/beck/room/pal_entry.c");
return 1;
}
