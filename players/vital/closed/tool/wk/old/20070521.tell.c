#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str)
{
  int x;
  object who;
  string foo, foo2, color;
  x = (random(13)+1);
  switch(x)
  {
    case 1: color = RED; break;
    case 2: color = YEL; break;
    case 3: color = GRN; break;
    case 4: color = BLU; break;
    case 5: color = CYN; break;
    case 6: color = MAG; break;
    case 7: color = HIR; break;
    case 8: color = HIY; break;
    case 9: color = HIG; break;
    case 10: color = HIB; break;
    case 11: color = HIC; break;
    case 12: color = HIM; break;
    case 13: color = HIW; break;
  }
  if(!str || sscanf(str, "%s %s", foo, foo2) != 2) return 0;
  if(!(who = find_player(foo)))
  {
    write("Player not found.\n");
    return 1;
  }
  if(who->query_invis() > 99) { write("Player not found.\n"); return 1; }
  if(in_editor(who)) write(capitalize(foo)+" is editing.\n");
  if(!who->query_interactive()) write(capitalize(foo)+" is disconnected.\n");
  else if(query_idle(who) > 120) write(capitalize(foo)+" is idle.\n");
  if(who->query_level() < 20 && this_player()->query_invis()) 
  {
    who->add_tellhistory("Someone tells you: "+foo2);
    tell_object(who,format(color+"Someone tells you: "+NORM+foo2,70));
  }
  else
  {
    who->add_tellhistory("Vital tells you: "+foo2);
    tell_object(who,format(color+"Vital tells you: "+NORM+foo2,70));
    write(format("You tell "+color+capitalize(foo)+NORM+": "+foo2,70));
    who->Replyer("vital");
  }
  return 1;
}

get_help()
{
  string help;
  help = "A Private Tell";
  return help;
}
