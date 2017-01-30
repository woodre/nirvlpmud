/* This cantrip will move an object to the bardic charity room */

charity(str)  {
object CANTRIP_TARG;

  if(spell(-50,0,3,this_object()) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C4"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("What do you want to send to the charity room?\n");
    return 1;
          }
  
  if(!(CANTRIP_TARG = present(str, TP)))  {
    write("You don't have a "+str+" to send to the charity room.\n");
    return 1;
          }

 if(call_other(CANTRIP_TARG, "drop", 0))  {
    write("\nYour cantrip is not that powerful.\n\n");
    return 1;
       }
            
  write("\nYou hiss as you drop "+lower_case(CANTRIP_TARG->short())+" to the ground.\n");
  say("\n"+tp+" hisses.\n");

  command("drop "+CANTRIP_TARG, TP);

  tell_room(environment(TP),
    "\nA sudden gust of wind blows "+lower_case(CANTRIP_TARG->short())+" from the room.\n");
  
  move_object(CANTRIP_TARG, "/players/saber/closed/bard/r/charity.c");
  tell_room(environment(CANTRIP_TARG),
    "\n"+CANTRIP_TARG->short()+" falls from the sky.\n");
   
  ALI_CHANCE = random(100);
  
    if(ALI_CHANCE > 90)  {
      call_other(TP, "add_alignment", random(25));
          }
  
  call_other(TP, "add_spell_point", -3); 
  return 1;
          }
