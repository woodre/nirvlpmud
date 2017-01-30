#include <ansi.h>

inherit "obj/monster";
int x;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Anakin");
  set_alt_name("figure");
  set_race("action figure");
  set_alias("anakin");
  set_short("Anakin");
  set_long("\
  Anakin Skywalker transforms before your eyes into legendary\n\
bad guy Darth Vader. The basic action figure is of pre-dark side\n\
Anakin and while he’s not the most finely detailed figure ever\n\
made, there is still a glint of menace in his eyes. Anakin come\n\
with a head, interchangeable hands, tunic, two belts, pants, sash,\n\
two pairs of boots, two lightsabers, Vader head, Vader armor,\n\
shoulder plates, headgear, undercloak, cape and gloves.\n");
  set_level(22);
  set_hp(600 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(-100);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"Come over to the "+HIB+"Dark Side!"+NORM+"\"\n");
  load_chat("You feel the presence of the force move through you!\n");
  while(x < 4)
  {
    move_object(clone_object("/players/angel/area/walmart/obj/money.c"), this_object());
    x++;
  }
  add_spell("saber","#MN# slices his light $HR$saber$N$ through you.\n",
                     "#MN# slices his light $HR$saber$N$ through #TN#.\n",
                     75,30,"other|evil");
}
