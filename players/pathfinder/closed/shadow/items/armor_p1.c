
int old_ac, new_ac;

get() { return 1; }
drop() { return 1; }
query_weight() { return 1; }

id(str) {
  return str == "armor_plus_one";
}

init() {
  old_ac = this_player()->query_ac();
  new_ac = old_ac + 1;
  this_player()->set_ac(new_ac);
  call_out("end_bonus", 600);
}

end_bonus() {
  object mark;
  mark = present("shadow-mark", this_player());
  this_player()->set_ac(old_ac);
  mark->add_bonus(-1);
  write("You can feel your shadowy protectiveness leaving you.\n");
  destruct(this_object());
  return 1;
}

