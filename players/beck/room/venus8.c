inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("???");
long_desc=
"This is the edge of some large cliffs.  The ocean is fifty feet straight DOWN.\n"+
"Behind you is the field.  Be careful walking here.  There are lots\n"+
"of sharp rocks, and dangerous creatures that lurk here.\n"+
"",
items=
({
"ocean","The ocean stretches out for miles and miles",
"field","The field you see is covered with tall grass. Try walking to it",
"cliffs","These cliffs are very steep.  If you are afraid of heights\n"+
"this is not the place to hang around. You can walk to the other cliffs too",
"rocks","Sharp rocks cover the side of the cliff.\n"+
"You notice, however, a large formation of granite close by.\n"+
"Inspecting closer you see a place you might be able to climb",
});
dest_dir=
({
});
if(!present("flytrap", this_object())){
move_object(clone_object("/players/beck/monster/giant_flytrap.c"), this_object());
}
if(!present("octophant 1", this_object())){
move_object(clone_object("/players/beck/monster/octophant.c"), this_object());
}
}
init() {
::init() ;
add_action("walk","walk");
add_action("climb","climb");
}
walk(arg) {
if(!arg) {write("You can only walk to the other cliffs or to the field.\n"); return 1;}
if(arg=="cliffs") {
write("You walk over to the other cliffs.\n");
call_other(this_player(),"move_player","walk#/players/beck/room/venus11.c");
return 1;
}
if(arg=="field") {
write("You walk back to the field.\n");
call_other(this_player(),"move_player","walk#/players/beck/room/venus7.c");
return 1;
}
}
climb(arg) {
if(!arg) {write("What do you want to climb?\n"); return 1;}
if(arg !="rocks") {
write("The only thing to climb here is the rocks.\n");
return 1; }
call_other(this_player(),"move_player","climb#/players/beck/room/venus5.c");
return 1;
}
