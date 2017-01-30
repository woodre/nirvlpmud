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


weapon_hit(attacker){
int w, x, y;

   w = random(14);
   x = random(3);

if(w > 9)  {
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
return 7;
    }
    return;
}

query_save_flag()  { return 0; }
