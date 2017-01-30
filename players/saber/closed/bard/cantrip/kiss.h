/* This cantrip will put the 'frog curse' upon a monster. */


kiss(str)  {
object CANTRIP_TARG;

  if(!INSTR->query_cantrip("C15"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("What creature do you want to curse?\n");
    return 1;
        }
  
  if(!(CANTRIP_TARG = present(str, ENV)))  {
    write("You do not see "+capitalize(str)+".\n");
    return 1;
        }
  
  if(attack_spell(-50,0,20,CANTRIP_TARG) == -1) return 0;
        
  write("\nYou point at "+lower_case(CANTRIP_TARG->short())+" as you"+
        " trace a "+BOLD+"rune of alteration"+NORM+"\n");
  say("\n"+tp+" points at "+lower_case(CANTRIP_TARG->short())+" as "+
      PRO+" traces a "+BOLD+"rune of alteration"+NORM+"\n");
  
  if(present("pro_from_cant", CANTRIP_TARG))  { 
    tell_room(ENV, HIB+"Runes of blue"+NORM+" flash to life around "+
              lower_case(CANTRIP_TARG->short())+".\n"+
              "The "+BOLD+"rune of alteration"+NORM+" fails.\n");
    call_other(TP, "add_spell_point", -20); 
    return 1;
          }

  tell_room(ENV,
    CANTRIP_TARG->short()+" shimmers a little, and then returns to normal.\n\n");  
  
  CANTRIP_TARG->set_frog(1);
          
  call_other(TP, "add_spell_point", -20); 
  return 1;
        }
