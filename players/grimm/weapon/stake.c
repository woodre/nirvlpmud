inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;
set_name("wooden stake");
        set_alt_name("stake");
        set_short("A wooden stake");
set_long("A very old and long wooden stake.\n");
        set_class(4);
        set_weight(2);
        set_value(30000); /* quest item...so expensive */
}

query_save_flag() { return 0; }
