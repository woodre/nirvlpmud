/* This cantrip will add 15 intox points to the player, for the cost of 5-20 coins */

intox()  {

  if(spell(-50,0,5,this_object()) == -1) return 0;

  if(!INSTR->query_cantrip("C14"))  {
    write("You have not yet learned this cantrip.\n");
    return 1;
      }

  if(((TP->query_attrib("int")+TP->query_attrib("wil"))*2)+LEVEL<random(102) )
    { write("Your cantrip fails.\n"); 
      call_other(TP,"add_spell_point",-random(15)); 
      return 1; }
  
  COINS = 5 + random(15);

  if(TP->query_money() < COINS)  {
    write("You need a few coins to do that...\n");
    return 1;
          }
        
  if((TP->query_intoxination()) > (15 + TP->query_level()))  {
    write("You are too intoxicated to trace runes.\n");
    return 1;
          }
  
  if(COLOR)  {
    write("You trace magical symbols in the air with your little finger.\n"+
      "You are surrounded by a "+MAG+"dull purple aura"+NORM+".\n");
    say(tp+" traces magical symbols in the air with "+POSS+" little finger.\n"+
      tp+" is surrounded by a "+MAG+"dull purple aura"+NORM+".\n");
      }  else  {
    write("You trace magical symbols in the air with your little finger.\n"+
      "You are surrounded by a dull purple aura.\n");
    say(tp+" traces magical symbols in the air with "+POSS+" little finger.\n"+
      tp+" is surrounded by a dull purple aura.\n");
            }
    
    if((TP->query_intoxination()) > (TP->query_level() * 2))  {
      write("You feel drunk.\n");
      say(tp+" looks drunk.\n");
            }
    
  call_other(TP, "drink_alcohol", 15);
  call_other(TP, "add_money", - COINS);
  call_other(TP, "add_spell_point", -5);
  return 1;
  
        }
