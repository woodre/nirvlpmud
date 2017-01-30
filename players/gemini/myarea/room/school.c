/*
 *      File:                   school.c
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
   set_short("Ridgemont High School");
   set_long(
"     You have entered a City High School. The hallway has a shiny\n"+
"gloss to them like they were just waxed. You see an open door to the\n"+
"east that leads into a classroom. All the other doors along the\n"+
"hallway look to be locked up tight. There writing on the walls in an\n"+
"odd font that looks familiar.\n"
           );
   set_light(1);
   add_item("hallway","You look down at the hallway and see a reflection");
   add_item("reflection","You see a reflection of yourself");
   add_item("floor","It looks like the Janitor just waxed it recently");
   add_item("doors","These lead into classrooms when clases are in session");
   add_item("door","It leads into a classroom. It is wide open");
   add_item("walls","Someone had some fun spray painting all over them");
   add_item("writing","You see the words 'Ridgemont Sucks!' on the wall\n"+
                      "written in spray paint");
   add_item("spray paint","It is red and was put on overly thick and has runs");
   add_smell("main","You smell spray paint");
   add_exit("/players/gemini/myarea/room/highschool","east");
   add_exit("/players/gemini/myarea/room/main","out");
}
