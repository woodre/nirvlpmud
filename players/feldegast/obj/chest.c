inherit "/obj/treasure.c";

int damsel;

void reset(int arg) {
  set_id("chest");
  set_alias("miniquest-like chest-sorta thingy");
  set_short("A mahogany chest");
  set_long("This is a finely crafted mahogany chest, bound with iron\n"+
           "and sturdily constructed.  The lock has been dented repeatedly,\n"+
           "as though someone had attempted to force the lock.\n");
  set_weight(20);
}

get() {
  if(environment() && present("brigand",environment())) {
    write("The brigand prevents you from taking it.\n");
    return 0;
  }
  else return 1;
}

set_damsel(arg) { damsel=arg; }
query_damsel() { return damsel; }
