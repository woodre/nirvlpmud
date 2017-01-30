/*
 *  False Speak: Rename
 *
 *    Cover - Changes item desc
 *    Disappear - Makes an item invisible (removes it's short())
 *    Change - hide self
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

rename(str)  {
string RENAME, RENAME2;
string new_name, old_name, new_short, new_long, new_alias;
object TARG, ARMOR;

  if(!str)  {
    write("Rename: < cover > < disappear > < change >\n");
    return 1;
        }

  if(sscanf(str, "%s %s", RENAME, RENAME2) < 2)  { sscanf(str, "%s", RENAME); }

 
 if(RENAME == "cover" || RENAME == "Cover")  {


 if(!INSTR->query_know_spell("rename_cover"))  {
    write("You have not yet learned the words of covering.\n");
    return 1;
      }

 if(!str || sscanf(str, "%s %s %s %s %s | %s", RENAME, old_name, new_name, new_alias, new_short, new_long) < 6)  {
  write("Syntax: nu cover <current name> <new name> <nickname> <appearance> | <detailed desc>\n");
  return 1;
        }

  ARMOR = present(old_name, TP);
  
  if(!present(old_name, TP))  {
    write("You do not have a "+old_name+" to cover with illusion.\n");
    return 1;
        }

  if(spell(-50,9,20) ==-1)  return 0;

  write("\nYou whisper \""+BOLD+"Anu paco dimo mehigu rupa ski meya"+NORM+".\"\n");

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou lose your focus.\n\n");
   call_other(TP, "add_spell_point", -20);
    return 1; 
      }

  ARMOR->set_name(new_name);
  ARMOR->set_alias(new_alias);
  ARMOR->set_short(new_short);
  ARMOR->set_long(new_long+"\n");

 if(COLOR)  {
 
  write("\nYou rename the "+capitalize(old_name)+" with "+HIM+"illusion"+NORM+".\n"+
    "It now appears as '"+new_short+"'.\n\n");
        
        }  else  {
        
  write("\nYou rename the "+capitalize(old_name)+" with illusion.\n"+
    "It now appears as '"+new_short+"'.\n\n");
        }       

 if(RENAME == "cover")  {
  say("\n"+tp+" whispers \""+BOLD+"Anu paco dimo mehigu rupa ski meya"+NORM+".\"\n");
  say(tp+" changes "+POSS+" "+capitalize(old_name)+" into a "+capitalize(new_name)+".\n");
        }  else  {
  say(tp+" sings softly.\n");
        }

        
  call_other(TP, "add_spell_point", -20);
  return 1;
        }
        


 if(RENAME == "disappear" || RENAME == "Disappear")  {


 if(!INSTR->query_know_spell("rename_disappear"))  {
    write("You have not yet learned the words of disappearance.\n");
    return 1;
      }

 if(!RENAME2)  {
  write("Syntax: nu disappear < item >\n");
  return 1;
        }
  
  if(!(ARMOR = present(RENAME2, TP)))  {
    write("You do not have a "+RENAME2+" to make disappear.\n");
    return 1;
        }

  if(spell(-50,11,30) ==-1)  return 0;

  write("\nYou whisper \""+BOLD+"Anu paco rume pahi be mo meliwo ju mayado"+NORM+".\"\n");

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou lose your focus.\n\n");
   call_other(TP, "add_spell_point", -30);
    return 1; 
      }

  ARMOR->set_short();

 if(COLOR)  {
 
  write("\nYou rename the "+capitalize(RENAME2)+" with "+HIM+"illusion"+NORM+".\n"+
    "The \""+RENAME2+"\" shimmers and fades away.\n\n");
        
        }  else  {
        
  write("\nYou rename the "+capitalize(RENAME2)+" with illusion.\n"+
    "The \""+RENAME2+"\" shimmers and fades away.\n\n");
        }       

 if(RENAME == "disappear")  {
  say("\n"+tp+" whispers \""+BOLD+"Anu paco dimo mehigu rupa ski meya"+NORM+".\"\n");
  say(tp+"'s "+capitalize(RENAME2)+" shimmers and fades away.\n");
        }  else  {
  say(tp+" sings softly.\n");
        }


  call_other(TP, "add_spell_point", -30);
  return 1;
        }
        


 if(RENAME == "change" || RENAME == "Change")  {


 if(!INSTR->query_know_spell("rename_change"))  {
    write("You have not yet learned the words of change.\n");
    return 1;
      }

 if(!RENAME2)  {
  write("Syntax: nu change < item >\n");
  write("\nItems: stick, jacket, bottle\n");
  return 1;
        }
  
 if(RENAME2 != "stick" && RENAME2 != "jacket" &&
    RENAME2 != "bottle")  {
  write("Syntax: nu change < item >\n");
  write("\nItems: stick, jacket, bottle\n");
    return 1;
        }

  if(spell(-50,14,40) ==-1)  return 0;

  write("\nYou whisper\n\n"+
  "               \""+BOLD+"Ski anu paco paco ski skili be mo ananu"+NORM+"\"\n"+
  "               \""+BOLD+"Ju tosifu paco ski lalowo ananuwo"+NORM+"\"\n");

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou lose your focus.\n\n");
   call_other(TP, "add_spell_point", -40);
    return 1; 
      }

 if(COLOR)  {
 
  write("\nYou rename the "+capitalize(RENAME2)+" with "+HIM+"illusion"+NORM+".\n"+
        "You are now a \""+RENAME2+"\".\n\n");
  write("\nType \"shapechange\" to change back.\n\n");
        
        }  else  {
        
  write("\nYou rename yourself with the illusion of "+capitalize(RENAME2)+".\n"+
        "You are now a \""+RENAME2+"\".\n\n");
  write("\nType \"shapechange\" to change back.\n\n");
        }       

 if(RENAME == "change")  {
  say("\n"+tp+" whispers\n\n"+
  "               \""+BOLD+"Ski anu paco paco ski skili be mo ananu"+NORM+"\"\n"+
  "               \""+BOLD+"Ju tosifu paco ski lalowo ananuwo"+NORM+"\"\n\n");
  say(tp+"'s shapechanges into a "+capitalize(RENAME2)+".\n");
        }  else  {
  say(tp+" sings softly.\n");
        }

  ARMOR = clone_object("/players/saber/closed/bard/itm/shapechange.c");
  
       if(RENAME2 == "stick")  {
    ARMOR->set_name("stick");
    ARMOR->set_new_short("A stick");
    ARMOR->set_new_long("A short stick");
    }
  else if(RENAME2 == "jacket")  {
    ARMOR->set_name("jacket");
    ARMOR->set_new_short("A leather jacket");
    ARMOR->set_new_long("A leather jacket");
    }
  else if(RENAME2 == "bottle")  {
    ARMOR->set_name("bottle");
    ARMOR->set_new_short("An empty bottle");
    ARMOR->set_new_long("An empty bottle");
    }
  
  move_object(ARMOR, ENV);
  move_object(TP, ARMOR);

  call_other(TP, "add_spell_point", -40);
  return 1;
        }
       
 
  command("nu", TP);
  return 1;
       }
