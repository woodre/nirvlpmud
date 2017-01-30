/* Blob of flesh
 * A monster with extremely high hps.
 * In ChAoS, it is dangerous to fight for long...
 */

inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("flesh blob");
     set_short("A huge blob of flesh");
     set_race( "chaoscreature");
     set_alias("blob");
     set_long(
"This is a huge blob of flesh. Whether it is sentient or not you cannot\n"+
"tell. It is definitely alive though. It looks like it could take a lot of\n"+
"damage but does not look very dangerous. There may be treasure inside the\n"+
"bulk. Then again, maybe not.\n");
     set_level(18);
     set_ac(3+ random(5));
     set_wc(5 + random(5));
     set_hp(2000 + random(1000));
     set_al(0);
     money = random(3000);
     set_aggressive(0);
    set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat(
"The blob of flesh ripples slowly.\n");
     load_chat(
"The blob squirms slowly over the ground.\n");
     load_a_chat(
"The blob wiggles around in a useless attempt to escape.\n");
     load_a_chat(
"The fleshy blob quivers in pain!\n");
   }
}

monster_died() {
  tell_room(environment(this_object()),
     "The battered and beaten blob quivers one last time...\n");
  if(query_attack()) tell_room(environment(), query_attack()->query_real_name()+"\n");
  return 0;
}
