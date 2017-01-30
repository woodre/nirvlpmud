inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("claws");
  set_alias("claw");
  set_short("Claws of a Drake");
  set_long("You behold a set of gleaming metallic claws.\n"+
           "You shiver in fear and delight as you touch the razor edges.\n");
  set_class(16);
  set_weight(3);
  set_value(1500);
  set_hit_func(this_object());
}

query_save_flag() { return 0; }
query_dwep() { return 1; }

weapon_hit(attacker){
if(random(3) == 0) {
  say(this_player()->query_name()+" strikes out with great speed!\n"+
      "Razor-like claws slice into "+attacker->query_name()+"'s flesh!\n");
  write("You strike with great speed!\n\n"+
      "Razor-like claws slice into your enemy's flesh!\n");
return 9;   /* wc 16 return 9 = eff_wc = 25.... legal */
}
   return;
}
