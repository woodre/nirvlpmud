/* Casa de Nirvana Theater */

inherit "room/room";
int show;

reset(arg){
   if(arg) return;
   setup();
   show = (random(12)+1); 
	switch(show){
	   case 1: ELVIS();
	   break;
	   case 2: NEWTON();
	   break;
	   case 3: SIEGFRIED();
	   break;
	   case 4: MILLER();
	   break;
	   case 5: CAREY();
	   break;
	   case 6: MANILOW();
	   break;
	   case 7: KNIGHT();
	   break;
           case 8: WILLIAMS();
	   break;
	   case 9: LIBERACE();
	   break;
	   case 10: CARLIN();
	   break;
	   case 11: PENN();
	   break;
	   case 12: CIRQUE();
	   break;
	}
}

query_show(){
   if(!present("entertainer")) return "none";
   if(present("contortionist")) return "cirque";
   if(present("elvis")) return "elvis";
   if(present("newton")) return "newton";
   if(present("siegfried") || present("roy")) return "siegfried";
   if(present("miller")) return "miller";
   if(present("carey") || present("stiles") || present("brady"))return "carey";
   if(present("manilow")) return "manilow";
   if(present("knight")) return "knight";
   if(present("williams")) return "williams";
   if(present("carlin")) return "carlin";
   if(present("liberace")) return "liberace";
   if(present("penn")) return "penn";
   return show;
  }
     
ELVIS(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "The one...the only...the King himself...ELVIS PRESLEY!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/elvis.c"),this_object());
     			
}

NEWTON(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "Mr. Las Vegas himself....WAYNE NEWTON!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/newton.c"),this_object());
     			
}

SIEGFRIED(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "The Amazing....SEIGFRIED and ROY!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/siegfried.c"),this_object());
     move_object(clone_object("/players/aingeal/casino/NPC/roy.c"),this_object());
     			
}

MILLER(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "The irreverent........DENNIS MILLER!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/dmiller.c"),this_object());
     			
}

CAREY(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "DREW CAREY hosting WHOSE LINE IS IT ANYWAY!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/dcarey.c"),this_object());
     			
}

MANILOW(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "Our generation's greatest entertainer...BARRY MANILOW!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/manilow.c"),this_object());
     			
}

KNIGHT(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "The captivating.....GLADYS KNIGHT!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/knight.c"),this_object());
     			
}

WILLIAMS(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "The KING of COMEDY......ROBIN WILLIAMS!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/williams.c"),this_object());
     			
}


LIBERACE(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "Mr. Shomanship, himself...the legendary LIBERACE!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/liberace.c"),this_object());
     			
}

CARLIN(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "The irrepressible........GEORGE CARLIN!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/carlin.c"),this_object());
     			
}

PENN(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "The Bad Boys of Magic......PENN and TELLER!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/penn.c"),this_object());
     move_object(clone_object("/players/aingeal/casino/NPC/teller.c"),this_object());
     			
}

CIRQUE(){
     say("A voice from offstage booms,'AND NOW...\n"+
         "Casa de Nirvana Theater is proud to present...\n"+
         "CIRQUE du SOLEIL performing the captivating....\n"+
	 "Awe-inspiring.....................MYSTERE!\n");
     move_object(clone_object("/players/aingeal/casino/NPC/contortionist.c"),this_object());
     move_object(clone_object("/players/aingeal/casino/NPC/contortionist.c"),this_object());
     move_object(clone_object("/players/aingeal/casino/NPC/contortionist.c"),this_object());
     			
}

