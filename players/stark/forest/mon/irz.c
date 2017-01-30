inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("irz");
  set_alt_name("snake");
  set_short("Irz Sithos");
  set_long(
"   Irz is an assasin of the Tribe of Sithos.  The black fabric has been \n"+
"wrapped around the entirety of her body.  Her womanly features are \n"+
"barely noticeable in the concealment of darkness.   Her eyes seem to \n"+
"flicker like a distant fire coming to life.  Her fangs are fully \n"+
"pronounced and seem to be secreting fluid.\n"
  );
  set_gender("female");
  set_race("snake");
  set_level(18);
  set_wc(26);
  set_ac(15);
  set_hp(450);
  set_al(-200);
  set_aggressive(1);
  set_chat_chance(3);
  load_chat("Irz hisses and stares at you.\n");
  load_chat("Irz says: You will serve well as food for our Lord.\n");
  load_chat("Irz bares her fangs.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
write("\nA chunk of the black fabric falls loose from the Irz's body!\n\n");
  move_object(clone_object("/players/stark/forest/obj/18fabric.c"),this_object());
return 1;}
