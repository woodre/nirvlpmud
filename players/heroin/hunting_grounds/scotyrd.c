inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("cop")) move_object(clone_object("players/heroin/hunting_grounds/cop.c"), this_object());
if (!present("cop2")) move_object(clone_object("players/heroin/hunting_grounds/cop2.c"), this_object());
if (!present("cop3")) move_object(clone_object("players/heroin/hunting_grounds/cop3.c"), this_object());
short_desc="Scotland Yard";
items=({
"files","These are police files.  On the front of each is written\n in big red letters CONFIDENTIAL.  The police dont seem to notice you \n looking at the files, so go ahead and READ them.",
"cells","These are ordinary jail cells completely filled\n with street urchens.  You can see that the frustrated police have done\n what you were inclined to do-lock up, beat, even kill the urchens.  However, you dont believe for a second that any of these kids could have\n committed these haneous acts.",
"keys","The keys to the cells.  Hmm maybe someday you might be able\n to unlock the cells and bring reform to the street kids..You goody-two-shoes!"});
dest_dir=({
"/players/heroin/hunting_grounds/hallway.c","leave",
"players/heroin/hunting_grounds/london.c","northwest",});
long_desc =
"The famous Scotland Yard..You must have caught the cops on a\n"+
"bad day.  The whole place is littered with files and debris\n"+
"The cops dont seem to care or notice your presence, what a\n"+
"good opportunity to help yourself to some free info.  As\n"+
"you get a closer look, you notice files (hehehe) laying\n"+
"within reach of your grubby little hands..You wont be able\n"+
"to leave with them..so you better make good use of your time\n"+
"You hear one cop complaining that he hates being disturbed\n"+
"from his routine.  I mean he was sooooo close to being able\n"+
"to do the billy-club dance.  Now, it will be weeks before he'll\n"+
"be able to practice his exercises.  You continue to look around\n"+
"and see jail cells filled with street urchens..The cops really\n"+
"are clueless to what-or who they are dealing with..Wow, there\n"+
"is the keys to the cell just laying there\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("kill","kill");
   add_action("search","search");
  add_action("read","read");
}
kill(str){
object test;
test = (present("counter", this_player()));
if (test) { test->inc_count();}
}
search(){
write("You see some crumbs..cops ate donuts way back then,,wow.\n");
say(tp +"sweeps up some crumbs.  One thing can's stand is a mess.\n");
return 1;
}
smell(){
write("Your not sure what you smell.\n");
say(tp+" looks puzzled..\n");
return 1;
}
listen(){
write("You hear the hustle and bustle of England's finest\n hard at work ..God Save the Queen.\n");
say(tp + "tell you: I wish i were one of England's finest\n");
return 1;
}
read(){
write("The files are reports on the recent murders.\n The police believe the killer to be a male. DUH. Noone has yet to actually see the killer, and all \n of his victims have been found brutally slashed apart\n some might even say ripped apart\n The only other useful info is that a man has been seen lurking\n in the shadows of the alleyway..Also, the instrument of death \n appears to be a razor. You think to yourself..I like razors\n");
say(tp + "appears to be trying to read some papers.\n We all know that he cant read..who's he trin' to impress\n");
return 1;
}

