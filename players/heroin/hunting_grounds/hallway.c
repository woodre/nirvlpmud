inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Hallway";
items=({
"london","This appears to be a picture of LONDON..is the picture you see a sceneof what appears to be a panic-stricken woman running..wait a sec. is the shadow in the painting actually moving closer to her?",
"gotham","Angst must appreciate his comics, because your staring at the famous Gotham city. Yeah the very one where Batman reigns as supreme vigilante",
"book shelves","You can tell easily that these shelves used to be filled with volumes, however, now they are empty..maybe Angst doesnt want to share everything with you.  Oops, Angst seems to have missed one.  Maybe you could get more info on Angst by looking at it.",
"book","You examine the title of the book, hmm How to serve man by Angst the artist..oops that's sandwich artist..oooh youll never think of the coldcut combo the same"});
dest_dir=({
"/players/heroin/hunting_grounds/london.c","london",
"players/heroin/hunting_grounds/hunt1.c","north",
"players/heroin/hunting_grounds/gotham","gotham",
"players/heroin/hunting_grounds/hallway2.c","south",});
long_desc =
"  You are in a long hallway. All around you are paintings of places\n"+
"you've often heard about.  However two paintings particularily\n"+
"catch your attention.  One of Gotham city and one of London. Might want\n"+
"to further examine them.  Also, you notice a bookshelf with one lone\n"+
"book on it.\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("path","path");
   add_action("search","search");
}
search(){
write("You find a PATH that you could follow.\n");
say(tp + "ponders the situation \n");
return 1;
}
 
path() {
if(present("badge",this_player())) {
write("You follow the path around...and look who's here.\n");
move_object(this_player(), "/players/heroin/quests/room/khan2.c");
command("look",this_player());
return 1;}
else {
write("You can't go there yet.\n");
return 1;}
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

