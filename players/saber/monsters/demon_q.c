inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("demon");
     set_short("A large Demon with black wings");
     set_alias("rizrakah");
     set_race( "demon");
     set_long("Your eyes can not understand what they see...\n");
     set_level(20);
    set_heal(1,8);
     set_ac(17);
     set_wc(33);
     set_hp(1000);
     set_al(-1000);
     set_aggressive(0);
set_chat_chance(2);
load_chat("The chamber blazes.\n");
load_chat("Smoke gets in your eyes.\n");
load_chat("A burst of fire singes you.\n");
load_chat("You feel very hot.\n");
load_chat("The demon glares at you.\n");
load_chat("Tiny tongues of fire lick at your boots.\n");
set_spell_mess1("The demon steals part of your soul.");
set_spell_mess2("The demon steals part of your soul.");
     set_chance(10);
     set_spell_dam(50);
   }
}

init()  {
   add_action("o_out","out");
        }

o_out()  {
 say("The Demon looks at you and laughs...\n");
  return 1;
        }
