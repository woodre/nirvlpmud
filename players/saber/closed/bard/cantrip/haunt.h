/* This cantrip will move an object into the room which will make it appear
   haunted.  The object id is < fear_obj > */

haunt()  {

  if(spell(-50,0,15) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C11"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  move_object(clone_object("/players/saber/closed/bard/itm/fear_obj.c"),environment(TP));

  write("You trace a minor "+BOLD+"rune"+NORM+" of fear in the air.\n");
  say(tp+" traces a "+BOLD+"rune"+NORM+" in the air.\n");

  call_other(TP,"add_spell_point",-15);
  return 1;
        }
