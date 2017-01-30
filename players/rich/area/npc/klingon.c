#include <ansi.h>

inherit "/obj/monster.c";

void
reset(int arg)
{
  object money;
  ::reset(arg);
  if(arg) return;
  set_name("arkha");
  set_alt_name("guard");
  set_alias("honor guard");
  set_race("klingon");
  set_short(RED + "Klingon Honor Guard" + NORM);
  set_long("\
  The " + short_desc + " is standing at attention here, ready to\n\
defend the Empire and his captain at any cost. Regardless of where\n\
people stand in the room, his gaze follows them and his body is\n\
tensed and ready to attack at the slightest provocation. It is not\n\
unheard of for " + short_desc + " to be quite \"liberal\" in their\n\
application of the term \"provocation\".\n");
  set_ac(3);
  set_wc(7);
  set_level(4);
  set_al(-100);
  set_hp(75);
  set_aggressive(1);
  set_chat_chance(20);
  set_a_chat_chance(30);
  load_chats( ({
    short_desc + " growls, \"Today is a good day to die.\"\n",
    short_desc + " growls, \"You can't find quality targ here.\"\n",
    short_desc + " growls, \"This is taking too long.\"\n",
    }) );
  load_a_chats( ({
    short_desc + " screams in rage!\n",
    short_desc + " yells, \"Die, Weakling, Die\"\n",
    short_desc + " yells, \"You will surely go to Gre\'thor today!\"\n",
    }) );
  money = clone_object("/obj/money.c");
  money->set_money( (int)this_object()->query_level() * (random(20)+1));
  move_object(money, this_object());
}
