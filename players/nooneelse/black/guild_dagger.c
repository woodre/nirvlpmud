/*
 guild_dagger.c
*/

inherit "obj/weapon";

string str;

int new_wc;

object dagger;

init() {
  ::init();

  if (!living(environment(this_object())) ||
      !present("vampire fangs", environment(this_object())))
    call_out("trash_this", 10);
}


trash_this() { destruct(this_object()); }

query_save_flag() { return 1; }

reset(arg) {
  ::reset(arg);

  set_name("guild dagger");
  set_class(2);
  set_weight(2);
  set_value(0);
  set_short("a black dagger");
  set_long("It is a sharp dagger made of a black metal.\n");
  set_read("For use by guild members only");
}

prevent_insert() {
  write("You don't really want to hide your guild's dagger do you?\n");
  return 1;
}

set_class(new_wc) { class_of_weapon = new_wc; }

id(str) { return (str=="dagger" || str=="guild dagger" || str=="black dagger"); }
