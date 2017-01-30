inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";

reset (int arg){
if (!arg){
set_light(1);
}
if (!obj) {
obj=clone_object("obj/treasure.c");
call_other(obj,"set_name","filth");
call_other(obj,"set_id","filth");
call_other(obj, "set_alias","pile");
call_other(obj,"set_short","A pile of filth");
call_other(obj,"set_long",
"This is a huge mound of rotting and decaying bodies.  They appear to be\n"+
"picked clean by some kind of scavengers.  But wait!  Now that you look closer\n"+
"you are sure that you see puncture wounds.  How can that be?\n");
call_other(obj,"set_weight",200);
move_object(obj, this_object());
}
short_desc="A Rocky Canyon";
 long_desc=
"   This is the northern end of the canyon.  There are many rocks, and\n"+
"other debri scattered about here.  The whole area is in total chaos.  You\n"+
"This may have something to do with the Hurricane that is whipping\n"+
"through this place.  You are kept on your toes constantly by the flying rubble\n"+
"and other junk.  You are pretty sure that you don't want to get too close\n"+
"to the actual hurricane, lest you get sucked up into it.  There is also\n"+
"seems to be some kind of wailing from the center of the hurricane.  This whole\n"+
"place makes you really nervous.  And to think, this is only the second circle.\n";
items=({
 "rock","A very large rock",
 "debri","You must be careful or you will get decked by flying debri",
 "rubble","The rubble consists of splintered wood, bodies, and crushed rocks",
 "junk","More flying rubble",
  "hurricane","This hurricane dances all about the cavern floor.\nYou think"+
" you hear voices from inside of it",
     "rocks","There are large rocks strewn about the canyon floor",});
dest_dir=({
"/players/unsane/closed/hell/circle2.c","south",});
}
init(){
::init();
add_action("enter","touch");
add_action("enter","enter");
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
object ob;
if (i == 0) {
write("You search about and find a broken spear in the mass of bodies.\n");
say(tp + " searches and finds something.\n");
ob = clone_object("/players/unsane/closed/hell/bspear");
move_object(ob, this_player());
i++;
return 1;}
write("There is nothing else to find here.\n");
return 1;
}
smell(){
write("The air here is thick.  And you think you can smell blood.\n");
say(tp + " sniffs the air here.\n");
return 1;
}
enter(str){
string a,b;
if(sscanf(str, "%shurricane%s", a, b) != 2 ) {
write("You want to enter what???\n");
return 1;}
write("You are immediately sucked up into the hurricane.\n");
say(tp + " is sucked into the hurricane.\n");
move_object(this_player(),"players/unsane/closed/hell/air.c");
return 1;}
listen(){
write("The winds is loud here, but you are still sure you hearing screaming.\n");
say(tp + " perks up their ears.\n");
return 1;
}

