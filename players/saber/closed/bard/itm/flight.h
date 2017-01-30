/*
 *  False Speak: False Light
 *
 *    Minor Illusion - Brief illusion
 *    Major Illusion - More detailed
 *    Send illusion - glorified faremote.
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

false_light(str)  {
string LIGHT, LIGHT2, LIGHT3, NAME, ALT_NAME, SHORT;
object TARG, TO_HIT, ILLUSION;

  if(!str)  {
    write("False light: < send > < mn > < mj >\n");
    return 1;
        }

  if(sscanf(str, "%s %s %s", LIGHT, LIGHT2, LIGHT3) < 3)  { 
  if(sscanf(str, "%s %s %s", LIGHT, LIGHT2) < 2)  { 
     sscanf(str, "%s", LIGHT); 
     }
     }

 if(LIGHT == "send")  {

  if(!INSTR->query_know_spell("false_send"))  {
    write("You have not yet learned the words for sending flase light.\n");
    return 1;
      }

  if(spell(-50,10,10) == -1) return 0;
  
  if(!LIGHT2 || !LIGHT3)  {
    write("Who will you send an image to?\n");
    write("Syntax: da <send > < player > < message >\n");
    return 1;
        }
   
  if(!(TARG = find_player(LIGHT2)))  {
    write(capitalize(LIGHT2)+" is not within the realms of magic.\n");
    return 1;
        }
   
  if(TARG->query_level() > 20 && TARG->query_name() != "Saber")  {
    write("Illusions are not seen by wizards.\n");
    return 1;
        }

  write("\nYou sing ");
  say("\n"+tp+" sings ");
  tell_room(ENV,"\""+BOLD+"Soun ski buskiya nuhi nuhidi loda rume pabu ripo yaka"+NORM+"\".\n");
        

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour illusion flutters and then fades away.\n\n");
   call_other(TP, "add_spell_point", -10);
    return 1; 
      }

  write("\nAn illusions appears before "+capitalize(LIGHT2)+".\n\n * "+LIGHT3+"\n\n"); 
  tell_object(TARG, "\nAn illusion from "+tp+" appears briefly before you, then is gone.\n\n"+
    LIGHT3+"\n");

   call_other(TP, "add_spell_point", -10);
   return 1;
   
        }


 if(LIGHT == "mr" || LIGHT == "MR")  {
  
  if(!INSTR->query_know_spell("false_minor"))  {
    write("You have not yet learned the words for minor illusion.\n");
    return 1;
      }

  if(sscanf(str, "%s %s %s %s", LIGHT, NAME, ALT_NAME, SHORT) < 4 )  {
    write("An illusion must be given shape and name.\n"+
          "Syntax: da mr < illusion_name > < illusion_nickname > < illusion_description >\n");
    write("For more help, type < lore > < illusion >\n");
    return 1;
       }
  
   if(spell(-50,8,20) == -1) return 0;
    
    if(!NAME || !ALT_NAME || !SHORT)  {
      write("An illusion must be given two names and a description.\n"+
            "Syntax: illusion mr < illusion_name > < illusion_nickname > < illusion_description >\n");
      return 1;
        }
     
  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou lose your focus.\n\n");
   call_other(TP, "add_spell_point", -20);
    return 1; 
      }

     ILLUSION = clone_object("/players/saber/closed/bard/itm/minor_illusion.c");
     ILLUSION->set_name(NAME);
     ILLUSION->set_alias(ALT_NAME);
     ILLUSION->set_short(SHORT);
     
     move_object(ILLUSION, ENV);
     
  if(COLOR)  {
     write("\nYou softly sing a minor song of "+HIM+"false light"+NORM+".\n"+
           "You recite \""+BOLD+"Awe loda dimo mehigu rupa ski meya"+NORM+"\"\n"+
           "You shape your song to form the image of "+HIM+lower_case(SHORT)+NORM+".\n\n");
        }  else  {
     write("\nYou softly sing a minor song of false light.\n"+
           "You recite \""+BOLD+"Awe loda dimo mehigu rupa ski meya"+NORM+"\"\n"+
           "You shape your song to form the image of "+lower_case(SHORT)+".\n\n");
       }

  if(LIGHT == "mr")  {
     say("\n"+tp+" softly sings \""+BOLD+"Awe loda dimo mehigu rupa ski meya"+NORM+"\"\n"+
         "Strands of "+HIM+"mist"+NORM+" gather, and begin to form a pattern.\n"+
         "The image of "+HIM+""+lower_case(SHORT)+""+NORM+" shimmers into view.\n");
        }  else  { 
     say(tp+" sings softly.\n");
        }

     call_other(TP, "add_spell_point", -20);
     return 1;
        }


 if(LIGHT == "mj" || LIGHT == "MJ")  {
  
  if(!INSTR->query_know_spell("false_illusion"))  {
    write("You have not yet learned the words for major illusion.\n");
    return 1;
      }

  if(sscanf(str, "%s %s %s %s", LIGHT, NAME, ALT_NAME, SHORT) < 4) {
    write("An illusion must be given shape and name.\n"+
          "Syntax: da mj < illusion_name > < illusion_nickname > < illusion_description >\n");
    write("For more help, type < lore > < illusion >\n");
    return 1;
       }
  
   if(spell(-50,12,35) == -1) return 0;
    
    if(!NAME || !ALT_NAME || !SHORT)  {
      write("An illusion must be given two names and a description.\n"+
            "Syntax: illusion mr < illusion_name > < illusion_nickname > < illusion_description >\n");
      return 1;
        }
     
  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou lose your focus.\n\n");
   call_other(TP, "add_spell_point", -35);
    return 1; 
      }

     ILLUSION = clone_object("/players/saber/closed/bard/itm/major_illusion.c");
     ILLUSION->set_name(NAME);
     ILLUSION->set_alias(ALT_NAME);
     ILLUSION->set_short(SHORT);
     
     move_object(ILLUSION, ENV);
     
  if(COLOR)  {
     write("\nYou softly sing a major song of "+HIM+"false light"+NORM+".\n"+
           "You recite \""+BOLD+"Awe reri soun loda dimo mehigu rupa ski meya"+NORM+"\"\n"+
           "You shape your song to form the image of "+HIM+lower_case(SHORT)+NORM+".\n\n");
        }  else  {
     write("\nYou softly sing a major song of false light.\n"+
           "You recite \""+BOLD+"Awe reri soun loda dimo mehigu rupa ski meya"+NORM+"\"\n"+
           "You shape your song to form the image of "+lower_case(SHORT)+".\n\n");
        }

  if(LIGHT == "mj")  {
     say("\n"+tp+" softly sings \""+BOLD+"Awe reri soun loda dimo mehigu rupa ski meya"+NORM+"\"\n"+
         "Strands of "+HIM+"mist"+NORM+" gather, and begin to form a pattern.\n"+
         "The image of "+HIM+""+lower_case(SHORT)+""+NORM+" shimmers into view.\n");
        }  else  { 
     say(tp+" sings softly.\n");
        }

     call_other(TP, "add_spell_point", -35);
     return 1;
        }
         
 
  command("da", TP);
  return 1;
       }
