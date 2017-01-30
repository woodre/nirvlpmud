
/*
 * Generic flail for use with /players/molasar/rowan/obj/tr_gen
 */

inherit "obj/weapon";

reset(arg) {
   if(arg) return;
   set_name("flail");
   set_short("A flail");
   set_long("A medium-sized flail.\n");
   set_weight(2);
   set_value(100);
   set_class(10);
}

