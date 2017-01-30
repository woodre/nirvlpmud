/* This cantrip will protect the Bard from cantrips. */

protect(str)  {
object CANTRIP_TARG;

  if(spell(-50,0,25) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C21"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  if(!str)  {
     str = TPQ;
    }

  if(!(CANTRIP_TARG = present(str, TP)))  {
   if(!(CANTRIP_TARG = present(str, environment(TP))))  {
    write("There is no "+str+" here.\n");
    return 1;
          }
          }
 
    move_object(clone_object("/players/saber/closed/bard/itm/pro_from_cant.c"),
                CANTRIP_TARG);
    
    if(COLOR)  {
      write("\nUsing two fingers, you trace a "+HIB+"blue rune"+NORM+" of warding.\n"+
            "You are now protected from cantrips.\n\n");
      say("\n"+tp+" traces a "+HIB+"blue rune"+NORM+" of warding.\n");
    }  else  {
      write("\nUsing two fingers, you trace a blue rune of warding.\n"+
            "You are now protected from cantrips.\n\n");
      say("\n"+tp+" traces a blue rune of warding.\n");
    }
      
  call_other(TP, "add_spell_point", -25);
  return 1;
        }
