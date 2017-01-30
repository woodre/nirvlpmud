inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("Negative Elemental");
     set_short("A huge creature encased in black");
     set_alt_name("creature");
     set_race("elemental");
     set_gender("creature");
     set_long("A massive humanoid figure stands before you, bands of pure\n"+
              "energy ripple across its form. The air around the creature\n"+
              "seems to scream in agony and death. Not a friendly\n"+
              "being.\n");
     set_level(19);
     set_ac(16);
     set_wc(28 + random(9));
     set_hp(450 + random(120));
     set_al(-1000);
     set_aggressive(1);
     set_a_chat_chance(25);
     load_a_chat("The elemental thirsts for the taste of the living.\n");
     load_a_chat("The elemental howls in anger and fury.\n");

   }
}
