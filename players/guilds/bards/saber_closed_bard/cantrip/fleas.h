/* This cantrip will give a monster 'scratching' talk */


fleas(str)  {
object CANTRIP_TARG;
int CANTRIP_INT;

  if(!INSTR->query_cantrip("C9"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("What do you want to put fleas on?\n");
    return 1;
        }
  
  if(!(CANTRIP_TARG = present(str, ENV)))  {
    write("You do not see "+capitalize(str)+" put fleas on.\n");
    return 1;
        }
  
  if(attack_spell(-50,0,5,CANTRIP_TARG) == -1) return 0;
        
  write("\nYou glance at "+lower_case(CANTRIP_TARG->short())+" as you"+
        " trace a "+BOLD+"rune of summoning"+NORM+"\n");
  say("\n"+tp+" glances at "+lower_case(CANTRIP_TARG->short())+" as "+
      PRO+" traces a "+BOLD+"rune of summoning"+NORM+"\n");
  
  tell_room(ENV,
    "Hundreds of tiny black specks appear on "+lower_case(CANTRIP_TARG->short())+"\n\n");
  
  if(present("pro_from_cant", CANTRIP_TARG))  { 
    tell_room(ENV, HIB+"Runes of blue"+NORM+" flash suddenly around "+
              lower_case(CANTRIP_TARG->short())+".\n"+
              "The black specks melt away.\n");
    call_other(TP, "add_spell_point", -5); 
    return 1;
          }
  
  CANTRIP_TARG->load_chat(CANTRIP_TARG->query_name()+" scratches for fleas.\n");
  CANTRIP_TARG->load_a_chat(CANTRIP_TARG->query_name()+" scratches for fleas.\n");
  
  CANTRIP_INT = random(100);
  
  if(CANTRIP_INT > 94)  {
      CANTRIP_TARG->set_ac(CANTRIP_TARG->query_ac() - 1);
      tell_room(ENV, CANTRIP_TARG->short()+" scratches for fleas.\n");
          }
        
  call_other(TP, "add_spell_point", -5); 
  return 1;
        }
