/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Barterable item on mob
//  Create Date:  2002.01.27
//  Last Edit:    2004.07.28 -Forbin
//  Notable Changes:
//    2004.01.26 - Recoded sizable portion in an effort to make 
//                 bartering easier -Forbin            
//    2004.07.28 -changed prices to follow monster.guide
*/

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "wing" || str == "drake wing"); }

reset(arg) {
  if(arg) return;
  set_short(RED+"A drake wing"+NORM);
  set_long("  A wide leathery wing from a drake.  A bone protrudes from the meat\n"+
           "of it, and looks twisted and gnarled - as it if just broke off.  The\n"+
           "wing has a ruddy red-brown color with three bony appendages that run\n"+ 
           "across its width.  Many people will exchange it for coins.\n");           
  set_weight(1);
  set_value(500+random(251));
/*  set_value(500+random(251));
//  changed to monster.guide values -Forbin*/
  set_value(600 + random(501));  
}

query_save_flag()  { return 1; }

init() {
  ::init();
  add_action("coin_me","exchange");
}

coin_me(string arg) {      
  int coins;
  object wing;
  string merchant, what;
  switch(random(3)) {
    case 0: merchant = "Madam Rue"; break;
    case 1: merchant = "Sedjak"; break;
    case 2: merchant = "the old Gurther"; break;
      return 1; 
  }
  switch(random(6)) {
    case 0: what = "haggles"; break;
    case 1: what = "bargains"; break;
    case 2: what = "quibbles"; break;
    case 3: what = "barters"; break;
    case 4: what = "wrangles"; break;
    case 5: what = "negotiates"; break;
      return 1;
  }
   
  wing = present("drake wing",environment(TO));
  coins = wing->query_value();
   
  if(arg == "wing" || arg == "drake wing") { 
    if(!present("sedjak",environment(TP)) && 
       !present("gurther",environment(TP)) &&
       !present("rue",environment(TP))) {
      write("Only someone like "+HIW+merchant+NORM+" would be interested in this\n"+
            "drake wing.\n");
        return 1; 
    }
  if(present("sedjak",environment(TP))) {
    write("Sedjak "+what+" with you, eventually giving you "+YEL+coins+NORM+" coins for the\n"+
          "drake wing.\n"); 
  }
  if(present("gurther",environment(TP))) {
    write("The gurther "+what+" with you, finally giving you "+YEL+coins+NORM+" coins for the\n"+
          "drake wing.\n"); 
  }
  if(present("rue",environment(TP))) {
/*  coins += 100+random(151);
//  fixed to better reward players finding the best barter mob -Forbin */
    coins += 300;        
    write("Madam Rue "+what+" with you, ultimately giving you "+YEL+coins+NORM+" coins for the\n"+
          "drake wing, but not before telling you to always come back with more.\n"); 
  }
  this_player()->add_money(coins);
  this_player()->add_weight(-1);
  destruct(wing);
    return 1; 
  }
  FAIL("Exchange what?\n"); 
    return 0; 
}