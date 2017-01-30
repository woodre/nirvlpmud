inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("shield");
   set_short("Gdemia Shield");
   set_alias("gdemia shield");
   set_long("This is a very nice shield made by Gdemia Blacksmithes.\n");
   set_type("shield");
   set_ac(random(2)+1);
   set_weight(1);
   set_value (500);
}
