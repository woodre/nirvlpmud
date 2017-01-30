int v;
int i;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("demon")) {
for (i=0; i<4; i++) {
move_object(clone_object("/players/unsane/closed/hell/slothful"), this_object());
}}
short_desc="Drowning in the River Styx";
 long_desc=
"   You can hardly see your own hand in this mess.  The water here is thick\n"+
"and stained red.  You can taste the blood in the water.  Most of the lighter\n"+
"particles have sunk down here.  So, you can see corpses and heads and\n"+
"such down on the bottom of the river.  This is the resting place of the\n"+
"slothful, who let their lives pass away in idleness.  The seem to be\n"+
"harmless enough, but who knows?  You can still hear the screams of the\n"+
"wrathful above you and you are glad they aren't coming down here.\n";
items=({
  "muck","There are all sorts of monstrosities down here",
  "limbs","The river bottom is littered with these things",
  "heads","These lifeless heads litter the river",
  "head","This head has no eyeballs",
"limb","A severed limb",
"corpses","These corpses carpet the river bottom",
"corpse","This corpse has been gutted",
  "water","The water is thick with gore here",});
dest_dir=({
"/players/unsane/closed/hell/river.c","up",});
}
init(){
::init();
add_action("dive","dive");
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
if (v < 2) {
write("You find a hacked off head.\n");
move_object(clone_object("players/unsane/closed/hell/head.c"),this_player());
say(tp+" just found a severed head.\n");
v++;
return 1; }
v++;
write("You search the river bottom, but to no avail.\n");
say(tp +"searches the river bottom in vain.\n");
return 1;
}
smell(){
write("You snort water up your nose.\n");
say(tp+" breathes in water like a moron.\n");
return 1;
}
listen(){
write("You can hear the screams of the wrathful echoing through the water.\n");
say(tp + " perks up their ears.\n");
return 1;
}

