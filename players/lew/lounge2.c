 

inherit "room/room";

reset(arg){

   object ob;

   if(!arg) {

     set_light(1);

    short_desc = "McCormick lounge";

     long_desc =

"You have entered McCormic lounge.  You see many students laying\n"+

"pretending to study, when they are really plotting to take over\n"+

"the world and make it a living hell for all.  You better hurry and \n"+
"kill them, or else the world will end up one giant IIT.\n";

 

dest_dir = ( {


     "players/lew/cafeteria", "south",
/* Added by Snow 8/99 since it appears to be missing. Which makes the quest impossible. */
    "players/lew/easthall/firstfloor","east",


} );

}

 

}

