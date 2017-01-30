inherit "obj/monster";
object gold, weap, duh;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("mage");
   set_alias("mage");
   set_short("Level 20 Mage");
set_long("The supreme mage in all Ledsville. He has perfected\n"+
"the art of conjuring so beware. He is tough.\n");
   set_level(19);
   set_hp(475);
   weap=clone_object("players/nightshade/weap/invis_sword");
   move_object(weap, this_object());
   init_command("wield razor");
  set_wc(28);
   set_ac(16);
/* Master Mage now has a spell attack  -Snow */
   set_chance(70);
   set_spell_mess1("The Master Mage blasts lightning!\n");
   set_spell_mess2("The Master Mage blasts you with lightning!\n");
   set_spell_dam(25);
   gold=clone_object("obj/money");
  gold->set_money(2000);
   move_object(gold, this_object());
   
duh=clone_object("players/nightshade/misc/spell_book");
move_object(duh, this_object());
}

/* money was 3000+rnd(500) wc was 3 ac was 13 hp was 400 - mythos <6-17-96> */
