#include "../defs.h"
#define DIV 300000

object worn_by;
int damage;

int id(string str)
{
  return str=="crystalskin";
}

string extra_look()
{
  return CYN+(string)worn_by->query_name() + " is protected by a sheathe of crystal armor"+NORM;
}

string short()
{
  if((int)TP->query_level() > 20)
    return "Crystalskin [dam = "+damage+"]";
}

void start(object ob)
{
  mixed stats;
  stats = ({ "physical", 2, 0, "do_special" });
  ob->RegisterArmor(stats, this_object());
  worn_by = ob;
  return;
}

void stop()
{
  worn_by->RemoveArmor(this_object());
  return;
}

int do_special(object owner)
{
  if(damage++ > random(DIV))
  {
    tell_object(owner, HIR+"Your crystal skin shatters!\n"+NORM);
    owner->hit_player(random(80));
    stop();
    destruct(this_object());
    return 0;
  }
}

void remove_object(object ob)
{
  stop();
}
