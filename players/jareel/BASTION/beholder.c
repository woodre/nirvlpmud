inherit "obj/monster";

reset(arg) {
     object money;
     ::reset(arg);
     if(!arg) {
          set_name("beholder");
          set_race("beholder");
          set_level(22);
          set_hp(600);
          set_al(-1000);
          set_short("a beholder");
          set_long("It is a large, floating orb, with many eyestalks atop\n"+
                   "its body. Its one large eye, framed in the centre of\n"+
                   "its chitinous body, fixes on you.\n");
          set_aggressive(0);
          set_chance(20);
          set_spell_dam(15 + random(30));
          set_spell_mess1("The beholder fires a death ray.");
          set_spell_mess2("The beholder fires a death ray at you!");
          set_a_chat_chance(30);
          load_a_chat("The beholder cast a disintegrate spell.\n");
          load_a_chat("The beholder casts cause serious wounds.\n");
          load_a_chat("The beholder casts flesh to stone.\n");
          set_wc(36);
          set_ac(20); 
          money=clone_object("obj/money");
          money->set_money(4000 + random(2000));
          move_object(money, this_object()); }
}