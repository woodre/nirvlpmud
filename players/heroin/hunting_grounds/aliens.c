inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Deep Space";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/hallway2.c","leave",
"players/heroin/hunting_grounds/corr1.c","corridor"});
long_desc=
"In the empty vaccuum of space, the prey of the hunter is limited\n"+
"and difficult to conquer.  The dangers for the hunter are different\n"+
"than anywhere else..Here man finds his greatest challanges, and to\n"+
"the experienced hunter--he finds his greatest rewards.  In space,\n"+
"there is nowhere to run or hide..one can only survive or die.  And\n"+
"also in space..one always dies alone without the sympathy of their \n"+
"saviors.  You find yourself inside a vessel of some sort...\n"+
"Time to prove yourself..or cower like the dog you really are!\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find nothing of significance\n");
say(tp + "says: hey look at me..I have nothin' new\n");
return 1;
}
listen(){
write("Droned out by the engines, is the faint sound of laughter\n");
say(tp + "thinks about death\n");
return 1;
}
