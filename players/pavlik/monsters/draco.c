inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "dragon" );
     set_alias("draco-lich");
     set_short("A Draco-Lich");
  set_long("This is a mighty undead Dragon.  A fearsome combination\n"+
   "of magic and razor sharp claws the Draco-lich is a deadly foe.\n");
     set_level(25);
     set_ac(20);
     set_wc(25);
     set_hp(1000);
     set_al(-1000);
   set_chance(25);
   set_spell_dam(random(25)+10);
  set_spell_mess1("The Draco-lich spews a fireball at you!\n");
  set_spell_mess2("The Draco-lich casts a spell of death at you!\n");
    set_aggressive(1);
     set_chat_chance(40);
     set_a_chat_chance(60);
  load_a_chat("Dragon rakes you with his powerful claws.\n");
  load_a_chat("The Draco-lich sends chills through your spine.\n");
     set_dead_ob(this_object());

 }
}

  monster_died() {
  object ob, attk;
   attk=this_object()->query_attack();
   tell_object(attk, "Well Done!   You have defeated the Draco-lich!!!\n"+
  "After slaying the un-dead monster you rush to the back wall.\n"+
  "There you find a human female chained to the wall.  At you approach\n"+
  "she asks: Will You free me?\n\n\n");
  tell_object(attk, "Do you free her? (yes/no)\n");
  return 0;
}

