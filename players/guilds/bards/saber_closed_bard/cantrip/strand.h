/* This cantrip will summon a strand of chaos.  The strand can be used
   in the bardic magic of shaping */

strand()  {

  if(spell(-50,0,5) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C24"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  move_object(clone_object("/players/saber/closed/bard/itm/strand.c"),TP);

  if(COLOR)  {
  write("\nYou reach through reality and grasp a strand of "+BOLD+"chaos"+NORM+".\n\n");
  say("\n"+tp+" reaches through reality and pulls forth a strand of "+BOLD+"chaos"+NORM+".\n\n");
    }  else  {
  write("\nYou reach through reality and grasp a strand of chaos.\n\n");
  say("\n"+tp+" reaches through reality and pulls forth a strand of chaos.\n\n");
        }

  call_other(TP,"add_spell_point",-5);
  return 1;
        }
