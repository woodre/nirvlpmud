inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("A large field");
long_desc=
"You are in a large field covered in waist deep grass.\n"+
"All that grows here is the grass and flowering weeds.\n"+
"Off to the north in the distance you can spot a few trees, and\n"+
"to the northeast you think you can see some signs of civilization.\n"+
"South of you rises a barren mountain a few hundred feet tall.\n"+
"It appears there is something on it.\n"+
"",
items=
({
"grass","thick, green grass, about 3 feet tall",
"trees","A line of poplar trees",
"mountain","It is actually a giant, barren, rock",
"weeds","various weeds that are growing mulitcolored flowers",
});
dest_dir=
({
});
}
init() {
::init() ;
add_action("north","north");
add_action("south","south");
}
north(arg){
call_other(this_player(),"move_player","north#/players/beck/room/road2.c"); return 1;}
south(arg) {
call_other(this_player(),"move_player","south#/players/beck/room/mountain1.c"); return 1;}
