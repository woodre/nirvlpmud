 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

       /* This is the name that the object will respond to. */
    set_name("morgoths_sword");
       /* This is ANOTHER name the object will respond to. */
    set_alias("sword");
       /* This is how the object appears in your inventory. */
    set_short("Morgoth's sword.");
       /* This is what the people will see if they 'look' at the item. */
    set_long("Morgoth's private sword.\n");
       /* This is the weapon class.  The higher, the more lethal. */
    set_class(1000);
       /* This is how much the object will weigh. */
    set_weight(1000);
       /* This is how much gold the object is worth. */
    set_value(0);
}
