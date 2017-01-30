inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("derz");
  set_alt_name("snake");
  set_short("Derz Sithos");
  set_long(
"   Derz is a worker in the Tribe of Sithos.  Strong, bulging muscles \n"+
"are evident under his scaly green skin.  Red eyes burn deep as they \n"+
"protrude from his snake like head.  Black fabric is wound around his \n"+
"waist much like a kilt.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(16);
  set_wc(22);
  set_ac(13);
  set_hp(400);
  set_al(50);
  set_chat_chance(3);
  load_chat("Derz straightens his kilt.\n");
  load_chat("Derz touches the walls and rubs his hand against the rock.\n");
  load_chat("Derz comments:  This is a hard time for us.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
write("\nThe fabric around his waist unravels and falls to the ground...\n\n");
  move_object(clone_object("/players/stark/forest/obj/16fabric.c"),this_object());
return 1;}
