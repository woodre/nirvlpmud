/* Looks just like a drifter in the room, players shouldn't know which they are about to
   attack until they get into the fight.  Just a little bit of a surprise */

#define here = environment(this_object());
inherit "/players/daranath/closed/monster1.c";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

     set_name("DoomDrifter");
     set_short("A spirit drifts about the area");
     set_alias("spirit");
     set_alt_name("drifter");
     set_race("undead");
     set_gender("creature");
     set_long("A wandering spirit who has failed the task of becoming a mourning\n"+
              "coil drifts about the area, bringing a child breeze wherever it\n"+
              "goes. Spirits such as this one were nicknamed 'drifters' by the\n"+
              "former residents of Qual'tor, and the name stuck.\n");
     set_level(21);
     set_ac(17);
     set_wc(36 + random(10));
     set_hp(600 + random(100));
     set_al(-1000);
     set_aggressive(0);
     set_a_chat_chance(15);
     load_a_chat("The DoomDrifter tears into your throat, drawing blood.\n");
     load_a_chat("The DoomDrifter tries to make you one of the dead.\n");

     set_spell_mess2("The DoomDrifter absorbs a part of your soul!\n");
     set_spell_mess1("The DoomDrifter casts an arcane spell, howling gleefully.\n");
     set_chance(15);
     set_spell_dam(50+random(75));

set_mult(2);
set_mult_chance(25);
set_mult_dam1(10);
set_mult_dam2(8);

     gold = clone_object("/obj/money.c");
     gold->set_money(random(4000)+4000);
/* average coins of 6000, exactly per monster guide */
     move_object(gold,this_object());
   }
  }

