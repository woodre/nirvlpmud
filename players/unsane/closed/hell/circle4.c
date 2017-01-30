inherit "room/room";

#define tp this_player()->query_name()
/* changed id checking from 'demon' to plutus. Some guilds have demons as pets. -miz 2007 jan 13 */
object plutus;

reset (int arg){
if (!arg){
set_light(1);
}
if (!present("plutus")) {
plutus = clone_object("players/unsane/closed/hell/plutus.c");
move_object(plutus, this_object());
}
short_desc="The Boundary of the Fourth Circle";
 long_desc=
"     This is the boundary of the Fourth Circle.  Since you aren't actually\n"+
"in a circle, you are experiancing some strange sensations.  All of\n"+
"matter is in a constant state of flux here.  The colours of the landscapes\n"+
"constantly shift and change without warning.  The sky is clear here however,\n"+
"and you are grateful for that.  You can see the other three circles swirling\n"+
"above you in the chaotic space above your head.  Here you find Plutus,\n"+
"the god of wealth.  He appears to be a raving lunatic determined not to let\n"+
"by him.  He seems to be quite fierce as well.  Perhaps you should turn\n"+
"around and leave him be?\n";
items=({
  "colors","The colors here change wildly",
 "colours","The colours of the landscape change in maddening patterns",
 "circle","These circles just tumble and swirl about through the space above",
"circles","The circles appear to move quite randomly, you wonder why they don't collide",
"sky","The sky is clear as a bell here, but it is maddening to stare at",});
dest_dir=({
"/players/unsane/closed/hell/circle4+.c","down",
"/players/unsane/closed/hell/circle1.c","flee",});
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
add_action("down","down");
add_action("my_say");add_xverb("'");
add_action("my_say","say");
add_action("my_tell","tell");
   add_action("search","search");
}
down(){
if (present("plutus")) {
write("Plutus stops you from proceeding further down.\n");
say(tp+" is stopped by Plutus.\n");
return 1; } }
search(){
write("You search around and find nothing.\n");
say(tp+"searches about and finds nothing.\n");
return 1;
}
my_say(str){
if (present("plutus")) {
write("You say: "+str+"\n");
say(tp+" says: "+str+"\n");
say("Plutus says: Please don't say '"+str+"\n");
write("Plutus says: Please don't say '"+str+"'\n");
write("Plutus runs away.\n");
say("Plutus runs away.\n");
destruct(find_living("plutus"));
return 1;
}
}
my_tell(str){
string a,b;
if (present("plutus")) {
if (sscanf(str,"%splutus%s",a,b) == 2) {
say("Plutus runs away.\n");
write("Plutus becomes very frightened of you and runs off.\n");
destruct(find_living("plutus"));
write("You tell plutus something mean.\n");
}
}
return 1;
}
smell(){
write("This place doesn't really smell like anything.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
listen(){
if (!present("plutus")) {
write("The air is now still.\n");
}
if (present("plutus")) {
write("Apparently Plutus is clucking to himself.\n");
}
say(tp + " perks up their ears.\n");
return 1;
}

