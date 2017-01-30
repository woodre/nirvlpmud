inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

object gold;
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("sandworm");
  set_alt_name("shinshi_sandworm");
  set_race("worm");
  set_alias("sandworm");
  set_short(YEL+"Sandworm"+NORM);
  set_long("\
This rare, small worm is ribbon-like in appearance, and has\n\
three eyes on its head. The body comprises of twenty-six or\n\
twenty-seven segments, each of which bears bristles know as\n\
chaetae.\n");
  gold = clone_object("obj/money");
  gold->set_money(2000+random(5000));
  move_object(gold, this_object());
  set_level(20);
  set_hp(500 + random(100));
  set_ac(17 + random(8));
  set_wc(30 + random(10));
  set_al(-7000);
  set_chat_chance(1);
  load_chat(query_name()+" hisses and begins to dig a hole.\n");
  add_spell("bite","#MN# " + HIG + "bites" + NORM +
            " your leg and makes it " + HIR + "bleed" + NORM + "!\n",
            "#MN# " + HIR + "bites" + NORM + " your leg and you " + HIR +
            "bleed" + NORM + ".\n",
            35,75,"other|physical");
}


heart_beat()
{
  object tun;
  ::heart_beat();
  if(!environment()) return;
  
  tun = present("tunnel");
  
  if(tun)
  {
    destruct(tun);
    tell_room(environment(this_object()),
                          "You have died. You must 'exit' and get to the " +
                          "church.\n");
  }
}
