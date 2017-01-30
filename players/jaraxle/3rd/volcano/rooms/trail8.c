/* 03/14/06 Earwax: Closed this area, needs to be recoded for efficiency */
/*  10/08/06 - Rumplemintz
      Moved inherit above #include statement
      Changed CAVE from int to string and moved definition to top of enter() function
*/

inherit "/players/jaraxle/room2.c";
#include "/players/jaraxle/define.h"
int i;
reset(arg) {
    if(arg) return;
    set_light(1);
    long_desc =
    "\n"+
    ""+GRN+"\t@@@@@@@@@@@\n"+
    "\t@@@@@@@@@@@\n"+
    "\t@@@@"+YEL+"##"+GRN+"@@@@@\n"+
    "\t@@@"+YEL+"#"+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
    ""+YEL+"\t####"+NORM+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
    "\t@@@"+YEL+"#"+NORM+RED+"**"+YEL+"#"+GRN+"@@@@\n"+
    "\t@@@@"+HIB+"X"+NORM+YEL+"#"+GRN+"@@@@@\n"+
    "\t@@@@@@@@@@@\n"+
    "\t@@@@@@@@@@@\n"+
    "\t@@@@@@@@@@@"+NORM+"\n";
    items = ({ 
      "trees","Thick trunks reach high up sprouting with abuntant amounts of foliage\nThe trees bar passage in any direction around the path",
      "volcano","The volcano rises high above.\nThe volcano's girth prohibits viewing anything around it.\nThere is a trail following around the base of the volcano",
      "base","The wide base of the volcano is a dark, burned orange color.\nA smooth trail follows it around to the northwest and east",
      "forest","The forest follows on the left edge of the trail.\nThe trees have grown very close together, prohibiting venture into the forest from here",
      "trail","A smooth sandy trail follows closely around the base of the volcano\nThe trail leads east and northwest",
      "cave","A deep, dark cave you can "+HIW+"enter"+NORM+"",
      "dust","Red specs of dust whisking in the blowing wind",
      "rocks","Small clay-like rocks",
    });
    for(i = 0; i < 0 + random(3); i++)
    {
	MOCO("/players/jaraxle/3rd/volcano/mons/snake.c"),TO);
}

}

short(){ return "Third Earth"; }

init(){
    ::init();

    add_action("enter","enter");
    add_action("north","north");
    add_action("south","south");
    add_action("the_key","key");
    add_action("west","west");
    add_action("east","east");
    add_action("northwest","northwest");
    add_action("search_me","search");
}

east(){
    write("You follow the path to the east.\n");
    TP->move_player("east#/players/jaraxle/3rd/volcano/rooms/trail7.c");
    return 1; }

northwest(){
    write("You follow the path to the northwest.\n");
    TP->move_player("east#/players/jaraxle/3rd/volcano/rooms/trail9.c");
    return 1; }

north(){ write("The volcano blocks you in from the north.\n"); return 1; }
south(){ write("The forest blocks you in from the south.\n"); return 1; }
west(){ write("The forest blocks you in from the west.\n"); return 1; }

enter(arg){ 
    string CAVE;
    if(arg == "cave"){
/*
	write("This area has been closed for maintenance.\nSorry for the inconvenience -Earwax\n");
	return 1;
*/
	switch(random(3)){
	case 1: CAVE = "bravely"; break; case 2: CAVE = "cautiously"; break; case 0: CAVE = "carefully"; break; }
	write("\nYou "+CAVE+" enter the cave.\n");
	TP->move_player("into the volcano#/players/jaraxle/3rd/volcano/rooms/f_cave.c");
	return 1; }
    notify_fail("Enter what?\n");
    return 0;
}


search_me(arg){
    if(!arg){
	write("A flat, worn trail following snuggly to the volcano.  The forest\n"+
	  "follows the trail on the left side to create the look of a tunnel\n"+
	  "without a ceiling.  The volcano on the right still sends off a \n"+
	  "feeling of heat from behind the rock base.  Dust and rocks trickle\n"+
	  "over a cave on the face of the volcano.\n");
	return 1; }
    write("You search "+arg+" and find nothing of intrest.\n");
    return 1; }

the_key(){
    write("\n"+
      BLU+"\tX"+NORM+" = You are here!\n"+
      GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      YEL+"\t#"+NORM+" = Walkable Path\n"+
      RED+"\t*"+NORM+" = Volcano\n"+
      RED+"\t$"+NORM+" = Further Access Denied!\n");
    return 1; }
