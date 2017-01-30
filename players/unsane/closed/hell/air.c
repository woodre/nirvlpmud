inherit "room/room";
/* i changed the id checks from 'demon' to 'harpy' because some
 * people have pets with an id of 'demon' ...

 * - miz 2007 jan 13 */

#define tp this_player()->query_name()
int i;
object obj, harpy;
inherit "room/room";

reset(arg){
if (!arg){
set_light(1);
}
if (!present("harpy")) {
for (i = 0; i <3; i++) {
harpy = clone_object("players/unsane/closed/hell/harpy.c");
move_object(harpy, this_object());
}
}
short_desc="2000 Feet Above the Ground";
 long_desc=
"    You are in the center of the hurricane.  It has grabbed your body and\n"+
"tossed you like a rag doll up here, 2000 feet above the ground?!  You\n"+
"fell a little nauseous when you look down.  Now that you are above the cloud\n"+
"cover you can see the sky here in the second circle.  The sky is a turbulent\n"+
"chaos.  It is maddening to look at.  There seems to be pieces of earth and\n"+
"some human forms just flying about up there.  Must be new arrivals.  You can\n"+
"also see the first circle far away through the chaos.  But, there's no\n"+
"time for that now.  All around you here are the scavengers.  Beware the \n"+
"guardian harpies!\n";
items=({
 "hurricane","You are right in the middle of it",
   "sky","This is truly a bizarre and frightening sight",
"clouds","These clouds actually look kind of pretty from up here",
"humans","There are humans forms floating through the sky toward the first circle",
"human","A lost soul drifting about in the chaos",
"soul","A floating human form",
"form","The shape of a human tossing through the void",
"circle","The first circle hangs above you, how much better it looks",
  "earth","This is just some of the debri floating in the void",
"ground","You are sure you are gonna die if you fall",});
dest_dir=({
"/players/unsane/closed/hell/hurricane.c","down",});
}
init(){
::init();
add_action("down","down");
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
add_action("fall","fall");
   add_action("search","search");
}
search(){
object ob;
write("Yeah ok, you are gonna search whilst flying about through the air?\n");
say(tp + " tries to search the air like a moron.\n");
return 1;
}
smell(){
write("All you can smell is the stench of the Harpies presence.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
down() {
if (!present("harpy")) {
write("You made it!\n");
move_object(this_player(),"players/unsane/closed/hell/hurricane.c");
command("look",this_player());
return 1; }
write("You cannot escape while the harpies are attacking you.\n");
say(tp + " tries to run, but fails.\n");
return 1; }
fall() {
write("You fall 2000 feet to your almost certain death.\n");
say(tp + " falls to their death.\n");
this_player()->hit_player(50);
move_object(this_player(),"players/unsane/closed/hell/hurricane.c");
command("look",this_player());
return 1; }
listen(){
if (!present("harpy")) {
write("The air still echoes with the screams of the dead harpies.\n");
}
if (present("harpy")) {
write ("All you can hear is the screaming harpies.\n");
}
say(tp + " perks up their ears.\n");
return 1;
}

