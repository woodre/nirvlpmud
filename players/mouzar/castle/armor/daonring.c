inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("nose ring");
   set_short("A nose ring");
/* MIZAN 2009 sep 11
 * changed armor type from 'glove' to 'ring'
 * Bug found by Wallace (Data).
 */
   set_type("ring");
   set_alias("ring");
   set_ac(1);
   set_weight(1);
   set_value(500);
  set_long("A very good looking nose ring.  You can see some slimy stuff on it.\n");
}
