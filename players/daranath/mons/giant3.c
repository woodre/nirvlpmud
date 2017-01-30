inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3;
     ob = clone_object("obj/money");
     ob->set_money(random(3000) + 1250);
/* Average coins of 2750 plus 750 from sack = 3500 per monster guide */
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/items/sack.c");
     move_object(ob2, this_object());
  move_object(clone_object("/players/daranath/qualtor/newstuff/heals/cheese2.c"),ob2);
  move_object(clone_object("/players/daranath/qualtor/newstuff/heals/cheese2.c"),ob2);
    ob3 = clone_object("/players/daranath/qualtor/newstuff/weps/fog_mace.c");
  move_object(ob3, this_object());
     set_name("fog giant");
     set_short("Fog Giant");
     set_race( "giant");
     set_gender("creature");
     set_long("Fog Giant towers over you, a hulking mass of sheer, brute power.\n"+
         "The last thing you notice is its foot coming down at your face.\n");
     set_level(18);
     set_ac(14 + random(3));
     set_wc(24 + random(5));
     set_hp(450 + random(50));
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(12);
     set_a_chat_chance(15);
     load_chat("Fog Giant looks at you as his next meal.\n");
     load_chat("Fog Giant growls: Good! Lunch is here!!!\n");
     load_chat("Fog giant glares at you.\n");
     load_a_chat("Fog Giant steps on you!\nOof!!!\n");
     load_a_chat("The Fog Giant kicks muck in your face.\n");
init_command("wield mace");
     set_spell_mess1("Fog Giant uproots a nearby tree and clubs you with it.\n");
     set_spell_mess2("Fog Giant uproots a nearby tree and clubs its foe with it.\n");
     set_chance(15);
     set_spell_dam(15);
   }
}
