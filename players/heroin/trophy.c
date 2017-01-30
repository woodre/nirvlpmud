
inherit "room/room";

#define tp this_player()->query_name()
realm() {return "NT";}
reset (arg){
if (!arg){
set_light(5);
}

short_desc="***Trophy Entrance***  ";
dest_dir=({
"/players/heroin/hunting_grounds/hunt1.c", "leave",
"/players/heroin/quests/room/cia1.c", "quest",});
long_desc =
"You appear in room that youve never seen before. \n"+
"As you get your bearings you realize that you are\n"+
"someplace between time and space, the real and the hypereal\n"+
"You feel one with all that is and understand your calling\n"+
"for once in your life...you must help Heroin\n"+
"by completeing the quest!  Go forth ..and good luck.\n";
}
init(){
::init();
add_action("analyze","analyze");
   add_action("read","read");
   add_action("search","search");
}
search(){
write("You find a JOB notice: \n"+
"It reads: WANTED CIA AGENT\n"+
"Interested parties must ASK for the job. EOE\n");
say(tp + "considers their options carefully. \n");
return 1;
}