setup(){
   set_light(1);
   short_desc="Casa de Nirvana Theater";
   long_desc=
     "A hushed atmosphere and opulent decor welcome patrons to the Grand\n"+
     "Theater of the Casa de Nirvana Hotel and Casino.  The enormous stage\n"+
     "dominates the east end of the cavernous room, its stage lights blinding\n"+
     "in the relatively dim room.  The stage is flanked by heavy floor-length\n"+
     "velvet curtains the lush color of fresh blood.  The dim apex of the\n"+
     "vaulted ceiling supports a staggeringly broad chandelier that reflects\n"+
     "enough diffuse, twinkling light to illuminate the entire room.  Row upon\n"+
     "row of deep, plush red velvet seats line the carpeted hall, each offering\n"+
     "an excellent view of the stage.  A darkened orchestra pit is located just\n"+
     "below the front edge of the stage, and soft background music can be\n"+
     "heard originating there.  The floor-length curtains lining the walls are\n"+
     "interrupted at even intervals by small alcoves containing box seats.  A\n"+
     "large balcony looms overhead, containing still more seating for patrons.\n"+
     "To the south is the nearly-hidden exit to the Lobby.\n";

   items=({
   "stage","The enormous stage is a rich mahogany in color, and is\n"+
           "flanked by floor-length red velvet curtains.  A row of\n"+
	   "hot stage lights line the front of the stage, casting\n"+
	   " almost blinding illumination to every corner of it",
   "lights","Blinding stage lights line the front edge of the stage",
   "stage lights","Blinding stage lights line the front edge of the stage",
   "curtains","Heavy velvet curtains, the rich color of fresh blood, flank\n"+
              "the stage and line the walls of the theater.  The lush \n"+
	      "material absorbs both light and sound, creating a warm,\n"+
	      "cozy ambiance",
   "curtain","The heavy velvet curtain is the rich color of fresh blood.\n"+
              "The lush material absorbs both light and sound, creating \n"+
	      "a warm, cozy ambiance",
   "ceiling","The vaulted ceiling is veiled in shadow.  Suspended from\n"+
             "its apex is an enormous chandelier that scatters dancing,\n"+
	     "twinkling light throught the theater",
   "chandelier","The monsterous chandelier hovers overhead, suspended by\n"+
                "several sturdy chains to the ceiling above.  Thousands\n"+
		"of lighted crystalline teardrops spill warm, diffuse\n"+
		"illumination throughout the theater",
   "seat","The plush red velvet seat has padded arm rests and reclines\n"+
	   "partially to offer patrons the maximum comfort while watching\n"+
	   "the show.  It looks both comfortable and inviting.  You may\n"+
	   "wish to 'sit' in it while you watch the show",
   "seats","The plush red velvet seats lining the theater have padded\n"+
	   " arm rests and recline partially to offer patrons the \n"+
	   "maximum comfort while watching the show.  They look both\n"+
	   " comfortable and inviting.  You may wish to 'sit' in one\n"+
	   "while you watch the show",
   "rows","Row after row of comfortable-looking red velvet seats\n"+
	   "line the audience hall of the theater",
   "row","A long row of comfortable-looking red velvet seats\n"+
	  "arcs across the expanse of the audience hall of the theater",
   "carpet","Plush red carpet lines the vast floor of the theater, muting\n"+
	   "the footsteps of patrons when they walk through the room",
   "floor","Plush red carpet lines the vast floor of the theater, muting\n"+
	   "the footsteps of patrons when they walk through the room",
   "walls","The walls are lined with blood-red floor-length velvet curtains\n"+
	   "that frame the small alcoves for patrons holding box seat tickets",
   "wall","The wall is lined with blood-red floor-length velvet curtains\n"+
	   "that frame the small alcoves for patrons holding box seat tickets",
   "pit","A deep shadow off the edge of the stage marks the line of the\n"+
	   "orchestra pit.  The orchestra is not visible from the theater\n"+
	   "seats, but soft music can be heard emanating from within",
   "orchestra pit","A deep shadow off the edge of the stage marks the line\n"+
	          "of the orchestra pit.  The orchestra is not visible from \n"+
	          "the theater seats, but soft music can be heard emanating\n"+
		  "from within",
   "alcove","The darkened recess in the wall of the theater is reserved\n"+
	   "for patrons holding box seat tickets",
   "alcoves","Darkened recesses in the wall of the theater are reserved\n"+
	   "for patrons holding box seat tickets",
   "box seats","Although the seats themselves cannot be distinguished in the\n"+
	   "dim light, darkened alcoves along the wall of the theater have\n"+
	   "been reserved for patrons holding box seat tickets",
   "balcony","The large balcony looms overhead.  Only the underside of\n"+
	     "balcony is visible from the seats below, its expanse \n"+
	     "resplendent with colorful frescoes similar to those found\n"+
	     "in the lobby of Casa de Nirvana Hotel",
   "frescoes","The underside of the balcony is lavishly decorated with\n"+
	      "decadent plaster artwork in bright colors depicting\n"+
	      "cherubs at play",
   
   });
}

init() {
   add_action("sit_down","sit");
   add_action("south","south");
  }

blee() { return 1; }

sit_down() {
   write("You ease into one of the comfortable, overstuffed seats near\n"+
         "the center of the second row.  Enjoy the show!\n");
   say(this_player()->query_name()+" eases down into one of the comfortable,\n"+
   "overstuffed seats near the center of the second row.\n");
   return 1;

}

south() {
  call_other(this_player(),"move_player","south#players/boltar/casino/hall1e1.c");
  return 1;
}



	
