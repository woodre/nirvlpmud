inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("armor");
   set_short("Leather armor");
   set_alias("leather armor");
   set_long("This is a very nice leather armor.\n");
   set_type("armor");
/* This is leather armor, not platemail. -Snow */
   set_ac(2);
   set_weight(2);
   set_value (1000);
}
