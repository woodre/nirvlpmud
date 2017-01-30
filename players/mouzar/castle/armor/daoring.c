inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("ring");
   set_short("A gold ring");
/* MIZAN 2009 sep 11
 * Armor type was 'gloves', changed to 'ring'.
 * Bug spotted by Wallace (Data).
 */
   set_type("ring");
   set_alias("gold ring");
   set_ac(1);
   set_weight(1);
   set_value(600);
  set_long("A very pretty ring with a gem placed on top of it.\n");
}
