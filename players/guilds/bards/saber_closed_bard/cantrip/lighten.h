/* This cantrip will reduce the weight of an item by 1 (but will never
   give it a weight of less then 1) for 20 sp */

lighten(str)  {
object CANTRIP_TARG;

  if(spell(-50,0,20) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C17"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("What object do you wish to lighten?\n");
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

 if(CANTRIP_TARG->query_weight() < 2)  {
    write("Your cantrip can not make the "+str+" weigh any less.\n");
    return 1;
       }

 if(present("pro_from_cantrips", CANTRIP_TARG))  {
    tell_room(ENV,
      "The "+BOLD+"rune of mass"+NORM+" fizzles and then fade away.\n");
    write("The cantrip has failed.\n");
    call_other(TP, "add_spell_point", -20); 
    return 1;
          } 

    write("\nYou hum a quick tune.\n\n");
    say("\n"+tp+" hums a quick tune.\n\n");
   
    command("drop "+str, TP);
    
    CANTRIP_TARG->set_weight(CANTRIP_TARG->query_weight() - 1);

    write("You trace an inverted "+BOLD+"rune of mass"+NORM+".\n");
    say(tp+" traces an inverted "+BOLD+"rune of mass"+NORM+".\n");
    
    if(COLOR)  {
      tell_room(ENV,
        "\n"+CANTRIP_TARG->short()+" "+GRN+"glows softly"+NORM+".\n");
    }  else  {
      tell_room(ENV,
        "\n"+CANTRIP_TARG->short()+" glows softly.\n\n");
        }
   
     command("get "+str, TP);
     
     write("The "+str+" feels lighter.\n");
   
  call_other(TP, "add_spell_point", -20);
  return 1;
        }
