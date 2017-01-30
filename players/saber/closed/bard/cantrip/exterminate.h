/* Exterminate is a cantrip which will kill any creature with 5 or less hp */

exterminate(str)  {
object CANTRIP_TARG;

  if(!INSTR->query_cantrip("C7"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("\nWhat creature would you like to exterminate?\n\n");
    return 1;
          }
        
  if(!(CANTRIP_TARG = present(str, environment(TP))))    {
    write("\nThere is no "+str+" here to exterminate.\n\n");
    return 1;
          }

  if(attack_spell(-50,0,10,CANTRIP_TARG) == -1) return 0;

  if(CANTRIP_TARG->query_hp() > 5)  {
    write("You sense that "+capitalize(str)+" has too much lifeforce to be exterminated.\n");
    return 1;
          }
  
  write("\nYou point at "+capitalize(str)+" and say \""+BOLD+"DIE"+NORM+"\".\n");
  say("\n"+tp+" points at "+capitalize(str)+" and says \""+BOLD+"DIE"+NORM+"\".\n");

  if(present("pro_from_cantrips", CANTRIP_TARG))  {
    tell_room(ENV,
      "\nA series of "+HIB+"runes"+NORM+" flare to life before "+capitalize(str)+".\n"+
      "The exterminate cantrip fails.\n");
     call_other(TP, "add_spell_point", -10); 
    return 1;
          } 

  CANTRIP_TARG->hit_player(40);
  
  ALI_CHANCE = random(100);
  
  if(ALI_CHANCE > 90)  {
    call_other(TP, "add_alignment", -random(25));
          }
  
  call_other(TP, "add_spell_point", -10);
  return 1;
        }
