
/*
 * Generic sword for use with /players/molasar/rowan/obj/tr_gen
 */

inherit "obj/weapon";

reset(arg) {
   if(arg) return;
   set_name("sword");
   set_short("A shortsword");
   set_weight(2);
   set_value(100);
   set_class(10);
}

