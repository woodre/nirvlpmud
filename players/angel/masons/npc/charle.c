#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Charle");
  set_race("human");
  set_alt_name("charle");
  set_short("Charle");
  set_long("The Masons barhop.\n");
  set_level(30);
  set_hp(10000);
  set_wc(60);
  set_ac(60);
  set_al(1000);
  set_chat_chance(1);
  load_chat(query_name()+" asks, \"What can I get you?\"\n");
}