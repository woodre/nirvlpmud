 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("demon claws");
    set_alias("claws");
    set_type("claws");         /* set type added by Pavlik */
   set_alt_name("demonclaws");
    set_short("Demon Claws");
    set_long("A small pair of claws taken from a minor demon.\n"+
       "They look like they would make a decent weapon.\n");
    set_class(9);
    set_weight(1);
    set_value(25);
}

quest_ob()  { return 1; }
