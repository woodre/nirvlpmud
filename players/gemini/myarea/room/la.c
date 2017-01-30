/*
 *      File:                   la.c
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
   set_short("L.A. - Gangbang Land");
   set_long(
"     Yo Yo YO boyeeee! Gang bangers walk around the land like they\n"+
"own it. Fear anyone whoz zaround dis neck o da woods. It'z very scary\n"+
"YO!. You should be strapped to be up in dis mofo... WERD! Don't be\n"+
"hatin, and definitely don't be hatin the G funk...Garbage is all\n"+
"around you at your feet. It has a horrid smell.\n"+
"The music has you covering your ears!\n"
           );
   set_light(1);
   add_item("garbage","Down near your feet you see wrappers of candy bars, and\n"+
            "smashed bottes of malt liquor");
   add_item("bottles","Glass remnants of a malt liquor bottle, they look sharp");
   add_item("garbage","Lots of garbage all strewn aover he ground");
   add_listen("music","You hear rap music... Bad rap music at that");
   add_smell("garbage","It smells terrible!");
   add_smell("main","You smell garbage");
   add_exit("/players/gemini/myarea/room/fakers","westsyde");

   if(!present("ali")) move_object(clone_object
("/players/gemini/myarea/mon/alig"), this_object());

}
