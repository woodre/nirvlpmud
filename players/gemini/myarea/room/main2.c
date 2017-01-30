/*
 *      File:                   main2.c
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
   set_short("Main Street North");
   set_long(
"     You are on Main Street. You can hear voices coming from an\n"+
"unknown direction, and there is something familiar about them. There\n"+
"is a video game store up somewhere in the northern direction. The\n"+
"ground looks wet, the air feels humid and has a musty odor. There\n"+
"used to be lightpoles in the ground but they are missing. All that\n"+
"remains are holes in the ground.\n"
           );
   set_light(1);
   add_item("item","item");
   add_item("ground","It is wet due to a recent rain storm.\n"+
                     "These are holes in the ground");
   add_item("light poles","They are no longer here");
   add_item("holes","These are holes in the ground, nothing special here yet");
   add_listen("voices","You think you hear someone singing 'The Rainbow connection'");
   add_smell("air","The air smells very musty and damp. If you had asthma\n"+
                   "you would need your inhaler");
   add_smell("main","You can smell the fresh air");
   add_exit("/players/gemini/myarea/room/muppetland","portal");
   add_exit("/players/gemini/myarea/room/gamestore","northwest");
   add_exit("/players/gemini/myarea/room/main","south");

}
