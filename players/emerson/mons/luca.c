inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
gold->set_money((4000));
  move_object(gold,this_object());
  ob2 = clone_object("/players/emerson/weap/icepick.c");
move_object(ob2,this_object());
   ob3 = clone_object("/players/emerson/obj/clip.c");
   move_object(ob3,this_object());
init_command("wield ice pick");
     set_name("luca");
     set_alias("hutboss");
set_short("Luca Brasi");
     set_race( "human");
     set_long("Luca is the meanest,scariest,most gruesome looking man\n"+
     "you have ever seen. He is mumbling something about a wedding day\n"+
     "off by himself. I wouldn't bother him if you could help it.\n");
     set_level(20);
     set_ac(20);
     set_wc(33);
     set_hp(1000);
     set_al(-1000);
     set_aggressive(0);
     set_chance(40);
     set_spell_dam(20);
    set_spell_mess1("");
    set_spell_mess2("");
     set_chat_chance(20);
     set_a_chat_chance(20);
     load_chat("Luca looks scary.\n");
     load_chat("Luca sleeps with tha fishies.\n");
     load_a_chat("Luca says: You fool!  You can't be this stupid!\n");
     load_a_chat("Luca slaps you across the face.\n");
     load_a_chat("Luca punches you in the stomach.\n");
     load_a_chat("Luca says: Surrender and I shall let you live...\n");
   }
}
