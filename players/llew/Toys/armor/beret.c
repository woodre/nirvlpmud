inherit "obj/armor";

reset(arg) {
  ::reset(arg);
   if(arg) return;
   set_name("beret");
   set_short("A black beret");
   set_value(125);
   set_weight(1);
   set_alias("sergeant_beret");
   set_ac(1);
   set_long("A sleek black beret of an special forces sergeant.\n");
   set_type("helmet");
}
