#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

#define tp this_player()

inherit "obj/weapon.c";

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  message_hit =
  ({
    HIR+" B L U D G E O N E D "+NORM," into "+BOLD+"unrecognizable pulp"+NORM,
    HIR+" P U L V E R I Z E D "+NORM," with a blow from "+BOLD+"HELL"+NORM,
    HIR+" S M A S H E D "+NORM," with demonic force",
    HIR+" b a s h e d "+NORM,", with a sickening CRUNCH",
    HIR+" b o n k e d "+NORM," leaving a sizeable welt",
    HIR+" clunked "+NORM," just missing a solid blow",
    HIR+" tapped "+NORM," with hardly any result"
  });
  set_name("mace");
  set_alias("fist mace");
  set_short(BOLD+"Unholy Fist Mace"+NORM);
  set_long("This gleaming black mace is made from some sort of special alloy\n\
unknown to man.  It has the strength of hardened steel but the\n\
weight of aluminum.  The sleek, tapered leather-bound handle pro-\n\
vides a comfortable grip while the clenched-fist head has the \n\
look of menace written all over it.\n");
  set_type("club");
  set_class(18);
  set_weight(2);
  set_value(1000);
  add_wear(500);
  set_hit_func(this_object());
}

weapon_hit(attacker)
{
  int W;
  W = random(13);
  if(W>9)
  {
    if(tp->query_alignment() < -900)
    {
      say(BOLD+"The Unholy Mace DEVASTATES its target!"+NORM+"\n");
      write(BOLD+"You DEVASTATE your target with the Unholy Mace!"+NORM+"\n");
      return 6;
    }
    else
    {
      say(BOLD+"The power of the Unholy Mace goes unharnessed!"+NORM+"\n");
      write(BOLD+"You try to harness the evil power of the Unholy Mace but"+
            "fail miserably!"+NORM+"\n");
      return 0;
    }
    return 1;
  }
}

init()
{
  ::init();
}

heart_beat()
{
  ::heart_beat();
  if(tp->query_alignment() > 0)
  {
    command("unwield mace",tp);
    return 1;
  }
}

wield(str)
{
  if(this_player()->query_alignment() > 10)
  {
    write("You are too holy to wield this mace!\n");
    return 1;
  }
  else
  ::wield();
}

query_wear()
{
  int wear;
  wear = 3*misses/4 + 4*hits/18;
  return wear;
}
