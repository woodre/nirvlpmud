inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("wahz");
  set_alt_name("snake");
  set_short("Wahz Sithos");
  set_long(
"   Wahz is an assasin of the Tribe of Sithos.  All but his eyes and \n"+
"fangs are hidden in wraps of fabric.  Folds of the fabric blend in the \n"+
"movements of arms and legs.  His eyes flicker and rage like a sea of \n"+
"flames.  His fangs extend far past his mouth and are dripping wet.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(18);
  set_wc(26);
  set_ac(15);
  set_hp(450);
  set_al(-200);
  set_aggressive(1);
  set_chat_chance(3);
  load_chat("Wahz moves his arms, hidden in the folds of fabric.\n");
  load_chat("Wahz says: You will be destroyed when Our Lord Rises.\n");
  load_chat("Wahz stares at you with burning eyes.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
write("\nWith one last blow you rip off some of the black fabric!\n");
  move_object(clone_object("/players/stark/forest/obj/18fabric.c"),this_object());
return 1;}
