 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

       /* This is the name that the object will respond to. */
    set_name("sword");
       /* This is ANOTHER name the object will respond to. */
    set_alias("sword");
       /* This is how the object appears in your inventory. */
    set_short("A long sword.");
       /* This is what the people will see if they 'look' at the item. */
    set_long("A long, heavy sword made of the finest steel.\n");
       /* This is the weapon class.  The higher, the more lethal. */
    set_class(15);
       /* This is how much the object will weigh. */
    set_weight(3);
       /* This is how much gold the object is worth. */
    set_value(600);
}
