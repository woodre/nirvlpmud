inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gir");
  set_alt_name("snake");
  set_short("Gir Sithos");
  set_long(
"   Gir is a guardian of Sithos.  His scaly feet and arm are constantly \n"+
"prepped for an assault.  His fiery eyes have been plucked from his \n"+
"sockets, leaving him blinded.  Gir is wearing a small wrapping of \n"+
"fabric around his waist.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(475);
  set_al(-200);
  set_chat_chance(3);
  load_chat("Gir faces you and smiles.\n");
  load_chat("Gir says: None shall touch our Lord Sithos.\n");
  load_chat("Gir cracks his knuckles one by one.\n");
  set_dead_ob(this_object());
}
init() {
  ::init();
  add_action("pray","pray");
}
pray() {
  write("Gir doesn't allow you to Pray.\n");
  return 1;
}

monster_died(ob){
write("\nThe small bit of black fabric rips off the dying body!\n\n");
  move_object(clone_object("/players/stark/forest/obj/19fabric.c"),this_object());
return 1;}
