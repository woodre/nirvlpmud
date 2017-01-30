object obj;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("demon")) {
move_object(clone_object("/players/unsane/closed/hell/medusa.c"),this_object());
}
short_desc="The Top of the Tower";
 long_desc=
"  This is a featureless black room carved from one huge piece of Onyx.  The\n"+
"walls absorb all light and sound.  That is all the sound besides the screams\n"+
"of the gorgon, Medusa.  This is the lair of Medusa and you have intruded. \n"+
"The room seems to sense that you are an intrusion and you can feel a slight\n"+
"pressure exuding from the walls, trying to force you out.  Now, that your\n"+
"eyes adjust to the lack of light, you notice the floor here is about one\n"+
"half inch of dried blood, now turned to powder.  You have a feeling that\n"+
"if you stick around much longer, you too will be part of the decore.\n";
items=({
 "blood","This is a fine powder of ancient blood covering the floor",
 "walls","The walls are smooth, featureless and black",
 "wall","All the walls look the same",
  "floor","The floor is covered with blood",});
dest_dir=({
"/players/unsane/closed/hell/tower.c","down",});
}
init(){
::init();
   add_action("my_look","look");
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
my_look(str) {
string a,b;
if (str) {
if (sscanf(str, "%smedusa%s",a,b) == 2) {
if (present("medusa")) {
  this_player()->hit_player(50, "other|earth");
write("You look at the Gorgon and make a big mistake!\n\n\n");
  write("Medusa causes bits of you flesh to turn to stone.\n");
}
}
}
}
search(){
write("You search and find nothing.\n");
say(tp+" searches around and finds nothing.\n");
return 1;
}
smell(){
write("It smells like old blood here.\n");
say(tp+ " takes a deep breath fo the air here.\n");
return 1;
}
listen(){
if (!present("demon")) {
write("It is deathly quiet here now that the beast is dead.\n");
}
else write("All you can hear is Medusa screaming.\n");
say(tp + " perks up their ears.\n");
return 1;
}

