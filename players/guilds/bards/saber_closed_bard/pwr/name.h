/*
 *  True Speak: Naming
 *
 *    Agony - Stop healing on monster while bard is present
 *    True Name - wil+random(60) damage and lower target wc/ac
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

name(str)  {
object TARG, NO_HEAL, MARK, TRUE_NAME;
string NAME, NAME2;
int AMOUNT, OLD_WC, NEW_WC, NEW_AC;

  if(!str)  {
    write("Name: < agony > < true >\n");
    return 1;
        }

  if(sscanf(str, "%s %s", NAME, NAME2) < 2)  { sscanf(str, "%s", NAME); }  


  /* Stop healing */
  
  if(NAME == "agony")  {

  if(!INSTR->query_know_spell("name_agony"))  {
    write("You have not yet learned the words of Agony.\n");
    return 1;
      }
  
  if(!NAME2)  {
    write("What creature will you speak the words of Agony to?\n"+
          "Syntax: na agony < target >\n");
    return 1;
        }
  
  if(!(TARG = present(NAME2, ENV)))  {
    write("There is no "+capitalize(NAME2)+" here.\n");
    return 1;
      }

  if(attack_spell(-50,10,15,TARG) == -1) return 0;
            
 if(present("heal_stop", TARG))  {
   write(TARG->query_name()+" is already in Agony.\n");
   return 1;
      }
 
 if(COLOR)  {
   write("\nPlaying a "+HIR+"dissonant chord"+NORM+" upon your "+INST+", you sing:\n\n");
   say("\nPlaying a "+HIR+"dissonant chord"+NORM+" upon "+POSS+" "+INST+
          ", "+tp+" sings:\n\n");
 
        }  else  {
 
   write("\nPlaying a dissonant chord upon your "+INST+", you sing:\n\n");
   say("\nPlaying a dissonant chord upon "+POSS+" "+INSTR+", "+tp+" sings:\n\n");  
        }
   
   tell_room(ENV, "      \""+BOLD+"Nuhi koko a ski soun koko"+NORM+"\"\n"+
                  "      \""+BOLD+"Lahe un hihi koko da"+NORM+"\"\n");

   tell_room(ENV, "\nA "+BOLD+"black aura"+NORM+" settles over "
                        +lower_case(TARG->short())+".\n\n");

   
  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou mispronounce the words.\n\n");
    say(tp+" stumbles over the words.\n\n");
    call_other(TP,"add_spell_point",-15); 
    return 1; 
      }
      
   call_other(TARG, "set_heal", 0,100);

   NO_HEAL = clone_object("/players/saber/closed/bard/itm/noheal.c");
   NO_HEAL->set_master(TPQ);
   move_object(NO_HEAL, TARG);
   
   call_other(TP,"add_spell_point",-15);
   return 1;
        }

  
  /* true name */
  
  if(NAME == "true")  {

  if(!INSTR->query_know_spell("true_name"))  {
    write("You have not yet learned the words of True Naming.\n");
    return 1;
      }

  if(!NAME2)  {
    write("\nSyntax: true_name < monster >\n\n");
    return 1;
       }
  
  if(!(TARG = present(NAME2, ENV)))  {
    write("\nYou must see the creature to speak its "+BOLD+"True Name"+NORM+".\n");
    write("Syntax: true_name < creature >\n\n");
    return 1;
        }

  if(attack_spell(-50,14,100, TARG) == -1) return 0;

  if(present("true_name", TARG))  {
    write("The "+BOLD+"True Name"+NORM+" of a creature may onld be commanded once.\n");
    return 1;
        }

  tell_room( ENV, "\n\n");
  write("You whisper "+TARG->query_name()+", \""+BOLD+
        "Nuhi koko li a ski soun koko mo ski"+NORM+"\"\n");

  say(tp+" whispers "+TARG->query_name()+", \""+BOLD+
        "Nuhi koko li a ski soun koko mo ski"+NORM+"\"\n");

  if(10 + (TP->query_attrib("wil") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYou mispronounce the creatures True Name.\n\n");
    say("\n"+tp+" stubles over the words.\n\n");
    call_other(TP,"add_spell_point",-100); 
    return 1; 
      }

  tell_room( ENV, "You watch as "+TARG->query_name()+" writhes in"+BOLD+"\n\n");
  tell_room( ENV,
    "                  *\n"+
    "                *  *\n"+
    "              *    *\n"+
    "             * ** *   ****  *****  ****   *   *\n"+
    "            *    *   *  *   *   *   *  *   *   *\n"+
    "           *    *   *  *    *   *    *  *   *   *\n");
  tell_room( ENV,
    "          *    *   * **     *****     *  *   *****\n"+
    "                     *                            *\n"+
    "                    *                       *      *\n"+
    "               *****                       **********\n\n");
  tell_room( ENV,
    "                                "+NORM+"at the sound of its TRUE NAME."+NORM+"\n\n\n");

  TP->attack_object(TARG);
  TARG->hit_player(25+random(50));
  if(living(TARG))  TARG->attack_object(TP);

  TRUE_NAME = clone_object("/players/saber/closed/bard/itm/true_name.c");

  if(MARK = present("bind_mark", TARG))  {
    NEW_WC = (MARK->query_org_wc() * 3) / 4;
    NEW_AC = (MARK->query_org_ac() * 2) / 3;

    if(NEW_WC < (MARK->query_org_wc() - 7))  NEW_WC = MARK->query_org_wc() - 7;
    if(NEW_AC < (MARK->query_org_wc() - 4))  NEW_AC = MARK->query_org_ac() - 4;
  
    TRUE_NAME->set_org_ac(MARK->query_org_ac());
    TRUE_NAME->set_org_wc(MARK->query_org_wc());
    TRUE_NAME->set_master(TPQ);
    
    destruct(MARK);

      }  else  {

    NEW_WC = (TARG->query_wc() * 3) / 4;
    NEW_AC = (TARG->query_ac() * 2) / 3;

    if(NEW_WC < (TARG->query_wc() - 7))  NEW_WC = TARG->query_wc() - 7;
    if(NEW_AC < (TARG->query_wc() - 4))  NEW_AC = TARG->query_ac() - 4;

    TRUE_NAME->set_org_ac(TARG->query_ac());
    TRUE_NAME->set_org_wc(TARG->query_wc());
    TRUE_NAME->set_master(TPQ);

        }
    
  TARG->set_ac(NEW_AC);   TARG->set_wc(NEW_WC);
  
  move_object(TRUE_NAME, TARG);

  call_other(TP, "add_spell_point", -100);
  return 1;

      }
 
  command("na", TP);
  return 1;
       }
