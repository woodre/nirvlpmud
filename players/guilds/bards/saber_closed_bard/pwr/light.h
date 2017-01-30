/*
 *  True Speak: Light
 *
 *    Light - a light spell
 *    Darkness - darkness spell
 *    Shield - ac 1 shield & spell attack
 *    True - attack vs undead, spirits & illusions
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

light(str)  {
string LIGHT, LIGHT2;
object DARKNESS, HIT_LIGHT;
int DAMAGE, CHANCE;

  if(!str)  {
    write("Light: < light > < dark > < shield > < true >\n");
    return 1;
        }

  if(sscanf(str, "%s %s", LIGHT, LIGHT2) < 2)  { sscanf(str, "%s", LIGHT); } 

        
 /*  Bard Ability to Summon Light.  */

if(LIGHT == "light")  {
  
  if(INSTR->query_light() == "light")  {
    write("The Canticle of Light is already in use.\n"+
          "Song < dark > to put it out.\n");
    return 1;        
        }
        
  if(spell(-50,8,10) == -1)  return 0;

  if(!(INSTR->query_know_spell("light_light")))  {
    write("You have not yet learned the Canticle of Light.\n");
    return 1;
      }
  
if(COLOR)  {
    write("\nYou spread your arms and sing \""+BOLD+"Ski gena Soli gu soli"+NORM+"\".\n"+
          "You are surrounded by an "+HIY+"aura of light"+NORM+".\n\n");
    say("\n"+tp+" spreads "+POSS+" arms and sings \""+BOLD+"Ski gena Soli gu soli"+NORM+"\".\n"+
        tp+" is surrounded by an "+HIY+"aura of light"+NORM+".\n\n");   
  }  else  {
    write("\nYou spread your arms and sing \""+BOLD+"Ski gena Soli gu soli"+NORM+"\".\n"+
          "You are surrounded by an aura of light.\n\n");
    say("\n"+tp+" spreads "+POSS+" arms and sings \""+BOLD+"Ski gena Soli gu soli"+NORM+"\".\n"+
        tp+" is surrounded by an aura of light.\n\n");   
  }


if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour light wavers and fails.\n\n");
    say("\nThe light surrounding "+tp+" wavers and fails.\n\n");
    call_other(TP, "add_spell_point", -10); 
    return 1; 
      }
      
  INSTR->set_light(1);
  INSTR->set_instr_light("light");

  call_other(TP, "add_spell_points", -10);
  return 1;
  
        }

 
   /*  Extinguish Instrument Light  */

  if(LIGHT == "dark")  {
  
  if(INSTR->query_light() == "light")  {
  
    INSTR->set_light(0);
    INSTR->set_instr_light("dark");
  
  if(COLOR)  {
    write("\nYou spread your arms and sing \""+
      BOLD+"Ski gena Crysea un soli"+NORM+"\".\n"+
        "The surrounding area "+BOLD+"dims"+NORM+".\n");
    say("\n"+tp+" spreads "+POSS+" arms and sings \""+
      BOLD+"Ski gena Crysea un soli"+NORM+"\".\n"+
      "The area "+BOLD+"dims"+NORM+" as the "+HIY+"aura of light"+NORM+" surrounding "+tp+" fades away.\n");
     }  else  {
    write("\nYou spread your arms and sing \""+BOLD+"Ski gena Crysea un soli"+NORM+"\".\n"+
        "The surrounding area "+BOLD+"dims"+NORM+".\n");
    say("\n"+tp+" spreas "+POSS+" arms and sings \""+BOLD+"Ski gena Crysea un soli"+NORM+"\".\n"+
        "The area "+BOLD+"dims"+NORM+" as the aura of light surrounding "+tp+" fades away.\n");
     }
     
  return 1;
        }
  
        
   /*  Bard Ability to Summon Darkness  */    

  if(!INSTR->query_know_spell("light_dark"))  {
    write("You have not yet learned the Canticle of Darkness.\n");
    return 1;
      }

  if(spell(-50,8,20) == -1)  return 0;
  
    if(COLOR)  {
    write("\nYou spread your arms and sing \""+
      BOLD+"Ski gene Crysea gu crysea"+NORM+"\".\n"+
        "The surrounding area "+BOLD+"dims"+NORM+".\n");
    say("\n"+tp+" spreads "+POSS+" arms and sings \""+
      BOLD+"Ski gene Crysea gu crysea"+NORM+"\".\n"+
      "The area dims as the "+HIY+"light"+NORM+" fades away.\n");
 
     }  else  {

    write("\nYou spread your arms and sing \""+BOLD+"Ski gene Crysea gu crysea"+NORM+"\".\n"+
        "The surrounding area dims.\n");
    say("\n"+tp+" spreas "+POSS+" arms and sings \""+BOLD+"Ski gene Crysea gu crysea"+NORM+"\".\n"+
        "The area dims as the light fades away.\n");
     }

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour darkness wavers and fails.\n\n");
    say("\nThe darkness surrounding "+tp+" wavers and fails.\n\n");
    call_other(TP,"add_spell_point",-20); 
    return 1; 
      }

   DARKNESS = clone_object("/players/saber/closed/bard/itm/darkness.c");
   move_object(DARKNESS, ENV);
   call_other(TP, "add_spell_points", -20);
   return 1;
      }

  
  /* Shield of light */
  
  if(LIGHT == "shield")  {

  if(!INSTR->query_know_spell("light_shield"))  {
    write("You have not yet learned the words for Shield of Light.\n");
    return 1;
      }
  
  if(present("sphere_of_light",TP))  {
    write("You have already shaped a shield of chromatic spheres.\n");
    return 1;
        }
  
  if(spell(-50,11,100) == -1)  return 0;
           
 if(COLOR)  {
  write("\n"+
    "You play a psalm upon your "+INST+" as you sing \""+BOLD+"Seri soli di kowepo lo cry"+NORM+"\".\n"+
    "\nThe music slowly shapes the forces of primal "+BOLD+"chaos"+NORM+" into a sphere of "+HIY+"light"+NORM+".\n"+
    "\nThe psalm ends as the "+HIY+"c"+HIR+"h"+HIG+"r"+HIC+"o"+HIM+"m"+HIB+"a"+HIR+"t"+HIY+"i"+HIB+"c"+NORM+ 
    " shield-sphere gently floats into your hand.\n\n");
  say("\n"+
    tp+" plays a psalm upon "+POSS+" "+INST+" as "+PRO+" sings \""+BOLD+"Seri soli di kowepo lo cry"+NORM+"\".\n"+
    "\nThe music slowly shapes the forces of primal "+BOLD+"chaos"+NORM+" into a sphere of "+HIY+"light"+NORM+".\n");
  say(
    "The psalm ends as the "+HIY+"c"+HIR+"h"+HIG+"r"+HIC+"o"+HIM+"m"+HIB+"a"+HIR+"t"+HIY+"i"+HIB+"c"+NORM+
    " shield-sphere lands in "+tp+"'s hand.\n\n");
 
    }  else  {
    
  write("\n"+
    "You play a psalm upon your "+INST+" as you sing \""+BOLD+"Seri soli di kowepo lo cry"+NORM+"\".\n"+
    "\nThe music slowly shapes the forces of primal "+BOLD+"chaos"+NORM+" into a sphere of light.\n"+
    "\nThe psalm ends as the chromatic shield-sphere gently floats into your hand.\n\n");
  say("\n"+
    tp+" plays a psalm upon "+POSS+" "+INST+" as "+PRO+" sings \""+BOLD+"Seri soli di kowepo lo cry"+NORM+"\".\n"+
    "\nThe music slowly shapes the forces of primal "+BOLD+"chaos"+NORM+" into a sphere of light.\n"+
    "The psalm ends as the chromatic shield-sphere lands in "+tp+"'s hand.\n\n");
        }
   
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe sphere "+BOLD+"shimmers"+NORM+" and fades away.\n\n");
    say("\n"+tp+"'s sphere "+BOLD+"shimmers"+NORM+" and fades away.\n\n");
    call_other(TP,"add_spell_point",-100); 
    return 1; 
      }
      
   DARKNESS = clone_object("/players/saber/closed/bard/itm/sphere.c");
   move_object(DARKNESS, TP);
   
   call_other(TP,"add_spell_point",-100);
   return 1;
        }

  
  /* light vs illusions, spirits and dreams */
  
  if(LIGHT == "true")  {

  if(!INSTR->query_know_spell("light_true"))  {
    write("You have not yet learned the words for True Light.\n");
    return 1;
      }

  if(!LIGHT2 && TP->query_attack())  {
    LIGHT2 = TP->query_attack()->query_real_name();
        }

  if(!LIGHT2)  {
    write("What do you want to expose to True Light?\n");
    return 1;
      }
  
  if(!(HIT_LIGHT = present(LIGHT2, ENV)))  {
    write("There is no "+capitalize(LIGHT2)+" here.\n");
    return 1;
      }

  if(attack_spell(-50,11,35, HIT_LIGHT) == -1) return 0;

  if((!(call_other(HIT_LIGHT, "id", "spirit")))    &&
     (!(call_other(HIT_LIGHT, "id", "illusion")))  &&
     (!(call_other(HIT_LIGHT, "id", "dream")) )    &&
     (!(call_other(HIT_LIGHT, "id", "vampire")))   &&
     (!(call_other(HIT_LIGHT, "id", "ghost")))     &&
     (!(call_other(HIT_LIGHT, "id", "undead"))))  {
     
     write("True light will have no effect upon "+capitalize(LIGHT2)+".\n");
     return 1;
      }

if(COLOR) {
  write("\n"+
    "Pointing at "+lower_case(HIT_LIGHT->short())+", you invoke \""+BOLD+"Li soli hafu soske"+NORM+"\".\n"+
    "A ray of "+HIY+"pure light"+NORM+" flashes towards "+lower_case(HIT_LIGHT->short())+".\n\n");
  say("\n"+
    tp+" points at "+lower_case(HIT_LIGHT->short())+" and invokes \""+BOLD+"Li soli hafu soske"+NORM+"\".\n"+
    "A ray of "+HIY+"pure light"+NORM+" flashes towards "+lower_case(HIT_LIGHT->short())+".\n\n");

  }  else  {

  write("\n"+
    "Pointing at "+lower_case(HIT_LIGHT->short())+", you invoke \""+BOLD+"Li soli hafu soske"+NORM+"\".\n"+
    "A ray of pure light flashes towards "+lower_case(HIT_LIGHT->short())+".\n\n");
  say("\n"+
    tp+" points at "+lower_case(HIT_LIGHT->short())+" and invokes \""+BOLD+"Li soli hafu soske"+NORM+"\".\n"+
    "A ray of pure light flashes towards "+lower_case(HIT_LIGHT->short())+".\n\n");
        }

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe light fades away.\n\n");
    say("\n"+tp+"'s light fades away.\n\n");
    call_other(TP,"add_spell_point",-35); 
    return 1; 
      }

  CHANCE = random(5);
  
       if(CHANCE == 0) tell_room(ENV, HIT_LIGHT->short()+" screams in pain.\n\n");
  else if(CHANCE == 1) tell_room(ENV, HIT_LIGHT->short()+" staggers back a step.\n\n");
  else if(CHANCE == 2) tell_room(ENV, HIT_LIGHT->short()+" begins to burn.\n\n");
  else if(CHANCE == 3) tell_room(ENV, HIT_LIGHT->short()+"'s image wavers.\n\n");
  else if(CHANCE >  3) tell_room(ENV, HIT_LIGHT->short()+"'s skin begins to smoke.\n\n");

    TP->attack_object(HIT_LIGHT);
    if(living(HIT_LIGHT))  HIT_LIGHT->attack_object(TP);
    DAMAGE = TP->query_attrib("wil") + random(55);

    HIT_LIGHT->hit_player(DAMAGE);

   call_other(TP,"add_spell_point",-35);   
   return 1;
      }
 
  command("li", TP);
  return 1;
       }
