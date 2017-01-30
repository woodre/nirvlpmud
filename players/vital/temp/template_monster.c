#include <ansi.h>

inherit "/obj/monster.c";

void
reset(int arg)
{
  object money;
  ::reset(arg);
  if(arg) return;
  set_name("");
  set_alt_name("");
  set_alias("");
  set_race("");
  set_short();
  set_long("\
  ");
  set_ac();
  set_wc();
  set_level();
  set_al();
  set_hp();
  set_aggressive();
  set_chat_chance();
  set_a_chat_chance();
  load_chats( ({
    short_desc + " \n",
    short_desc + " \n",
    short_desc + " \n",
    }) );
  load_a_chats( ({
    short_desc + " \n",
    short_desc + " \n",
    short_desc + " \n",
    }) );
  money = clone_object("/obj/money.c");
  money->set_money();
  move_object(money, this_object());
}
