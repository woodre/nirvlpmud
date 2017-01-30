#include "/players/fred/defs.h"
#include "/players/fred/ansi.h"
inherit "obj/monster";
#define ON owner->query_name()
#define MEAT TO->query_attack()
#define MEATN MEAT->query_name()
object owner;
int x,y,q;
string eggs;

reset(arg)
{
  ::reset();
  if(arg) return;
  set_race("ryo");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_gender("male");
  set_hp(150);
  set_dead_ob(TO);
  set_name("ryo");
  set_ep(1);
  q = random(8);
  switch(q)
  {
    case 0: eggs = "fat"; break;
    case 1: eggs = "large"; break;
    case 2: eggs = "mutated"; break;
    case 3: eggs = "deformed"; break;
    case 4: eggs = "deranged"; break;
    case 5: eggs = "enraged"; break;
    case 6: eggs = "enslaved"; break;
    case 7: eggs = "devious"; break;
  }
}



short()
{
  return "A "+eggs+" ryo";
}

long()
{
  write("A "+eggs+" ryo that has been bound to "+ON+" until the end of time.\n");
}

id(str)
{
  return str == "bf_ryo" || str == "bf_mob" || str == "ryo";
}

query_bf_ryo(){ return 1; }

patch_owner(o)
{
  owner = o;
}

query_owner()
{
  return owner;
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  if(!owner) return;
  if(owner && owner->query_ghost() && (x < 1))
  {
    tell_room(environment(owner),
      TO->short()+", noticing his fallen master, realizes he is now free.\n");
      call_out("go", 5);
  }
  if(owner && !owner->query_ghost())
  {
    if(ENV(TO) != ENV(owner))
    {
      say(capitalize(TO->short())+" shuffles after "+ON+".\n");
      MO(TO, ENV(owner));
      write(capitalize(TO->short())+" shuffles in after "+ON+".\n");
      set_heart_beat(1);
    }
    if(owner->query_attack() && !MEAT && !random(50))
    {
      tell_room(environment(owner),
        TO->short()+" screams in anger as it charges into battle...\n");
      attacker_ob = owner->query_attack();
    }
    if(!owner->query_attack())
    {
      int stat,foo,doubly;
      stat = owner->query_attrib("luc");
      foo = owner->query_attrib("cha");
      doubly = stat + foo;
      if(random(doubly) < 15)
      {
        tell_object(owner,
          TO->short()+"'s eye's burn "+RED+"red"+NORM+" with hatred...\n"+
          "Longing to be free "+TO->short()+" charges at you!\n");
        tell_room(environment(owner),
          TO->short()+"'s eye's burn "+RED+"red"+NORM+" with hatred...\n"+
          "Longing to be free "+TO->short()+" charges at "+ON+"!\n", ({ owner }));
        attacker_ob = owner;
        return;
      }
      if(!owner->query_weapon())
      {
        tell_object(owner,
          "Your "+BOLD+BLU+"weapon"+NORM+" pulsates with light absorbing "+TO->short()+" back into the gem.\n");
        tell_room(environment(owner),
          ON+"'s "+BOLD+BLU+"weapon"+NORM+" pulsates with light absorbing "+TO->short()+" back into it.\n", ({ owner }));
        move_object(TO, "/room/void");
        destruct(TO);   
      }
      tell_object(owner,
        "Your "+BOLD+BLU+owner->query_weapon()->query_name()+NORM+" pulsates with light absorbing "+TO->short()+" back into the gem.\n");
      tell_room(environment(owner),
        ON+"'s "+BOLD+BLU+owner->query_weapon()->query_name()+NORM+" pulsates with light absorbing "+TO->short()+" back into it.\n", ({ owner }));
      move_object(TO, "/room/void");
      destruct(TO);
    }
  }
}

go()
{
  tell_room(environemt(TO),
    TO->short()+" lets out blood curdling roar that echoes off in the distance.\n");
  call_out("go2", 3);
}

go2()
{
  tell_room(environment(TO),
    TO->short()+" shuffles out of the room...\n");
  move_object(TO, "/room/void");
  destruct(TO);
}
   
  