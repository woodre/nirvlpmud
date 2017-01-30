inherit "players/mythos/dmon/splitmon";
object coinage;

reset(arg) { 
  ::reset(arg);
  if(arg) return;
  set_name("sanddevil");
  set_alias("sand");
  set_race("devil");
  set_short("SandDevil");
  set_long("A humanoid figure made out of sand chitters at you.\n"+
           "Cold blue eyes stare back at you.  Do not underestimate\n"+
           "the power of this little creature.\n");
  set_level(6);
  set_hp(100);
  set_wc(16);
  set_ac(5);
  set_al(-1000);
  set_parts(3);
  set_line(15);
  set_mult(2);
  set_chance(2);
  set_spell_dam(250);
  set_spell_mess1("Suddenly the SandDevil screams with a sound that tears at the soul!\n");
  set_spell_mess2("The SandDevil screams and you feel great PAIN!\n"); 
  set_chat_chance(2);
  set_a_chat_chance(2);
  load_chat("The wind whips sand around.\n");
  load_chat("A SandDevil giggles.\n");
  load_chat("The Devil grins.\n");
  load_a_chat("The SandDevil leaps at you!\n");   
  load_a_chat("The SandDevil tears into flesh!\n");
  coinage = clone_object("/obj/money.c");
  coinage->set_money(400 + random(100));
  move_object(coinage,this_object());
}
