/*
 * A vicious monster that does not stop in its quest for blood inside the realm of
 * ChAoS. High ac, wc, spell damage, extra damage, extra attacks...
 * Also one of the few monsters in ChAoS that carries coins
  */

inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(random(4000) + 4000);
  move_object(gold,this_object());
 
  ob = clone_object("/players/snow/chaos/objects/fscim.c");
  move_object(ob,this_object());
 
     set_name("efreeti");
     set_short("A powerful minion of fire");
     set_race("chaoscreature");
     set_alias("minion");
     set_alt_name("efreet");
     set_long(
"This is a fabled efreeti. It is about twelve feet tall and wielding\n"+
"a huge battleaxe of flame. Be prepared for a battle as the efreet\n"+
"always fight to the death.\n");
     set_level(21);
     set_ac(18 + random(4));
     init_command("wield axe");
     set_wc(32 + random(16));
     set_hp(450 + random(100));
/* NEW CODE */
set_wc_bonus(7);
     set_al(-800);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The efreeti says: My master wishes you to die.\n");
     load_chat("The efreeti grins in anticipation of battle.\n");
     load_a_chat("The efreeti says: 'twil be a pleasure to disembowel you!\n");
     load_a_chat("The efreeti sends its battleaxe blurring at you.\n");
  set_spell_mess1("The Efreeti is engulfed in a reddish haze!\n");
  set_spell_mess2("The Efreeti is engulfed in a reddish haze!\n");
  set_chance(20);
  set_spell_dam(20);
   }
}
heart_beat() {
  object meat;
  ::heart_beat();
  if(!environment()); return 1;
meat = this_object()->query_attack();
if(meat) {
  if(environment(meat) == environment(this_object())) {
    if(random(10) < 7) return 1;
else
    say("The Efreet bellows forth flame upon "+
      capitalize(meat->query_name())+"!\n");
    tell_object(meat,"***You are severely burned!***\n");
    meat->hit_player(random(20)+10);
  }
  if(environment(this_object()) != environment(meat)) {
    if(environment(meat)->query_chaos() != "devour") return 1;
move_object(this_object(),environment(meat));
    say("An Efreet storms into the room looking for "+
      capitalize(meat->query_name())+"!\n");
  }
}
return 1;
}

