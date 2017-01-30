/*
 *  Corpse healing for the Bardic Guild
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


corpse_healing()  {

object CORPSE, HEADSTONE;
int HEAL, HEALTH, MANA;

  HEAL = 0;
  
  CORPSE = present("corpse", ENV);
  
  if(!CORPSE)  {
    CORPSE = present("corpse", environment(TP));  }
      if(!CORPSE)  {
        write("There is no corpse here.\n");
        return 1;  }

  if(BTYPE == "pyre")  {
   if(COLOR)  {
    write("\nChanting a melancholy requiem, you call a "+HIY+BOLD+
          "lightning bolt"+NORM+" from the sky.\n"+
          "The "+HIY+"bolt"+NORM+" strikes the corpse, "+HIR+
          "incinerating"+NORM+" it in a makeshift "+HIR+"funeral pyre"+NORM+".\n");
    say("\n"+tp+" chants a melancholy requiem.\n"+
        "A "+HIY+BOLD+"lightning bolt"+NORM+" strikes the corpse"+
        ", "+HIR+"incinerating"+NORM+" it in a makeshift "+HIR+"funeral pyre"+NORM+".\n\n");  
      }  else  {
     write("\nChanting a melancholy requiem, you call a bolt of "+BOLD+
          "lightning"+NORM+" from the sky.\n"+
          "The bolt strikes the , incinerating it in a makeshift uneral pyre.\n");
    say("\n"+tp+" chants a melancholy requiem.\n"+
        "A "+BOLD+"lightning bolt"+NORM+" strikes the corpse"+
        ", incinerating it in a makeshift funeral pyre.\n\n");  
        }
        }
  
  else if(BTYPE == "grave")  {
   HEADSTONE = clone_object("/players/saber/closed/bard/itm/marker.c");
   move_object(HEADSTONE, ENV);
   if(COLOR)  {
    write("\nSinging a brief "+HIB+"ayre"+NORM+", you bury a corpse.\n");
    say("\n"+tp+" sings a brief "+HIB+"ayre"+NORM+" as "+PRO+
        " buries the corpse.\n\n");   
    tell_room(ENV, "A headstone rises from the ground.\n");
      }  else  {
    write("\nSinging a brief ayre, you bury the corpse.\n");
    say("\n"+tp+" sings a brief ayre as "+PRO+" buries a corpse.\n\n");
    tell_room(ENV, "A headstone rises from the ground.\n");
        }
        }
  
  else {
   if(COLOR)  {
    write("\nSinging a brief "+HIB+"prayer"+NORM+", you bury a corpse.\n");
    say("\n"+tp+" sings a brief "+HIB+"prayer"+NORM+" as "+PRO+
        " buries the corpse.\n\n");   
      }  else  {
    write("\nSinging a brief prayer, you bury the corpse\n");
    say("\n"+tp+" sings a brief prayer as "+PRO+" buries a corpse.\n\n");
        }
        }
   
  HEAL = CORPSE->heal_value();
  call_other(TP, "heal_self", HEAL);  

  HEALTH = TP->query_hp() * 100 / TP->query_mhp();
  MANA   = TP->query_sp() * 100 / TP->query_msp();
  write("You feel better  "+BOLD+"[ "+HEALTH+"% hp : "+MANA+"% mana ]\n\n"+NORM);

  destruct(CORPSE);
  return 1;
        }
