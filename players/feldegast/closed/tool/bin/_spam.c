#include "/players/feldegast/defines.h"
do_cmd(str)
{
  object target;
  string spam;
  int i;

  notify_fail("Usage: spam <player>\n");
  if(!str) return 0;
  target=find_player(str);
  notify_fail("Player not found.\n");
  if(!target) return 0;
  for(i=0; i < 400; i++)
  {
    switch(random(33))
    {
      case 0: spam+=HIB; break;
      case 1: spam+=HIR; break;
      case 2: spam+=HIY; break;
      case 3: spam+=HIG; break;
      case 4: spam+=HIM; break;
      case 5: spam+=BLU; break;
      case 6: spam+=RED; break;
      case 7: spam+=YEL; break;
      case 8: spam+=GRN; break;
      case 9: spam+=MAG; break;
      case 10: spam+="***********"; break;
      case 11: spam+="#############"; break;
      case 12: spam+="@@@@@@@@@@@@@"; break;
      case 13: spam+="XXXXXXXXXXXXX"; break;
      case 14: spam+="%%%%%%%%%%%%%"; break;
      case 15: spam+="LOVE"; break;
      case 16: spam+="HATE"; break;
      case 17: spam+="FEAR"; break;
      case 18: spam+="LUST"; break;
      case 19: spam+="APATHY"; break;
      case 20: spam+="HONOR"; break;
      case 21: spam+="CONFUSION"; break;
      case 22: spam+="FIRE"; break;
      case 23: spam+="WATER"; break;
      case 24: spam+="EARTH"; break;
      case 25: spam+="AIR"; break;
      case 26: spam+="ORDER"; break;
      case 27: spam+="CHAOS"; break;
      case 28: spam+="DEMOCRACY"; break;
      case 29: spam+="TYRANNY"; break;
      case 30: spam+="THERECANBEONLYONE"; break;
      case 31: spam+="WAR"; break;
      case 32: spam+="PEACE"; break;
    }
  }
  spam+=NORM+"\n";
  write("You spammed "+target->query_name()+".\n");
  tell_object(target,spam);
  return 1;
}
