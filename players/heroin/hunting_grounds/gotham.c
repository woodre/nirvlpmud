inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Gotham City";
items=({
"batteries","On the ground in front of you is an empty package of \n energizer batteries.  As you examine the package, you notice a receipt\n stabled to the back.  Thes batteries were only purchased an hour ago.\n You think to yourself: Hmmm..could this be a clue? You notice another package \n laying in the gutter to the east.",
"marks", "Man, someone left here in a hurry..there are marks from\n tires pealing out heading to the south.  You wonder: Hmm..what kinda car in Gotham\n could do such a thing..?"});
dest_dir=({
"/players/heroin/hunting_grounds/gordqrtrs.c","east",
"players/heroin/hunting_grounds/batcve.c","south",
"players/heroin/hunting_grounds/hallway.c","leave",});
long_desc =
"You find yourself in a thick smoke..it is hard to see but you can hear\n"+
"voices near by.  As you concentrate, you recognize at least one of the\n"+
"voices as Angst's.  From the sounds of it, Angst is pissed and\n"+
"if fighting with two men.  No NO NO Angst I swear I did not destroy the\n"+
"Predator...The writers only made it appear that way..but really, \n"+
"I am innocent....Please Angst, take me out of the hunt\n"+
"Another voice pipes up: No Batman, technically you were successful\n"+
"in you skirmish with the Predator..Remember, DC wouldnt have it any\n"+
"other way.  NO I remember drawing ya in..ya definitely won..\n"+
"Angst's voice comes in: I dont care ...As far as i am concerned as\n"+
"a hero..your days are numbered..For all these years, I have held my\n"+
"tounge, while your pansy-ass beats the shit out of the universe's \n"+
"toughest creatures...well now here your chance to see how tough\n"+
"you are.......go ahead and hide Batman...my hunters will find you.\n"+
"As for you, the one responsible for drawing Batman...well you just\n"+
"go away and die...! \n"+
"You hear the third man scream as he meets his demise..and ya also hear\n"+
"tires squeal..and you see Angst approach you. As he sees ya he smiles\n"+
"and says: Get Batman..He's hidden well..but he's sloppy and left clues\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You notice what looks like batteries..take a closer look\n");
say(tp+" says my God don`t you see it.\n");
return 1;
}
smell(){
write("There is a thick burned-rubber smell to the night air\n");
say(tp+" waves there hand in front of their face.\n");
return 1;
}
listen(){
write("Faintly, way off in the distance, you hear the cackle of a troubled soul\n");
say(tp +"tells you: any idea what that is\n");
return 1;
}

