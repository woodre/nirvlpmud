/*
 *  False Speak: Harm
 *
 *    Lightning - attack spell using up
 *    Syphon - attack/healing spell
 *
 *    All harm spells make the bard more evil
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

harm(str)  {
string HARM, HARM2, NAME, MESS;
object TARG, TO_HIT;
int LIFE, RAN, OPPONENT, HEALTH, MANA;

  if(!str)  {
    write("Harm: < lightning > < syphon >\n");
    return 1;
        }

  if(sscanf(str, "%s %s", HARM, HARM2) < 2)  { sscanf(str, "%s", HARM); } 


 if(HARM == "lightning" || HARM == "light" || HARM == "project")  {


  if(!INSTR->query_know_spell("harm_project"))  {
    write("You have not yet learned the words for projecting lighting.\n");
    return 1;
      }

  if(!HARM2 && TP->query_attack())  {
    HARM2 = TP->query_attack()->query_real_name();
        }
  
  if(!HARM2)  {
    write("Who will you project lightning towards?\n");
    write("Syntax: ha < project > < target >\n");
    return 1;
        }
   
  if(!(TO_HIT = present(HARM2, ENV)))  {
    write("You must project lightning towards a creature...\n");
    return 1;
        }
   
  if(attack_spell(-1000,9,0,TO_HIT) == -1) return 0;
  
  NAME = TO_HIT->query_name();
  RAN = random(7);

  write("You chant\n");
  say(tp+" chants\n");
  tell_room(ENV,
        "            \""+BOLD+"Ski guda ske wegi me juha ski juyo"+NORM+"\"\n"+
        "            \""+BOLD+"Faske liyo libuske be daunwe pabu hilo"+NORM+"\"\n");
        
    write("\nYou hurl a bolt of "+BOLD+"dark lightning"+NORM+" at "+NAME+".\n");
    say("\n"+tp+" staggers as "+PRO+" hurls a bolt of "+BOLD+"dark lightning"+NORM+
      " at "+NAME+".\n");

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe lightning fades away.\n\n");
    say("\n"+tp+"'s lightning fades away.\n\n");
    call_other(TP,"add_hit_point",-25); 
    return 1; 
      }

  if(RAN == 0)  MESS = NAME+" stumbles backwards";
  if(RAN == 1)  MESS = "Currents of "+BOLD+"electricity"+NORM+" arc through the air";
  if(RAN == 2)  MESS = "Wisps of "+BOLD+"smoke"+NORM+" drift from "+NAME+"'s body";
  if(RAN == 3)  MESS = "You smell the faint oder of burnt flesh";
  if(RAN == 4)  MESS = NAME+" screams in pain";

  if(RAN < 5)  {  tell_room(ENV, MESS+".\n\n"); }

   call_other(TP, "add_alignment", -(random(400)+50));  

   LIFE = 25 + random(20);
   TP->attack_object(TO_HIT);
        /* Hit Monster for 25 + random(20) damage */
   TO_HIT->hit_player(LIFE);
        /* Hit Player for same 25 + random(20) damage, - 5 */
   TP->hit_player(LIFE-5);

   OPPONENT = TO_HIT->query_hp() * 100 / TO_HIT->query_mhp();
   write(BOLD+"[ "+OPPONENT+"% opponent ]\n"+NORM);

   return 1;
   
        }


 if(HARM == "silence" || HARM == "si")  {

  if(!INSTR->query_know_spell("harm_syphon"))  {
    write("You have not yet learned the words for syphoning silence.\n");
    return 1;
      }

  if(!HARM2 && TP->query_attack())  {
    str = TP->query_attack()->query_real_name();
        }
  
  if(!HARM2)  {
    write("Whom would you Syphon your Silence into?\n");
    write("Syntax: ha < syphon > < target >\n");
    return 1;
        }
  
  if(!(TO_HIT = present(HARM2, ENV)))  {
    write("You must Syphon the Silence into a creature...\n");
    return 1;
        }
   
   if(attack_spell(-1000,12,50,TO_HIT) == -1) return 0;
   
   NAME = TO_HIT->query_name();
   RAN = random(3);
   
   tell_rom(ENV, "\n");
   
   if(RAN == 0)  {
     write("Raising two fingers of your left hand, you step towards "+NAME+"\n");
     say(tp+" raises two fingers of "+POSS+" left hand as "+PRO+" steps towards "+NAME+
            "\n");
        }
   else if(RAN == 1)  {
     write("Glancing at "+NAME+", you cover your left eye with your left hand.\n");
     say(tp+" glanes at "+NAME+" as "+PRO+" covers "+POSS+" left eye with "+POSS+
            " left hand.\n");
        }
   else {
     write("You extend your left hand slowly towards "+NAME+".\n"); 
     say(tp+" slowly extends "+POSS+" left hand towards "+NAME+".\n");
        }
   
   write("You sing \n");
   say(tp+" sings \n");

   tell_room(ENV, "        "+BOLD+"Ski mase koko renaana di mo ski"+NORM+"\"\n"+
                  "        "+BOLD+"Paco koko repapo be juguun mo"+NORM+"\"\n\n");

   write("You Syphon the dark silence from your heart and channel it into "+NAME+".\n"+
         "You feel the music from "+NAME+"'s soul explode within you.\n");
   say(NAME+" and "+tp+" are surrounded by a cacophony of vibrant, chaotic music.\n"+
       "Syphoning vitality from the music, "+tp+" channels the dark silence into "+
       NAME+".\n\n");

   if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou stumble over the words.\n\n");
    say("\n"+tp+" stumbles over the words.\n\n");
    call_other(TP,"add_spell_point",-50); 
    return 1; 
      }  
   
   LIFE = 50 - random(50);

   TP->attack_object(TO_HIT);
          /* Do d50 damage to target   */
   TO_HIT->hit_player(LIFE);
          /* Add same d50 hp to player */
   TP->add_hit_point(LIFE);

   HEALTH   = TP->query_hp() * 100 / TP->query_mhp();
   MANA     = TP->query_sp() * 100 / TP->query_msp();
   OPPONENT = TO_HIT->query_hp() * 10 / TO_HIT->query_mhp();
   write(BOLD+"[ "+HEALTH+"% hp : "+MANA+"% mana : "+OPPONENT+"% opponent ]\n"+NORM);

   call_other(TP, "add_alignment", -(random(400)+50));
   call_other(TP, "add_spell_point", -50);
   return 1;
        }
 
 
  command("ha", TP);
  return 1;
       }
