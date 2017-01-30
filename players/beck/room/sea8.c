inherit "room/room";
reset(arg) {
object shark1;
	if(arg) return;
set_light(1);
short_desc=("???");
long_desc=
"You are swimming out in a gigantic ocean.\n"+
"You bob up and down in the large waves.  You have swam out\n"+
"so far that the waterfront is hardly visible; And offers no protection!\n"+
"It is best to be careful out in these waters.\n"+
"You can see some land way off in the distance also.\n"+
"",
items=
({
"water","Yup, this is really liquid H20",
"ocean","There is lots of water everywhere",
"waterfront","You can barely see it from here",
"island","This island is very small.  It is covered with tall grass\n"+
"and has a few trees, and a rock formation near the center",
"waves","Just as you look up a giant wave crashes over your head",
});
dest_dir=
({
});
if(!present("shark 1", this_object())){
move_object(clone_object("/players/beck/monster/sand_shark.c"), this_object());
}
}
init() {
::init() ;
add_action("swim","swim");
}
swim(arg) {
if(!arg) {write("You can swim around, back, or out, but you must swim somewhere.\n");
return 1; }
if(arg =="back") {
call_other(this_player(),"move_player","swim#/players/beck/room/sea9.c");
write("You swim clockwise around the island.\n");
return 1;
}
if(arg == "out") {
write("You swim farther out to sea.\n");
call_other(this_player(),"move_player","swim#/room/sea");
return 1;
}
if(arg=="around") {
call_other(this_player(),"move_player","swim#/players/beck/room/sea7.c");
write("You swim counter-clockwise around the island.\n");
return 1;
}
if(arg=="waterfront") {
write("You swim over to the waterfront.\n");
call_other(this_player(),"move_player","swim#/players/beck/room/venus10.c");
return 1;
}
}
