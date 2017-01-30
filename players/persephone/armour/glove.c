/* Glove value changed from 1000 to 100 due to description and low level monster. -Snow 1/00 */
inherit "obj/armor";
reset(arg) {
    ::reset();
    if (arg) return;
    set_name("glove");
    set_alias("glove");
    set_type("ring");
    set_short("Pirate glove");
    set_long("This is a rough, raggedy glove used by pirates.\n");
    set_ac(1);
    set_weight(2);
    set_value(100);
}
