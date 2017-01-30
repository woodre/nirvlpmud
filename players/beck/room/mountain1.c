inherit "room/room";
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Base of a mountain");
long_desc=
"You arrive at the base of a small mountain.  It appears to\n"+
"be nothing more than a large rock, as there is no vegetation on it.\n"+
"Looking toward the top you see a structure or building of some sort.\n"+
"A large field stretches out to the north of you. \n"+
"Even though the surface is quite smooth and steep, it appears that\n"+
"you might be able to scale the mountain.\n"+
"",
items=
({
});
dest_dir=
({
});
}
init() {
::init() ;
add_action("north","north");
add_action("scale","scale");
}
north(arg) {
call_other(this_player(),"move_player","north#/players/beck/room/field1.c"); return 1;}
scale(arg){
if(!arg){write("What do you want to scale?\n"); return 1;}
if(arg !="mountain"){write("You can only scale the mountain.\n"); return 1;}
call_other(this_player(),"move_player","mountain#/players/beck/room/mountain2.c"); return 1;}
