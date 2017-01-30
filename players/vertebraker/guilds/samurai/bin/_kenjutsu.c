#include "../def.h"

cmd_kenjutsu(str)
{
  object atk;
  int    cost;
  string msg, rmsg, omsg;
  object gob;
  
 gob=previous_object();
 if(TP->query_guild_rank() < 1) return 0;
  if(!(atk=this_player()->query_attack()))
  {
    write("You must be in combat.\n");
    return 1;
  }
  if(TP->query_ghost()) return 0;
  if(!TP->query_weapon())
  {
    write("You must be wielding a weapon!\n");
    return 1;
  }
  
 if(gob->query_beating()) return 1;
 if(TP->query_spell_dam()) return 1;
  cost = this_player()->query_guild_rank() * 5;
  if(cost < 15) cost = 15; /* Let's make it a touch less useless at low levels - ill Jun 2011 */
  if(cost > 50) cost = 50;
  
  if(this_player()->query_sp() < cost)
  {
    write("You need more energy. ["+cost+"]\n");
    return 1;
  }
  
  switch(random(12))
  {
    case 0:
      msg = "You "+BOLD+"hack and slash"+NORM+" into "+atk->QN+".\n";
      rmsg = TP->QN+" "+BOLD+"hacks and slashes"+NORM+" into "+atk->QN+".\n";
      omsg = TP->QN+" "+BOLD+"hacks and slashes"+NORM+" into you.\n";
      break;
    case 1:
      msg = "You "+RED+"slice"+NORM+" a deep wound into "+atk->QN+".\n";
      rmsg = TP->QN+" "+RED+"slices"+NORM+" a deep wound into "+atk->QN+".\n";
      omsg = TP->QN+" "+RED+"slices"+NORM+" a deep wound into you.\n";
      break;
    case 2:
      msg = "You "+HIW+"gash"+NORM+" open "+atk->QN+"!\n";
      rmsg = TP->QN+" "+HIW+"gashes"+NORM+" open "+atk->QN+"!\n";
      omsg = TP->QN+" "+HIW+"gashes"+NORM+" you open!\n";
      break;
    case 3:
      msg = "You split "+atk->QN+" apart with a massive slash.\n";
      rmsg = TP->QN+" splits "+atk->QN+" apart with a massive slash.\n";
      omsg = TP->QN+" splits you open with a massive slash.\n";
      break;
    case 4:
      msg = "You carve a deep "+BOLD+"slit"+NORM+" into "+atk->QN+".\n";
      rmsg = TP->QN+" carves a deep "+BOLD+"slit"+NORM+" into "+atk->QN+".\n";
      omsg = TP->QN+" carves a deep "+BOLD+"slit"+NORM+" into you.\n";
      break;
    case 5:
      msg = "You "+BOLD+"cleave"+NORM+" pieces from "+atk->QN+".\n";
      rmsg = TP->QN+" "+BOLD+"cleaves"+NORM+" pieces from "+atk->QN+".\n";
      omsg = TP->QN+" "+BOLD+"cleaves"+NORM+" pieces from you.\n";
      break;
    case 6:
      msg = "You "+BOLD+"cut"+NORM+" deeply into "+atk->QN+".\n";
      rmsg = TP->QN+" "+BOLD+"cuts"+NORM+" deeply into "+atk->QN+".\n";
      omsg = TP->QN+" "+BOLD+"cuts"+NORM+" deeply into you.\n";
      break;
    case 7:
      msg = "You "+HIW+"dissect"+NORM+" "+atk->QN+" into tiny, gibbering pieces.\n";
      rmsg = TP->QN+" "+HIW+"dissects"+NORM+" "+atk->QN+" into tiny, gibbering pieces.\n";
      omsg = TP->QN+" "+HIW+"dissects"+NORM+" you into tiny, gibbering pieces.\n";
      break;
    case 8:
      msg = "You "+HIW+"incise"+NORM+" "+atk->QN+", revealing flesh.\n";
      rmsg = TP->QN+" "+HIW+"incises"+NORM+" "+atk->QN+", revealing flesh.\n";
      omsg = TP->QN+" "+HIW+"incises"+NORM+" you, revealing flesh.\n";
      break;
    case 9:
      msg = "You "+RED+"slice"+NORM+" deep into "+atk->QN+"'s flesh\n"+
            "as a fine "+RED+"red mist"+NORM+" sprays around the room.\n";
      rmsg = TP->QN+" "+RED+"slices"+NORM+" deep into "+atk->QN+"'s flesh\n"+
            "as a fine "+RED+"red mist"+NORM+" sprays around the room.\n";
      omsg = TP->QN+" "+RED+"slices"+NORM+" deep into your flesh\n"+
            "as a fine "+RED+"red mist"+NORM+" sprays around the room.\n";
      break;
    case 10:
      msg = "You spin around fast, slashing your enemy across the cheek\n"+
            "as "+RED+"blood"+NORM+" slowly drips from "+possessive(atk)+" chin.\n";
      rmsg = TP->QN+" spins around fast, slashing "+possessive(TP)+" enemy across the cheek\n"+
            "as "+RED+"blood"+NORM+" slowly drips from "+possessive(atk)+" chin.\n";
      omsg = TP->QN+" spins around fast, slashing you across the cheek\n"+
            "as "+RED+"blood"+NORM+" slowly drips from "+possessive(atk)+" chin.\n";
      break;
    case 11:
      msg = "A fearsome scream is let out as you "+HIW+"Slash"+NORM+" violently at\n"+
            "your victim, leaving them standing in a pool of "+RED+"blood"+NORM+".\n";
     rmsg = "A fearsome scream is let out as "+TP->QN+" "+HIW+"Slashes"+NORM+" violently at\n"+
            possessive(TP)+" victim, leaving "+objective(atk)+" standing in a pool of "+RED+"blood"+NORM+".\n";
     omsg = "A fearsome scream is let out as "+TP->QN+" "+HIW+"Slashes"+NORM+" violently at\n"+
            "you, leaving you standing in a pool of "+RED+"blood"+NORM+".\n";            
      break;
  }
  
  this_player()->spell_object(atk,
  "slash",
/* This has to be the least efficient damage spell on the mud - illarion 6.15.2010
 random(cost) - (gob->query_shame() * 5),
*/
/* lowering damage a bit more, and moving the spell_dtype call to where it actually does something - ill 6.15.11
 cost/2 + random(cost) - (gob->query_shame() * 5),
*/
  cost/3 + random(2 * cost / 3) - (gob->query_shame() * 5),
  cost,
  msg,
  omsg,
  rmsg);
  this_player()->set_spell_dtype("magical");
  return 1;
}
