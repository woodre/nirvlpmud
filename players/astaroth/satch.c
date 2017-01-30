inherit "obj/monster";
reset(arg) {
  if(!arg) {
  ::reset(arg);
  set_name("satriani");
  set_level(20);
  set_ep(1700000);
  set_alias("joe");
  set_race("human");
  set_hp(600 + random(250));
  set_al(800);
  set_short("Joe Satriani");
  set_long("He is the best of the best of the guitar legends.\n" +
           "You will never match his playing, but his guitar\n" +
           "is wielded with guitar knowledge.\n" +
           "");
  set_wc(20);
  set_ac(19);
  set_chance(40);
  set_spell_mess1(this_player()->query_name()+" sends you flying in a blue dream.");
  set_spell_mess2("Satch plays an awesome rift.");
  set_spell_dam(25);
  if(!present("guitar", this_object())) {
    move_object(clone_object("/players/astaroth/guitar"), this_object());
    command("wield guitar");
  }
  if(!present("strap", this_object())) {
    move_object(clone_object("/players/astaroth/strap"), this_object());
  }
  if(!present("heal", this_object())) {
    move_object(clone_object("/obj/heal"), this_object());
  }
  }
}
