inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 

object gold,ob;
  gold = clone_object("obj/money");
  gold->set_money(random(300) + 100);
  move_object(gold,this_object());

  ob = clone_object("players/snow/WEAPONS/snowball.c");
  move_object(ob,this_object());
      set_name("snowman");
     set_short("An evil snowman");
     set_race("snowman");
     set_alias("man");
     set_long(
"A few huge masses of snow shoved together in the semblance of a man. This\n"+
"one is pissed that he was so poorly made. He is a tough character so \n"+
"watch out!\n");
     set_level(11 + random(6));
     set_ac(6 + random (5));
     set_wc(10 + random(8));
     set_hp(100 + random(80));
     set_al(-500);
     set_aggressive(0);
set_chance(15);
set_spell_mess1(
"The snowman smashes his victim with fists of soggy snow!\n");
set_spell_mess2(
"The snowman smashes you with fists of soggy snow!\n");
set_spell_dam(10);
   }
}
