id(str) {
  return str == "test_object" || str == "no_weapon_attack";
}

get() { return 1; }

short() { return "Test object."; }

do_no_attack_message(ob) {
  tell_object(environment(),"You fumble with your weapon and forget to attack.\n");
  return 1;
}