inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
     set_name("black");
   set_short("A black shadow");
     set_alt_name("shadow");
     set_gender("male");
     set_race( "immortal");
     set_long("A dark black shadow that seems to mirror your movements.\n");
     set_level(20);
     set_ac(10);
     set_wc(5);
     set_hp(800);
     set_al(-1000);
     set_heal(5,25);
     set_aggressive(0);

     set_spell_mess2("The black shadow drain part of your life force.");
     set_spell_mess1("The black shadow drains part of its foe's life force.\n");
 set_chance(12);
 set_spell_dam(20);
   }

}
