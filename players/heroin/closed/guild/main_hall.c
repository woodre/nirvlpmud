inherit "room/room";
 
#define tp this_player()->query_name()
 
reset (arg){
if (!arg){
set_light(1);
}
short_desc="The Merchant Guild ";
items=({
"london","This appears to be a picture of LONDON..is the picture you see a sceneof what appears to be a panic-stricken woman running..wait a sec. is the shadow in the painting actually moving closer to her?",
"gotham","Angst must appreciate his comics, because your staring at the famous Gotham city. Yeah the very one where Batman reigns as supreme vigilante",
"book","You examine the title of the book, hmm How to serve man by Angst the artist..oops that's sandwich artist..oooh youll never think of the coldcut combo the same"});
dest_dir=({
"room/adv_guild", "advguild",
"room/church", "church",
"room/post_office", "post",
"players/heroin/hunting_grounds/hunt2", "HUNT",
"players/heroin/closed/guild/merch1.c","exit",
"players/heroin/closed/guild/biochamber.c","in",
"players/heroin/closed/guild/discuss.c","south",
"room/church","church",
"room/adv_guild","advguild",
"room/post","post",
"players/unsane/closed/hell/circle1.c", "HELL",});
long_desc =
"  You are standing in the main hallway of the Merchant's guild.\n"+
"From here you have access to all of the Merchant's main rooms and \n"+
"teleports.  If you wish to advance your guild influence, go to the\n"+
"Bio-Bar, or to the guild shop then type <in>.\n"+
"If you wish to go the Merchant discussion rooms go south.\n"+
"Finally if you wish to join Heroin's hunt or go to Unsane's hell,\n"+
"then type the appropriate teleports.\n";
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
write("You smell money, power, and greed.\n");
say(tp+" clenches their fist.\n");
return 1;
}
listen(){
write("You hear the grinding of machinery starting up..must be lunch time.\n");
say(tp + " perks up their ears.\n");
return 1;
}
                
