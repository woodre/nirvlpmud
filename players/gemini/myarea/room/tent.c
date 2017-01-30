/*
 *      File:                   tent.c
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
   set_short("A fortune teller's tent");
   set_long(
"     You have entered a bright red colored tent with gold trim.\n"+
"There is a worn path at your feet making you believe that many people\n"+
"have visited this area before you. There is a table in the middle of\n"+
"the tent with a crystal ball in the middle of it.\n"
           );
   set_light(1);
   add_item("path","You can see where the grass has worn away, and you just see dirt");
   add_item("table","It is made of wood and has a red tablecloth covering it.\n"+
                    "There is a crystal ball placed in the middle");
   add_item("ball","It looks very clear, there seems to be some fingerprints on it");
   add_item("fingerprints","They seem to be left from the last patron to visit here");
   add_smell("main","You smell 'bullshit' all around you");
   add_exit("/players/gemini/myarea/room/fakers","leave");

   if(!present("cleo")) move_object(clone_object
("/players/gemini/myarea/mon/mscleo"), this_object());

}
