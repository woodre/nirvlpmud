/*
 *  False Speak: Obscure
 *
 *    Fumble - attack spell
 *    Mislead - target attacks self
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

obscure(str)  {
string OBSCURE, OBSCURE2, OBSCURE3, NAME, NAME2;
object TARG, TO_HIT, FUMBLE;
int OPPONENT, TIME, MLVL, MLVL2, COST;
int RAN;
string MESS;


  if(!str)  {
    write("Obscure: < fumble > < mislead >\n");
    return 1;
        }

  if(sscanf(str, "%s %s %s", OBSCURE, OBSCURE2, OBSCURE3) < 3)  { 
  if(sscanf(str, "%s %s", OBSCURE, OBSCURE2) < 2)  { sscanf(str, "%s", OBSCURE); } }


 if(OBSCURE == "fumble" || OBSCURE == "fu")  {


  if(!INSTR->query_know_spell("obscure_fumble"))  {
    write("You have not yet learned the words which cause fumbles.\n");
    return 1;
      }

  if(!OBSCURE2 && TP->query_attack())  {
    OBSCURE2 = TP->query_attack()->query_real_name();
        }
  
  if(!OBSCURE2)  {
    write("Who will you cause to fumble?\n");
    write("Syntax: re < fumble > < target >\n");
    return 1;
        }
   
  if(!(TARG = present(OBSCURE2, ENV)))  {
    write("You must name a creature present...\n");
    return 1;
        }
   
  if(present("fumble_obj", TARG))  {
    write(capitalize(OBSCURE2)+" is already fumbling.\n");
    return 1;
        }
  
  if(attack_spell(-50,8,20,TARG) == -1) return 0;
  
  NAME = TARG->query_name();
  RAN = random(5);

  write("You raise your hand into the air as you chant\n\n");
  say(tp+" raises "+POSS+" hand into the air as "+PRO+" chants\n\n");
  tell_room(ENV,
        "            \""+BOLD+"Gure paskoya lo ski juya"+NORM+"\"\n"+
        "            \""+BOLD+"Paco pabu be juha pabuski"+NORM+"\"\n\n");
        

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou loose your focus.\n\n");
    say("\n"+tp+" blinks.\n\n");
    call_other(TP,"add_spell_point",-20); 
    return 1; 
      }

  if(RAN == 0)  MESS = NAME+" looks dizzy";
  if(RAN == 1)  MESS = "You catch the faint oder of banana peels";
  if(RAN == 2)  MESS = "Wisps of steam drift from "+NAME+"'s ears";
  if(RAN == 3)  MESS = NAME+" takes a step back";
  if(RAN == 4)  MESS = NAME+" wobbles";

  tell_room(ENV, MESS+".\n\n");

   TIME = (BLVL + TP-query_attrib("wil")/5;
   FUMBLE = clone_object("/players/saber/closed/bard/itm/fumble.c");
   move_object(FUMBLE, TARG);
   FUMBLE->set_hit(TIME);
   FUMBLE->set_master(TPQ);
   
   OPPONENT = TO_HIT->query_hp() * 100 / TO_HIT->query_mhp();
   write(BOLD+"[ "+OPPONENT+"% opponent ]\n"+NORM);

   return 1;
   
        }


 if(OBSCURE == "mislead" || OBSUCRE == "mis")  {

  if(!INSTR->query_know_spell("obscure_mislead"))  {
    write("You have not yet learned the words that mislead.\n");
    return 1;
      }
  
  if(!OBSCURE2 || !OBSCURE3)  {
    write("Who would you mislead?\n");
    write("Syntax: re < mislead > < target > < target >\n");
    return 1;
        }
  
  if(!(TO_HIT = present(OBSUCRE2, ENV)) || !(TARG = present(OBSCURE3, ENV)))  {
    write("You must mislead two present creatures...\n");
    return 1;
        }
   
   if(attack_spell(-1000,12,25,TO_HIT) == -1) return 0;
   
   if(TO_HIT->is_player() || TARG->is_player() ||
      TO_HIT->is_pet()    || TARG->is_pet())  {
      write("You can not mislead pets or players.\n");
      return 1;
        }
   
   NAME = TO_HIT->query_name();  NAME2 = TARG->query_name();
   MLVL = TO_HIT->query_level(); MLVL2 = TARG->query_level();
   
   COST = MLVL + MLVL2 + 10;
   
   tell_rom(ENV, "\n");
   
   write("Raising both hands, you point at "+NAME+" and "+NAME2+".\n");
   say(tp+" raises both hands as "+PRO+" points at "+NAME+" and "+NAME2+".\n");
   
   write("You sing\n\n");
   say(tp+" sings\n\n");

   tell_room(ENV, "         "+BOLD+"So mo un - Soli mo crysea"+NORM+"\"\n"+
                  "         "+BOLD+"Ski mehigu gure koko mo paco mejuwe"+NORM+"\"\n\n");

   if(COLOR)  {
   tell_room(ENV, HIR+NAME+NORM+" and "+HIR+NAME2+NORM+" begin to glow.\n\n");
     }  else  {
   tell_room(ENV, NAME+" and "+NAME2+" begin to glow.\n\n");     
     }
     

   if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou stumble over the words.\n\n");
    say("\n"+tp+" stumbles over the words.\n\n");
    call_other(TP,"add_spell_point",-COST); 
    return 1; 
      }  

   TARG->attack_object(TO_HIT);
   TO_HIT->attack_object(TARG);

   TIME = random(TP->query_attrib("wil")/2) + 5;
      
   FUMBLE = clone_object("/players/saber/closed/bard/itm/mislead.c");
   FUMBLE->set_time(TIME);
   FUMBLE->set_master(TPQ);
   move_object(FUMBLE, TARG);

   FUMBLE = clone_object("/players/saber/closed/bard/itm/mislead.c");
   FUMBLE->set_time(TIME);
   FUMBLE->set_master(TPQ);
   move_object(FUMBLE, TO_HIT);

   call_other(TP, "add_spell_point", -COST);
   return 1;
        }
 
 
 /* test */
 
 if(OBSCURE == "zap")  {


  if(!INSTR->query_know_spell("obscure_fumble"))  {
    write("You have not yet learned the words which cause fumbles.\n");
    return 1;
      }

  if(!OBSCURE2 && TP->query_attack())  {
    OBSCURE2 = TP->query_attack()->query_real_name();
        }
  
  if(!OBSCURE2)  {
    write("Who will you cause to fumble?\n");
    write("Syntax: re < fumble > < target >\n");
    return 1;
        }
   
  if(!(TARG = present(OBSCURE2, ENV)))  {
    write("You must name a creature present...\n");
    return 1;
        }
   
  if(present("fumble_obj", TARG))  {
    write(capitalize(OBSCURE2)+" is already fumbling.\n");
    return 1;
        }
  
  if(attack_spell(-50,8,5,TARG) == -1) return 0;
  
  NAME = TARG->query_name();
  RAN = random(5);

  write("You raise your hand into the air as you chant\n\n");
  say(tp+" raises "+POSS+" hand into the air as "+PRO+" chants\n\n");
  tell_room(ENV,
        "            \""+BOLD+"Gure paskoya lo ski juya"+NORM+"\"\n"+
        "            \""+BOLD+"Paco pabu be juha pabuski"+NORM+"\"\n\n");
        

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou loose your focus.\n\n");
    say("\n"+tp+" blinks.\n\n");
    call_other(TP,"add_spell_point",-20); 
    return 1; 
      }

   spell_object(TO_HIT,"",-50,0,"","","");
   
   OPPONENT = TO_HIT->query_hp() * 100 / TO_HIT->query_mhp();
   write(BOLD+"[ "+OPPONENT+"% opponent ]\n"+NORM);

   return 1;
   
        }

  command("re", TP);
  return 1;
       }
