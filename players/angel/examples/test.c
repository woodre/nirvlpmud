#include <ansi.h>
inherit "obj/monster";
#define OWNER "angel"

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("parent volunteer");
  set_race("human");
  set_alias("parent");
  set_alt_name("volunteer");
  set_long("\
This is an average parent. The parent wants to help others at the\n\
school. The tag on her shirt reads, How may I help you?\n");
  set_level(13);
  set_hp(195);
  set_wc(17);
  set_al(300);
  set_chat_chance(4);
  load_chat(query_name()+" asks, \Hello, how can I help you today?\"\n");
  load_chat("Parent volunteer says, all the classrooms are down the hallway!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(400)+25);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/belt_01.c");
  move_object(armor, this_object());
  command("wear belt", this_object());
  set_ac(10);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     20,20,"other|fire");
}

short()
{
  string dis;

  dis = " "+HIB+"Money Belt"+NORM+"";
  if( !present("parent", this_object()) ) dis = dis + " (worn)";
  if(this_player() && this_player()->capitalize(OWNER)) dis;
  if(this_player() && this_player()->query_level() > 39) dis;
  return dis;
}