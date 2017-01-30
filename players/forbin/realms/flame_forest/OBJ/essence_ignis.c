/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Realm:        Flame Forest
//  Function:     Barterable item on mob
//  Create Date:  2002.04.29
//  Last Edit:    2004.07.28 -Forbin
//  Notable Changes:
//    2004.01.26 - Recoded sizable portion in an effort to make 
//                 bartering easier -Forbin            
//    2004.07.28 -changed prices to follow monster.guide
*/

#include "/players/forbin/define.h"
inherit "obj/treasure";

int Heals, Used;

id(str) { return (::id(str) || str == "essence" || str == "glowing essence"); }

reset() {
  set_short(HIW+"A glowing essence"+NORM);
  set_long("  This is all that's left of a once vital Ingis Fatuus, also known as\n"+ 
           "a Will-o'-the-wisp.  The essence pulses slowly with a bright light,\n"+  
           "yet feels oddly cool to the touch.  It's well rumored to have healing\n"+ 
           "value when 'breathe'd upon by a living creature.  Perhaps, if it goes\n"+
           "unused, you could find someone willing to exchange it for coins.\n");
  set_weight(0); /* approved at 0 for a reason */
/*  set_value(1250+random(751));
//  changed to monster.guide values -Forbin*/
  set_value(1550 + random(801));  
  Heals = 2+random(3);
}

query_save_flag()  { return 1; }
init() {
  ::init();
  add_action("coin_me","exchange");
  add_action("spheal","breathe");
}

coin_me(string arg) {      
  int coins;
  object essence;
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
   
  essence = present("glowing essence",environment(TO));
  coins = essence->query_value();
   
  if(arg == "essence" || arg == "glowing essence") { 
    if(!present("sedjak",environment(TP)) && 
       !present("gurther",environment(TP)) &&
       !present("rue",environment(TP))) {
      write("Only someone like "+HIW+merchant+NORM+" would be interested in this\n"+
            "glowing essence.\n");
        return 1; 
    }
  if(Used == 1) {
    write("The "+HIW+"essence"+NORM+" is weak...and no longer valuble.\n");
      return 1;
  }
  if(present("sedjak",environment(TP))) {
    write("Sedjak "+what+" with you, eventually giving you "+YEL+coins+NORM+" coins for the\n"+
          "glowing essence.\n"); 
  }
  if(present("gurther",environment(TP))) {
    write("The gurther "+what+" with you, finally giving you "+YEL+coins+NORM+" coins for the\n"+
          "glowing essence.\n"); 
  }
  if(present("rue",environment(TP))) {
/*  coins += 250+random(251);
//  fixed to better reward players finding the best barter mob -Forbin */
    coins += 300;    
    write("Madam Rue "+what+" with you, ultimately giving you "+YEL+coins+NORM+" coins for the\n"+
          "glowing essence.  She explains to you that she could always use them\n"+
          "to make potions.\n"); 
  }
  this_player()->add_money(coins);
  destruct(essence);
    return 1; 
  }
  FAIL("Exchange what?\n"); 
    return 0; 
}

spheal() {
  Heals --;
  Used = 1;
  TP->add_spell_point(30);
  write("Holding the essence close to your face, you gently begin to\n"+
        "blow upon the essence.  Quickly it becomes hot the the touch\n"+
        "and "+HIW+"GLOWS"+NORM+" brightly for a moment.  You feel rejuvinated.\n");
  say(TPN+ " uses the "+HIW+"essence"+NORM+" to heal.\n");
  if(Heals == 0) {
    write("The "+HIW+"esse"+NORM+"nce fades.\n");
    destruct(TO);
  }
    return 1;
}