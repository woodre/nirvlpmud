/* This cantrip will move an object into the room which will 'RING' when the
   next player enters it */


alarm()  {
object STONE;

  if(spell(-50,0,5) ==-1) return 0;
  
  if(!INSTR->query_cantrip("C1"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }

  move_object(clone_object("/players/saber/closed/bard/itm/alarm.c"),environment(TP));

  write("\nYou spin in a circle and whisper the word \"\Alarm\"\.\n\n");
  say("\n"+tp+" spins in a circle and whispers the word \"\Alarm\"\.\n\n");
  command("alarm_on", TP);

  call_other(TP,"add_spell_point",-5);
  return 1;
        }
