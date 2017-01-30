inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("armor");
   set_short("Gdemia chain mail");
   set_alias("mail");
   set_long("This is a very nice chainmail made by Gdemia blacksmithes.\n");
   set_type("armor");
/* Changed from 4 to 3 (weaker than plate) -Snow 3/00 */
   set_ac(3);
   set_weight(2);
   set_value (1000);
}
