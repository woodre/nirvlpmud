/*
 *      File:                   gamestore.c
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
   set_short("Gamestore");
   set_long(
"     You are in the doorway of the town gamestore. There is a standup\n"+
"video game console in the corner that emits a humming sound and a\n"+
"bluish glow that fades in and out. You are in awe at all of the\n"+
"shelves filled with items of your desire. There is a counter in the\n"+
"opposite corner of the console. The attendant is not around right now\n"
           );
   set_light(1);
   add_item("game","It looks like a possible exit into another realm!");
   add_item("console","You should try looking at the game itself,\n"+
                      "and not the console itself");
   add_item("glow","The bluish color seems to fade in and out, almost\n"+
                   "like a pattern, not at random intervals");
   add_item("shelves","Shelves line the walls with various computer and video\n"+
                      "game boxes. You drool at the amount of silicon entertainment\n"+
                      "around you.");
   add_item("items","You see on the shelf Boxes of games like: QuakeI,II,III, and other\n"+
                   "games such as Descent, Joust, Pac-man and Centipede");
   add_item("counter","A deserted counter. There is nothing on it. You wonder what\n"+
                      "It is used for... Perhaps the attendant can help you");
   add_item("attendant","The attendant is not here right now. You will have to come\n"+
                        "back some other time if you need his help");
   add_listen("humming","You hear a humming sound, similar to the sound that\n"+
                     "high voltage transformers make");
   add_smell("main","You smell warm plastic");
   add_exit("/players/gemini/myarea/room/mpcroom","game");
   add_exit("/players/gemini/myarea/room/main2","southeast");
}
