inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Inside the ship";
items=({
"lever","A lever of some sort. Looks like it simply opens the door"});
dest_dir=({
"/players/heroin/hunting_grounds/aliens.c","escape",
"players/heroin/hunting_grounds/crewqtrs.c","lever",
"players/heroin/hunting_grounds/robotqtrs.c","lab",
"players/heroin/hunting_grounds/corr2.c","jump"});
long_desc=
"The corridor stretches out ahead of you. You have entered the \n"+
"first section of what appears to be a very large spaceship.\n"+
"Before it didn't look as though the ship was occuppied, however\n"+
"now that you look around you see that someone has spent alot\n"+
"of time and energy trying to close off the ship from something\n"+
" or someone. The walls are filled with smattering of different welds\n"+
"You see a few hatches which seem to have been left alone\n"+
"You start to feel excited as for hunter's instincts go wild.\n"+
"The fear, the hate, the adrenaline all mingle inside this ship\n"+
"to create perhaps the perfect killing fields!\n";
}
init(){
::init();
add_action("listen","listen");
add_action("smell","smell");
add_action("search","search");
}
search(){
write("Becoming a better tracker, you notice at LEAST two trails\n leading away from here. One is a gummy, silicon-like substance covering\n the walls, floors leading staright ahead...Shit..there is a hole directly in\n front of you.  You also notice a trail of white elmer's glueish \n looking substance on the door to the lab.\n");
say(tp + "says: Ahhh, I see\n");
return 1;
}
smell(){
write("You smell fear...You feel like a crazed animal\n");
say(tp + "flales about violently. Suddenly you notice your\n companion   looking at you with a strange hint of violence.\n");
return 1;
}
listen(){
write("SCREECHH...RAKKKKKKK...AKKRKKKZZZSCREECH\n");
say(tp + "'s hair stands on end.\n");
return 1;
}
