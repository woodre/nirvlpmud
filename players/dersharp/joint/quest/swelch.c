inherit "room/room";
#include "ex.h"
reset(arg){
   if(arg) return;
   short_desc="South Welch Avenue";
   long_desc ="  You find yourself on a sidewalk that seems to be\n"+
	      "in the midst of a small city.  There is a signpost here\n"+
	      "that may indicate where you are are at this moment.\n"+
	      "A four-lane road runs what seems to be east to west on\n"+
              "your southern side.  Going north, a two-laner heads into\n"+
              "what you recognize as a campustown.  You see different \n"+
	      "shops and even some fast-food establishments.  However\n"+
	      "it seems from your vantage that most of them are closed.\n"+
	      "At your feet you see a large puddle of brownish water that\n"+
	      "seems to more than what it seems...\n";
   set_light(1);
   dest_dir=
	({
		Quest+"welch","north",
	});
   items=
	({
		"sign"," The sign shows the names of the intersecting\n"+
		       "streets:  (N/S Welch Ave.  E/W Lincoln Way.)",
                "signpost"," The sign shows the names of the intersecting\n"+
		       "streets:  (N/S Welch Ave.  E/W Lincoln Way.)",
		"puddle","  Amazingly, you can see the realm of Nirvana\n"+
			 "within the confines of the muddy pool.  Kind\n"+
			 " of fitting actually, you think...",
	});
}
init() {
   ::init();
   add_action("Pooldive","enter");
   add_action("South","south");
   add_action("Nope","west");
   add_action("Nope","east");
}
Pooldive(arg) {
   if(!arg){
      write("What do you wish to do?\n");
      return 1;
   }
   if(arg=="puddle" || arg=="pool"){
      write("You gingerly touch the puddle with your foot and\n");
      write("find yourself transported to the portal room in Nirvana!\n");
      say(Tpn+" tries to look cool but is sucked into the puddle\n"+
          "making high-pitched screams....embarrassing.\n");
      move_object(tp, Road+"anarch.c");
      return 1;
   }
}
South() {
   write("You try to cross the street to ther side but every\n"+
         "attempt is thwarted as a car comes out of the blue, sending\n"+
         "you running back to Welch Avenue.\n");
   return 1;
}
Nope() {
   write("As you try to head off the avenue people crowd you suddenly,\n"+
         "pounding you back to Welch Avenue.\n");
   return 1;
}
