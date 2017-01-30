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

/* two-handed code <illarion dec 2004>*/
two_handed() { return 1; }
id(str) { 
  if(str == "notarmor" && wielded && previous_object() && previous_object()->query_type()=="shield")
    return 1;
  if(str == "notweapon" && (!previous_object() || previous_object()==this_object())) {
    object *inv;
    int s;
    inv=all_inventory(environment());
    s=sizeof(inv);
    while(s--)
      if(inv[s]->query_type()=="shield" && inv[s]->query_worn())
        return 1;
  }
  return ::id(str);
}