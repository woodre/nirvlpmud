inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "basilisk" );
     set_alias("basilisk");
     set_short("A Basilisk");
set_long("This is a long eight-legged reptile with strange glowing red\n"+
"eyes.  He sits protectively on an enormous pile of treasure!\n");
     set_level(17);
     set_ac(15);
     set_wc(25);
     set_hp(430);
     set_al(-1000);
set_spell_mess1("The Basilisks eyes glow bright red as he stares into your eyes..you feel weak inside.\n");
    set_aggressive(1);
     set_dead_ob(this_object());

 }
}

  monster_died() {
   object ob, attk, gold, armor;
   object gem, pants;
   attk=this_object()->query_attack();
  gold=clone_object("obj/money");
   gold->set_money(random(5000)+5000);
   move_object(gold, this_object());
    armor = clone_object("players/pavlik/armor/bask.c");
   move_object(armor, this_object());
  gem = clone_object("players/pavlik/items/gem.c");
  move_object(gem, this_object());
  pants = clone_object("players/pavlik/armor/bask1.c");
      move_object(pants, this_object());
  tell_object(attk, "You slay the monster and all if it's treasure pours forth into\n"+
    "the room!\n");
  return 0;
}

