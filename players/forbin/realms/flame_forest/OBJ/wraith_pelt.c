/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Barterable item on mob
//  Create Date:  2002.04.30
//  Last Edit:    2004.07.28 -Forbin
//  Notable Changes:
//    2004.01.26 - Recoded sizable portion in an effort to make 
//                 bartering easier -Forbin            
//    2004.07.28 -changed prices to follow monster.guide
*/

#include "/players/forbin/define.h"
#define ROOT "/players/forbin/realms/flame_forest/"
inherit "obj/treasure" ;

id(str) { return (::id(str) || str == "pelt" || str == "wraith pelt"); }

reset(arg) {
  if(arg) return;
  set_short("A "+HIR+"wraith "+HIW+"pelt"+NORM); 
  set_long("  A beautiful coat of fur from a thermal wraith.  It is milky white\n"+
           "and covered with bright, red stipes in a fine pattern similar to that\n"+
           "of a tiger.  It is of great value to many people and may be exchanged\n"+
           "with the right person.\n");
  set_weight(2);
/*  set_value(3750+random(1001));
//  changed to monster.guide values -Forbin*/
  set_value(4050 + random(1001));
}

query_save_flag()  { return 1; }

init() {
  ::init();
  add_action("coin_me","exchange");
}

coin_me(string arg) {      
  int coins;
  object pelt;
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
   
  pelt = present("wraith pelt",environment(TO));
  coins = pelt->query_value();
   
  if(arg == "pelt" || arg == "wraith pelt") { 
    if(!present("sedjak",environment(TP)) && 
       !present("gurther",environment(TP)) &&
       !present("rue",environment(TP))) {
      write("Only someone like "+HIW+merchant+NORM+" would be interested in this\n"+
            "wraith pelt.\n");
        return 1; 
    }
  if(present("sedjak",environment(TP))) {
/*  coins += 250+random(251);
//  fixed to better reward players finding the best barter mob -Forbin */
    coins += 550;
    write("Sedjak "+what+" with you, eventually giving you "+YEL+coins+NORM+" coins for the\n"+
          "wraith pelt.\n"+
          "  As he turns to put the pelt away, he looks back and says:\n"+
          "    \"If you were to bring me more pelts, I would pay you well.\"\n"); 
  }
  if(present("gurther",environment(TP))) {
    write("The gurther "+what+" with you, finally giving you "+YEL+coins+NORM+" coins for the\n"+
          "wraith pelt.\n"); 
  }
  if(present("rue",environment(TP))) {
    write("Madam Rue "+what+" with you, ultimately giving you "+YEL+coins+NORM+" coins for the\n"+
          "wraith pelt.\n"); 
  }
  this_player()->add_money(coins);
  this_player()->add_weight(-2);
  destruct(pelt);
    return 1; 
  }
  FAIL("Exchange what?\n"); 
    return 0; 
}