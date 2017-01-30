inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Estate grounds";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/frntgates.c","scurry",
"players/heroin/hunting_grounds/nugey.c","brush"});
long_desc=
"You stepped onto the estate grounds and find yourself deep within\n"+
"heavy brush.  You can still see the house from here, but now\n"+
"your hunter's adrenaline is kicking in and you know the true\n"+
"hunt is within this brush, not with killing off servants. YAWN\n"+
"You feel a strong urge to hide yourself in the brush and quietly\n"+
"pounce upon your unsuspecting prey.  Who could possibly refuse the\n"+
"hunt when the brush is the arena?\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find a path through the thick brush\n");
say(tp + "points to the brush\n");
return 1;
}
listen(){
write("You listen and hear a faint: FSWWWWWW Thump.\n");
say(tp + "checks his compass\n");
return 1;
}
