int w, z;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("revolver");
    set_alias("colt");
    set_type("gun");         /* set type added by Pavlik */
    set_short("A Colt .68 Heavy Revolver");
    set_long("The biggest Heavy Revolver you have ever seen!\n");
    set_class(17);
    set_weight(2);
    set_value(800);
    set_hit_func(this_object());
}
weapon_hit(attacker){
  int total;
  if(environment()->is_player())
    w=random(this_player()->query_attrib("dex"));
  else if(environment()->is_kid())
    w=random(17);
  else
    w=random(30);
    /* 35% chance at dex 30 */
  if (w>random(40)) {
    total=7;
    say(this_player()->query_name()+" blows "+attacker->query_name()+" away with a well aimed shot from "+this_player()->query_possessive()+" Colt .68\n");
    write("You knock "+attacker->query_name()+" back with a well placed shot from your Colt .68\n");
    
    if(w>random(50))  {
      z = random(6);
      tell_room(environment(this_player()),
      this_player()->query_name()+" fires again at "+attacker->query_name()+".\n");
      
      while (z < 6)  {      
        tell_room(environment(this_player()),"\n BAMN!\n");
        z = z + 1;
        total++;
      }
      
      write("\n");
      say("\n");
      /* Instead of heal_self we'll add 1 point for each extra shot to the return
         (the monster this is from isn't hard enough to justify heal_self damage)
         - illarion 2 dec 2004
      attacker->heal_self(-5);
      */
    }
    return total;
  }
}
