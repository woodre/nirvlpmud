object obj, lucky;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
short_desc="Entrance to a mansion";
 long_desc=
"  You stand here in front of a large and beautiful mansion.  While it does\n"+
"appear to be quite old, It is still very sturdy.  There are no cars here\n"+
"and you can't see any lights on inside.  To your left is a small sign, kind\n"+
"of like those signs that the real estate companies use.  For some reason\n"+
"this mansion seems familiar to you, but you're not sure where you've seen\n"+
"it before just yet.  The massive door to the interior is here, as well as a few\n"+
"windows also.  Perhaps you can go inside?\n";
items=({
  "sky","The sky here is clear and beautiful",
  "windows","All of the shades have been drawn.  No peeking for you",
  "door","This sturdy oak door is closed at the moment.  You could ring the doorbell?  Hmmm..",
  "sign","A large sign declaring the purpose of this mansion",
  "doorbell","Just a button to push",
  "mansion","This mansion is breathtakingly beautiful",});
dest_dir=({
"/players/unsane/xmen/field.c","south",});
}
init(){
::init();
add_action("listen","listen");
  add_action("push","push");
  add_action("ring","ring");
  add_action("read","read");
  add_action("knock","knock");
   add_action("smell","smell");
   add_action("search","search");
}
knock() {
write("You knock on the door and nothing happens.\nTry the bell.\n");
return 1; }
ring(str){
string a,b;
lucky = this_player();
if(sscanf(str,"%sbell%s",a,b) == 2) {
write("You ring the doorbell and it echoes through the mansion.\n");
call_out("bell",2);
}
else write("Ring what?\n");
return 1; }
push(str){
string a,b;
lucky=this_player();
if (sscanf(str,"%sbutton%s",a,b) == 2) {
write("You ring the doorbell and it echoes through the mansion.\n");
call_out("bell",2);
}
else write("Push what?\n");
return 1; }
search(){
write("You notice the doormat looks a bit peculiar....Oh well...\n");
say(tp+" searches the ground.\n");
return 1;
}
bell() {
say("A slot in the door opens and closes quickly.\n");
say("You see the doormat fall open!\n");
say(lucky->query_name()+" has fallen into the dungeon.\n");
move_object(lucky, "/players/unsane/xmen/dungeon");
}
read(str) {
string a,b;
if (sscanf(str,"%ssign%s",a,b) == 2) {
write("WELCOME TO PROFESSOR XAVIER'S SCHOOL FOR GIFTED CHILDREN\n");
}
else write("Read what?\n");
return 1; }
smell(){
write("The air here is smells sweetly of grass and flowers.\n");
say(tp+" takes a deep breath of the fragrant air.\n");
return 1;
}
listen(){
write("You can hear the birds chirping and other sounds of spring.\n");
say(tp + " perks up their ears.\n");
return 1;
}

