/*
 *      File:                   underground2.c
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
   set_short("The rat room");
   set_long(
"     You have entered the rat room. There are many rodents around,\n"+
"some are mean, some are nice. This area is the home of a very cruel\n"+
"King. Many have tried to overpower him, but the skeletons on the\n"+
"floor are proof no one has succeeded.\n"
           );
   set_light(0);
   add_item("rodents","The rodents scutter around your feet and look hungry");
   add_item("skeletons","You see skeletons of warriors of years past.\n"+
                        "The bones look picked clean of flesh");
   add_item("bones","They have no meat on them");
   add_item("floor","Skeletons cover the floor making it difficult\n"+
                    "for you to walk without tripping over them");
   add_exit("/players/gemini/myarea/room/underground","east");
   add_smell("main","You smell a rat");

   if(!present("goodrat")) move_object(clone_object
("/players/gemini/myarea/mon/goodrat"), this_object());

   if(!present("badrat")) move_object(clone_object
("/players/gemini/myarea/mon/badrat"), this_object());

}
