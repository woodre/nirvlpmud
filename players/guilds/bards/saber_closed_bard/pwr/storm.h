/*
 *  True Speak: Storm
 *
 *    Lighting: Area effect attack
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

static object HERE;

storm(str)  {
object TARG, GEM, TO_HEAL, FOG, CLOUD, AG;
string STORM, STORM1, STRING;
int GEM_COST, COST, AMOUNT, SPENT, WHICH, HOW_MANY;
  
  if(!str)  { 
    write("Syntax: so < storm > < fly > < lightning > < fog > < cloud >\n");
    return 1;
      }

  if(sscanf(str, "%s %d", STORM, SPENT) < 2)  { sscanf(str, "%s", STORM); } 


  /*  Area effect attack  */

  if(str == "lightning")  {

  if(spell(-50,11,50) == -1) return 0;
  if(TP->query_ghost()) { notify_fail("Only the living can heal the living.\n");  }
  
  if(!INSTR->query_know_spell("storm_lightning"))  {
    write("You have not yet learned the words for Lightning Storm.\n");
    return 1;
      }

  GEM = present("gem", INV);
    if(!GEM)  { GEM = present("diamond",INV);  }
    if(!GEM)  { GEM = present("pearl",INV);    }
    if(!GEM)  { GEM = present("ruby",INV);     }
    if(!GEM)  { GEM = present("sapphire",INV); }
    if(!GEM)  { GEM = present("topaz",INV);    }
  
  if(GEM)  GEM_COST = GEM->query_value();
  
  if(SPENT < 20)  SPENT = 20;
  if(SPENT > 60)  SPENT = 60;

  write("\nYou play with primal fury upon your "+INST+" as you sing:\n\n");

  say("\n"+tp+" plays with primal fury upon "+POSS+" "+INST+
        " as "+PRO+" sings:.\n\n");

  tell_room(ENV,
    "     \""+BOLD+"Dakola libuske repada lo weso"+NORM+"\"\n"+
    "     \""+BOLD+"Repada lo faske jamo bedo"+NORM+"\"\n");
  
  if(COLOR)  {
    tell_room(ENV, "\nThe "+BOLD+"storm clouds"+NORM+" about you "+HIR+
    "flash"+NORM+" with "+HIR+BOLD+"lightning"+NORM+".\n\n");
      }  else  {
    tell_room(ENV, "\nThe "+BOLD+"storm clouds"+NORM+" about you flash with "
              +BOLD+"lightning"+NORM+".\n\n");    
      }
  
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou stumbles on the words.\n");
    tell_room(ENV, tp+" suddenly stops singing.\n\n");
    call_other(TP,"add_spell_point",-25); 
    return 1; 
      }

  COST = 0; AMOUNT = 0;
  
  TO_HEAL = first_inventory(ENV);
  
  while(TO_HEAL)  {

    if(present("instrument", TO_HEAL))  {
       tell_object(TO_HEAL, "You shield yourself from the lightning storm.\n\n");
            }

    else if(TO_HEAL->is_player())  {
        tell_room(ENV, TO_HEAL->query_name()+" is missed by a bolt of lightning.\n\n");
        tell_object(TO_HEAL, "You fell very, very lucky.\n");
            }

    else if(TO_HEAL->is_pet())  {
        tell_room(ENV, TO_HEAL->short()+" is missed by a "+HIR+
          "bolt of lightning"+NORM+".\n\n");
            }

    else if(TO_HEAL->query_npc())  {
        tell_room(ENV, TO_HEAL->short()+" is "+HIR+"FRIED"+NORM+" by a "+HIR+
                  "bolt of lightning"+NORM+".\n\n");
          if(!TO_HEAL->query_attack())  {
            if(living(TO_HEAL)) { TO_HEAL->attack_object(TP);
                                  TP->attack_object(TO_HEAL); }
                   }
          TP->attack_object(TO_HEAL);
          TO_HEAL->hit_player(SPENT/2);
          AG = clone_object("/players/saber/closed/bard/itm/hit_again.c");
          move_object(AG, TO_HEAL);
          AG->set_dam(SPENT/2);
          COST = COST + SPENT;
          AMOUNT++;
            }

     TO_HEAL = next_inventory(TO_HEAL);
            }
     
  tell_room(ENV, "\nThere is a booming "+BOLD+"rumble of thunder"+NORM+
                 " in the distance.\n");
  
  if(AMOUNT < 1)  {
    write("\nThere were no targets for the lightning to hit.\n");
    return 1;
            }  else  {
    call_out("again", 1);
            }
  
  /*destroy the gem or reduce it's value */
  if(GEM)  {
    if(COST > (GEM_COST / 12))  {    
      tell_room(ENV, GEM->short()+" glows and then is gone.\n");
      COST = COST - (GEM_COST / 12);
      destrut(GEM);
       } else { 
    tell_room(ENV, GEM->shot()+" cracks.\n");
      COST = (COST - 20) * 12;
      GEM_COST = GEM_COST - COST;
      GEM->set_value(GEM_COST);
      COST = 20;
      } 
      }          
  
  HERE = environment(this_player());
  
  write("\nYou spent "+COST+" mana to fry "+AMOUNT+" monsters.\n\n");
  call_other(TP, "add_spell_point", -COST);
  return 1;
        }
  

  if(str == "fog")  {
  
  if(spell(-50,12,25) == -1) return 0;
  
  if(!INSTR->query_know_spell("storm_fog"))  {
    write("You have not yet learned the words for fog.\n");
    return 1;
      }

  if(present("fog_cloud", ENV))  {
    write("There is already fog in the room.\n");
    return 1;
        }
 
   write("\nTuning your "+INST+", you sing \""+BOLD+
          "Kada lo soli crysea paco ru\""+NORM+".\n");         

   say("\n"+tp+" tunes "+POSS+" "+INST+" as "+PRO+" sings \""+BOLD+
          "Kada lo soli crysea paco ru\""+NORM+"\n");
      
   tell_room(ENV,
     "\nFog seeps from "+tp+"'s fingers, engulfing the room.\n"); 

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe fog gusts away.\n");
    tell_room(ENV, "The fog fades away.\n\n");
    call_other(TP,"add_spell_point",-25); 
    return 1; 
      }

  FOG = clone_object("/players/saber/closed/bard/itm/fog.c");
  move_object(FOG, ENV);
  FOG->set_go_away(BLVL * 30);
  call_other(TP, "add_spell_point", -25);
  return 1;
        }


  if(str == "cloud")  {
  
  if(spell(-50,13,40) == -1) return 0;
  
  if(!INSTR->query_know_spell("storm_cloud"))  {
    write("You have not yet learned the words of clouds.\n");
    return 1;
      }

  if(present("cloud", ENV))  {
    write("You are already on a cloud.\n");
    return 1;
        }
 
   write("\nRaising your left hand, you sing \""+BOLD+
          "Ski dakola hea coloda kowepo wesoya\""+NORM+".\n");         

   say("\n"+tp+" raises "+POSS+" left hand as "+PRO+" sings \""+BOLD+
          "Ski dakola hea coloda kowepo wesoya\""+NORM+"\n");
      
   tell_room(ENV,
     "\nA "+BOLD+"strom cloud"+NORM+" drifts in.\n"); 

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe cloud drifts from the room.\n");
    tell_room(ENV, "The cloud drifts from the room.\n\n");
    call_other(TP,"add_spell_point",-40); 
    return 1; 
      }

  write("You fly up onto the cloud.\n");
  say(tp+" flies up into the air and lands on the cloud.\n\n");

  CLOUD = clone_object("/players/saber/closed/bard/itm/cloud.c");
  CLOUD->set_master(TP);
  move_object(CLOUD, ENV);
  move_object(TP, CLOUD);
  call_other(TP, "add_spell_point", -40);
  return 1;
        }

  write("There is no such storm power.\n");
  return 1;
        }


  /*  2nd part of area effect attack  */

