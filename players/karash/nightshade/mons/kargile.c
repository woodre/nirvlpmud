inherit "obj/monster";

reset(arg){
   object gold,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("wulfgar");
   set_alias("wulfgar");
   set_short("Wulfgar");
  set_long("A brute of a man with a massive war hammher hanging gingerly over his shoulder. Best be careful with this one.\n");
   set_level(20);
   set_hp(999);
   set_al(-1000);
   set_wc(30);
   set_ac(16);
set_chat_chance(15);
load_chat("Wulfgar laughs at your impotence.\n");
set_chance(35);
set_spell_dam(15);
set_spell_mess1("Wulfgar nails his opponent on the head with his mighty hammer!");
set_spell_mess2("You see Wulfgar's hammer arc over and pound you on the head!");
weapon=clone_object("/players/nightshade/weap/hammer");
   move_object(weapon, this_object());
gold=clone_object("obj/money");
gold->set_money(1000);
move_object(gold, this_object());
}
