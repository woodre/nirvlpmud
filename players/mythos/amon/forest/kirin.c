#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "obj/monster";
reset(arg)  {
  object ob;
  ::reset(arg);
  if(arg) return;
  set_name("kirin");
  set_alias("unicorn");
  set_race("beast");
  set_short("The Mythical Kirin");
  set_long("The one horned beast is of incredible beauty.  Its white hide radiates\n"+
    "an aura of tranquility.  The Kirin is surounded in smoke and occasioanlly\n"+
    "flame appears.\n");
  set_hp(1200);
  set_level(25);
  set_al(750);
  set_wc(40);
  set_ac(19);
  set_heal(2,10);
  set_aggressive(0);
  ob=clone_object("/players/mythos/amisc/forest/horn3.c");
  move_object(ob,this_object());
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The Kirin rises up in the air.\n");
  load_chat("The Kirin nods at you.\n");
  load_a_chat("The Kirin charges into battle!\n");
  load_a_chat("\t>>CRUNCH<<\n");
  set_chance(35);
  set_spell_dam(random(75));
  set_spell_mess1(RED+"\n\tThe Kirin smashes a hoof into its foe!\n"+NORM);
  set_spell_mess2(RED+"\n\tThe Kirin smashes a hoof into you!\n"+NORM);
}
#include "/players/mythos/amon/hb_ag.h"
