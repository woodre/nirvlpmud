inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("smock");
   set_short("Homer's Dirty Smock");
   set_alias("Smock");
   set_long("A dirty bartender's smock, this does not provide much protection\n"+
            "against attacks, but it sure helps to kept the bar clean.\n");
   set_type("armor");
   set_ac(1);
   set_weight(1);
   set_value(100);
}
