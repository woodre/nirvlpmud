/* This cantrip will move an object into the room which will inform the caster
   when a player enters the room */

inform()  {

  if(spell(-50,0,15) ==-1) return 0;
  
    if(!INSTR->query_cantrip("C13"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  move_object(clone_object("/players/saber/closed/bard/itm/inform.c"),environment(TP));

  write("\nYou spin in a circle and whisper the word \"Inform\".\n\n");
  say("\n"+tp+" spins in a circle and whispers the word \"Inform\".\n\n");
  command("inform_on", TP);

  call_other(TP,"add_spell_point",-15);
  return 1;
        }
