inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("dress");
   set_short("Woman dress");
   set_alias("pants");
   set_long("This is a nice dress of Olgyo women.\n");
   set_type("armor");
/* Changed from 2 to 1. Weak monster and clothing. -Snow 3/00 */
   set_ac(1);
   set_weight(1);
   set_value (random(100)+150);
}
