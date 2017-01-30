inherit "obj/armor";
reset(arg) {
   if (arg) return;
   set_name("robe");
   set_short("Monkey's Robes");
/* MIZAN - 2009 sep 11
 * previously, this armor was of type 'chest'. I have since adjusted this
 * to be 'armor' while maintaining the original AC value.
 * Credit for finding this bug goes to Wallace (Data).
 */
   set_type("armor");
   set_alias("robes");
   set_ac(5);
   set_weight(3);
   set_value(10000);
   set_long("Very fancy robes.  They are white with gold trimming.  As you look closer\n"+
           "you see that the gold is very much real.  It doesn't look like it would\n"+
           "provide much protection.\n");
}
