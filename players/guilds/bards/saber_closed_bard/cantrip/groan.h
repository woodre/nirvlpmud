/* This cantrip will summon an object <id: groan_obj> into the room.  The object
   will make groaning noises for a few min and then fade away. */

groan()  {

  if(spell(-50,0,15) == -1)  return 0;

  if(!INSTR->query_cantrip("C10"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  move_object(clone_object("/players/saber/closed/bard/itm/groan.c"),environment(TP));
  
  write("You groan as you trace subtle runes upon the ground.\n");
  say(tp+" doubles over and groans in pain.\n");
            
  call_other(TP, "add_spell_point", -15);
  return 1;
        }  
