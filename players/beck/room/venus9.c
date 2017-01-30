inherit "room/room";
reset(arg) {
object flytrap1, flytrap2;
	if(arg) return;
set_light(1);
short_desc=("???");
long_desc=
"You are right along the waterfront.  The grass comes right down to\n"+
"the edge of the ocean.  There are a few small rocks that have washed up\n"+
"in between.  You can see a large field behind you.  Some of the strangest\n"+
"creatures around live in this unusual envoirnment.\n"+
"",
items=
({
"ocean","The ocean stretches out for miles and miles.\n"+
"Maybe you'd like to take a swim",
"grass","The grass blows gently in the breeze",
"field","The field is covered with tall grass.  Maybe you could walk to it",
"waterfront","Where the ocean meets the land.\n"+
"You can probally walk to the other part",
});
dest_dir=
({
});
if(!present("flytrap 1", this_object())){
move_object(clone_object("/players/beck/monster/flytrap.c"), this_object());
}
if(!present("flytrap 2", this_object())){
move_object(clone_object("/players/beck/monster/flytrap.c"), this_object());
}
}
init() {
::init() ;
add_action("swim","swim");
add_action("walk","walk");
}
walk(arg) {
if(!arg) {write("You can only walk to the field or along the waterfront.\n"); return 1;}
if(arg=="waterfront") {
write("You walk along the waterfront.\n");
call_other(this_player(),"move_player","walk#/players/beck/room/venus10.c");
return 1;
}
if(arg=="field"){
write("You walk back into the field.\n");
call_other(this_player(),"move_player","walk#/players/beck/room/venus6.c");
return 1;
}
}
swim(arg) {
if(!arg) {write("Where do you want to swim?\n"); return 1;}
if(arg !="ocean") {
write("You can only swim in the ocean.\n");
return 1;
}
write("You go for a swim in the ocean.\n");
call_other(this_player(),"move_player","swim#/players/beck/room/sea9.c");
return 1;
}
