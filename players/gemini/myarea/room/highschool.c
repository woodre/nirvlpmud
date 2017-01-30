/*
 *      File:                   highschool.c
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
   set_short("Ridgemont Highschool Classroom");
   set_long(
"     This is Mr. Hand's History Class. There are rows of desks with\n"+
"chairs and even a teacher's desk at the front of the class. There is\n"+
"a blackboard to your right and a globe on the desk. The windows are\n"+
"open and you can see the world outside. You see pictures on the wall\n"+
"of famous people.\n"
           );
   set_light(1);
   add_item("desk","You see those kind of desks that are hard as hell to\n"+
            "get in and out of");
   add_item("desks","You see those kind of desks that are hard as hell to\n"+
            "get in and out of");
   add_item("chairs","You see those kind of chairs that are part of the desk\n"+
            "and hard as hell to get in and out of");
   add_item("chair","You see those kind of chairs that are part of the desk\n"+
            "and hard as hell to get in and out of");
   add_item("teacher's desk","This is Mr. Hand's desk. He does not like people sitting on it");
   add_item("blackboard","This is a standard blackboard with some writing on it");
   add_item("writing","You see 'MR. HAND SUCKS MONKEY POLE!!!!' written on the board");
   add_item("globe","This is a round globe that you can spin");
   add_item("windows","The windows appear to be quite old and frail");
   add_item("pictures","There are pictures of the following people on the wall:\n"+
            "Benjamin Franklin, Thomas Edison, and Theodore Roosevelt");
   add_item("franklin","You see a plump man flying a kite with a key tied to the string");
   add_item("edison","You see Thomas Edison sitting tall and proud of the many inventions he created");
   add_item("roosevelt","You see a man with a mustache standing against a wall wearing glasses");
   add_item("wall","This is a wall with pictures on it");     
   add_smell("main","All you smell is lots of years of dust");
   add_exit("/players/gemini/myarea/room/school","west");

   if(!present("spicoli")) move_object(clone_object
("/players/gemini/myarea/mon/spicoli"), this_object());

 if(!present("hand")) move_object(clone_object
("/players/gemini/myarea/mon/mrhand"), this_object());

}

init() {
       ::init();
       add_action("read","read");
       add_action("spin","spin");
}
read(str){
       if (!str) {
       write("Read what?\n");
       return 1;
     }
       if (str == "board" || str == "blackboard"|| str =="writing") {
       write("The read the blackboard, it says: You see 'MR. HAND SUCKS MONKEY POLE!!!!\n");
       write("You laugh!\n");
       say(this_player()->query_name()+" reads the blackboard and begins to laugh.\n");
       return 1;
     }
}
spin(str){
       if (!str) {
       write("Spin what?\n");
       return 1;
    }
       if (str == "globe") {
       write("You spin the globe and see it spin and you get dizzy.\n");
       say(this_player()->query_name()+" spins the globe then gets dizzy and falls down on their ass!\n");
       return 1;
    }

}
