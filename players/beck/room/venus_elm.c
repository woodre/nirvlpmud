inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("???");
long_desc=
"You are at the top of a large elm tree.\n"+
"From this spot you can see almost the entire island as well as the ocean.\n"+
"You can see some cliffs off in the distance as well as the beach\n"+
"and another waterfront area.  You think you can see some land way\n"+
"off in the distance past the sea beyond the waterfront.\n"+
"",
items=
({
"beach","A small beach runs along one side of the island",
"field","A large field stretches out below you",
"waterfront","Off in the distance you see another waterfront area where you can get to the ocean",
"cliffs","You see some steep cliffs on one side of the island",
"ocean","In every direction you see an endless sea",
});
dest_dir=
({
});
}
init() {
::init();
add_action("climb","climb");
}
climb(arg){
if(!arg){ write("Where are you going to climb?\n"); return 1;}
if(arg !="down") {
write("You can only climb down from here.\n"); return 1; }
write("You climb down the tree.\n");
call_other(this_player(),"move_player","climb#/players/beck/room/venus6.c");
return 1;
}
