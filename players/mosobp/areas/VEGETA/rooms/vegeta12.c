/*
 *  File:   /players/mosobp/areas/TOWER/rooms/t1.c
 *  Function:  room
 *  Author(s):  Mosobp@Nirvana
 *  Copyright: copyright (c) 2008 Mosobp
 *             all rights reserved 
 *                                       
 *                                       
 *  Source:  7/17/08
 *  Notes:  
 *  
 *   
 *  Change History:              
 */

#include "/sys/lib.h"

#include "/obj/ansi.h"

inherit "room/room";
reset(arg){
    ::reset(arg);
	
	
    if(arg) return;
	
set_light(1);
short_desc = RED+"Planet Vegeta"+NORM;
long_desc = 
"  "+HIB+"blah"+NORM+"\n";

 items = ({
"bridge","It looks stable enough, but better hope you don't fall anyways\n"+
"it looks like there is something in the water",
"water","The water is crystal clear, and it looks like there are aligators in the moat",
"moat","Crystal clear water surrounding the castle. It looks like there\n"+
"are alligators in the water",
"alligators","These alligators arent just normal alligators, they are 15 \n"+
"feet long and have huge mouths",
"gate","The gate to the castle",
"castle","The home of King Saichoryo",
});

dest_dir = ({
"/players/mosobp/areas/VEGETA/rooms/vegeta13.c",   "east",
"/players/mosobp/areas/VEGETA/rooms/vegeta11.c",   "west",
"/players/mosobp/areas/VEGETA/rooms/vegeta0.c",    "down",
});
}