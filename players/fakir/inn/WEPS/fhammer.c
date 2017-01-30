inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("hammer");
  set_alias("hammer");
  set_short("Forge Hammer");
  set_long("This two-and-a-half pound forge hammer has a rounded\n"+
    "head on one side and a flat face on the other.  The handle\n"+
    "is at least two feet long and made of well seasoned hickory.\n");
  set_class(15);
  set_weight(2);
  set_value(500);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(20);
if(W>14)  {
  say("\nThe Forge Hammer slams into its foe.\n\n"+
    "    ~~~~~~~~~ B A S H ~~~~~~~~~\n\n"+
    "You see BRAIN TISSUE fly everywhere.\n");
  write("\nThe Forge Hammer slams into your foe.\n\n"+
    "     ~~~~~~~~ B A S H ~~~~~~~~\n\n"+
    "The SKULL is CRUSHED and BRAIN TISSUE flies everywhere.\n");
return 4;

   }
   return;
}
