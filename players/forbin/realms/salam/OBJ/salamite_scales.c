/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Salamite Caves
//  Function:     Barterable item on mob
//  Create Date:  2002.06.04
//  Last Edit:    2004.07.27 -Forbin
//  Notable Changes:
//    2004.07.28 -changed prices to follow monster.guide
*/ 

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "scales" || str == "salamite scales"); }

reset(arg) 
{
  if(arg) return;
  set_short(HIR+"Sala"+NORM+RED+"mite "+HIR+"scales"+NORM);
  set_long("  A cluster of ruddy red scales from a race of salamander-like humanoids\n"+ 
           "called Salamites.  They are covered in a hard black substance - said to\n"+ 
           "be from molten obsidian that the Salamites smear on their body to form\n"+ 
           "a hardened armor.  Ground into a red powder long ago in a far-off land\n"+ 
           "and used for mystical enchantments and shadow magic, it could probably\n"+  
           "be exchanged for money if the right person is found.\n");
  set_weight(1);
/*  set_value(2875+random(1501)); 
//  changed to monster.guide values -Forbin*/
  set_value(3250 + random(1001));
}

init() {
  ::init();
  add_action("coin_me","exchange");
}

coin_me(string arg) {      
  int coins;
  object scale;
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
   
  scale = present("salamite scales",environment(TO));
  coins = scale->query_value();
   
  if(arg == "scales" || arg == "salamite scales") { 
    if(!present("sedjak",environment(TP)) && 
       !present("gurther",environment(TP)) &&
       !present("rue",environment(TP))) {
      write("Only someone like "+HIW+merchant+NORM+" would be interested in this\n"+
            "salamite scale.\n");
        return 1; 
    }
  if(present("sedjak",environment(TP))) {
    write("Sedjak "+what+" with you, eventually giving you "+YEL+coins+NORM+" coins for the\n"+
          "salamite scale.\n"); 
  }
  if(present("gurther",environment(TP))) {
/*  coins += 250+random(251);
//  fixed to better reward players finding the best barter mob -Forbin */
    coins += 500;
    write("The gurther "+what+" with you, finally giving you "+YEL+coins+NORM+" coins for the\n"+
          "salamite scale.\n"+
          "  The old gurther smiles and says:\n"+
          "    \"Ahh...I can pulverize this and sell it to the shadow guild\n"+
          "     for a handsome sum.  Please bring me any more that you find.\"\n");
  }
  if(present("rue",environment(TP))) {
    write("Madam Rue "+what+" with you, ultimately giving you "+YEL+coins+NORM+" coins for the\n"+
          "salamite scale.\n"); 
  }
  this_player()->add_money(coins);
  this_player()->add_weight(-1);
  destruct(scale);
    return 1; 
  }
  FAIL("Exchange what?\n"); 
    return 0; 
}
