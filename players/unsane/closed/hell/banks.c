inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Banks of the River, Styx";
 long_desc=
"   Here you are at the banks of the swamp-like river Styx.  You feel a bit\n"+
"more safe here than you did a second ago.  Perhaps that is because you\n"+
"can discern no visible threat.  Mired in this bog of a river are the Wrathful.\n"+
"They constantly tear and mangle each other, while fighting not to drown\n"+
"themselves.  The water of the river is thick and there are bits and\n"+
"pieces of muck and refuse floating in it.  There is also an occaisonal human\n"+
"limb or bit of flesh as well.  After you have been here awhile, you notice\n"+
"bubbles appearing on the muddy surface of the water.  You wonder if\n"+
"there could be something else to be found in the deeper depths of the bog?\n"+
"Also, now that you are close to the river, you can see a tower off in the\n"+
"distance.  There appear to be signal fires burning on top of the tower.\n"+
"You are unsure of their purpose.\n";
items=({
 "river","You don't know why anyone would want to swim in this disgusting river",
 "water","The water of the river Styx is disgusting and filled with trash",
 "refuse","There is all sorts of unthinkable nasty things in the river",
 "muck","The flesh here has coagulated into a mucky paste",
 "flesh","The river is filled with torn human flesh",
 "tower","The tower looms menacingly in the distance",
 "fires","You have no idea what these signal fires are for",
  "limbs","These limbs fill up the river with their decay",
"wrathful","They are very dangerous, Be careful",
"bubbles","You fear that their may be a more deadly evil mired deep in the bog",
  "sky","The sky is dark and clouded here",
  "limb","Occaisonally you spot one of these floating in the river",});
dest_dir=({
"/players/unsane/closed/hell/circle4+.c","south",});
}
init(){
::init();
add_action("swim","swim");
add_action("swim","dive");
add_action("enter","enter");
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
swim() {
write("You foolishly enter the muddy waters.\n");
say(tp+" jumps into the bog.\n");
move_object(this_player(), "/players/unsane/closed/hell/river.c");
return 1; }
enter(str) {
string a, b;
if (!str) {
write("What do you wish to enter?\n");
return 1; }
if (sscanf(str, "%sriver%s",a,b) == 2) {
write("You foolishly enter the river, Styx\n");
say (tp +" enters the river.\n");
move_object(this_player(), "players/unsane/closed/hell/river.c");
return 1; }
write("Enter what??\n");
return 1; }
search(){
write("You search the swampy earth, but to no avail.\n");
say(tp +"searches the swampy earth in vain.\n");
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

