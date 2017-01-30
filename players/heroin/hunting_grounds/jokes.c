inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(1);
}
if (!present("Joker")) move_object(clone_object("/players/heroin/hunting_grounds/joker.c"), this_object());
short_desc="A Round Padded Room";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/sewerent.c","north",
"players/heroin/hunting_grounds/hallway.c","whine"});
long_desc=
"You followed the laughter to a small ladder leading up into the\n"+
"floor above.  Climbing up the ladder, you have found yourself in\n"+
"a large, round, padded room.  The only contents in the room are a\n"+
"large drain in the middle of the room and a strang looking man with\n"+
" a grin that goes ear to ear.  The man is laughing hysterically and\n"+
"staring right at you.  You find the whole scenerio quite disturbing.\n"+
"The man is wearing a stright-jacket, however, it doesn't seem to \n"+
"impair him much. Especially since he just hit you.  As you take a cl\n"+
"closer look at the jacket, you notice it has printed on it: Property\n"+
"of Arkum Asylum.  You shake your head in disbelief; you have just \n"+
"found the joker!!\n";
}
init(){
::init();
add_action("listen","listen");
add_action("turn","turn");
add_action("kill","kill");
add_action("search","search");
}
kill(str){
object test;
test =(present("counter",this_player()));
if (test) { test->inc_count();}
}
search(str){
string a, b;
if(!str) { 
write("You find a note from Batman: Will you be my friend?\n");
say(tp + "makes a paper airplane\n");
return 1;
}
write ("You search the "+str+"\n");
if(sscanf(str,"%sfloor%s",a,b) ==2 ) { 
write ("There is shiny handle under the water.  Turn it.\n"); 
return 1;}
else {
write("Be more specific.\n");
return 1;
}}    
turn() {
object badge;
if(present("badge",this_player())) {
write ("*Click*, the hatch swings open and you fall into the\n"+
"darkness. \n");
move_object(this_player(),"/players/heroin/quests/room/khan2.c");
command("look",this_player());
return 1;}
else{ 
write("You do NOT work for Heroin. \n");     
return 1; }} 
listen(){
write("HA HA HA HA HA HA HA HA HA HA HA HA  HA HA HA HA HA...\n");
say(tp + "yells: shut the F**K up!\n");
return 1;
}
