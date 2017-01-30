inherit "obj/weapon";
 
reset(arg) {      
  ::reset(arg);
  if (arg) return;
  set_name("fly swatter"); 
  set_alias("fly");
  set_class(0);
  set_short("A Powerful Fly Swatter"); 
  set_long("This weapon is stronger than RAID! \n"+
        "It kills everything except wizzes.\n");
  set_value(0);
  set_weight(0);
  
set_hit_func(this_object());
}
 
weapon_hit(attacker) {
int mxhp, mon_ac, damage;
mxhp = attacker->query_mhp();
mon_ac = attacker->query_ac();
damage = mxhp + mon_ac;
attacker->hit_player(damage-1); 
write("You swat across "+attacker->query_name()+"'s head.\n");
say(this_player()->query_name()+" swats "+query_possessive()+" fly"+
" swatter across "+attacker->query_name()+"'s head.\n");
return 100000;
   }
drop() {
  return 0;
} 
