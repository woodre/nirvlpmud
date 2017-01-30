/* Simple save_object and restore_object tester */

inherit "/obj/treasure";

string ostring;
int oint;

void
reset(status arg) {
  if (arg) return;
  ::reset(arg);
  set_name("tester");
  set_short("Tester");
  set_long("A save_object and restore_object tester.\n" +
           "You can use 'stest' or 'rtest' to test saving and restoring \n");
}

int get() { return 1; }

void
init() {
  ::init();
  add_action("test_func", "stest");
  add_action("test_func", "rtest");
  add_action("var_func", "varlist");
  add_action("var_func", "varset");
}

int test_func() {
  if (query_verb() == "stest")
    save_object("players/rumplemintz/wiz/tester2");
  else
    if (restore_object("/players/rumplemintz/wiz/tester2")) {
      write("Restore returned 1\n");
    } else { write ("Restore returned 0\n");
    }
    restore_object("players/rumplemintz/wiz/tester2");
  write(query_verb() + ".\n");
  return 1;
}

int var_func() {
  if (query_verb() == "varlist") {
    write("ostring set to " + ostring + ".\n");
    write("oint set to " + oint + ".\n");
  } else {
    write("Changing variables.\n");
    oint = !oint;
    if (ostring == "set") ostring = "not_set"; else ostring = "set";
  }
  return 1;
}
