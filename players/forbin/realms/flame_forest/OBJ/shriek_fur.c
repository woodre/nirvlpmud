/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Barterable item on mob
//  Create Date:  2002.01.26
//  Last Edit:    2004.07.28 -Forbin
//  Notable Changes:
//    2004.01.26 - Recoded sizable portion in an effort to make 
//                 bartering easier -Forbin            
//    2004.07.28 -changed prices to follow monster.guide
*/

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "fur" || str == "shriek fur"); }

reset(arg) {
  if(arg) return;
  set_short(HIC+"Shr"+HIW+"iek "+HIC+"fur"+NORM);
  set_long("  A long strip of fur about 4 feet long.  Bright blue, the fur has a\n"+
           "single wide strip of white running down its length.  It is spotted\n"+
           "here and there with dark crusty blood.  On the open market it might\n"+
           "be exchanged with the right person for a sizable sum.\n");           
  set_weight(1);
/*  set_value(2750+random(917));
//  changed to monster.guide values -Forbin*/
  set_value(2800 + random(1001));
}

query_save_flag()  { return 1; }

init() {
  ::init();
  add_action("coin_me","exchange");
}

coin_me(string arg) {      
  int coins;
  object fur;
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
   
  fur = present("shriek fur",environment(TO));
  coins = fur->query_value();
   
  if(arg == "fur" || arg == "shriek fur") { 
    if(!present("sedjak",environment(TP)) && 
       !present("gurther",environment(TP)) &&
       !present("rue",environment(TP))) {
      write("Only someone like "+HIW+merchant+NORM+" would be interested in this\n"+
            "shriek fur.\n");
        return 1; 
    }
  if(present("sedjak",environment(TP))) {
/*  coins += 250+random(251);
//  fixed to better reward players finding the best barter mob -Forbin */
    coins += 400;
    write("Sedjak "+what+" with you, eventually giving you "+YEL+coins+NORM+" coins for the\n"+
          "shriek fur.  After giving it a good looking over, he tells you that he\n"+
          "would pay well for any more specimens in such good shape.\n"); 
  }
  if(present("gurther",environment(TP))) {
    write("The gurther "+what+" with you, finally giving you "+YEL+coins+NORM+" coins for the\n"+
          "shriek fur.\n"); 
  }
  if(present("rue",environment(TP))) {
    write("Madam Rue "+what+" with you, ultimately giving you "+YEL+coins+NORM+" coins for the\n"+
          "shriek fur.\n"); 
  }
  this_player()->add_money(coins);
  this_player()->add_weight(-1);
  destruct(fur);
    return 1; 
  }
  FAIL("Exchange what?\n"); 
    return 0; 
}