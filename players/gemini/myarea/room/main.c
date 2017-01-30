/*
 *      File:                   main.c
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
   set_short("Main Street South");
   set_long(
"     Flowers are all around you in flower pots. There is a nice scent\n"+
"in the air from them. You see many directions where to go from here.\n"+
"This is just a plain street where the pavement has been chip sealed.\n"+
"If you were to fall you would scrape many layers of skin off!\n"+
"buildings to your left and right look like they have been closed for\n"+
"a long time. A school can be seen in the distance to the East, and\n"+
"you smell food nearby. A dark hole is in the ground a few feet away\n"+
"and looks very intimidating.\n"
           );
   set_light(1);
   add_item("flowers","Roses, daffodils and posies are all around, they smell wonderful");
   add_item("flower pots","The flower pots contain beautiful flowers");
   add_item("street","A plain street that has been recently chip sealed");
   add_smell("flowers","MMMmmmmmm, delightful");
   add_smell("air","You sniff the air, and catch the smell of the roses and other flowers");
   add_item("pavement","It has been chip sealed. This is the process of putting down hot tar\n"+
                     "followed with a layer of stone chips. It is very rough and can do a lot\n"+
                     "of damage if you were to fall");
   add_item("buildings","They closed down a long time ago, when the vendor's taxes went up\n"+
                        "and they could no longer afford the store front space on this street");
   add_item("school","You squint your eyes and look around. Off to the East you see a school");
   add_smell("food","You raise your nose in the air and turn in a circle, and feel your\n"+
                    "tummy start to rumble when you are pointing West");
   add_item("hole","It could lead to a dangerous place. Make sure you\n"+
                   "are ready for what is on the other side\n"+
                   "It looks like you could 'enter' it");
   add_smell("main","You smell flowers");
   add_exit("/players/gemini/myarea/room/main2","north");
   add_exit("/players/gemini/myarea/room/school","east");
   add_exit("/players/gemini/myarea/room/fakers","fakers");
   add_exit("/players/gemini/myarea/room/yankerburger","west");
   add_exit("/room/alley","south");
}

init() {
     ::init();
     add_action("enter","enter");
       }
enter(str){
       if (!str) {
       write("What do you want to enter?\n");
       return 1;
     }
       if (str == "hole") {
       write("You jump into the hole!\n");
              say(this_player()->query_name()+" jumpes into the hole.\n");
       this_player()->move_player("up#players/gemini/myarea/room/underground");
       return 1;
     }
}
