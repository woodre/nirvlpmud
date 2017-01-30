/*
 *  False Speak: Distort
 *
 *    Bind: temp lowering of monster ac/wc
 *    Confusion: Monsters attacks self for a bit
 *
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


distort(str)  {
object TARG, MARK, DOPP;
string BIND, BIND2;
int NEW_AC, WC, AC;
  
  if(!str)  { str = TPQ; }

  if(sscanf(str, "%s %d", BIND, BIND2) < 2)  { sscanf(str, "%s", BIND); } 

  
  /* Binding */

  if(BIND == "bind")  {
  
  if(!INSTR->query_know_spell("distort_bind"))  {
    write("You have not yet learned the words of spectral binding.\n");
    return 1;
      }

  if(attack_spell(-50,9,30) == -1) return 0;

  if(!BIND2)  {
    write("\nSyntax: bind < monster >\n\n");
    return 1;
       }
  
  if(!(TARG = present(BIND2, ENV)))  {
    write("\nYou must see the creature to spectral bind.\n");
    write("Syntax: bind < creature >\n\n");
    return 1;
        }

  /* Can't bind if True Name has been done */
  if(present("true_name", TARG))  {
    write(TARG->short()+" has been bound by it's "+BOLD+"True Name"+NORM+".\n"+
          TARG->query_name()+" can not be effected by illusions.\n");
    return 1;
        }
        
  /* Give target item to keep track of org ac and wc */
  if(!present("bind_mark", TARG))  {
    MARK = clone_object("/players/saber/closed/bard/itm/bind_mark.c");
    move_object(MARK, TARG);

        }  else  {
        
    write(TARG->query_name()+" has already been bound.\n");
    return 1;
        }

  write("\nLooking at "+TARG->query_name()+", you play a waltz on your "+INST+"\n"+
        "You whisper \""+BOLD+"Ski soun koko meso di loda"+NORM+"\"\n");

  say("\n"+tp+" looks at "+TARG->query_name()+" as "+PRO+" plays a waltz on "+POSS+
         " "+INST+"\n"+
         tp+" whispers \""+BOLD+"Ski soun koko meso di loda"+NORM+"\"\n");

 if(COLOR)  {
  tell_room(ENV,
      "\nWaves of slow, ethereal music coalesces around "+TARG->query_name()+".\n\n"+
      "The music "+BOLD+"solidifies"+NORM+", fettering "+TARG->query_name()+
       " in "+HIM+"illusionary"+NORM+" chains.\n\n");
       
    }  else  {
  tell_room(ENV,
      "Waves of slow, ethereal music coalesces around "+TARG->query_name()+".\n\n"+
      "The music solidifies, fettering "+TARG->query_name()+" in illusionary chains.\n\n");
    }

  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour "+BOLD+"spectral chains"+NORM+" fade away.\n\n");
    say("\nThe "+BOLD+"spectral chains"+NORM+
                " surrounding "+lower_case(TARG->short())+" fade away.\n\n");
    call_other(TP,"add_spell_point",-35); 
    return 1; 
      }

    NEW_AC = (TARG->query_ac() * 2) / 3;

    if(NEW_AC < (TARG->query_wc() - 4))  NEW_AC = TARG->query_ac() - 4;

    MARK->set_org_ac(TARG->query_ac());  TARG->set_ac(NEW_AC);
    MARK->set_master(TPQ);
  
  move_object(MARK, TARG);

  call_other(TP, "add_spell_point", -30);
  return 1;

      }

  
  /* Confusion */

  if(BIND == "confusion" || BIND == "confuse" || BIND == "con")  {
  
  if(!INSTR->query_know_spell("distort_confusion"))  {
    write("You have not yet learned the words of confusion.\n");
    return 1;
      }

  if(attack_spell(-50,13,35) == -1) return 0;

  if(!BIND2)  {
    write("\nSyntax: gi confuse < monster >\n\n");
    return 1;
       }
  
  if(!(TARG = present(BIND2, ENV)))  {
    write("\nYou must see the creature to confuse it.\n");
    write("Syntax: confuse < creature >\n\n");
    return 1;
        }
        
  /* Give target item to keep track of damage */
  if(!present("confuse_mark", TARG))  {
    MARK = clone_object("/players/saber/closed/bard/itm/confuse_mark.c");
    move_object(MARK, TARG);

        }  else  {
        
    write(TARG->query_name()+" is already confused.\n");
    return 1;
        }

  write("\nLooking at "+TARG->query_name()+", you sings\n\n");

  say("\n"+tp+" looks at "+TARG->query_name()+" as "+PRO+" sings\n\n");

  tell_room(ENV,
          "           \""+BOLD+"Gure koko cabu mo crysea ju soli"+NORM+"\"\n\n"+
          "           \""+BOLD+"Te koko fadateya kokoski be juwe"+NORM+"\"\n\n");


  if(10 + (TP->query_attrib("int") * 4) + ((1 + BLVL) / 6) < random(100) )  {
    write("\nYour fumble over the words.\n\n");
    say("\n"+tp+" fumbles over the words.\n\n");
    call_other(TP,"add_hit_point",-25);
    call_other(TP,"add_spell_point",-35); 
    return 1; 
      }

    tell_room(ENV, TARG->query_name()+" looks confused.\n");
    

    DOPP = clone_object("/players/saber/closed/bard/itm/dopp.c");
        
    if(living(TARG))  TARG->attack_object(DOPP);

    WC = TARG->query_wc();  AC = TARG->query_ac();

    MARK->set_org_wc(WC);  TARG->set_wc(0);
    MARK->set_master(TPQ);
    
    DOPP->set_master(TPQ);  DOPP->set_how_long(TP->query_attrib("wil"));
    DOPP->set_dummy(lower_case(TARG->query_name()));
    DOPP->set_org_wc(WC);   DOPP->set_org_ac(AC);  

  call_other(TP, "add_hit_point", -25);
  call_other(TP, "add_spell_point", -35);
  return 1;

      }
      
        
  command("gi", TP);
  return 1;
       }
