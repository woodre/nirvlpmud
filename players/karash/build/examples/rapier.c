
/*
 *  A rapier for players to fight with.
 *  Read this, and than BLUEBLADE.c
 *                                             -- Saber
 */

/* This give the weapon the basic characteristics of weapon.c   */
 inherit "obj/weapon.c";

/* The reset is called to check a few certain things...
 *   At the moment, don't mess with it.  Save that for later.  */
 reset(arg) {
    ::reset(arg);
    if (arg) return;

       /* This is the name that the object will respond to. */
    set_name("rapier");
       /* This is ANOTHER name the object will respond to. */
    set_alias("sword");
       /* This is how the object appears in your inventory. */
    set_short("A slender rapier");
       /* This is what the people will see if they 'look' at the item. */
    set_long("A slender rapier made from fine steel.\n");
       /* This is the weapon class.  The higher, the more lethal. */
    set_class(13);
       /* This is how much the object will weigh. */
    set_weight(2);
       /* This is how much gold the object is worth. */
    set_value(450);
}
