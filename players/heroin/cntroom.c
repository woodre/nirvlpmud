object obj;
int i,v;
inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("insect")) {
obj = clone_object("players/unsane/chaos/roach.c");
move_object(obj, this_object());
}
short_desc="The Gateway to Chaos";
 long_desc=
"  You have lost your mind.  You have come to understand that the place you /n"+
"found yourself earlier was, in fact, not hell.  It was a giant illusion\n"+
"held together by a supreme act of will.  That seems to explain why the\n"+
"colours and shapes lost and gained stability.  It must have required a \n"+
"tremendous amount of concentration to keep the illusion constant.  Apparently\n"+
"when you destroyed the gorgon, Medusa.  The strain became too much to bear\n"+
"and the illusion faded.  So that leaves you with a few questions.  Where are\n"+
"you now?  And who was the creator of the illusion?  And who is this cochroach\n"+
"in the room?";
items=({
"void","This room is disquieting",});
dest_dir=({
"/players/unsane/closed/hell/uptower.c","out",
"/players/unsane/chaos/black.c","onward",});
}
init(){
::init();
add_action("kill","kill");
add_action("down","down");
add_action("listen","listen");
add_action("smell","sniff");
   add_action("smell","smell");
   add_action("search","search");
}
kill(str){
object test;
test=(present("counter",this_player()));
if(test){test->inc_count();}
}
down(){
if (this_object() && !this_object()->query_attack()) return 0;
command("out",this_object());
return 1; }
search(){
write("There is nothing here.\n");
say(tp+" searches the ground in vain.\n");
return 1;
}
smell(){
write("There is no scent here whatsoever.\n");
say(tp + " takes a deep breath of the air here.\n");
return 1;
}
listen(){
write("It is deathly silent here.\n");
say(tp + " perks up their ears.\n");
return 1;
}
