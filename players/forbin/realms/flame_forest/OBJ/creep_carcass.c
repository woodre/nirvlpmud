/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Barterable item on mob
//  Create Date:  2002.03.18
//  Last Edit:    2004.07.28 -Forbin
//  Notable Changes:
//    2004.01.26 - Recoded sizable portion in an effort to make 
//                 bartering easier -Forbin            
//    2004.07.28 -changed prices to follow monster.guide
*/ 

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "carcass" || str == "creep carcass"); }

reset(arg) 
{
  if(arg) return;
  set_short(HIK+"A creep carcass"+NORM);
  set_long("  What is left of a Creep.  Creep carcasses are prized in many locals\n"+
           "and used to make a variety of products.  Especially useful in many\n"+
           "magical and sacramental rituals, it could probably be exchanged for\n"+
           "a good deal of money if the right person is found.\n");
  set_weight(1);
/*  set_value(2750+random(1251));
//  changed to monster.guide values -Forbin*/
  set_value(3300 + random(1001));
}

query_save_flag()  { return 1; }

init() {
  ::init();
  add_action("coin_me","exchange");
}

coin_me(string arg) {      
  int coins;
  object carcass;
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
   
  carcass = present("creep carcass",environment(TO));
  coins = carcass->query_value();
   
  if(arg == "carcass" || arg == "creep carcass") { 
    if(!present("sedjak",environment(TP)) && 
       !present("gurther",environment(TP)) &&
       !present("rue",environment(TP))) {
      write("Only someone like "+HIW+merchant+NORM+" would be interested in this\n"+
            "creep carcass.\n");
        return 1; 
    }
  if(present("sedjak",environment(TP))) {
    write("Sedjak "+what+" with you, eventually giving you "+YEL+coins+NORM+" coins for the\n"+ 
          "creep carcass.\n"); 
  }
  if(present("gurther",environment(TP))) {
    write("The gurther "+what+" with you, finally giving you "+YEL+coins+NORM+" coins for the\n"+
          "creep carcass.\n"); 
  }
  if(present("rue",environment(TP))) {
/*  coins += 250+random(251);
//  fixed to better reward players finding the best barter mob -Forbin */
    coins += 400;
    write("Madam Rue "+what+" with you, ultimately giving you "+YEL+coins+NORM+" coins for the\n"+
          "creep carcass.\n"+
          "  She smiles and says:\n"+
          "    \"Please bring me any more that you find.  They are very helpful in making\n"+
          "     the many potions and salves that I make.\"\n"); 
  }
  this_player()->add_money(coins);
  this_player()->add_weight(-1);
  destruct(carcass);
    return 1; 
  }
  FAIL("Exchange what?\n"); 
    return 0; 
}