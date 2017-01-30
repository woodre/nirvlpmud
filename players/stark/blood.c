inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("irz");
  set_alt_name("snake");
  set_short("Irz Sithos");
  set_long(
"   Irz is a assasin of the Tribe of Sithos.  The black fabric has been \n"+
"wrapped around the entirety of her body.  Her womanly features are \n"+
"barely noticeable in the concealment of darkness.   Her eyes seem to \n"+
"flicker like a distant fire coming to life.  Her fangs are fully \n"+
"pronounced and seem to be secreting fluid.\n"
  );
  set_gender("female");
  set_race("snake");
set_level(50);
  set_wc(26);
  set_ac(15);
set_hp(1);
  set_al(-200);
  set_aggressive(1);
  set_a_chat_chance(3);
  load_a_chat("Irz hisses and stares at you.\n");
  load_a_chat("Irz says: You will serve well as food for our Lord.\n");
  load_a_chat("Irz bares her fangs.\n");
}
