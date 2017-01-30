/* This cantrip will add a 'leap' message to the movement message */

leap()  {

  if(spell(-50,0,10,this_object()) == -1)  return 0;
  
  if(!INSTR->query_cantrip("C16"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
    move_object(clone_object("/players/saber/closed/bard/itm/jump.c"),
                this_player());
    
    write("\nYou whistle a light tune as you trace a "+BOLD+"rune of movement"+NORM+".\n"+
        "Your legs feel strong!\n\n");
    say("\n"+tp+" whistle a light tune as "+PRO+" traces a "+BOLD+"rune of movement"+NORM+".\n\n");

  call_other(TP, "add_spell_point", -10);
  return 1;
        }
