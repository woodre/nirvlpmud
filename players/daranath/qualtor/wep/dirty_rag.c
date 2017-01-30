 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("rag");
    set_alias("dirty");
    set_type("rag");
    set_short("A dirty and nasty rag");
    set_long("A smelly and dirty rag, Homer used this to clean most of the\n"+
             "glasses within the bar. Blood stains the rag now.\n");
    set_class(15);
    set_weight(1);
    set_value(100);
}
