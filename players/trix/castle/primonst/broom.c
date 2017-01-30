inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("broom");
   set_alt_name("broom");
   set_alias("broom");
   set_short("A wood broom");
   set_long("This is a normal wood broom but it could hurt enemies if wielded.\n");
   set_class(11);
   set_weight(2);
   set_value(400);
}
