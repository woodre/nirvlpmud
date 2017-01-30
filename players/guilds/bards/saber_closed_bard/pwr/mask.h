/*
 *  False Speak: Mask
 *
 *    Slip: Dummy for monster to hit
 *    Distortion: Temp armor
 *    Mirror: Brief multiple attacks
 *    Shadow: Create monster to attack opponents
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


Mask(str)  {
object TARG, MARK;
string MASK, MASK2, TEMP2;
int AC, WC, WEAP, HP, NUMBER, TEMP, COUNT, WIL;
  
  if(!str)  { 
    write("Syntax: di < slip > < distortion > < mirror > < shadow >\n");
    return 1;
    }

  if(sscanf(str, "%s %s", MASK, MASK2) < 2)  { sscanf(str, "%s", MASK); } 
  
  
  /*  Temp armor */

  if(MASK == "distortion" || MASK == "distort")  {
  
  if(spell(-50,8,25) == -1) return 0;
  
  if(!INSTR->query_know_spell("mask_distort"))  {
    write("You have not yet learned the words of distortion.\n");
    return 1;
      }

  if(present("mask_distort", TP))  {
      write("You have already distorted yourself.\n");
      return 1;
        }
   
  if(TP->query_ac() > 9)  {
      write("Distortion can not make your armor any better.\n");
      return 1;
        }
  
  if(COLOR)  {
    write("\nYou play the "+HIR+"chords of distortion"+NORM+" upon your "+INST+".\n\n"+
          "You sing\n\n"+
          "                \""+BOLD+"Podi ski skili nuhifi logu soli\""+NORM+"\n"+
          "                \""+BOLD+"Ahi ski we mapa ski ru\""+NORM+"\n"+          
          "\nA "+HIR+"shimmering"+NORM+" field surrounds you.\n\n");

    say("\n"+tp+" plays the "+HIR+"chords of distortion"+NORM+" upon "+POSS+" "+INST+".\n\n"+
          tp+" sings\n\n"+
          "                \""+BOLD+"Podi ski skili nuhifi logu soli\""+NORM+"\n"+
          "                \""+BOLD+"Ahi ski we mapa ski ru\""+NORM+"\n"+          
          "\nA "+HIR+"shimmering"+NORM+" field surrounds "+tp+".\n\n");
 
        }  else  {

    write("\nYou play the "+BOLD+"chords of distortion"+NORM+" upon your "+INST+".\n\n"+
          "You sing\n\n"+
          "                \""+BOLD+"Podi ski skili nuhifi logu soli\""+NORM+"\n"+
          "                \""+BOLD+"Ahi ski we mapa ski ru\""+NORM+"\n"+          
          "\nA shimmering field surrounds you.\n\n");
           
    say("\n"+tp+" plays the "+BOLD+"chords of distortion"+NORM+" upon "+POSS+" "+INST+".\n\n"+
          tp+" sings\n\n"+
          "                \""+BOLD+"Podi ski skili nuhifi logu soli\""+NORM+"\n"+
          "                \""+BOLD+"Ahi ski we mapa ski ru\""+NORM+"\n"+          
          "\nA shimmering field surrounds "+tp+".\n\n");
       }
 

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour distortion field shimmers away.\n");
    tell_room(ENV, "The field surrounding "+tp+" fades away.\n\n");
    call_other(TP,"add_spell_point",-25); 
    return 1; 
      }

  TARG = clone_object("/players/saber/closed/bard/itm/distort.c");
  move_object(TARG, TP);
  call_other(TP, "add_spell_point", -25);
  return 1;
        }
  

  /*  Temp living shield */

  if(MASK == "slip")  {
  
  if(spell(-50,8,25) == -1) return 0;
  
  if(!INSTR->query_know_spell("mask_slip"))  {
    write("You have not yet learned the words with which to Slip.\n");
    return 1;
      }

  if(present(tp+"_slip", ENV))  {
      write("You are still slipping.\n");
      return 1;
        }
  
  if(COLOR)  {
    write("\nYou whistle a "+HIR+"slip note"+NORM+" as you sing:\n\n");

    say("\n"+tp+" whistles a "+HIR+"slip note"+NORM+" as "+POSS+" sings:\n\n");
 
        }  else  {

    write("\nYou whistle a slip note as you sing:\n\n");
           
    say("\n"+tp+" whistles a slip note as "+POSS+" sings:\n\n");
       }

    write("                \""+BOLD+"Guda hea podi lo ski we sonu ski juyo\""+NORM+"\n"+
          "                \""+BOLD+"Dimo ski mehigu dakoli juha guda\""+NORM+"\n"+          
          "\nAn image of you appears and steps before you.\n\n");
 
    say("                \""+BOLD+"Guda hea podi lo ski we sonu ski juyo\""+NORM+"\n"+
        "                \""+BOLD+"Dimo ski mehigu dakoli juha guda\""+NORM+"\n"+          
        "\nAn image of "+tp+" appears and steps before "+OBJE+".\n\n");


  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour slip shadow fades away.\n");
    tell_room(ENV, "The slip shdow of "+tp+" fades away.\n\n");
    call_other(TP,"add_spell_point",-25); 
    return 1; 
      }

  TARG = clone_object("/players/saber/closed/bard/itm/mask.c");

  HP = BLVL + TP->query_attrib("wil");
  AC = (TP->query_attrib("int") / 2);

  TARG->set_hp(HP);      TARG->set_ac(AC);
  TARG->set_name(TPQ);   TARG->set_short("An image of "+tp);
  TARG->set_master(TPQ); TARG->set_alt_name(tp+"_slip");
  
  move_object(TARG, ENV);
  
  
  MARK = first_inventory(ENV);
  
  while(MARK)  {
  
   if(MARK->query_attack()->query_real_name() == TPQ)  {
    
    MARK->stop_fight();          MARK->stop_fight();
    MARK->stop_hunter();
    
    MARK->attack_object(TARG);
    
        }
    
    MARK = next_inventory(MARK);
    
        }  

  call_other(TP, "add_spell_point", -25);
  return 1;
        }


  /*  Temp attackers */

  if(MASK == "mirror")  {
    
  if(!INSTR->query_know_spell("mask_mirror"))  {
    write("You have not yet learned the words of Mirror Self.\n");
    return 1;
      }

  if(present(tp+"_mirror", ENV))  {
      write("You still have mirror images.\n");
      return 1;
        }
  
  if(sscanf(str, "%s %d", MASK, NUMBER) < 2)  { sscanf(str, "%s", MASK); }

  if(!(TARG = TP->query_attack()) ||
     !(present(TARG, ENV)))  {
   write("You must be in combat to cast Mirror.\n");
   return 1;
     }
  
  if(NUMBER < 1) NUMBER = 1;
  
  TEMP = NUMBER * 25;
  
  if(attack_spell(-50,11,TEMP,TARG) == -1) return 0;

  if(NUMBER < 2) TEMP2 = "a few"; else TEMP2 = "a series of";

  if(COLOR)  {
    write("\nYou whistle "+TEMP2+" "+HIR+"mirrored notes"+NORM+" as you sing:\n\n");

    say("\n"+tp+" whistles "+TEMP2+" "+HIR+"mirrored notes"+NORM+" as "+POSS+" sings:\n\n");
 
        }  else  {

    write("\nYou whistle "+TEMP2+" mirrored notes as you sing:\n\n");

    say("\n"+tp+" whistles "+TEMP2+" mirrored notes as "+POSS+" sings:\n\n");
       }

    tell_room(ENV, 
      "                \""+BOLD+"Ya hea podi, Ya hea mehigu\""+NORM+"\n"+
      "                \""+BOLD+"Gudawo mo juha ski juyo\""+NORM+"\n\n");
 

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour mirror images appear, and then fade away.\n");
    tell_room(ENV, tp+" is briefly surrounded by images of "+OBJE+"self.\n\n");
    call_other(TP,"add_spell_point",-TEMP); 
    return 1; 
      }

