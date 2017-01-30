#include "/players/sado/guild/std.h"

int time;
object hastee;

init()
{
  add_action("quit","quit");
}

quit(str)
{
  remove_call_out("haste");
  destruct(this_object());
  return 0;
}

id(str)
{
  return str=="hastener";
}

set_hastee(who)
{
  hastee=who;
}

start_haste()
{
  time=40;
  tell_object(hastee,"You suddenly feel your heart rate accelerate.\n");
  haste();
  haste();
}

freek_out()
{
  int i;
  i=random(3);
  if(i==0) command("bounce",hastee);
  else if(i==1) command("flip",hastee);
  else command("dance",hastee);
}

haste()
{
  if(!hastee)
    {
      destruct(this_object());
      return 0;
    }
  time--;
  if(time) call_out("haste",1);
  else
    {
      tell_object(hastee,"You feel your heart rate slow to normal again.\n");
      destruct(this_object());
    }
  if(random(4)==1) freek_out();
  tell_object(hastee,"Calling 3 HBs in " + hastee->query_name() + "\n");
  if(this_player() != hastee) set_this_player(hastee);
  hastee->heart_beat();
  hastee->heart_beat();
  hastee->heart_beat();
}
