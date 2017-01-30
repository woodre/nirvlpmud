inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("leather");
   set_short("Supple leather armor");
   set_alias("leather");
   set_long("Strong yet light and flexible leather armor. A favorite of thieves\n"+
     "throughout the realms.\n");
   set_type("armor");
   set_ac(3);
   set_weight(1);
   set_value(2750);
}

