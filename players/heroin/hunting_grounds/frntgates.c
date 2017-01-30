inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Mansion entrance";
items=({
"note","The note reads: Hey Rush ole Buddy ole Pal, come on\n around I'll be in the back practicing my aim"});
dest_dir=({
"/players/heroin/hunting_grounds/limo.c","drive",
"players/heroin/hunting_grounds/yard1.c","crawl",
"players/heroin/hunting_grounds/yard2.c","climb"});
long_desc=
"After all the crap ypu pulled in the limo, its not surprising the\n"+
"driver has stopped the car. However, at least you could have been\n"+
"dropped off in a worse place.  You are standing at the front gates\n"+
"of a a vast estate, stretching for as far as your eyes can see.\n"+
"You can see a house way off in the distance, but the estate grounds\n"+
"themselves appear to be more interesting.  Your thoughts turn to\n"+
"the movie Robin Hood, for the grounds look like the movie set. Now\n"+
"that the driver has drove off, you might as well go in and look\n"+
"around. After all, the street looks busy enough you could always\n"+
"hitchhike back to the arena if you dont like it.\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You find a note to Rush\n");
say(tp + "says: Rush??\n");
return 1;
}
listen(){
write("Ding Dong  Ding Dong\n");
say(tp + "rings the doorbell..surprise attack I presume.\n");
return 1;
}
