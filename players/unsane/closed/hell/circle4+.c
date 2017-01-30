inherit "room/room";

#define tp this_player()->query_name()

reset (int arg){
if (!arg){
set_light(1);
if (!present("demon")) {
move_object(clone_object("/players/unsane/closed/hell/prodigal"),this_object());
move_object(clone_object("/players/unsane/closed/hell/miserly"),this_object());
}
short_desc = "Further Down in Hell";
 long_desc=
" This is the Fourth Circle of Hell.  It has rocky and bleak terrain similar\n"+
"to what you have seen so far.  Somehow you expected hell to be different.  \n"+
"Also, the circles seem to be becoming more and more stable as you progress \n"+
"further down.  Albeit the colours and shapes still waver and flicker in and out\n"+
"of reality, but not nearly as much.  Perhaps that will prove to be \n"+
"important later on?  You are confronted by two groups of shouting mobs here.\n"+
"They are the Prodigal and the Miserly.  Their earthly concerns with\n"+
"material possesions have doomed them to a life of eternal damnation.  It would\n"+
"seem that they are taking out their misfortune on each other.  They are \n"+
"clashing huge rolling weights against each other with their chests.\n"+
"Rather sad really.  You can see a river in the distance to the north.\n";
items=({
"weights","The two angry mobs are rolling these things at one another",
 "terrain","The rocky terrain is very bleak here",
 "colors","The colors seem to be changing less frequently now",
"colours","The colous seem to be changing less frequently now",
 "shapes","The shapes are assuming natural forms now",
"river","The river Styx can be seen in the distance.  It doesn't look pleasant",
"sky","The sky here is jet black",});
dest_dir=({
 "/players/unsane/closed/hell/circle4.c","up",
"/players/unsane/closed/hell/banks.c","north",});
} }
init(){
::init();
add_action("enter","enter");
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(){
write("You find nothing but the fragments of boulders\n");
say(tp+ " searches all about.\n");
return 1;
}
smell(){
write("The air here is filled with the dust of smashed boulders.\n");
say(tp+" sniffs the air here.\n");
return 1;
}
listen(){
if (present("demon")) {
write("The crashing boulders echo through the canyons.\n");
say(tp + " listens to the crashing boulders.\n");
return 1; }
else {
write("It is now very silent here.\n");
say(tp + " perks up their ears.\n");
return 1; }
}

