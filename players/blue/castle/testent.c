inherit "room/room";

reset(arg) {

if (!arg) {
     set_light(1);
     short_desc = "An entrance";
     long_desc =
"   Sunlight filters through the rotting castle door to uncover a dusty\n"+
"entryway.  Ahead of you is a closed metal gate that comes down from the\n"+
"and rests on the ground.  There is something pinned under the spikes at \n"+
"end, but it looks as old as the dust covering it.  A rope hangs from a ho"+
"le\nin the ceiling. If you are powerful enough, you maybe be able to lift \n"+
"the gate and go to the courtyard beyond.\n"+
"    There is also a sign to read.\n";

dest_dir = ({ 
          "room/plane2","out",
     "players/blue/dungeon/entrance","down",
     "players/blue/castle/entry2","up"
   });

        }
}

init() {
   ::init();
     add_action ("lift_gate", "lift");
   add_action("read_sign","read");
     add_action("up","up");
   add_action("down_me","down");
   }

lift_gate(str) {
     if(!str) return 0;
     if(str != "gate") { write("lift what?\n"); return 1;}
     if (this_player()->query_level() < 13) {
     write("You are not strong enough.\n");
     return 1;}
     write("You lift the gate and quickly walk under it.It crashes down"+
        " behind you.\n");
   this_player()->move_player("gate#players/blue/castle/entry1b");
     return 1;
}

up() {
   if(this_player()->query_level() > 7) {
     write("Sorry.  You are too powerful to go up there.\n");
      return 1;
   }
   this_player()->move_player("up#players/blue/castle/entry2");
   return 1;
}

down_me() {
   if(this_player()->query_level() >2) {
     write("You are too powerful...\n");
   return 1;
   }
   this_player()->move_player("down#players/blue/dungeon/entrance");
   return 1;
}

read_sign(str) {
   if(!str) return 0;
   if(str!="sign") return 0;
   write("Welcome to my castle!\n\n\n"+
"You will hopefully find this castle interesting and well stocked. There are"+
"\nareas for new-newbies, kinda newbies, and players with big...swords.\n"+
"I appoligize to those stuck in between...your area will take more time (but"+
"\nhopefully worth the wait!).  But for now....\n"+
"\nNEW-NEWBIES - DOWN - Check out the cellar\n"+
"\nNEWBIES-UP - Take a peek at the uglies upstairs\n"+
"\nHIGH-LEVELS - Lift the gate. You will have to be more creative than n,s"+
",\n              e,w...for starters, try 'lift gate'.\n"+
"\nPlease mail me with any problems, complaints or opinions!\n"+
"\n                                    -Blue\n");
   return 1;
}
