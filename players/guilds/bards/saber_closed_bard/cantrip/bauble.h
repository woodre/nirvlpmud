/* This cantrip will make a bauble.  This is a fun, but useless, cantrip. */

bauble()  {

  if(spell(-50,0,3,this_object()) == -1)  return 0;
  
    if(!INSTR->query_cantrip("C2"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
      
    move_object(clone_object("/players/saber/closed/bard/itm/bauble.c"),this_player());

    if(COLOR)  {
      write("\nYou murmur strange syllables which flow softly over your tongue.\n"+
        "A solid bauble of "+MAG+"light"+NORM+" materializes in your hand.\n\n");
      say("\n"+tp+" murmurs strange syllables which flow softly over "+POSS+" tongue.\n"+
        "A solid bauble of "+MAG+"light"+NORM+" materializes in "+tp+"'s hand.\n\n");
    }  else  {
      write("\nYou murmur strange syllables which flow softly over your tongue.\n"+
        "A solid bauble of light materializes in your hand.\n\n");
      say("\n"+tp+" murmurs strange syllables which flow softly over "+POSS+" tongue.\n"+
        "A solid bauble of light materializes in "+tp+"'s hand.\n\n");
    }
        
  call_other(TP, "add_spell_point", -3);
  return 1;
        }
