
/*
 * GENERIC PRACTICE MONSTER
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("monster");
   set_alias("practice monster");
   set_short("A practice monster");
   set_long("This is a generic practice monster for training.\n");
   set_aggressive(1);
   ::reset();
}

