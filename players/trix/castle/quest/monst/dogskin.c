inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_short("A dog skin");
   set_long("The skin of a rabid dog, it's brown and dirty.\n");
   set_ac(2);
   set_weight(1);
   set_value(50);
   set_alias("armor");
   set_name("skin");
   set_type("armor");
}
