inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("panoramix");
   set_race("human");
   set_alias("druid");
   set_short("Panoramix, the druid");
   set_long("He is a little old man but it seems to be powerful.\n");
   set_level(19);
   set_hp(475);
   set_al(0);
   set_wc(28);
   set_ac(16);
   set_chat_chance (20);
   load_chat("Panoramix says: 'I want to find some berries for the potion.'\n");
   load_chat("The druid search for the berries.\n");
   load_chat("Panoramix says: 'Where are you Asterix?'\n");
   set_chance(10);
   set_spell_dam(random(10)+10);
   set_spell_mess1("The druid shows his power.\n");
  set_spell_mess2("You are hit from a strange beam. You fall to the ground.\n");
   gold=clone_object("players/hurtbrain/obj/potion");
   move_object(gold,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/gaul/staff");
   move_object(ob1,this_object());
}
