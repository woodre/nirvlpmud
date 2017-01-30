inherit "obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
  set_name("magical vestment");
  set_alias("vestment");
  set_weight(0);
  set_type("armor");
set_short("Magical vestment (glowing)");
  set_long(
  "     This is a misty looking armour that surrounds the wearer. It is\n"
+ "     weightless but offers powerful protection. It is very hard to\n"
+ "     see and will disappear when dropped.\n");
  set_value(0);
}

drop() {
  if(this_object()->query_worn()) {
    command("remove vestment", this_player());
    destruct(this_object());
    return 1;
  }
  destruct(this_object());
  return 1;
}

