/*
 *  False Speak: Calm
 *
 *    Silence - stops talking
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

calm(str)  {
string CALM, CALM2;
object TARG, SILENCE;

  if(!str)  {
    write("Calm: < silence >\n");
    return 1;
        }

  if(sscanf(str, "%s %s", CALM, CALM2) < 2)  { sscanf(str, "%s", CALM); }
 
  /* Silence area */
  
  if(CALM == "silence")  {

  if(!INSTR->query_know_spell("calm_silence"))  {
    write("You have not yet learned the words for calming silence.\n");
    return 1;
      }
  
  if(present("aura_of_silence",TP))  {
    write("There is already a wall of silence here.\n");
    return 1;
        }
  
  if(spell(-50,13,50) == -1)  return 0;
           
  write("\nHolding your hands above your head, you spread your finger wide.\n");
  write("You sing \"                             \"\n"); 
  say("\n"+tp+" holds "+POSS+" hands above "+POSS+" and spreads "+POSS+" fingers wide\n");
  say(tp+" sings \"                             \"\n"); 

  tell_room(ENV, "\nAn "+BOLD+"Aura of Silence"+NORM+" engulfs the room.\n\n");
   
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nThe aura of silene fades away.\n\n");
    say("\n"+tp+"'s aura of silence fades away.\n\n");
    call_other(TP,"add_spell_point",-50); 
    return 1; 
      }
      
   SILENCE = clone_object("itm/silence.c");
   move_object(SILENCE, ENV);
   
   call_other(TP,"add_spell_point",-50);
   return 1;
        }
 
  command("ca", TP);
  return 1;
       }
