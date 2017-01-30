inherit "room/room";

#define tp this_player()->query_name()
object dog;

reset (arg){
if (!arg){
set_light(1);
}
if (!present("thrull")) {
for (i=0; i<2; i++){
dog=clone_object("players/unsane/closed/extra/thrull.c");
move_object(dog, this_object());
}
}
short_desc="The Pit of Despair";
 long_desc=
"  This area pulsates evil waves of darkness.  You feel a sinking feeling in\n"+
"your stomach as well.  Around you echo the cries of the Thrulls, evil beings\n"+
"created by the Ebon Order.  The walls and floor here are sticky with slime\n"+
"and the oozing presence of the Thrulls.  That hole from the bar must have\n"+
"led to the very depths of the ninth circle of hell!!!  You must find a way \n"+
"to escape!  You cannot take the evilness.\n";
items=({
"walls","The walls move and pulsate with evil",
"hole","The hole leads back up to the bar",
"floor","The floors pool up with a vile substance",
"hell","You must escape from this hell",});
dest_dir=({
"/players/unsane/closed/extra/room2.c","up",});
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You search the much and find more of these evil thrulls!!!\n");
say(tp+" unearths more evil thrulls.\n");
move_object(clone_object("/players/unsane/closed/extra/baby.c"),this_object());
return 1;
}
smell(){
write("The stench of thrulls is ever present here.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
listen(){
if (!present("thrull")) {
write("All you can hear is the oozing of the walls.\n");
}
if (present("thrull")) {
write("The thrulls scream all about you!\n");
}
say(tp + " perks up their ears.\n");
return 1;
}

