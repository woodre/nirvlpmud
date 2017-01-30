inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("A Dirt Road");
long_desc=
"This is a small dirt road leading out of Angel Grove.  There are rows\n"+
"of poplar trees lining the road, with a large expanse of fields just\n"+
"on the other side of them.  The road is fairly well maintained by the\n"+
"local farmers who use it to bring goods into the market near Angel Grove.\n"+
"However not much through traffic uses this road.\n"+
"To the west the road continues into the countryside, and to the east\n"+
"leads to the town square of Angel Grove.\n"+
"",
items=
({
"fields","You see fields to the north and south just past the trees\n"+
"The field to the south is escecially large.  Try going in that direction",
"trees","One long row of poplar trees",
});
dest_dir=
({
"players/beck/room/square.c","east",
"players/beck/room/crossroads.c","west",
});
}
init() {
::init() ;
add_action("south","south");
}
south(arg) {
call_other(this_player(),"move_player","south#/players/beck/room/field1.c"); return 1;}
