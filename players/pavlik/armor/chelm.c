inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_short("A Steel Helmet");
   set_arm_light(0);
set_long(
"This is a highly polished steel helm that would provide adaquate\n"+
  "protection for one's head.\n");
   set_ac(1);
   set_weight(1);
   set_value(100);
   set_alias("helmet");
   set_name("helmet");
   set_type("helmet");
}
