/*
 *      File:                   lab.c.c
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
   set_short("A Laboratory");
   set_long(
"    Lab instruments are all over the place. A long stone countertop\n"+
"with a notebook is over to the other side of the room next to the\n"+
"window. Next to you there is a fire extinguisher on the wall. The\n"+
"ceiling looks like it has been burned from experiments gone bad.\n"
           );
   set_light(1);
   add_item("instruments","You see bottles of chemicals, thermometers and lots of other things");
   add_item("bottles","They might have dangerous chemicals in them");
   add_item("chemicals","They look highly corrosive");
   add_item("thermometers","They are around 2 feet long and filled with Mercury");
   add_item("things","You look at things you do not know the name of");
   add_item("countertop","The stone countertop is around 10 feet long, and 4 feet wide.\n"+
                         "There is a notebook on top of it");
   add_item("notebook","A scientists notebook, it might be able to be read");
   add_item("extinguisher","It is red, and puts out the fires that the scientists start");
   add_item("ceiling","It is a typical ceiling with recessed lights, but some burn marks");
   add_item("lights","You see standard flourescent lights");
   add_item("burn marks","These were caused by a bad experiment or two by the Scientist and Beaker");
   add_smell("main","You smell burnt cinders, and a sulfur smell");
   add_exit("/players/gemini/myarea/room/muppetland","leave");
  

   if(!present("beaker")) move_object(clone_object
("/players/gemini/myarea/mon/beaker"), this_object());

   if(!present("scientist")) move_object(clone_object
("/players/gemini/myarea/mon/scientist"), this_object());

}

init() {
       ::init();
       add_action("read","read");
       }
read(str){
       if (!str) {
       write("Read what?\n");
       return 1;
     }
       if (str == "book" || str == "notebook") {
       write("By reading the notebook, you know that mixing vinegar and baking soda\n");
       write("is pretty darn cool\n");
       say(this_player()->query_name()+" read the notebook, and looks smarter.\n");
       return 1;
     }
}
