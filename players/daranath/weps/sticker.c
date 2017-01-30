/*
 *    A pig-sticker carried by an ugly orc.
 */

inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("pig-sticker");
    set_alias("sticker");
    set_alt_name("stick");
    set_short("A wooder pig-sticker");
    set_long("A sharpened stick with a point on one end.\n"+
             "It looks like it is used to kill pigs.\n");
    set_class(12);
    set_weight(2);
    set_value(50);
}

