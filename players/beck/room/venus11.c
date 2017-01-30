inherit "room/room";
reset(arg) {
object flytrap1;
	if(arg) return;
set_light(1);
short_desc=("???");
long_desc=
"This is the edge of some large cliffs.  The ocean is fifty feet straight DOWN.\n"+
"Behind you is the waterfront.  Be careful walking here.  There are lots\n"+
"of sharp rocks, and dangerous creatures that lurk here.\n"+
"",
items=
({
"cliffs","These are steep cliffs covered with sharp rocks.  Don't try\n"+
"scale down them.  You can walk over to some more cliffs too",
"ocean","The ocean stretches out for miles and miles",
"rocks","Large pieces of granite and sharp shale",
"waterfront","A place where the ocean comes right up to the land.\n"+
"You can walk over there from here",

});
dest_dir=
({
});
if(!present("stagbeetle 1", this_object())){
move_object(clone_object("/players/beck/monster/stagbeetle.c"), this_object());
}
if(!present("flytrap 1", this_object())){
move_object(clone_object("/players/beck/monster/giant_flytrap.c"), this_object());
}
}
init() {
::init() ;
add_action("walk","walk");
}
walk(arg) {
if(!arg) {write("You can only walk to the other cliffs or to the waterfront.\n"); return 1;}
if(arg=="cliffs") {
write("You walk over to the other cliffs.\n");
call_other(this_player(),"move_player","walk#/players/beck/room/venus8.c");
return 1;
}
if(arg=="waterfront") {
write("You walk back to the waterfront.\n");
call_other(this_player(),"move_player","walk#/players/beck/room/venus10.c");
return 1;
}
}
