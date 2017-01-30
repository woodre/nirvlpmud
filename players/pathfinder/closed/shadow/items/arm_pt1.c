id(str) { return str == "armor_part_one"; }

init() {
  call_out("destruct_me", 120);
}

destruct_me() {
  destruct(this_object());
  return 1;
}

