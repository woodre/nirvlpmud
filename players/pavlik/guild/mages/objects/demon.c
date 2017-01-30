inherit "obj/monster";

reset(arg){
   ::reset(arg);
   if(arg) return;
  set_name("Bone Demon");
  set_race("demon");
  set_short("A Bone Demon");
  set_long("A Bone Demon, accidently conjured by a clumsy mage.\n");
  set_hp(100);
  set_ac(6);
  set_wc(30);
  set_al(-1000);
  set_level(5);
}

do_demon(obj){
  tell_room(environment(this_object()),
  "Bone Demon booms: Foolish Mortal!\n");
  this_object()->attack_object(obj);
  obj->attack_object(this_object());
  return 1;
}
