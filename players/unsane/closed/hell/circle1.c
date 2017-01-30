string *judge_killas;
inherit "room/room";

#define tp this_player()->query_name()

reset (int arg){
if (!present("sign")) {
move_object(clone_object("/players/unsane/sign"),this_object());
}
if(!present("comic")) {
move_object(clone_object("players/unsane/xmen/comicbook.c"),this_object());
}
if(!present("judge")) {
  move_object(clone_object("/players/unsane/closed/monsters/judge.c"),this_object());
}
if (!arg){
set_light(0);
  short_desc="A Cosmic Gateway";
 long_desc=
"    You have found yourself at gateway, or limbo.  It is very cold here\n"+
"and you hope to be able to escape very soon.  This creature with you does\n"+
"not help to reassure you.  He seems to act as some sort of cosmic judge.\n"+
"There doesn't seem to be any quick way out of this frightening place.  At\n"+
"least none that are easily discerned.  But you know there must be an escape.\n"+
"Perhaps this insect creature can help you?\n"+ 
"If you cannot find the guardian of this realm here, type judge_me.\n";
items=({
  "limbo","A terrible place.  You hope to escape",
  "gateway","A powerful portal",});
dest_dir=({
"room/big_tree","leave",});
} }
init(){
::init();
set_light(0);
call_out("lights",5);
add_action("my_say"); add_xverb("'");
   add_action("my_say","say");
   add_action("ask","ask");
add_action("judge_me","judge_me");
  add_action("listen","listen");
  add_action("smell","smell");
   add_action("search","search");
}
smell(){
write("The air here has no fragrance...it is just emptiness.\n");
say(tp+" breathes in the air here.\n");
return 1;}
listen(){
write("Besides the insect, there are no noises here.\n");
say(tp+" perks up their ears.\n");
return 1; }
judge_me() {
/* lazy asses.

    verte
*/
  if(!judge_killas) judge_killas = ({ });
if(member_array(this_player()->query_real_name(), judge_killas) > -1)
    return (write("Go fight somewhere else.\n"), 1);
if (present("judge")) {
write("He is already here.\n");
return 1;}
write("You summon the judge to this place.\n");
move_object(clone_object("/players/unsane/closed/monsters/judge"), this_object());
return 1;}
lights() {
tell_room(this_object(),"The lights in the room come up suddenly!\n");
set_light(1);
return 1;}
ask() {
if (!present("insect")) {
write("perhaps you don't remember killing him?????\n");
return 1;}
write("The insect says: What are you, a fool?  You shall surely perish there.\n"+
"The insect begins hissing.\n");
say("The insect begins clicking and hissing to "+tp+".\n");
write("Insect says: Yesss....There are five exits from this place at this time\n"+
"\n"+
"Insect says: theesse exitsss are to a sssstrange and wonderousss land.\n"+
"Insect says: jussst sssayss which you would prefer...two, three or four?\n");
write("Insect says: or youss can sssay bar if you wisssh to go theresss.\n");
write("Insect says: you can alssso sssay Hunting grounds if you are foolisssh.\n");
return 1;
}
search() {
say(tp + "searches all about the ground, but in vain.\n");
write("You search, but to no avail.\n");
return 1; }

my_say(str) {
string a,b;
if (!str) {
write("Say What?\n");
return 1; }
write("You say: "+str+"\n");
say(tp+" says: "+str+"\n");
if (sscanf(str, "%stwo%s",a,b) == 2 || sscanf(str, "%s2%s",a,b) == 2) {
if (!present("insect")) {
write("You have destroyed the judge...you can go no further.\n");
return 1;
}
write("The insect screams: GUILTY!!!!!\n");
say("Insect screams at " + tp +".\n");
say(tp + " disappears in a puff of brimstone.\n");
move_object(this_player(), "players/unsane/closed/hell/circle2");
write("You appear to have been transported to a new place.....an evil place.\n");
command("look", this_player());
return 1;}
else {
if (sscanf(str,"%sthree%s",a,b) == 2 || sscanf(str,"%s3%s",a,b) == 2) {
if (!present("insect")) {
write("Sadly, you have killed your mode of transportation.\n");
return 1;}
write("The insect screams: GUILTY!!!!!\n");
say("The insect screams at " + tp +".\n");
say(tp+" disappears in a puff of brimstone.\n");
move_object(this_player(), "players/unsane/closed/hell/circle3.c");
write("You have been teleported to an evil place.\n");
command("look",this_player());
return 1;}
if (sscanf(str, "%shunt%s",a,b) == 2 || sscanf(str, "%sground%s",a,b) == 2){
if (!present("insect")) {
write("Sadly, the insect is dead and can take you nowhere.\n");
return 1;}
write("The insect screams: STUPID!!!\n");
say ("The insect screams at "+tp+".\n");
say(tp+"disappears in a puff of smoke.\n");
move_object(this_player(),"/players/heroin/hunting_grounds/hunt2.c");
write("You are now at the hunting grounds.\n");
command("look",this_player());
return 1;}
if (sscanf(str, "%sbar%s",a,b) == 2) {
if (!present("insect")) {
write("Sadly, the insect is dead and can take you nowhere.\n");
return 1;}
write("The insect screams:  THRISTY!!!\n");
say("The insect screams at  "+tp+".\n");
say(tp+" disappears in a puff of smoke.\n");
move_object(this_player(),"/players/unsane/closed/extra/titti.c");
write("You are at the nudie bar.\n");
command("look",this_player());
say(tp+" has just entered the nudie bar.\n");
return 1;}
if (sscanf(str,"%sfour%s",a,b) == 2 || sscanf(str,"%s4%s",a,b) == 2) {
if (!present("insect")) {
write("Sadly, you have killed your mode of transportation.\n");
return 1;}
write("The insect screams: GUILTY!!!!\n");
say("The insect screams at "+tp+".\n");
say(tp+" disappears in a puff of brimstone.\n");
 move_object(this_player(), "/players/unsane/closed/hell/circle4.c");
write("You have been sent to an evil place.\n");
command("look",this_player());
return 1;}
else {
if (!present("insect")) {
return 1;}
say (tp + " has puzzled the poor insect.\n");
write("The insect looks puzzled.\n");
return 1;
}
}
}

add_judge_killa(x) { judge_killas += ({ x }); }
