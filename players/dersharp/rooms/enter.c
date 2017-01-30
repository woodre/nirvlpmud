inherit "room/room";
#define Tpn		capitalize(this_player()->query_real_name())
#define Road		"/players/dersharp/road/"
#define tp		this_player()
reset(arg){
   if(arg) return;
   short_desc="A small clearing";
   long_desc= "	You find yourself in a small clearing in the\n"+
              "forest.  To the north and west you see a huge rock\n"+
              "formation, while to the east you see the forest.\n"+
              "You also see a road to the south leading to a \n"+
              "group of ruins.  You also see a sign in the middle\n"+
              "of the clearing...\n";
   set_light(1);
   dest_dir =
   ({
		"/room/forest12","east",
                Road+"roadw","west",
   });
   items=
   ({
		"sign","	Welcome to my little area.  I have opened\n"+
                "it up a bit so you can go around more.  However it is still\n"+
                "fairly shut up as of now.  I will soon have the Greyhawk area\n"+
                "and my guild up so keep watching this place! \n"+
                "                                     -Dersharp",
   });
}
init() {
   ::init();
   add_action("Track","search");
   add_action("Pillar","south");
   add_action("Readthis","read");
}
Readthis(arg){
   if(arg=="sign"){
      write("	Welcome to my little area.  I have opened\n"+
	    "it up a bit so you can go around more.  However it is still\n"+
	    "fairly shut up as of now.  I will soon have the Greyhawk area\n"+
            "and my guild up so keep watching this place! \n"+
            "                                     -Dersharp\n");
      return 1;
   }
   write("Read what?\n");
   return 1;
}
Track(arg){
   if(!arg){
      write("You find some tracks leading to the west....\n");
      say(Tpn+" searches the room quickly.\n");
      return 1;
   }
   if(arg=="room"){
      write("You find some tracks leading to the west....\n");
      say(Tpn+" searches the room quickly.\n");
      return 1;
   }
   write("You cannot search that!\n");
   return 1;
}
Pillar(){
   if(tp->query_level()>8){
      write("You shall not enter through this portal!\n");
      say(Tpn+" tries to enter the newbie zone but fails miserably.\n");
      return 1;
   }
   write("You manage to get by the newbie-zone protector.\n");
   write("You make your way into the Pillars of Peril.\n");
   say(Tpn+" enters the Pillars of Peril!\n");
   move_object(tp, "/players/dersharp/pillars/enter");
   return 1;
}
