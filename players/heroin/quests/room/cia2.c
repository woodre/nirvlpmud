
inherit "room/room";

#define tp this_player()->query_name()
realm() {return "NT";}
reset (arg){
if (!arg){
set_light(5);
}

short_desc="A Lab  ";
dest_dir=({
"/players/heroin/quests/room/cia1.c", "east",});
long_desc =
"You are in very large lab with tons of various devices used\n"+
"in for the analysis of evidence...Everybody must be at lunch right now.\n";
}
init(){
::init();
add_action("analyze","analyze");
   add_action("read","read");
   add_action("search","search");
}
search(){
write("You find a lab manual.\n");
say(tp + " considers their options carefully. \n");
return 1;
}
read(str) {                    
if (str == "manual") { 
write("This lab is primarily used in analyzing organic materials.\n");
return 1; }
else {
write ("Everyone knows you can't read.\n"); 
return 1;}
}
analyze(str) {
object tongue;
if(str == "tongue"){
if(present("tongue",this_player())) { 
write("Analysis:::: Nonhuman Organic Material:::::\n"+
"Organic material appears to be almost perfect, superior to human DNA\n"+
":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"+
"Good Job...But Khan you figure out the next clues?\n");
return 1; }
}
else {
write("You don't have the correct evidence.\n");
return 1;
}
}
