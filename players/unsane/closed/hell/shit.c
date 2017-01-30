inherit "room/room";

#define tp this_player()->query_name()

reset (int arg){
if (!arg){
set_light(0);
short_desc="The Entrance to the First Circle of Hell";
 long_desc=
"    You begin to weep.  The sickly sweet smell of burning flesh permeates\n"+
"this place.  You begin to become sick to your stomach.  In the pit below\n"+
"you, you can see the writhing human mass.  They appear to be burning alive\n"+
"in pools of living surging fire.  This whole scene is sickening.  Also in\n"+
"the pit below you discern a massive distorted figure.  This demon appears to\n"+
"be whipping the bungled mass below.  You wonder if you should alleviate their\n"+
"suffering, or add to it?  Or shall you just flee this place entirely?\n";
items=({
  "pit","A fathomless pit, You could enter if you wished?",
"mass","They are a pathetic sight",
  "demon","You have a hard time seeing him from up here",});
dest_dir=({
"/players/unsane/hallway.c","flee",
"/players/unsane/closed/hell/fringe.c","north",
"/players/unsane/closed/hell/fringe2.c","east",
"/players/unsane/closed/hell/fringe3.c","south",
"/players/unsane/closed/hell/fringe4.c","west",});
} }
init(){
::init();
add_action("enter","enter");
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
int i;
if (i == 0) {
write("You search through the dirt and ashes and find a charred human bone.\n");
say(tp + " searches and finds something.\n");
move_object("/players/unsane/closed/hell/bone.c", this_player());
i++;
return 1;
}
write("There is nothing else here.\n");
return 1;
}
smell(){
write("The air here is sickening, yet sweet also.\n");
say(tp + " sniffs the putrid air.\n");
return 1;
}
enter(str){
string a,b;
if(sscanf(str, "%spit%s", a, b) != 2 ) {
write("You want to enter what???\n");
return 1;}
write("You enter the flaming pit.\n");
say(tp + " enters into the burning pit of hell.\n");
move_object(this_player(),"players/unsane/closed/hell/pit.c");
return 1;}
listen(){
write("This cacophony of screaming souls is too much too bear.\n");
say(tp + " perks up his ears.\n");
}

