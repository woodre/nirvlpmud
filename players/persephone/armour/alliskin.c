inherit "obj/armor";
reset(arg){
 if(arg) return;
  set_name("skin");
  set_alias("armor");
  set_short("Alligator Skin Armor");
  set_long("A tough alligator skin suit that magically seems to transform\n" +
           "to your body shape and size.  It seems to be extremely durable\n" +
           "and strong.\n");
  set_value (8000);
  set_weight(3);
  set_ac(3);
  set_type("armor");
}
