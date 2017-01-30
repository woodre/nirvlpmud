/* This cantrip will keep a corpse from rotting */

preserve()  {
object CANTRIP_TARG;

  if(spell(-50,0,5,this_object()) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C20"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
    
  if(!(CANTRIP_TARG = present("corpse", TP)))  {
   if(!(CANTRIP_TARG = present("corpse", environment(TP))))  {
    write("There is no corpse here.\n");
    return 1;
          }
          }
              
  write("\nYou trace "+BOLD+"runes of preservation"+NORM+" on "+
           lower_case(CANTRIP_TARG->short())+"\n");
  say("\n"+tp+" traces "+BOLD+"runes of preservation"+NORM+" on "+
           lower_case(CANTRIP_TARG->short())+"\n");      
    
  if(present("pro_from_cantrips", CANTRIP_TARG))  {
    tell_room(ENV,
      "The "+BOLD+"runes of preservation"+NORM+" fizzle and then fade away.\n");
    write("The cantrip has failed.\n");
    call_other(TP, "add_spell_point", -5); 
    return 1;
          } 

  tell_room(ENV,
    "A whisp of vapor steams from "+lower_case(CANTRIP_TARG->short())+".\n");
  
  CANTRIP_TARG->set_heart_beat(0);
  
  ALI_CHANCE = random(100);
  
  if(ALI_CHANCE > 90)  {
    call_other(TP, "add_alignment", -random(25));
          }
      
  call_other(TP, "add_spell_point", -5); 
  return 1;
          }    
