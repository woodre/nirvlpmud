/*
 *  True Speak: Seek
 *
 *    Light - how bright?
 *    False - detects illusions
 *    Disease - detects disease
 *    WOP - who has cool weapons
 *    Armor - basic stats of creatures
 *    Find - gives 'short' for room an item is in
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

seek(str)  {
string SEEK, SEEK2, ARMORS, WEAPONS, LEVELS;
int CHECK_LIGHT, D_CHECK, ARMOR, WEAPON, HEALTH;
object MARK, MARKER;

  if(!str)  {
    write("Seek: < light > < false > < disease > < wop > < armor >\n");
    return 1;
        }

  if(sscanf(str, "%s %s", SEEK, SEEK2) < 2)  { sscanf(str, "%s", SEEK); }  


  /*  Detect brightness of room  */
  
if(SEEK == "light")  {

  if(spell(-50,8,5) == -1)  return 0;        

  if(!INSTR->query_know_spell("seek_light"))  {
    write("You have not yet learned the words which seek light.\n");
    return 1;
      }
  
    write("\nYou whisper \""+BOLD+"Meske noko soli"+NORM+"\" as you glance around.\n");
    say("\n"+tp+" whispers \""+BOLD+"Meske noko soli"+NORM+"\" as "+PRO+" glances around.\n");   


  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour seeking fails.\n\n");
    say(tp+" blinks.\n");
    call_other(TP,"add_spell_point",-5); 
    return 1; 
      }
      
  CHECK_LIGHT = ENV->query_light();
  write("Light = "+CHECK_LIGHT+".\n");

  call_other(TP, "add_spell_points", -5);
  return 1; 
        }

 
  /* seek illusions, spirits and dreams */
  
  if(SEEK == "false")  {

  if(!INSTR->query_know_spell("seek_false"))  {
    write("You have not yet learned the words which seek false light.\n");
    return 1;
      }

  if(spell(-50,8,5) == -1) return 0;

   write("\nYou whisper \""+BOLD+"Meske noko loda"+NORM+"\" as you glance around.\n");
   say("\n"+tp+" whispers \""+BOLD+"Meske noko loda"+NORM+"\" as "+PRO+" glances around.\n");   

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour seeking fails.\n\n");
    say(tp+" blinks.\n");
    call_other(TP,"add_spell_point",-5); 
    return 1; 
      }

  MARK = first_inventory(ENV);
  D_CHECK = 0;
  
  while(MARK)  {
  
  if((call_other(MARK, "id", "spirit"))    ||
     (call_other(MARK, "id", "illusion"))  ||
     (call_other(MARK, "id", "dream"))     ||
     (call_other(MARK, "id", "vampire"))   ||
     (call_other(MARK, "id", "ghost"))     ||
     (call_other(MARK, "id", "undead")))  {


         write(BOLD+MARK->short()+NORM+" radiates false light.\n");
         D_CHECK = 1;
    
        }

    MARK = next_inventory(MARK);
    
        }
        
   if(D_CHECK < 1)  {
     write("No creatures radiate false light.\n");
        }  

   write("\n");

   call_other(TP,"add_spell_point",-5);   
   return 1;
      }

 
 
  /* seek disease and poison */
  
  if(SEEK == "disease")  {

  if(!INSTR->query_know_spell("seek_disease"))  {
    write("You have not yet learned the words which seek disease.\n");
    return 1;
      }

  if(spell(-50,8,5) == -1) return 0;

   write("\nYou whisper \""+BOLD+"Meske noko jusoli reri yosko"+NORM+"\" as you glance around.\n");
   say("\n"+tp+" whispers \""+BOLD+"Meske noko jusoli reri yosko"+NORM+"\" as "+PRO+" glances around.\n");   

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour seeking fails.\n\n");
    say(tp+" blinks.\n");
    call_other(TP,"add_spell_point",-5); 
    return 1; 
      }

  MARK = first_inventory(ENV);
  D_CHECK = 0;
  
  if(present("poison", ENV))  {
    write("There is poison in the room.\n");
      }
  
  if(present("disease", ENV)) {
    write("There is disease in the room.\n");
      }

  while(MARK)  {
  
    if(present("disease", MARK) || present("flu", MARK))  {
         write(BOLD+MARK->query_name()+NORM+" radiates disease.\n");
         D_CHECK = 1;
         }

    if(present("poison", MARK))  {
         write(BOLD+MARK->query_name()+NORM+" radiates poison.\n");
         D_CHECK = 1;
         }

    if(MARK->query_frog())  {
         write(BOLD+MARK->query_name()+NORM+" is a frog!\n");
         }
    
    MARK = next_inventory(MARK);
    
        }
        
   if(D_CHECK < 1)  {
     write("There is no poison or disease in your area.\n");
        }  

   write("\n");

   call_other(TP,"add_spell_point",-5);   
   return 1;
      }


  /* seek weapons of power */
  
  if(SEEK == "wop")  {

  if(!INSTR->query_know_spell("seek_wop"))  {
    write("You have not yet learned the words which seek weapons of power.\n");
    return 1;
      }

  if(spell(-50,8,5) == -1) return 0;

   write("\nYou whisper \""+BOLD+"Meske noko wegi bucryya"+NORM+"\" as you glance around.\n");
   say("\n"+tp+" whispers \""+BOLD+"Meske noko wegi bucryya"+NORM+"\" as "+PRO+" glances around.\n");   

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour seeking fails.\n\n");
    say(tp+" blinks.\n");
    call_other(TP,"add_spell_point",-5); 
    return 1; 
      }

  MARK = first_inventory(ENV);
  D_CHECK = 0;
  
  while(MARK)  {
  
    if(living(MARK))  {
 
      MARKER = first_inventory(MARK);
      
        while(MARKER)  {
        
          if(MARKER->weapon_class() > 15)  {
            write(BOLD+MARKER->short()+NORM+" is a weapon of power.\n");
            D_CHECK = 1;  }
        
        MARKER = next_inventory(MARKER);
       }
    
       }  else  {
       
    if(MARK->weapon_class() > 15)  {
        write(BOLD+MARK->short()+NORM+" is a weapon of power.\n");
        D_CHECK = 1; }
        
       }

    MARK = next_inventory(MARK);
    
       }
        
   if(D_CHECK < 1)  {
     write("There are no weapons of power in your area.\n");
        }  

   write("\n");

   call_other(TP,"add_spell_point",-5);   
   return 1;
      }


  /* seek armorment */
  
  if(SEEK == "armor")  {

  if(!INSTR->query_know_spell("seek_armor"))  {
    write("You have not yet learned the words which seek armorment.\n");
    return 1;
      }

  if(spell(-50,8,5) == -1) return 0;

   write("\nYou whisper \""+BOLD+"Meske noko te mo cryya reri bucryya"+NORM+"\" as you glance around.\n\n");
   say("\n"+tp+" whispers \""+BOLD+"Meske noko te mo cryya reri bucryya"+NORM+"\" as "+PRO+" glances around.\n");   

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour seeking fails.\n\n");
    say(tp+" blinks.\n");
    call_other(TP,"add_spell_point",-5); 
    return 1; 
      }

  MARK = first_inventory(ENV);
  
  while(MARK)  {
  
    if(living(MARK))  {
 
      ARMOR  = MARK->query_ac();
      WEAPON = MARK->query_wc();
      HEALTH = MARK->query_hp() * 100 / MARK->query_mhp();

            if(ARMOR < 3)                ARMORS = "pitiful";
       else if(ARMOR > 2  && ARMOR < 5)  ARMORS = "poor";
       else if(ARMOR > 4  && ARMOR < 8)  ARMORS = "average";
       else if(ARMOR > 7  && ARMOR < 12) ARMORS = "good";
       else if(ARMOR > 11 && ARMOR < 16) ARMORS = "excellent";
       else if(ARMOR > 15)               ARMORS = "amazing";
 
            if(WEAPON < 5)                 WEAPONS = "pitiful";
       else if(WEAPON > 4  && WEAPON < 11) WEAPONS = "poor";
       else if(WEAPON > 10 && WEAPON < 15) WEAPONS = "average";
       else if(WEAPON > 14 && WEAPON < 19) WEAPONS = "good";
       else if(WEAPON > 18 && WEAPON < 25) WEAPONS = "excellent";
       else if(WEAPON > 26)                WEAPONS = "amazing";

      if(MARK == TP)  {
      write(BOLD+"You"+NORM+" have "+ARMORS+" armor, "+WEAPONS+
            " weaponry and are at "+HEALTH+" % health.\n");       
        } else {
      
      if(MARK->is_player())  {
      write(BOLD+MARK->query_name()+NORM+" has "+ARMORS+" armor, "+WEAPONS+
            " weaponry and is at "+HEALTH+" % health.\n");
        }  else  {
      write(BOLD+MARK->short()+NORM+" has "+ARMORS+" armor, "+WEAPONS+
            " weaponry and is at "+HEALTH+" % health.\n");

        }
        }        
 
        }

    MARK = next_inventory(MARK);
    
        }

   write("\n");

   call_other(TP,"add_spell_point",-5);   
   return 1;
      }


 /* seek to find where item is */
  
  if(SEEK == "find")  {

  if(!INSTR->query_know_spell("seek_find"))  {
    write("You have not yet learned the words which seek and find.\n");
    return 1;
      }

 if(!SEEK2)  {
   write("What do you wish to locate within the realms of magic?\n");
   write("Syntax: seek < item / person / monster >\n");
   return 1;
       }

  if(spell(-50,8,5) == -1) return 0;

   write("\nYou whisper \""+BOLD+"Meske noko te mo cryya reri bucryya"+NORM+"\" as you glance around.\n\n");
   say("\n"+tp+" whispers \""+BOLD+"Meske noko te mo cryya reri bucryya"+NORM+"\" as "+PRO+" glances around.\n");   

   write("You send forth your music into the realms of magic in search of \""+
          SEEK2+"\".\n\n");
   write("The notes fly through the sky");
 
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe notes of music do not return.\n\n");
    say(tp+" blinks.\n");
    call_other(TP,"add_spell_point",-5); 
    return 1; 
      }

 if(MARK = present(SEEK2, TP))  {
   write(" and then return to you.\n"+
         "The notes of music land on you and begin to "+BOLD+"glow"+NORM+".\n");
         }

 else if(MARK = present(SEEK2, ENV))  {
   write(" and then return.\n"+
         "The notes of music dance about the room and begin to "+BOLD+"glow"+NORM+".\n");
        }

 else if(MARK = find_player(SEEK2))  {
  write(" and and then return.\n\n");
  write("The notes begin to sing, telling you that\n\t");
  write(capitalize(SEEK2)+" can be found in '"+call_other(environment(MARK),"short")+"'.\n\n");
        }

 else if(MARK = find_living(SEEK2))  {
  write(" and and then return.\n\n");
  write("The notes begin to sing, telling you that\n\t");
  write(capitalize(SEEK2)+" can be found in '"+call_other(environment(MARK),"short")+"'.\n\n");
        }

 else if(MARK = find_object(SEEK2))  {
  write(" and and then return.\n\n");
  write("The notes begin to sing, telling you that\n\t");
  write(capitalize(SEEK2)+" can be found in '"+call_other(environment(MARK), "short")+"'.\n\n");
       }

 else if(!MARK)  {
  write(" and and then return.\n\n");
  write("The notes begin to sing, telling you that they can find no\n");
  write("active traces of "+capitalize(SEEK2)+" within the realms of magic.\n\n");
       }

  call_other(TP,"add_spell_point", -5);
  return 1;
        }
        

  command("ske", TP);
  return 1;
       }
