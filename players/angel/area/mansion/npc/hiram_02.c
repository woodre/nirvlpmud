#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/monster";
  
reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Hiram Abif Reborn");
  set_alt_name("mason");
  set_alt_name("abif");
  set_race("master mason");
  set_alias("hiram");
  set_short(HIW+"Hiram Abif Reborn"+NORM);
  set_long("\Grand Master Hiram Abif is the Grand Architect of\n\
King Solomon’s Temple. Hiram knows secret which, by its mere\n\
possession, a person would be allowed to pass himself off as a\n\
Master Mason, or journeyman builder. Secrets that can only be\n\
obtained by the death of Hiram Abif.\n");
  set_level(22);
  set_hp(900 + random (400));
  set_ac(20 + random (12));
  set_wc(28 + random (12));
  set_al(0);
  set_ac_bonus (20);
  set_wc_bonus (30);
  set_hp_bonus (1400);
  set_dead_ob(this_object());
  set_aggressive(1);
  set_chat_chance(5);
  load_chat(query_name()+" says, \"Come be "+HIW+"Re-Born"+NORM+"!\"\n");
  gold=clone_object("obj/money");
  gold->set_money(10000);
  move_object(gold, this_object());
  weapon=clone_object("/players/angel/area/mansion/obj/masonic_sword_01.c");
  move_object(weapon, this_object());
  command("wield sword", this_object());
  add_spell("sword","#MN# slices his Masonic $HR$Sword$N$ through you.\n",
                    "#MN# slices his Masonic $HR$Sword$N$ through #TN#.\n",
                    50,100,"other|fire");
}

heart_beat()
{
  ::heart_beat();
  corpse_grab();
}

corpse_grab()
{
  object ob;
  if((ob = present("corpse", environment())) && (int)ob->is_corpse())
  {
    tell_room(environment(), "Hiram snatches: "+(string)ob->short()+".\n");
    move_object(ob, this_object());
    corpse_grab();
  }
}

monster_died()
{
  say("Seek out the place with many colors. King Soloman protects the\n\
treasure to the day!\n");
}