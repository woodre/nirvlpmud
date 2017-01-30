inherit "obj/container.c";
 reset(arg) {
  ::reset(arg); /* changed from reset() */
    if (arg) return;
    set_name("bag");
    set_short("A bag of holding");
    set_long("A magical bag of holding.\n");
    set_weight(0);
    set_value(250);
    set_max_weight(100000);
}

query_save_flag() { return 1; }
