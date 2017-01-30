/*
 *  True Speak: Heal
 *
 *    Heal: Healing - about 1 pt for pt (20 sp min)
 *    Regeneration: Heal 1pt/hb until healed  (100 sp)
 *    Chorus: Heals all players, pets and kids in the room.
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


heal(str)  {
object TARG, REGEN, TO_HEAL, COMP;
string HEAL, NAME;
int AMNT, HEALING, HEALTH, TEMP, REGEN_COUNT, COUNT, COST, AMOUNT;
  
  if(!str)  { str = TPQ; }

  if(sscanf(str, "%s %d", HEAL, AMNT) < 2)  { sscanf(str, "%s", HEAL); } 


  /*  Area effect healing  */

  if(str == "all")  {

  if(spell(-50,13,50) == -1) return 0;
  if(TP->query_ghost()) { notify_fail("Only the living can heal the living.\n");  }
  
  if(!INSTR->query_know_spell("heal_all"))  {
    write("You have not yet learned the words for the Chorus of Crysea.\n");
    return 1;
      }

  write("\nYou play a melodic tune upon your "+INST+
        ", initiating the "+BOLD+"Chorus of Crysea"+NORM+".\n\n");
  say("\n"+tp+" plays a melodic tune upon "+POSS+" "+INST+
        ", initiating the "+BOLD+"Chorus of Crysea"+NORM+".\n\n");
  tell_room(ENV,
    "     \""+BOLD+"Repada lo lahe, dakoli te bu"+NORM+"\"\n"+
    "     \""+BOLD+"Crysea rujoya dakola sese defu"+NORM+"\"\n");
  tell_room(ENV, "\nYou feel the melody surge through you.\n\n");
  
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou stumble on the words.\n");
    tell_room(ENV, tp+" suddenly stops singing.\n\n");
    call_other(TP,"add_spell_point",-25); 
    return 1; 
      }

  COST = 0; AMOUNT = 0;
  
  TO_HEAL = first_inventory(ENV);
  
  while(TO_HEAL)  {
    if(TO_HEAL->is_player())  {
      if(TO_HEAL->query_hp() < (TO_HEAL->query_mhp() - 25))  {
        tell_room(ENV, TO_HEAL->query_name()+" is swept up in the Chorus of Crysea.\n");
          AMOUNT = 15 + random(TP->query_attrib("pie")/2);
          if(AMOUNT > TO_HEAL->query_infuse_limit()/2) 
             AMOUNT = TO_HEAL->query_infuse_limit()/2 - 2;
         if(AMOUNT > 2*((TO_HEAL->query_infuse_limit()) - TO_HEAL->query_infuse())/3)
          AMOUNT = (2*((TO_HEAL->query_infuse_limit()) - TO_HEAL->query_infuse())/3) - 2;
          TO_HEAL->add_hit_point(AMOUNT);
        tell_object(TO_HEAL, "You have been healed "+AMOUNT+" hit points.\n");
          COST = COST + AMOUNT;
          COUNT++;
            }
            }
    if(TO_HEAL->is_pet())  {
      if(TO_HEAL->query_hp() < (TO_HEAL->query_mhp() - 25))  {
        tell_room(ENV, TO_HEAL->short()+" is swept up in the Chorus of Crysea.\n");
          AMOUNT = 15 + random(TP->query_attrib("pie")/2);
          COST = COST + AMOUNT;
          TO_HEAL->heal_self(AMOUNT);
          COUNT++;
            }
            }
     TO_HEAL = next_inventory(TO_HEAL);
            }
     
  tell_room(ENV, "\nThere is a booming "+BOLD+"rumble of thunder"+NORM+
                 " in the distance.\n");
  
  if(COUNT < 1)  {
    write("\nYou spent no mana singing the Chorus of Cyrsea.\n");
    return 1;
            }
  
  write("\nYou spent "+COST+" mana to heal "+COUNT+" people, pets and children.\n\n");
  call_other(TP, "add_spell_point", -COST);
  return 1;
        }
  
  
  if(str == "regen")  {
  
  if(spell(-50,14,100) == -1) return 0;
  
  if(!INSTR->query_know_spell("heal_regen"))  {
    write("You have not yet learned the words of regeneration.\n");
    return 1;
      }

  if(present("regen", TP))  {
    REGEN = first_inventory(TP);
    
    while(REGEN)  {
      if(call_other(REGEN, "id", "regen"))  {
      REGEN_COUNT = REGEN_COUNT + 1;
        }
     REGEN = next_inventory(REGEN);
        }
        }
    
    if(REGEN_COUNT > 1)  {
      write("You are regenerating as fast as Bardic Lore will let you...\n");
      return 1;
        }
   
    if(COLOR)  {
     write("\nYou play the eleven chords of "+HIR+"Eternal Renewal"+NORM+ 
           " upon your "+INST+".\n\n"+
           "You sing \""+BOLD+"Sorupo lahe gu mo ski - Hihi te defu di ski we\""+NORM+"\n"+          
           "\nYou begin to regenerate.\n\n");

     say("\n"+tp+" plays the eleven chords of "+HIR+"Eternal Renewal"+NORM+
         " upon "+POSS+" "+INST+".\n\n"+
         tp+" sings \""+BOLD+"Sorupo lahe gu mo ski - Hihi te defu di ski we\""+NORM+"\n\n"+          
         tp+" begins to regenerate at a rapid rate.\n\n");
 
        }  else  {

     write("\nYou play the eleven chords of Eternal Renewal upon your "+INST+".\n\n"+
           "You sing \""+BOLD+"Sorupo lahe gu mo ski - Hihi te defu di ski we\""+NORM+"\n"+          
           "\nYou begin to regenerate.\n\n");

     say("\n"+tp+" plays the eleven chords of Eternal Renewal upon "+POSS+" "+INST+".\n\n"+
          tp+" sings \""+BOLD+"Sorupo lahe gu mo ski - Hihi te defu di ski we\""+NORM+"\n\n"+          
         tp+" begins to regenerate at a rapid rate.\n\n");
       }
 

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour regeneration spell fails.\n");
    tell_room(ENV, tp+" stops regenerating.\n\n");
    call_other(TP,"add_spell_point",-100); 
    return 1; 
      }

  REGEN = clone_object("/players/saber/closed/bard/itm/regen.c");
  move_object(REGEN, TP);
  call_other(TP, "add_spell_point", -100);
  return 1;
        }
  
  
  /* Heal Target */
  
  if(spell(-50,8,20) == -1)  return 0;        

  if(!INSTR->query_know_spell("heal_heal"))  {
    write("You have not yet learned the words of healing.\n");
    return 1;
      }
  
  if(HEAL == "me") HEAL = TPQ;
  
  if(!(TARG = present(HEAL, ENV)))  {
    write("There is no "+HEAL+" here to heal.\n");
    return 1;
      }
  
  if(TARG->query_hp() == TARG->query_mhp())  {
    write(TARG->query_name()+" has no wounds to heal.\n");
    return 1;
        }

  /* Only use what you need */
  if(TARG->query_hp() +20 > TARG->query_mhp() || (AMNT > 1 && AMNT < 20))  {
    write("You realize that "+TARG->query_name()+" only needs a bandage.\n");
    command("bandage "+HEAL, TP);
    return 1;
        }
          
  /* Defauly healing amount */
 if(AMNT == 0)  { AMNT = (BLVL * 2) + TP->query_attrib("pie"); }

  /* If they heal over their max, reduce to max */
 if(AMNT > ((BLVL * 2) + TP->query_attrib("pie")))  { 
    AMNT = (BLVL * 2) + TP->query_attrib("pie");
    }

  /* If they over heal, set so that they don't */
 if(AMNT > (TARG->query_mhp() - TARG->query_hp()))  {
    AMNT = (TARG->query_mhp() - TARG->query_hp()) - 5;
    }
 
 /* no useless healing */
 if(AMOUNT > TARG->query_infuse_limit()/2) 
    AMOUNT = TARG->query_infuse_limit()/2 - 2;


 if(COLOR)  {
  if(TARG == TP) {
    write("\nRaising your hands into the air, you are surround by a "+HIY+"halo"+NORM+" of "+HIY+"light"+NORM+".\n"); 
    say("\nA "+HIY+"halo"+NORM+" of "+HIY+"light"+NORM+" surrounds "+tp+" as "+PRO+" raises "+POSS+" hands into the air.\n");

  }  else  {
    write("\nRaising your hands into the air, you glance at "+TARG->query_name()+".\n");
    say("\nRaising "+POSS+" hands into the air, "+tp+" glances at "+TARG->query_name()+".\n");
  }
  
    write("You sing\n"+
          "         \""+BOLD+"Gu lahe mo kowepo reri unca mo cabu"+NORM+"\"\n"+
          "         \""+BOLD+"Ruja te koko webucryya higu rupo"+NORM+"\"\n\n"); 
    say(tp+" sings\n"+
      "           \""+BOLD+"Gu lahe mo kowepo reri unca mo cabu"+NORM+"\"\n"+
      "           \""+BOLD+"Ruja te koko webucryya higu rupo"+NORM+"\"\n\n"); 

  if(TARG == TP) {
    write("Your wounds are bathed in an "+HIY+"electrical current"+NORM+
           " of "+BLU+"healing light"+NORM+".\n\n");
  }  else  {
    write(TARG->query_name()+"'s wounds are bathed in an "+HIY+"electrical current"+NORM+
           " of "+BLU+"healing light"+NORM+".\n\n");
  }
    say(TARG->query_name()+"'s wounds are bathed in an "+HIY+"electrical current"+NORM+
           " of "+BLU+"healing light"+NORM+".\n\n");
   
    }  else  {

  if(TARG == TP) {
    write("\nRaising your hands into the air, you are surround by a halo of light.\n"); 
    say("\nA halo of light surrounds "+tp+" as "+PRO+" raises "+POSS+" hands into the air.\n");

  }  else  {
    write("\nRaising your hands into the air, you glance at "+TARG->query_name()+".\n");
    say("\nRaising "+POSS+" hands into the air, "+tp+" glances at "+TARG->query_name()+".\n");
  }
  
    write("You sing \""+BOLD+"Gu lahe mo kowepo reri unca mo cabu"+NORM+"\"\n"+
          "         \""+BOLD+"Ruja te koko webucryya higu rupo"+NORM+"\"\n"); 
    say(tp+" sings\n"+
      "           \""+BOLD+"Gu lahe mo kowepo reri unca mo cabu"+NORM+"\"\n"+
      "           \""+BOLD+"Ruja te koko webucryya higu rupo"+NORM+"\"\n"); 

  if(TARG == TP) {
    write("Your wounds are bathed in an electrical current of healing light.\n\n"); 
  }  else  {
    write(TARG->query_name()+"'s wounds are bathed in an electrical current of healing light.\n\n");
  }
    say(TARG->query_name()+"'s wounds are bathed in an electrical current of healing light.\n\n");

       }      


  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour words of healing fail.\n");
    tell_room(ENV, "The glow surrounding "+lower_case(TARG->short())+" fades away.\n\n");
    call_other(TP,"add_spell_point",-20); 
    return 1; 
      }


  if(AMNT > SPELL) AMNT = SPELL; 
   
  HEALING = random(TP->query_attrib("pie") / 2) + 1;
  HEALING = (AMNT - 5) + HEALING;
  
  /* Heal player */

  if(TARG->is_player())  {  TARG->add_hit_point(HEALING); }
    else  {

  /* Heal pet, monster, kid */
      TARG->heal_self(HEALING);
        }

  if(TARG != TP)  {
    tell_object(TARG, "You have been healed "+BOLD+HEALING+NORM+" hp.\n");  }
  
  HEALTH = TARG->query_hp() * 100 / TARG->query_mhp();  
  write(BOLD+"[ "+HEALING+" : "+HEALTH+"% ]\n"+NORM);

  call_other(TP,"add_spell_point",-AMNT);      
  return 1; 
        }
