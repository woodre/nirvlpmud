#include "/players/fred/defs.h"
#include "/players/fred/ansi.h"
inherit "obj/monster";
#define ON owner->query_name()
#define ORN owner->query_real_name()
#define MEAT TO->query_attack()
#define MEATN MEAT->query_name()
object owner;
int x,y,q, bye,ok;
string eggs;

reset(arg)
{
  ::reset();
  if(arg) return;
  set_race("faerie");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_gender("female");
  set_hp(150);
  set_dead_ob(TO);
  set_name("faerie");
  set_ep(1);
  q = random(8);
  ok = 1;
  switch(q)
  {
    case 0: eggs = "floating"; break;
    case 1: eggs = "fluttering"; break;
    case 2: eggs = "smiling"; break;
    case 3: eggs = "laughing"; break;
    case 4: eggs = "twinkling"; break;
    case 5: eggs = "glowing"; break;
    case 6: eggs = "silly"; break;
    case 7: eggs = "swooping"; break;
  }
  call_out("time_to_go", 300);
}



short()
{
  return "A tiny "+eggs+" faerie";
}

long()
{
  write("A tiny "+eggs+" faerie that follows "+ON+" around to help out.\n");
}

id(str)
{
  return str == "bf_faerie" || str == "bf_mob" || str == "faerie";
}

query_bf_faerie(){ return 1; }

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
  if(owner && find_player(ORN))
  {
    bye = 0;
  }
  else
  {
    bye += 1;
  }

  if(bye > 10 && ok)
  {
    call_out("alone", 4);
    ok = 0;
  }

  if(owner && owner->query_ghost() && (x < 1))
  {
    tell_room(environment(owner),
      TO->short()+", looks shocked about the death of it's beloved owner, "+ON+".\n");
      call_out("go", 5);
  }
  if(owner && !owner->query_ghost())
  {
    if(ENV(TO) != ENV(owner))
    {
      say(capitalize(TO->short())+" flies after "+ON+".\n");
      MO(TO, ENV(owner));
      write(capitalize(TO->short())+" flies in after "+ON+".\n");
      set_heart_beat(1);
    }
    if(owner->query_attack() && !MEAT)
    {
      if(!random(30))
      {
        tell_object(owner,
          TO->short()+CYN+" giggles"+NORM+" inanely as she casts a "+CYN+"healing"+NORM+" spell on you.\n");
        tell_room(environment(owner),
          TO->short()+CYN+" giggles"+NORM+" inanely as she casts a "+CYN+"healing"+NORM+" spell on "+ON+"\n", ({ owner }));  
        owner->heal_self(random(3)); 
     }  
    }
  }
}

go()
{
  tell_room(environment(TO),
    "Weeping softly the "+TO->short()+" flies off into the sky...\n");
  move_object(TO, "/room/void");
  destruct(TO);
}
   
alone()
{
  tell_room(environment(TO),
    "Sadly looking around for it's owner, "+TO->short()+" flies off into the sky...\n");
  move_object(TO, "/room/void");
  destruct(TO);
}

time_to_go()
{
  tell_room(environment(TO),
     TO->short()+" looks frightened and flies off into the sky.\n");
  move_object(TO, "/room/void");
  destruct(TO);
}
