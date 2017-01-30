object obj;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("demon")) {
for ( v = 0; v < 5; v++) {
obj = clone_object("players/unsane/closed/hell/wrathful");
move_object(obj, this_object());
}
obj = clone_object("/players/unsane/closed/hell/killer");
move_object(obj, this_object());
}
short_desc="Mired in the River Styx";
 long_desc=
"  You are now mired in this disgustingly filthy river.  The wrathful are all\n"+
"around you here.  They are constantly fighting and tearing at one another\n"+
"and anything else that happens to come their way.  The bog itself is\n"+
"really very warm.  You cannot touch the bottom of the river with your feet,\n"+
"so you assume it is a long way to the bottom.  Occasionally a severed head or\n"+
"a limb will float by you.  Also, you are not sure if this is water or not,\n"+
"mainly because it is stained red by the blood spilled here.\n"+
"The tower still looms ahead of you on the horizon.\n";
items=({
  "river","The river is stained with the blood of the wrathful",
  "limbs","These limbs fill up the river with their decay",
 "water","The blood red water gleams in the light.  Or is that something below the water? Hmm..",
 "tower","The tower looks to be an evil place",
"head","Sometimes a head will float past you",
"bubbles","You fear that their may be a more deadly evil mired deep in the bog",
  "sky","The sky is becoming more overcast",
  "limb","Occaisonally you spot one of these floating in the river",});
dest_dir=({
"/players/unsane/closed/hell/circle6.c","cross",
"/players/unsane/closed/hell/banks.c","back",});
}
init(){
::init();
add_action("dive","dive");
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
dive() {
write("You take a deep breath and dive down deeper.\n");
say(tp + " dives deep down into the bog.\n");
move_object(this_player(), "/players/unsane/closed/hell/down.c");
return 1; }
search(){
if (i < 3) {
write("You find a severed limb.\n");
move_object(clone_object("players/unsane/closed/hell/limb.c"),this_player());
say(tp+" just found a severed limb.\n");
i++;
return 1; }
i++;
write("You search the fetid waters, but to no avail.\n");
say(tp+" searches the dank waters in vain.\n");
return 1;
}
smell(){
write("The stench of the bog is overpowering.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
listen(){
write("The bubbling of the bog mixed with the screams of the wrathful makes this an unpleasant place.\n");
say(tp + " perks up their ears.\n");
return 1;
}

