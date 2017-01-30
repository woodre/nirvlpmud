/*
 guild_tuxedo.c
*/

inherit "obj/armor";

string str;
int test_ac;
object tuxedo, item_obj;

int new_ac;

init() {
  ::init();

  if (!living(environment(this_object())) ||
      !present("vampire fangs", environment(this_object())))
    call_out("trash_this", 10);
  add_action("check_armor", "wear");
}

trash_this() { destruct(this_object()); }

/* can't give them too much ac with this free armor! */
check_armor(str) {
  test_ac=this_player()->query_ac();
  item_obj=present(str, this_player());
  if (!item_obj) return;
  test_ac=test_ac + item_obj->query_ac();
  if (test_ac > 10) {
   write("White letters on your black tuxedo start to glow.  They say:\n"+
          "     I think you're wearing too much armor.\n");
    return 1;
  }
}

query_save_flag() { return 1; }

reset(arg) {
  ::reset(arg);

  set_name("tuxedo");
  set_short("a black tuxedo");
  set_value(0);
  set_weight(2);
  set_ac(2);
  set_type("armor");
}

prevent_insert() {
  write("You don't really want to hide your guild's tuxedo do you?\n");
  return 1;
}

set_ac(new_ac) { ac = new_ac; }

id(str) { return (str=="tuxedo" ||
                  str=="guild tuxedo" ||
                  str=="black tuxedo"); }
