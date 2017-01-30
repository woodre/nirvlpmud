inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("armor");
   set_short("Padded armor");
   set_alias("padded armor");
   set_long("This is padded armor of Olgyo hunters.\n");
   set_type("armor");
/* Changed ac from 3 to 2. It's very light and cheap archer armor. -Snow 3/00 */
   set_ac(2);
   set_weight(1);
   set_value(200);
}
