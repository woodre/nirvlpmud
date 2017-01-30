inherit "obj/weapon.c";
 
/* Shadow Sword.  12-25-94 */
/* The Shadow Sword is a powerful weapon which, if used by a player with */
/* a greater than 0 alignment will self destruct it. */
/* It is also the Shadow Guild Weapon as it will increase its return */
/* for each guild level the player has */
 
reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("sword of darkness");
  set_alt_name("sword");
  set_short("Sword of Darkness");
  set_long(
    "As you attempt to peer along the blade of the sword you can\n"+
    "faintly see a silhouette of a blade.  You can feel tremendous\n"+
    "evil radiating from the sword giving it an immense amount of\n"+
    "power.\n");
  set_class(18);
  set_weight(5);
  set_value(50000);
  set_hit_func(this_object());
}
 
/*
query_save_flag() { return 1; }
*/
 
weapon_hit(attacker) {
  int align, totret;
  string guild;
  
  totret = 0;
  
  align = environment(this_object())->query_alignment();
  guild = environment(this_object())->query_guild_name();
 
/* if person wielding this weapon's alignment is > 0 it will destruct */
/* itself */
 
  if(align > 0) {
    write("You feel the sword begin shaking violently in your hands\n");
    write("as a huge vortex appears and pulls it from your grasp!\n");
    say("You see "+capitalize(environment(this_object())->query_name())+"'s"+
        "weapon begin shaking out of control\n");
    say("in their hands as a huge, shadowy vortex appears and pulls the\n");
    say("weapon from their hands!\n");
    command("unwield sword", environment(this_object()));
    destruct(this_object());
    }
 
/* Just for an alignment bonus the player will get a guaranteed */
/* return of 3 + a random number of 0-2 */
/* This bonus is applicable 35% of the time */
 
  if(align < 0) {
    if((random(100) < 50)) {
      totret += (3 + random(3));
      }
    }
  /* end alignment section */
 
/* If Wielder is a player killer, then they get a bonus of 4 + random(4) */
/* 70% of the time. */
 
  if(environment(this_object())->query_pl_k() && !attacker->query_pl_k()) {
    if((random(10) < 7)) {
      write("You feel your more sinister side take hold with the\n");
      write("blade as your blows get more and more viscious!\n");
      totret += (4 + random(4));
      }
    }
  /* end player killer section */
 
/* For being in the shadow guild while using this weapon yields the */
/* player an extra 2 + random(4) points of damage */    
 
  if(guild == "shadow") {
    if(random(10) > 5) {
      write("You feel your shadow grow stronger with each hit!\n");
      say("You see "+capitalize(environment(this_object())->query_name()) +
          "'s shadow grow stronger with each swing of their sword!\n");
      }
    else {
      write("Your shadowy darkness begins to overwhelm the sword as it\n"+
            "hacks and slashes with immense power!\n");
      say("You see "+capitalize(environment(this_object())->query_name()) +
          "'s sword grow stronger!\n");
    }
    /* shadows will get a bonus 80% of the time */
    /* the bonus will be from 2-6 more damage */
    if((random(100) < 80)) {
      totret += (2 + random(4));
      }
  }
  /* end shadow section */
  return totret;
}

