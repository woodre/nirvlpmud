/*
 *      File:                   malibu.c
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
   set_short("Malibu");
   set_long(
"     You are in a very rich area with all kinds of expensive cars.\n"+
"There is only one true gangsta in all of Malibu. If you stick around\n"+
"long enough you might meet him. You feel calm and relaxed and no urge\n"+
"to feel intimidated. You wonder what is so bad about this place.\n"
           );
   set_light(1);
   add_item("cars","You see an Escalade, a BMW, and a Mercedes");
   add_item("escalade","It looks brand new excelt for some dents on the side\n"+
            "from people kicking it");
   add_item("bmw","This BMW looks brand new and is freshly washed and waxed");
   add_item("mercedes","Someone left the keys in it! Maybe you can start it");
   add_smell("main","You smell money... and lots of it");
   add_exit("/players/gemini/myarea/room/fakers","eastsyde");
   
   if(!present("brad")) move_object(clone_object
("/players/gemini/myarea/mon/brad"), this_object());

}

init() {
       ::init();
       add_action("start","start");
      }
start(str){
       if (!str) {
       write("Start what?\n");
       return 1;
     }
       if (str == "mercedes" || str == "car") {
       write("You reach in thru the window to try and start the Mercedes and you set the");
       write("alarm off. It wails loudly for a brief moment, then turns itself off.\n");
       say(this_player()->query_name()+" set off the alarm on the Mercedes!\n");
       say("OOOOHHHHEEEEEEEE  OOOOHHHHEEEEEEEE...\n");
       say("OOOOHHHHEEEEEEEE  OOOOHHHHEEEEEEEE...\n");
       return 1;
     }

}
