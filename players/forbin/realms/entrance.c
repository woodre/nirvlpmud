/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Function:     Entrance to my area(s)
//  Create Date:  2004.06.04
//  Last Edit:    2004.06.10 -Forbin
//  Notable Changes:
*/

inherit "/players/forbin/closed/std/room";
#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
#include "/players/forbin/closed/pc.h"

reset(arg) {
  if(arg) return;
  short_desc = "A dimly lit forest";
  long_desc = 
    "  The forest thins here as the trees open up and reveal of glimpse of\n"+
    "the sky above.  A large area has been cleaned of any growth, and seems\n"+
    "to have been smoothed out and tamped down to create a firm surface.  A\n"+
    "small, run-down shack is almost hidden by the trees to the north.  In\n"+
    "the center of the clearing a large stone circle has been inscribed\n"+
    "with runes and symbols.  Eight crystals float strangely above it.\n";
  set_light(1);
  add_item(({"forest","tree","trees",}),
    "The trees thin out into a clearing, but continue to grow thickly\n"+
    "everywhere else");
  add_item(({"shack","run-down shack",}),
    "Beginning to fall apart, the small shack has two open air windows and\n"+
    "several holes in its roof.  The door is open");    
  add_item("sky",
    "A beautiful blue sky paints a serene setting"); 
  add_item(({"area","clearing","ground","surface"}),
    "The ground has been cleared and leveled - probably to make room for\n"+
    "the large circle in the middle of the area");
  add_item(({"circle","stone circle",}),
    "The stone circle creates an enclosure almost 10 feet in diameter");
  add_item(({"rune","runes","symbol","symbols"}),
    "Though very strange looking, you believe you could read them");
  add_exit("room/south/sforst4","west");
  add_object("/players/forbin/realms/chalkboard.c");
  add_object("/players/forbin/realms/crystals.c");
}

short() {
  if(this_player()) 
    return "A dimly lit forest" + (this_player()->query_level() > 20 ? " (Forbin's Castle)" : "");
  else return "A dimly lit forest";
 }

init() {
  ::init();
  add_action("cmd_enter","enter");
}

/* 
//  ***********************************************************************
//  Function:    search 
//  Description: player can find hidden staircase
//  Arguments:   string str, where str is item player wishes to search
//  ***********************************************************************
*/

cmd_enter(string str) {
  string who;
  if(!str || (str != "shack" && str != "run-down shack" && str != "run down shack")) { 
      return 0; 
  }
  who = this_player()->query_name();
  write("You enter the run-down shack.\n");
  say(this_player()->query_name()+" enters the shack.\n");
  move_object(this_player(),"players/forbin/realms/shack.c");
#ifdef ENTERLOG
  log_this(ENTERLOG, "entered the shack.");
  if(find_player("forbin") && !query_pc(this_player()->query_real_name())) {
    tell_object(find_player("forbin"), 
      HIG+capitalize(who)+" just entered your castle.\n"+NORM);
  }
#endif  
  command("look",this_player());
  say(this_player()->query_name()+" enters the shack.\n");
    return 1; 
}
