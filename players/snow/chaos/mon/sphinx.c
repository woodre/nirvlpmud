/* Shadow Sphinx
 * Very high hps and heal rate, high wc, ac, and spell damage
 * One of few ChAoS creatures with coins
 */

inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
 
     set_name("sphinx");
     set_short("dark shadows");
     set_long(
"  As you peer closely at the shadows they seem to coalesce\n"+
"into a huge, menacing form. The sweeping shadows lengthen\n"+
"and widen to form monstrous wings while the claws and torso\n"+
"of a sphinx appear beneath them. This is a fabled Shadow\n"+
"Sphinx, ruler of all it surveys.\n");
     set_race("chaoscreature");
     set_alias("shadows");
     set_alt_name("shadowcreature");
     set_level(22);
     set_ac(20);
     set_wc(40);
     set_hp(random(700)+600);
     set_heal(1,1);
     set_al(0);
     set_aggressive(0);
    set_dead_ob(this_object());
     set_chat_chance(10);
     set_a_chat_chance(5);
    load_chat(
"The shadows slide gracefully closer to you.\n");
    load_a_chat(
"The Shadow Sphinx roars: You fool! I am like unto a god!\n");
    set_chance(15);
    set_spell_dam(40);
    set_spell_mess1("The Shadow Sphinx roars in anger!\n");
    set_spell_mess2("The Shadow Sphinx roars in anger!\n");
    money = random(4000)+4000;
   }
}

monster_died() {
  object ob;
  ob = clone_object("/obj/heal.c");
  tell_room(environment(this_object()),
    "The great shadows collapse into a pitiful grey form.\n");
  move_object(ob,this_object());
  return 0;
}
