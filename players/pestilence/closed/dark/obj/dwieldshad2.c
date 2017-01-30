#include "/players/pestilence/closed/dark/defs.h"
#include "/players/pestilence/ansi.h"
#define TP     this_player()
#define QN     query_name()
#define ENV    environment

object sh, weapon;
int   wt;

reset(arg) {
 if(arg || root()) return;

 call_out("end_it", 900+random(900));

}

load_it(s)
{
  sh = s;
  if(!sh->query_hit_func())
  {
    sh->set_hit_func(this_object());
    wt = 1;
  }
  shadow(sh, 1);
}


drop(str) {
  sh->drop(str);
  end_it();
  return 0; }

un_wield() {
  sh->un_wield();
  end_it();
  return 1; }

is_shrouded() {
  return 1;
}

short()
{
return sh->short()+" (enshrouded with "+HIR+"H A T R E D"+NORM+")";
}

weapon_hit(atk)
{
  if(!random(6))
  {
    tell_room(ENV(ENV(sh)),
      HIK+BLINK+"H A T R E D"+NORM+" pours out from the "+NORM+upper_case(sh->query_name())+NORM+"\n");
  if(atk)
    atk->hit_player(1+random(4), "other|evil");
  }
  return sh->weapon_hit(atk);
}

end_it()
{
  tell_object(ENV(sh),
   HIK+BLINK+"Hatred"+NORM+" subsides from "+sh->query_name()+".\n");
  if(wt)
  {
    sh->set_hit_func(sh);
  }
  destruct(this_object());
}

query_no_clean() { return 1; }

get() {
  if(this_player()->query_guild_name() != "Dark Order")
   {
    tell_room(ENV(TP), TP->QN+" feels the hatred from "+sh->query_name()+"!\n");
     TP->hit_player(50+random(50),"other|fire");
  }
  return sh->get();
}
