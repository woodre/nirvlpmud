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
"book shelves","You can tell easily that these shelves used to be filled with volumes, however, now they are empty..maybe Angst doesnt want to share everything with you.  Oops, Angst seems to have missed one.  Maybe you could get more info on Angst by looking at it.",
"book","You examine the title of the book, hmm How to serve man by Angst the artist..oops that's sandwich artist..oooh youll never think of the coldcut combo the same"});
dest_dir=({
"room/adv_guild", "advguild",
"room/church", "church",
"room/post_office", "post",
"players/heroin/hunting_grounds/hunt2", "HUNT",
"players/heroin/closed/guild/guild1.c","south",
"players/unsane/closed/hell/circle1.c", "HELL",});
long_desc =
"  You are standing in the entry way of the Merchant's guild.\n"+
"nothing here cause im not done..go away.\n";
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
write("You get the feeling suddenly that you\n stepped in Henry's shit. clean your shoes..thats disgusting\n");
say(tp+" checks their shoes for dogshit.\n");
return 1;
}
listen(){
write("You hear the grinding of machinery starting up..must be lunch time.\n");
say(tp + " perks up their ears.\n");
return 1;
}

