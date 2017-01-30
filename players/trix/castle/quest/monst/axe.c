inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("axe");
   set_alt_name("iron axe");
   set_alias("axe");
   set_short("An iron orchish axe");
   set_long("This is an orcish axe, a rough and heavy weapon built up by a stick of wood on\n"+
            "which has been applied a piece of barely sharpened iron.\n");
   set_class(16); /* From wc5 to wc16 -Feldegast 9-23-00 */
   set_weight(3);
   set_value(400);
}
