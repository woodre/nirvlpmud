object obj;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="The Ground Floor of the Sinister Tower";
 long_desc=
"  You are at the bottom of a long spiralling staircase.  The stairs are made\n"+
"of solid cold stone, and they are speckled with blood.  The position of\n"+
"the walls acts as a natural amplifier for any sound, so you are battered\n"+
"by the maniacal screaming of a woman at the top of the tower.  There is very\n"+
"little light here, even though their are torches present.  It is as if\n"+
"the room just absorbs all light.  You also notice that you are becoming\n"+
"colder as well.  The shivers from the cold coupled with your shivers of fright\n"+
"make it quite difficult to hold your self together.  Shall you proceed up\n"+
"up the long and windy staircase or turn back whilst you still can?\n";
items=({
 "torches","These torches line the walls around you.  Not that they do much good",
  "torch","Just a piece of wood dipped in tar",
 "stairs","These stairs wind up a long way to the top",
  "blood","This blood is black and cracked.  It must be quite old",
 "walls","The walls are solid stone",
 "wall","All the walls look the same",
 "stair","The first step on the journey to the top",
  "staircase","A long and windy staircase",});
dest_dir=({
"/players/unsane/closed/hell/circle6.c","out",
"/players/unsane/closed/hell/uptower.c","up",});
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You search and find nothing.\n");
say(tp+" searches around and finds nothing.\n");
return 1;
}
smell(){
write("It smells old and dusty here.\n");
say(tp+ " takes a deep breath fo the air here.\n");
return 1;
}
listen(){
write("The screams of a woman echo through the halls.\n");
say(tp + " perks up their ears.\n");
return 1;
}

