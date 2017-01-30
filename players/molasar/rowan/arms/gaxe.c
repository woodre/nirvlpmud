
/*
 * Generic axe for use with /players/molasar/rowan/obj/tr_gen
 */

inherit "obj/weapon";

reset(arg) {
   if(arg) return;
   set_name("axe");
   set_short("A double-bladed axe");
   set_long("A polished metal axehead attached to a wooden handle.\n");
   set_weight(2);
   set_value(100);
   set_class(10);
}

