/* This cantrip will increase the weight of an item by 1 for 5 sp */

weight(str)  {
object CANTRIP_TARG;

  if(spell(-50,0,5) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C28"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("What item do you wish to make heavy?\n");
    return 1;
            }

  if(!(CANTRIP_TARG = present(str, TP)))    {
    write("\nYou are not holding a "+str+".\n\n");
    return 1;
            }

 if(call_other(CANTRIP_TARG, "drop", 0))  {
    write("\nYour cantrip is not powerful enough to effect the "+str+".\n\n");
    return 1;
       }

 if(present("pro_from_cantrips", CANTRIP_TARG))  {
    tell_room(ENV,
      "The "+BOLD+"rune of mass"+NORM+" fizzles and then fade away.\n");
    write("The cantrip has failed.\n");
    call_other(TP, "add_spell_point", -5); 
    return 1;
          } 

    write("\nYou hum a slow tune.\n\n");
    say("\n"+tp+" hums a slow tune.\n\n");
   
    command("drop "+str, TP);
    
    CANTRIP_TARG->set_weight(CANTRIP_TARG->query_weight() + 1);

    write("You trace a "+BOLD+"rune of mass"+NORM+".\n");
    say(tp+" traces a "+BOLD+"rune of mass"+NORM+".\n");
    
    if(COLOR)  {
      tell_room(ENV,
        "\n"+CANTRIP_TARG->short()+" "+GRN+"glows softly"+NORM+".\n");
    }  else  {
      tell_room(ENV,
        "\n"+CANTRIP_TARG->short()+" glows softly.\n\n");
        }
   
     command("get "+str, TP);
     
     write("The "+str+" feels heavier.\n");
   
  call_other(TP, "add_spell_point", -5);
  return 1;
        }
