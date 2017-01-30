inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("ryo");
  set_short();
  set_alias("ryo");
  set_race("spirit");
  set_long("A bodiless head of a woman.\n"+
    "She died in tormet and she now longs for life again.\n"+
    "It is said that should she drink of the blood of the\n"+
    "Jinro- half man half beast, she will live again.\n");
  set_hp(700);
  set_level(20);
  set_al(-500);
  set_wc(40);
  set_ac(17);
  set_aggressive(1);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("Something whispers in your ear, 'I need blood...'\n");
  load_chat("The darkness presses down on you like a heavy weight.  "+
      "You feel tired...\n");
  load_a_chat("Something is really, really WRONG!\n");

  set_chance(30);
set_heart_beat(1);
  set_spell_dam(20);
  set_spell_mess1("Something is really, really WRONG!\n");
  set_spell_mess2("The head flies at you... it passes by and you feel a great "+
      "pain in your neck!\nYour Blood is slurped up by the Ryo.\n");
  move_object(clone_object("/players/mythos/amisc/forest/essence.c"),this_object());
}

heart_beat(){
::heart_beat();
 if(root() || !environment()) set_heart_beat(0);
if(creator(environment()) != "mythos"){
if(present("sheet", this_object())){
destruct(present("sheet", this_object()));
}
destruct(this_object());
}

}
