inherit "obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
  set_name("hammer");
  set_alias("hammer");
  set_weight(0);
set_short("Mystical hammer (glowing)");
set_long(
"This is a mystical looking hammer given to you by Matry in return for\n"+
"your faithfulness.\n");
  set_value(0);
}

drop() {
  if(this_object()->query_wielded()) {
    init_command("unwield hammer", this_player());
    destruct(this_object());
    return 1;
  }
  destruct(this_object());
write("You drop the hammer and its magical energies are released back to Matry.\n");
  return 1;
}

