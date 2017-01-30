 inherit "obj/weapon.c";
 reset(arg) {
   ::reset(arg);
    if (arg) return;
    set_name("battle axe");
   set_alias("axe");
   set_type("axe");         /* set type added by Pavlik */
   set_short("A two handed battle axe");
   set_long("A massive two handed battle axe.\n"+
     "It has a blade which has been sharpened a fine edge.\n");
    set_class(17);
    set_weight(4);
    set_value(550);
}
