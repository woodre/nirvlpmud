inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";
reset (int arg){
if (!arg){
set_light(1);
}
short_desc="The filthy sewage";
items=({
"sewage", "You are up to your neck in raw sewage"});
dest_dir=({
"/players/heroin/hunting_grounds/gordqrtrsd.c","climb",
"players/heroin/hunting_grounds/smanwrld.c","east",
"players/heroin/hunting_grounds/jokes.c","laughter"});
long_desc=
" AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH\n"+
"                   SPLASH                                  \n"+
"In your attempt to climb into the sewer, you have slipped and\n"+
"fallen approximately 30 feet into a pool of raw sewage.  It is hard\n"+
"to see for there is water and sewage pouring in on you from all \n"+
"around.  You swim over to the side and grab onto a grate.  The \n"+
"echos of the water falling is almost deafening..and if that wasn't\n"+
"bad enough, there is the maddening cackle coming from furthe in the\n"+
"sewers.  You feel a small suction from below you, and as you \n"+
"investigate, you notice just below the surface to the east, is an \n"+
"opening.  One thing is for sure, you'll drown if you stay here.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
object ob;
if(random(100) < 80){ write("You find nothing of interest.\n"); return 1; }
if (i == 0) {
write("You find a hotdog.\n");
say(tp + "asks you: Pardon me, but do you have any Grey Poupon?\n");
ob = clone_object("/players/heroin/hunting_grounds/hotdog");
move_object(ob, this_player());
i++;
return 3;}
write("That's it you greedy piggy.\n");
return 1;
}
listen(){
write("You can't hear a damn thing in here\n");
say(tp + "covers their ears\n");
return 1;
}