for(COUNT=0;COUNT<NUMBER;COUNT+=1)  {
  MARK = clone_object("/players/saber/closed/bard/itm/mask.c");

  HP = BLVL + TP->query_attrib("wil");
  AC = TP->query_ac();
  WC = TP->query_wc();

  MARK->set_hp(HP);      MARK->set_ac(AC);
  MARK->set_name(TPQ);   MARK->set_short("An mirror image of "+tp);
  MARK->set_master(TPQ); MARK->set_alt_name(tp+"_mirror");
  
  move_object(MARK, ENV);
  
  tell_room(ENV, short()+" appears and attacks "+TARG->query_name()+".\n");
  
  MARK->attack_object(TARG);
          }

  call_other(TP, "add_spell_point", -TEMP);
  return 1;
        }


  /*  Shadow attacker */

  if(MASK == "shadow")  {
    
  if(!INSTR->query_know_spell("mask_shadow"))  {
    write("You have not yet learned the words of Shadow Self.\n");
    return 1;
      }

  if(present(tp+"_shadow", ENV))  {
      write("You still have a shadow.\n");
      return 1;
        }
  
  if(sscanf(str, "%s %d %d", MASK, NUMBER, WIL) < 3)  { 
  if(sscanf(str, "%s %d", MASK, NUMBER) < 2)  { sscanf(str, "%s", MASK); } }
  
  if(NUMBER && NUMBER > TP->query_hp())  {
    write("You don't have enough hit points.\n");
    return 1;
        }
  
  if(WIL > TP->query_attrib("wil"))  {
    write("Your will power is not that great!\n");
    return 1;
        }
  
  if(spell(-50,14,30) == -1) return 0;

  if(COLOR)  {
    write("\nYou whistle the seven "+HIR+"notes of shadow"+NORM+" as you sing:\n\n");

    say("\n"+tp+" whistles the seven "+HIR+"notes of shadow"+NORM+" as "+POSS+" sings:\n\n");
 
        }  else  {

    write("\nYou whistle the seven notes of shadow as you sing:\n\n");

    say("\n"+tp+" whistles the seven notes of shadow as "+POSS+" sings:\n\n");
       }

    tell_room(ENV, 
       "                \""+BOLD+"Ski podi skiliski nuhidi crysoli\""+NORM+"\n"+
       "                \""+BOLD+"Rume mayado be ski ru ski juyoya\""+NORM+"\n\n");

    tell_room(ENV,  "A shadow of "+tp+" appears.\n\n");

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour shadow fades away.\n");
    tell_room(ENV, tp+"'s shadow fades away.\n\n");
    call_other(TP,"add_spell_point",-30); 
    return 1; 
      }

  MARK = clone_object("/players/saber/closed/bard/itm/mask.c");

  HP = BLVL + TP->query_attrib("wil") + NUMBER;
  AC = TP->query_attrib("wil") + (BLVL/7);
  WC = (TP->query_attrib("wil")/2) + (WIL*7) + 1;

  MARK->set_hp(HP);      MARK->set_ac(AC);
  MARK->set_name(TPQ);   MARK->set_short("The shadow of "+tp);
  MARK->set_master(TPQ); MARK->set_alt_name(tp+"_shadow");
  
  move_object(MARK, ENV);
    
  TARG = TP->query_attack();
  MARK->attack_object(TARG);

  call_other(TP, "add_spell_point", -30);
  call_other(TP, "add_hit_point", -NUMBER);
 if(WIL > 0)  
  call_other(TP, "raise_will_power", -WIL);
  
  return 1;
        }


  command("di", TP);
  return 1;
       }
