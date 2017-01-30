/* This cantrip will create a bubble (aka light source) */

bubble()  {

  if(spell(-50,0,10,this_object()) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C3"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }

  move_object(clone_object("/players/saber/closed/bard/itm/bubble.c"),this_player());

  if(COLOR)  {
    write("\nYou utter a single sharp syllable.\n"+
      "A solid sphere of "+HIB+"blue light"+NORM+" appears in your hand.\n\n");
    say("\n"+tp+" utters a single sharp syllable.\n"+
      "A solid sphere of "+HIB+"blue light"+NORM+" appears in "+POSS+" hand.\n\n");
      }  else  {
    write("\nYou utter a single sharp syllable.\n"+
      "A solid sphere of blue light appears in your hand.\n\n");
    say("\n"+tp+" utters a single sharp syllable.\n"+
      "A solid sphere of blue light appears in "+POSS+" hand.\n\n");
            }
            
  call_other(TP, "add_spell_point", -10);
  return 1;
        }       
