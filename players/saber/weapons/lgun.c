int w, z;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
   set_name("lazer gun");
    set_alias("gun");
    set_type("gun");         /* set type added by Pavlik */
    set_short("A lazer gun");
   set_long("A fully automatic lazer pistol.\nIt has a full charge.\n");
    set_class(16);
    set_weight(2);
    set_value(700);
    /* converted weapon_hit to laser type and lowered the damage a bit
      - the monster it's from isn't very hard - illarion 2 dec 2004
    set_hit_func(this_object());
    */
    set_params("other|laser",0,"laser_hit");
}
laser_hit(attacker){
  int extra;
  w=random(100);
  
  if (w>65) {
    
    say(this_player()->query_name()+" blasts "+attacker->query_name()+" with a burst of full auto lazer fire.\n");
    write("You empty a full clip of lazer fire into "+attacker->query_name()+"\n"+
    "You quickly reload.\n");
    
    if(w> 94)  {
      z = random(10);
      
      tell_room(environment(this_player()),
      this_player()->query_name()+" blows the hell outta "+attacker->query_name()+".\n");
      
      while (z < 10)  {
      
        tell_room(environment(this_player()),
        "\n   SSSSSSHHHHHHHHHHHHZZZZZZZTTTTTTTT\n");
        z = z + 1;
        /* add some extra damage when this happens, which isn't much */
        extra++;
      }
    
      write("\n");
      say("\n");
    }
    return 4+extra;
  }
}
