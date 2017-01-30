
int old_ac, new_ac;

id(str) {
  return str == "armor_plus_three";
}

init() {
  old_ac = this_player()->query_ac();
  new_ac = old_ac + 3;
  this_player()->set_ac(new_ac);
  call_out("end_armor", 1200);
}

end_armor() {
  this_player()->set_ac(old_ac);
  write("You feel your shadowy protection leaving you.\n");
  destruct(this_object());
  return 1;
}
