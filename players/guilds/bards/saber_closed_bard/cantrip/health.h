/* This cantrip will render the bard immune to catching (but will not dispel
   existing) any disease for a limited time */

health()  {

  if(spell(-50,0,20) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C12"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  move_object(clone_object("/players/saber/closed/bard/itm/no_disease.c"),TP);

  if(COLOR)  {
  write("\nUsing three fingers, you trace a "+BLU+"rune of health"+NORM+".\n\n");
  say("\n"+tp+" traces the three fingered "+BLU+"rune of health"+NORM+".\n\n");
    }  else  {
  write("\nUsing three fingers, you trace a rune of health.\n\n");
  say("\n"+tp+" traces the three fingered rune of health.\n\n");
        }

  call_other(TP,"add_spell_point",-20);
  return 1;
        }
