 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("tetsubo");
    set_alias("tets");
    set_type("polearm");
    set_short("A Two-handed Tetsubo");
    set_long("The Tetsubo is a devestating weapon against anyone who is\n"+
             "unarmored. It is an eight foot long club ringed with small\n"+
             "metal points, used to deliver crushing blows to any foe.\n"+
             "Quite a nasty little weapon.\n");
    set_class(16);
    set_weight(2);
    set_value(1200);
}
