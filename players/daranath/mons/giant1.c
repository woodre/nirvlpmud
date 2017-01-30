inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(200) + 1000);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/dar/sclub.c");
     move_object(ob2, this_object());
     set_name("swamp giant");
     set_short("Swamp Giant");
     set_race( "giant");
     set_gender("creature");
     set_long("Swamp Giant is lean and muscular in build. It's grim features\n"+
        "are encased in dark green hair.  It stands approximately\n"+
        "fifteen feet or so, and looks right at you.\n");
     set_level(17);
     set_ac(15);
     set_wc(25);
     set_hp(400 + random(50));
     set_al(-670);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(10);
     load_chat("The giant says: My, my.  What have we here?\n");
     load_chat("Giant switches his club to his other hand.\n");
     load_a_chat("Giant backhands you with a tremendous swing.\n");
     load_a_chat("Gaint steps on you.  Oof!!!\n");

     set_spell_mess1("Gaint pummels its foe with its club.\n");
     set_spell_mess2("Giant pummels you with its club.\n");
     set_chance(20);
     set_spell_dam(5);
   }
}
