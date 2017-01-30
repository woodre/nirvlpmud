inherit "players/mythos/dmon/splitmon";
object coinage;

reset(arg) { 
  ::reset(arg);
  if(arg) return;
  set_name("dunedevil");
  set_alias("dune");
  set_race("devil");
  set_short("DuneDevil");
  set_long("A small black humaniod creature stares back at you.\n"+
           "Beady red eyes encase a malevolence that is frightening.\n"+
           "Beware of this little devil.\n");
  set_level(10);
  set_hp(150);
  set_wc(14);
  set_ac(8);
  set_al(-500);
  set_parts(2);
  set_aggressive(1);
  set_line(30);
  set_chat_chance(2);
  set_a_chat_chance(2);
  load_chat("The DuneDevil grins.\n");
  load_chat("The sun beats down upon you.\n");
  load_chat("The Devil giggles.\n");
  load_a_chat("The DuneDevil SCREAMS!\n");   
  load_a_chat("The Devil snickers.\n");
  coinage = clone_object("/obj/money.c");
  coinage->set_money(400 + random(100));
  move_object(coinage,this_object());
}
