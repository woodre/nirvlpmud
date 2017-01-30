#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "obj/monster";

int Y;

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("gargawaine");
  set_short(RED+"Gargawaine"+NORM);
  set_alias("shaman");
  set_race("giant");
  set_long(
"     This twelve foot tall giant hunches over slightly, making it\n\
difficult to discern its true height. Bones and skulls and other\n\
grisly trophies hang from the shaman's belt. A crackling aura of\n\
energy emanates from this powerful being. His eyes gleem with red\n\
hatred and wicked intensity. \n");
  set_hp(1000);
  set_level(30);
  set_al(0);
  set_wc(60);
  set_ac(30);
  set_aggressive(0);
  set_chance(30);
  set_spell_dam(80);
  set_spell_mess1(RED+"Flames"+NORM+" leap from the hands of the shaman, engulfing its opponent.\n");
  set_spell_mess2(RED+"Flames"+NORM+" leap from the hands of the shaman, engulfing you.\n");
  remove_call_out("whip_ass");
  call_out("whip_ass",5);
  gold=clone_object("obj/money");
  gold->set_money(random(2000)+1000);
  move_object(gold,this_object());
}

heart_beat()
{
  ::heart_beat();
   heal_shaman();
   checkup();
   return 1;
}

whip_ass()
{
  object target;
  object envto;
  remove_call_out("whip_ass");
  envto=environment(this_object());
  if(!present(this_object())->query_attack(),envto)
  {
    target=first_inventory(envto);
    while(target)
    {
      if(target->is_player())
      {
        this_object()->attack_object(target);
        remove_call_out("whip_ass");
        call_out("whip_ass",5);
        return 1;
      }
      target=next_inventory(target);
    }
  remove_call_out("whip_ass");
  call_out("whip_ass",5);
  return 1;
  }
}

heal_shaman()
{
  int X;
  if(this_object()->query_hp() < 800) X = random(20);
  if(Y==0)
  {
    call_other(this_object(),"heal_self",X);
    if(X > 8)
    {
      say("The shaman's wounds seem to be healing.\n");
    }
    return 1;
  }
  return 1;
}

checkup()
{
  if(attacker_ob)
    if(attacker_ob == TO) pissed(1);
  if(TO->query_wc() < 60) pissed();
  return 1;
}

pissed(arg)
{
  if(!arg)
  {
    attacker_ob->stop_fight(); attacker_ob->stop_fight();
    attacker_ob->stop_hunter();
  }
  stop_fight(); stop_fight(); stop_hunter();
  TO->set_wc(80);
  TO->heal_self(1000);
  return 1;
}
