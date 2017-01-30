/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Sir Faris Perham Miniquest
//  Function:     timer object
//  Create Date:  2005.02.25
//  Last Edit:    2005.02.25 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"

int BFist, Timer;

reset(arg) {
  if(arg) return;
  
  if(!restore_object("players/forbin/realms/cave/timerob")) {
    BFist = 1; 
  }
  else if(Timer < time()) {
    BFist = 1;
    save_object("players/forbin/realms/cave/timerob");
  }   
}

id(str) { return (str == "atticus_miniquest_timer"); }

void init() {
  add_action("cmd_squeeze", "squeeze");
  add_action("cmd_wizard_reset", "reset_bfist");
}

int cmd_wizard_reset() {
  if((string)this_player()->query_real_name() != "forbin") return 0;
  tell_object(this_player(),
    "BFist Timer Reset.\nOk.\n");
  BFist = 1;
  Timer = 0;
  save_object("players/forbin/realms/cave/timerob");
  return 1;
}

int cmd_squeeze(string arg) 
{
  if(!arg || arg != "crack") 
  {
    tell_object(this_player(), 
      "Squeeze where?\n");
    return 1;
  }
  tell_object(this_player(), 
    "You turn sideways and carefully squeeze into the narrow crack...\n");
  "/players/forbin/realms/cave/RMS/deep.c"->load_it();
  if(BFist && !present("atticus_miniquest_npc", find_object("/players/forbin/realms/cave/RMS/deep.c")))
    move_object(clone_object(NPC+"atticus.c"), "/players/forbin/realms/cave/RMS/deep.c");  
  this_player()->move_player("into the darkness#players/forbin/realms/cave/RMS/deep.c");
  return 1;  
}

void bfist_gone() 
{
  BFist = 0;
  Timer = time() + 10800 + random(14400);  /* 3 - 7 hours before he reappears */
  save_object("players/forbin/realms/cave/timerob");
}