inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("katsuit");
   set_short("A bonafide skin-tight katsuit");
   set_alias("leather");
   set_long("A suit of skin tight black leather armor, the katsuit got\n"+
            "its name from the small set of cat like ears attaches to a\n"+
            "a leather hood. The tight black leather brings out every curve\n"+
            "of the wearer, driving members of the opposite sex\n"+
            "absolutly crazy.\n");
   set_type("armor");
   set_ac(3);
   set_weight(1);
   set_value(175);
}
