#define tp this_player()->query_name()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if(arg)  return;
   set_name("two scimitars");
   set_alias("scimitar");
   set_type("sword");         /* set type added by Pavlik */
   set_alt_name("scimitars");
   set_short("A pair of Silver Scimitars");
   set_long("A pair of enchanted scimitars forged from cold silver.\n"+
     "They are covered with dark runes.\n");
   set_read("Forged by Laura, Weapons Master of the Bards.\n");
   set_class(18);
   set_weight(3);
   set_value(1500);
   set_hit_func(this_object());
}

/* two-handed code */
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
  int w, x, y;
/* flat 1/3 chance for NPCs, players can get odds higher with dex attrib
   - illarion dec 2004
*/
  w = random(15);
  x = random(3);
  if(this_player()->is_player())
    w=random(this_player()->query_attrib("dex"));
  if(w > 10)  {
    if(x == 0)  {
      say(tp+" spins with a deadly grace through combat, wetting "+this_player()->query_possessive()+" silver scimitars\n"+
      "with "+attacker->query_name()+"'s blood.\n");
      write("You spin with a deadly grace through combat, wetting your silver\n"+
      "scimitars with "+attacker->query_name()+"'s blood.\n");
    }
    else if(x == 1)  {
      say(tp+" weaves through combat with a deadly grace, striking quickly with\n"+
      this_player()->query_possessive()+" silver scimitars.\n");
      write("You weave through combat with a deadly grace, striking quickly with\n"+
      "your silver scimitars.\n");
    }
    else if(x == 2)  {
      say(tp+" strikes with blinding speed,slashing "+attacker->query_name()+" twice with "+this_player()->query_possessive()+"\n"+
      "paired silver scimitars.\nYou watch blood spray in every direction.\n");
      write("You strike with blinding speed, slashing "+attacker->query_name()+" twice with your\n"+
      "paired silver scimitars.\nYou watch blood spray in every direction.\n");
    }
    /* upped the return value because of the two-handed limitation */
    return 10;
  }
  return;
}
