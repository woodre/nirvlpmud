/* This creature needs to be a VERY tough customer...the only way to get
by him is to ACTUALLY DIE... */
inherit "obj/monster.talk";
object coins, person;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("demon");
set_short("Demon Lord");
set_long("This is the Demon Lord, gaurdian of the mighty stake!\n");
set_alias("demon");
set_al(-500);
set_level(20);
set_hp(1100);
set_ac(17);
set_wc(60);
set_aggressive(1);
set_dead_ob(this_object());
set_chat_chance(90);
load_chat("Demon says: You'll never get past me...ALIVE!\n");
set_a_chat_chance(90);
load_a_chat("Demon says: You'll never get past me...ALIVE!\n");
}
monster_died(arg) {
  object blind;
  person = this_player();
  write("The Demon says: You may have beaten me, but Malachi will surely destroy you!!!\n");
  write("As the Demon lord dies he breathes fire into your eyes!!\n");
/*
  blind = clone_object("players/grimm/object/no_look");
  blind->set_life(1500);
  move_object(blind,this_player());
  call_out("blind_again",2);
*/
return 0;
}
blind_again() {
  object blind;
  tell_object(person,"straining to look around your eyes become weak once again.\n");
  blind = clone_object("players/grimm/object/no_look");
  move_object(blind,person);
  return 1;
}
