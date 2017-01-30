/* This cantrip will scare monsters of less then level three from the room. */    

spook(str)  {
object CANTRIP_TARG;

  if(!INSTR->query_cantrip("C23"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("What do you want to spook?\n");
    return 1;
        }
  
  if(!(CANTRIP_TARG = present(str, ENV)))  {
    write("You do not see "+capitalize(str)+" here to spook.\n");
    return 1;
        }
  
  if(attack_spell(-50,0,15,CANTRIP_TARG) == -1) return 0;
        
  write("\nYou glare at "+lower_case(CANTRIP_TARG->short())+" and say \"\BOO\"\!\n");
  say("\n"+tp+" glares at "+lower_case(CANTRIP_TARG->short())+" and says \"\BOO\"\!\n");
  
  if(CANTRIP_TARG->query_level() < 4  && !present("pro_from_cant", CANTRIP_TARG))  { 
    tell_room(ENV,
      CANTRIP_TARG->short()+" blinks in unmitigated terror.\n\n");
    CANTRIP_TARG->run_away();
    }  else  {
  tell_room(ENV,
    CANTRIP_TARG->short()+" blinks in confusion at "+tp+".\n");
          }
          
  call_other(TP, "add_spell_point", -15); 
  return 1;
        }
