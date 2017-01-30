/* This cantrip will put a tag of ownership on an item */

mark(str)  {
object CANTRIP_TARG;

  if(spell(-50,0,5,this_object()) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C18"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
    write("Syntax: cantrip mark < item >\n");
    return 1;
      }
  
  if(!(CANTRIP_TARG = present(str, TP)))  {
    write("You don't have a "+str+" to inscribe your rune upon.\n");
    return 1;
          }
            
  write("\nYou trace the "+BOLD+"runes"+NORM+" for your name in the air.\n"+
        "Holding up "+lower_case(CANTRIP_TARG->short())+", you softly blow the glowings runes towards it.\n"+
        "The runes \""+BOLD+""+tp+""+NORM+"\"\ inscribe themselves on "+lower_case(CANTRIP_TARG->short())+".\n"); 
  say("\n"+tp+" traces the "+BOLD+"runes"+NORM+" for "+POSS+" name in the air.\n"+
      tp+" holds up "+lower_case(CANTRIP_TARG->short())+" and blows the glowing runes towards it.\n"+
      "The runes \""+BOLD+""+tp+""+NORM+"\"\ inscribe themselves on "+lower_case(CANTRIP_TARG->short())+".\n");      
    
  CANTRIP_TARG->set_long(CANTRIP_TARG->long()+"\n"+
     "Runes spelling \""+BOLD+""+tp+""+NORM+"\" gleam in the light.\n");
     
  call_other(TP, "add_spell_point", -5); 
  return 1;
          }
