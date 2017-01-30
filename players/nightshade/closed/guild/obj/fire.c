inherit "obj/monster";
reset(arg) {
::reset(arg);
  set_name("wall of fire");
  set_alt_name("fire");
  set_alias("wall");
  set_wc(0);
  set_ac(0);
  set_hp(50);
  set_short("A wall of fire");
  set_long("A wall of fire created to protect the caster from the enemy.\n");
  over();
}
hit_player(dam) {
::hit_player();
  if(dead) {
    destruct(this_object());
    return 1;
  }
}
over() {
  call_out("gone", random(20)+20);
  return 1;
}
gone() {
  tell_room(environment(this_object()),
  "The wall of fire dies out leaving nothing but smoke.\n");
  destruct(this_object());
  return 1;
}


