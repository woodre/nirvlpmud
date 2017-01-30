inherit "obj/monster";
object gold,weap;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("mage");
   set_alias("drow");
   set_short("Drow Mage");
   set_long("This is a drow mage praticed in the dark magiks.\n");
   set_level(19);
   set_hp(475);
   weap=clone_object("players/nightshade/weap/invis_sword");
   move_object(weap, this_object());
   init_command("wield razor");
  set_wc(28);
   set_ac(16);
   gold=clone_object("obj/money");
  gold->set_money(2000);
   move_object(gold, this_object());
   
}

/* wc was 3, ac was 13 - mythos <6-17-96> */