again()  {
object TO_HEAL, AG;
int HOW_MANY, WHICH, COUNT;


  say("test1.\n");
  tell_room(HERE, 
    "\nThe "+BOLD+"storm clouds"+NORM+" about you "+HIR+
    "flash"+NORM+" with "+HIR+BOLD+"lightning"+NORM+".\n\n");
  
  TO_HEAL = first_inventory(HERE);
  
  while(TO_HEAL)  {

    if(AG = present("hit_again", TO_HEAL))  {

     tell_room(HERE, "\n");

    HOW_MANY = random(3) + 1;
    
      
      while(HOW_MANY > COUNT)  {
      
          WHICH = random(6);

          if(WHICH == 0)
              tell_room(HERE, 
              TO_HEAL->short()+" is struck by a raging bolt of "+HIR+
              "lightning"+NORM+".\n");

     else if(WHICH == 1)
              tell_room(HERE, 
              TO_HEAL->short()+" is fried by a bolt of "+HIR+
              "lightning"+NORM+".\n");

     else if(WHICH == 2)
              tell_room(HERE, 
              TO_HEAL->short()+" is struck by raging "+HIR+
              "electric fie"+NORM+".\n");

     else if(WHICH == 3)
              tell_room(HERE, 
              TO_HEAL->short()+" is hit by a bolt of "+HIR+
              "lightning"+NORM+".\n");
     
     else if(WHICH == 4)
              tell_room(HERE, 
              TO_HEAL->short()+" is engulfed in a column of primal "+HIR+
              "electricity"+NORM+".\n");

     else if(WHICH == 5)
              tell_room(HERE, 
              TO_HEAL->short()+" is hammered by a torrent of "+HIR+
              "lightning"+NORM+".\n");
          
          COUNT = COUNT + 1;
          }

          if(living(TO_HEAL)) { 
            TO_HEAL->hit_player(AG->query_dam());
            }
            }

     TO_HEAL = next_inventory(TO_HEAL);
            }
     
  tell_room(HERE, "\nThere is a booming "+BOLD+"rumble of thunder"+NORM+
                 " in the distance.\n");
                  
  return 1;
        }
