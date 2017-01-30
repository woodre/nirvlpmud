#include "../DEFS.h"


status main(string str)
{
  /* process for finishing off opponents
     attempts to counteract the inability of other attacks to kill */
  object ob;
  string name;
  int level, hp, cost;

  if(!str)
  {
    if(!TP->query_attack())
    {
      write("Usage: deathblow or db <monster>.\n");
      return 1; 
    }
    ob = (object)TP->query_attack();
  }
  if(str && !present(str, environment(TP)))
  {
     write("No "+capitalize(str)+" present.\n");
     return 1; 
  }
  if(!ob) ob = present(str, environment(TP));
  if(!call_other(COMBATD, "valid_attack", ob, TP))
  {
    write("You cannot use death blow on that!\n"); 
    return 1;
  }
  if(!present(ob, environment(TP)))
  { 
    write(BOLD+ob->query_name()+OFF+" is not present.\n");
    return 1;
  }
  name = RED+OPN+OFF;
  hp = (int)ob->query_hp();
  level = (int)IPTP->query_art_level() * 2;
  cost = hp * 2;
  if((int)TP->query_spell_point() < cost)
  {
    write("Low on power.\n"); 
    return 1;
  }

  if(hp <= level)
  {
    write(BOLD+RED+"You deal "+capitalize(name)+OFF+BOLD+RED+" a death blow!"+OFF+"\n");
    say(BOLD+RED+TPN+" deals "+capitalize(name)+OFF+BOLD+RED+" a death blow!"+OFF+"\n");
    TP->add_spell_point(-cost);
    ob->heal_self(-hp);
    ob->hit_player(level);
    return 1;
  }
  else write(capitalize(name)+" is too healthy to die.\n");
  return 1;
}
