/*
 *      File:                   muppetland.c
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
   set_short("Muppet land");
   set_long(
"     You are in Muppet Land. Ms. Piggy and Kermit the frog are known\n"+
"to hang out here. You notice all kinds of furniture. There is an\n"+
"empty stage in front of you where the Muppets perform their acts.\n"+
"The curtains on the stage are closed. They must be getting\n"+
"ready for a show! There is an exit to a Scientists lab\n"
           );
   set_light(1);
   add_item("stage","You see that it has not been used in a while.\n"+
            "It is very dusty, and the lighting is very dim");
   add_item("lighting","It is very dim in here. Ms. Piggy must keep the lights low");
   add_item("furniture","You see a few chairs, and a couch.\n"+
            "nothing you would want to sit on with all the dust");
   add_item("chairs","They are extremely dusty");
   add_item("couch","It is very dusty, looks uncomfortable and well used");
   add_item("curtains","The curtains are a deep shade of red and look expensive");
   add_smell("air","You smell years and years of dust and mildew in the theatre");
   add_smell("main","You smell the air");
   add_exit("/players/gemini/myarea/room/main2","back");
   add_exit("/players/gemini/myarea/room/lab","lab");

if(!present("mspiggy")) move_object(clone_object
("/players/gemini/myarea/mon/mspiggy"), this_object());

if(!present("kermit")) move_object(clone_object
("/players/gemini/myarea/mon/kermit"), this_object());

}
