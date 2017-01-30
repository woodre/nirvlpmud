#define tp this_player()->query_name()
inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("mist cat");
  set_alias("mist");
  set_race("spirit");
  set_short("A Cat Shaped Mist");
  set_long("The Mist seems to be shaped in a cat's form.  However, whenever\n"+
    "you try to look at it, its shape alludes you.  There\n"+
    "is something odd about it.\n");
  set_hp(180);
  set_level(12);
  set_al(-100);
  set_wc(16);
  set_ac(9);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The Mist drifts\n");
  load_chat("The mist breaks apart and goes back together.\n");
  load_a_chat("The Mist FLARES in anger.\n");
  set_chance(5);
  set_spell_dam(random(40));
  set_spell_mess1("\n"+tp+" is shrouded by the Mist.  You hear screams of A G O N Y coming from within.\n"+
    "The Mist clears and you see "+tp+" stagger and almost fall.  Blood is everywhere.\n");
  set_spell_mess2("\n You see the MIST gather around you.  You hear a quiet whistle. THEN....\n\n"+
    "\n             P  A  I  N\n\n\n"+
    "You see a silver streak of light and something disappears into the fog.\n"+
    "The mist clears and you feel faint.  Blood is everywhere- your blood.");
  gold=clone_object("obj/money");
  gold->set_money(random(50)+550);
  move_object(gold,this_object());
}
