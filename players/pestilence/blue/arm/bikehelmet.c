inherit "obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("bicycle helmet");
   set_alias("bicycle");
   set_type("helmet");
   set_short("A bicycle helmet");
   set_long("This is a red bicycle helmet.  It only covers the very top part of someone's head.\n");
  set_ac(1);
   set_weight(1);
   set_value(50);
}
