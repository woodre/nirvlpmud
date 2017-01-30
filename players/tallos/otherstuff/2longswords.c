#define tp this_player()->query_name()
 inherit "obj/weapon.c";
int w;
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("two longswords");
   set_alias("longsword");
   set_type("sword");         /* set type added by Pavlik */
   set_alt_name("longswords");
   set_short("A pair of Magical Longswords");
   set_long("A pair of enchanted longswords forged from cold iron.\n"+
     "They are covered with silver runes.\n");
   set_read("Forged by Laura, Weapons Master of the Bards.\n");
   set_class(17);
   set_weight(3);
   set_value(800);
   set_hit_func(this_object());
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


weapon_hit(attacker){
   w=random(15);
   /* added by illarion dec 2004 */
   if(this_player()->is_player())
     w=random(this_player()->query_attrib("str")*3/4);  /*same as static odds at str 20 */
   if (w>11) {
say(tp+" is bathed in a blue aura as the silver runes on the\n"+
     "longswords pulse with ancient power.\n");
write("You are bathed in a blue aura as the silver runes on your\n"+
     "longswords pulse with ancient power.\n");
return 7;
    }
    return;
}
