 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("tree");
    set_type("staff");         /* set type added by Pavlik */
    set_short("A small tree");
     set_long("A small tree.  It looks like it was ripped from the ground.\n");
    set_class(17);
    set_weight(6);
    set_value(400);
}
