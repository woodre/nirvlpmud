#include "/players/jaryn/closed/define.h"
#define ROOT "/players/jaryn/areas/maztica/"
#define BLISK BOLD+BLK+"Bo"+HIY+"ali"+BLK+"sk"+NORM
#define OBJ_PATH "/players/jaryn/areas/maztica/OBJ/"

inherit "/obj/treasure";

id(str) { return (::id(str) || str == "eye" || str == "eyeball" 
                            || str == "baslisk eye" || str == "baslisk eyeball"
                            || str == "glowing baslisk eye"); }


     reset(arg) {
       if(arg) return;
   
     set_short(
        "A "+HIY+"glowing "+BLK+"Bo"+HIY+"ali"+BLK+"sk"+NORM+" eye");
     set_long(
       "  This is an eye from the mighty boalisk. It seems to have retained\n"+
       "some magical properties as it has a faint glow to the eye. Many will\n"+
       "give anything to possess such a treasure and will most likely 'trade'\n"+ 
       "well for it. To harness the magical essence of the boalisk, one must\n"+
       "only 'flash' the eye at something.\n");
     set_weight(3);
     set_value(2000+random(1001)); /* Average 2500 */
}

     init() {
       ::init();
         add_action("coin_me","trade");
         add_action("coin_me","barter");
         add_action("rot_me","flash");
}

     coin_me(string str) {      
       int coins;
         object skin;
           string merchant, what;
             switch(random(6)) {
               case 0: merchant = "Madam Rue"; break;
               case 1: merchant = "Sedjak"; break;
               case 2: merchant = "Gurther"; break;
               case 3: merchant = "Anya"; break;
               case 4: merchant = "Mortifus"; break;
               case 5: merchant = "Hank the Trader"; break;
       return 1 ;
  }
  
     switch(random(6)) {
       case 0: what = "haggles"; break;
       case 1: what = "bargains"; break;
       case 2: what = "quibbles"; break;
       case 3: what = "barters"; break;
       case 4: what = "wrangles"; break;
       case 5: what = "negotiates"; break;
     return 1 ;
  }
   
     skin = present("skin",environment(TO));
       coins = skin->query_value();
         if(!str) { notify_fail("Trade what?\n"); return 1; }
         if(id(str)) {
           if(!present("sedjak",environment(TP)) && 
              !present("gurther",environment(TP)) &&
              !present("rue",environment(TP)) &&
              !present("anya",environment(TP)) &&
              !present("hank_the_ugly_barter_dude",environment(TP)) &&
              !present("mortifus",environment(TP))) {
                write("Someone like "+HIW+merchant+NORM+" would be interested\n"+
                      "in the "+GRN+"emerald tree boa"+NORM+" skin.\n");
     return 1; 
    }
     if(present("sedjak",environment(TP))) {
       write("Sedjak "+what+" with you, eventually giving\n"+
             "you "+YEL+coins+NORM+" coins for the "+GRN+"emerald tree boa"+NORM+" skin.\n"); 
    }
     if(present("gurther",environment(TP))) {
       write("The gurther "+what+" with you, finally giving\n"+
             "you "+YEL+coins+NORM+" coins for the "+GRN+"emerald tree boa"+NORM+" skin.\n"); 
    }
     if(present("rue",environment(TP))) {
       write("Madam Rue "+what+" with you, ultimately giving\n"+
             "you "+YEL+coins+NORM+" coins for the "+GRN+"emerald tree boa"+NORM+" skin.\n"); 
    }
     if(present("hank_the_ugly_barter_dude",environment(TP))) {
       write("Hank grumbles about the quality of the items you have brought him\n"+
             "but gives you "+YEL+coins+NORM+" for the "+GRN+"emerald tree boa"+NORM+" skin.\n");
    }
     if(present("anya",environment(TP))) {
       write("Anya argues with you, but in the end gives\n"+
             "you "+YEL+coins+NORM+" coins for the "+GRN+"emerald tree boa"+NORM+" skin.\n");
    }
     if(present("mortifus",environment(TP))) {
       write("Mortifus declines all offers and only gives\n"+
             "you "+YEL+coins+NORM+" for the "+GRN+"emerald tree boa"+NORM+" skin.\n");
    }
     if(present("xipe-topec",environment(TP))) {
       coins = (3000+random(1501));
         write("Xipe-Topec inspects the "+GRN+"emerald tree boa"+NORM+" skin.\n"+
               "He says, \"Ahh, a fine catch indeed! Lucky are you to survive\n"+
               "its thick coils!\"\n"+
               "He hands you "+YEL+coins+NORM+" for the\n"+
               "                  "+GRN+"emerald tree boa"+NORM+" skin.\n");
    }
     this_player()->add_money(coins);
     this_player()->add_weight(-3);
       destruct(skin);
       return 1; 
    }
     notify_fail("Trade what?\n");
       return 0;
    }

 int rot_me(string str) {
      object targ;
      object poison;
        if(!str) targ=(object)TP->query_attack();
        else targ=present(str,environment(TP));
      if(!targ) {
        notify_fail("Flash what?\n");
        return 0;
   }
    if(present("poison",targ)) {
      notify_fail((string)targ->query_name()+" is already cursed with the rot.\n");
        return 0;
   }
    poison=clone_object(OBJ_PATH+"blisk_rot.c");
      poison->set_damage(4+random(4));
        move_object(poison,targ);
          write("You flash the "+BLISK+" eye at "+(string)targ->query_name()+".\n"+
                "       "+(string)targ->query_name()+" falls back dazzed and stunned!\n"+
                "                      "+(string)targ->query_name()+" begins to "+BOLD+BLK+"ROT"+NORM+"!!!\n");
          say(TPN+" flashes the "+BLISK+" eye at "+(string)targ->query_name()+".\n"+
                  "       "+(string)targ->query_name()+" falls back dazzed and stunned!\n"+
                  "                      "+(string)targ->query_name()+" begins to "+BOLD+BLK+"ROT"+NORM+"!!!\n");
                   targ->attacked_by(TP);
      this_player()->add_weight(-1);
      destruct(this_object());
      return 1;
   }
