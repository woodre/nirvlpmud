/*
 *      File:                   fakers.c
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
   set_short("Faker Ville");
   set_long(
"     All throughout history there have been people who pretend to be\n"+
"people they are not. People who 'fake the funk' to pretend to be cool\n"+
"when they are not. You feel something is wrong but cannot explain it\n"+
"to yourself. There smoke hovering around your head.\n"
           );
   set_light(1);
   add_item("something","HAHA! You thought you were gonna see\n"+
                        "something didn't you?");
   add_item("smoke","This is normal smoke that comes from people's ass when\n"+
                    "they are fakin' da funk");
   add_smell("smoke","You smell smoke");
   add_exit("/players/gemini/myarea/room/malibu","westsyde");
   add_exit("/players/gemini/myarea/room/la","eastsyde");
   add_exit("/players/gemini/myarea/room/main","getreal");
   add_exit("/players/gemini/myarea/room/tent","fortune");

   if(!present("luis")) move_object(clone_object
("/players/gemini/myarea/mon/luis"), this_object());

if(!present("tank")) move_object(clone_object
("/players/gemini/myarea/mon/tank"), this_object());

}

init() {
       ::init();
       add_action("hit","hit");
       }

hit(str){
       if (!str) {
       write("Who are you looking to share voilence with?\n");
       return 1;
     }
       if (str == "luis" || str == "tank") {
       write("Are you crazy? Those are gang members...\n");
       write("You look around before making another move.\n");
       say(this_player()->query_name()+" is a voilent person.\n");
       return 1;
     }
}