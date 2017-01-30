/*
 *      File:                   mpcroom.c
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
   set_short("Deep inside the MPC");
   set_long(
"     You are standing deep inside a computer. You hear all kinds of\n"+
"buzzing and clicking. The smell of warm silicon is in the air. A\n"+
"fierce warrior sometimes stands here. He is awaiting his chance to\n"+
"take out the powerful MPC.\n"
           );
   set_light(1);
   add_item("mpc","The MPC is not ready!");
   add_item("warrior","The warrior is known to go by the name of 'Tron'");
   add_item("silicon","Silicon is what most computer parts are made from\n"+
            "You can smell the familar smell of it when it is warm");
   add_item("relay","The relays make sparks as the contacts open and close");
   add_item("relays","The relays make sparks as the contacts open and close");
   add_item("transformer","Transformers change the voltage of a circuit,\n"+
            "they often make a buzzing or humming sound as they do their job");
   add_item("transformers","Transformers change the voltage of a circuit,\n"+
            "they often make a buzzing or a humming sound as they do their job");
   add_smell("silicon","Your nostrils detect some components running at a warmer\n"+
                       "temperature than normal...");
   add_smell("main","You smell silicon in the air");
   add_listen("buzzing","You hear the buzz of transformers and other components");
   add_listen("humming","You hear the humm of transformers");
   add_listen("clicking","You hear relays making clicking sounds");
   add_exit("/players/gemini/myarea/room/gamestore","exit");

   if(!present("tron")) move_object(clone_object
("/players/gemini/myarea/mon/tron.c"), this_object());

}
