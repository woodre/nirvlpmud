inherit "obj/armor";
reset(arg){
   ::reset(arg);
    set_name("shades");
    set_alias("mirrorshades");
    set_short("Mirrorshades");
    set_long("High quality mirrored sunglasses.\n");
   set_type("helmet");
   set_ac(1);
   /* sunglasses protect against bright light
    - illarion 2 dec 2004
    */
   set_params("other|light",0,20,0);
   set_weight(1);
   set_value(50);
}
