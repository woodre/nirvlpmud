/*
 *      File:                   underground.c
 *      Function:               
 *      Author(s):              Gemini@Nirvana
 *      Copyright:              Copyright (c) 2004 Gemini
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

inherit "/players/vertebraker/closed/std/room";

reset(arg) {
   if(arg) return;
   set_short("Underground");
   set_long(
"     You are standing knee deep in black sludge. It is dark but\n"+
"enough light shines through the hole above to make out various\n"+
"shapes at your feet. There is a cavelike entrance to the west.\n"+
"If you are alone, this is not a good plce to be. A rope is hanging\n"+
"by your head.\n"
           );
   set_light(1);
   add_item("shapes","You see some cans, old cigarette cartons and some papers");
   add_item("cans","You notice they are Coca-Cola cans");
   add_item("cartons","These look like marlboro cartons");
   add_item("papers","All but one of the papers are not legible");
   add_item("rope","You can climb it to get out");
   add_smell("sludge","It smells terrible and you begin to seel sick");
   add_exit("/players/gemini/myarea/room/underground2","west");
   add_smell("main","You smell nasty rank sewage"); 
 
   if(!present("sludge")) move_object(clone_object
("/players/gemini/myarea/mon/sludge"), this_object());

}

init() {
     ::init();
     add_action("climb","climb");
       }
climb(str){
       if (!str) {
       write("What do you want to climb?\n");
       return 1;
     }
       if (str == "rope") {
       write("You rub your hands together to warm them up.\n");
       write("You climb the rope\n");
       say(this_player()->query_name()+" climbes the rope leaving you behind.\n");
       this_player()->move_player("up#players/gemini/myarea/room/main");
       return 1;
     }
}
