inherit "room/room";

#define tp this_player()->query_name()

reset (arg){
if (!arg){
set_light(0);
}
short_desc="Parking Garage";
items=({
"change", "change"});
dest_dir=({
"/players/heroin/hunting_grounds/gordqrtrs.c","up",
"players/heroin/hunting_grounds/sewerent.c","sewers"});
long_desc=
"The search is over, there in front of you sits the batcar. You\n"+
"aren't quite sure how a car would get through such a small hole but you\n"+
"figure Batman did it with some top-secret bat-function on his \n"+
"bat-utility belt. As you look at the car more carefully, you notice\n"+
"that the car appears to have had some cosmetic body work done to it.\n"+
"Curious about the work, you begin to rip apart the batcar.  Under\n"+
"the original paint is a lime-green hue. And under the batfins, are\n"+
"metal curves of the finest quality.  The batcar is a lime-green \n"+
"Gremlin.  You shake your head- its a shame when people destroy the\n"+
"classics.  Furious about the recent development, you begin to search\n"+
"around in a rage.  You notice you are in a parking garage.  It \n"+
"appears to be the parking garage located under City Hall.  You also\n"+
"notice that it has become quite chilly tonight. The storm must have \n"+
"moved in because you notice that there is puddles of water all over.\n"+
"You also notice that the the gutters are completely full and the sewers are\n"+
"having a hard time taking all the water.  Thats strange, you wonder\n"+
"what could possibly be clogging the sewers?\n";
}
init(){
::init();
add_action("listen","listen");
add_action("search","search");
}
search(){
write("You have a hard enough time just standing in the gutter-let alone\n search for something\n");
say(tp + "plays in the water <splash>\n");
return 1;
}
listen(){
write("You hear a faint: Knock Knock\n");
say (tp + " say: Who's there?\n");
return 1;
}
