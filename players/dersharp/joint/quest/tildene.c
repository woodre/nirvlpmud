inherit "room/room";
#include "ex.h"
int i;
reset(arg) {
   if(!present("bouncer")) {
      move_object(clone_object("players/dersharp/joint/mons/bounce"),tb);
   }
   if(!arg) {
   set_light(1);
   short_desc="Tilden Street";
   long_desc ="  The music becomes very loud as you enter\n"+
              "this part of Tilden Street.  To the north you\n"+
              "see a large warehouse structure with a large\n"+
              "sign hanging from it.  A large man is standing\n"+
              "at the entrance to the club, checking people for\n"+
              "passes to get in.  To the south is a small library.\n"+
              "To the west you see a QuickTrip, while the street\n"+
              "fades from view to the east.\n"; 
   dest_dir=
	({
		Quest+"nwelch","west",
		Club+"entrance","club",
                Quest+"library","south",
	});
   items=
	({
        "sign","--------------------------------------------------------\n"+
              "|[[[]]] []]]   []]]]   []    []     [[]]   []]]    [][] |\n"+
              "|  []   []  ]  []      []]  [[]    []  []  []  ]  []    |\n"+
              "|  []   []]]   []]]   []  ][  []  []    [] []]]     []  |\n"+
              "|  []   []  ]  []     []      []   []  []  []  ]      []|\n"+
              "|  []   []   ] []]]] []        []   [[]]   []   ]  [][] |\n"+
              "-----------------DANCE CLUB!!  Fee: 20 gp----------------",
	});
   }
}
init() {
   ::init();
   add_action("Pay","pay");
   add_action("Club","club");
}
Pay(arg) {
   if(arg=="fee" || arg=="vince"  || arg=="bouncer") {
      if(tp->query_money()<20) {
         write("You do not have enough money to get in!\n");
         return 1;
      }
      write("You pay the fee and enter the most chillin' spot\n"+
            "in da galaxy!\n");
      say(Tpn+" enters TrEmOrS dance club!\n");
      tp->add_money(-20);
      return 1;
   }
   write("Pay what?!?!\n");
   return 1;
}
