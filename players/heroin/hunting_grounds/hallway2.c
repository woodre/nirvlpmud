inherit "room/room";

#define tp this_player()->query_name()
int i;
object obj;
inherit "room/room";

reset (int arg) {
if (!arg){
set_light(1);
}
short_desc="Hallway";
items=({
"Space","As you begin to look into the painting you are struck by the coldness of the background.  You are looking down a long dark alien hallway. You feel like the inhabitants must have felt--Desperate and alone",
"concert","Cat scratch fever du du dun...Don't ya wish ya were there?",
"clippings","These are toenail clippings. From close examination- you are sure that the previous owner must have had a healthy, balanced diet..You wonder if the previous owner has become part of someone elses' well-balanced diet? Eat em' up."});
dest_dir=({
"/players/heroin/hunting_grounds/aliens.c","space",
"players/heroin/hunting_grounds/concert.c","concert",
"players/heroin/hunting_grounds/chess.c","south",
"players/heroin/hunting_grounds/hallway.c","north",});
long_desc =
"  You are in a long hallway. All around you are paintings of places\n"+
"you've often heard about.  However two paintings particularily\n"+
"catch your attention. One of the paintings is dark and uninviting\n"+
"while the other inspires you to furiously bang your head.  Upon\n"+
"getting up your nerve, you look closer at the dark painting. It\n"+
"depicts a futuristic look into man's attempt at space travel. SPACE\n"+
"and all its misgivings..You hope you are more succesful then the\n"+
"poor souls trapped in this painting.\n"+
"You think you hear the faint sounds of cheering teens. Now you're\n"+
"positive you heard it.  In an attempt to hear better..You turn\n"+
"around and find yourself facing a picture depicting a concert scene\n"+
"You see millions-maybe trillions-of rock-stricken teens yelling and\n"+
"dancing about.  Man, what a great photo...It makes you feel like you were \n"+
"there..or could be there!\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
object ob;
if(random(100) < 80){ write("You find nothing of interest.\n"); return 1; }
if (i == 0) {
write("You search around carefully and finds some clippings.\n");
say(tp+" quickly starts whistling and checks his finger nails.\n What's that bastard hiding from ya now?\n");
ob = clone_object("/players/heroin/hunting_grounds/clippings");
move_object(ob, this_player());
i++;
return 2;}
write("There is nothing else to find here.\n");
return 1;
}
smell(){
write("There is a dusty, stale odor omitting from the south\n Even though there is bright glow emitting from the room\n you get the distinct feeling that it\n has been a long time since anything has stirred.\n");
say(tp+" starts coughing and weezing..Man the dust is terrible.\n");
return 1;
}
listen(){
write("Catch Stcatch fever da da dun\n Catch Stratch fever da da dun\n");
write("YAHHHHH Hooo cheers claps cheers claps\n");
say(tp + "starts air-guitarin' like a madman\n");
return 1;
}

