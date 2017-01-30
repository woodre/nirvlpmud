inherit "obj/weapon.c";
#define TP this_player() 
#define TO this_object()
#define ENV environment 
#define CAP capitalize
 
int deaths;
 
set_deaths(amt) { deaths = amt; }
 
query_extra_look() {
  return "" + CAP(ENV(TO)) + 
         " has a sinister look to them";
}

query_save_flag() { return 1; }
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  deaths = 0;
  set_name("sword of death");
  set_alt_name("sword");
  set_short("Sword of Death");
  set_long(
        "This is the Sword of Death.  It uses the souls of your fallen\n"+
        "foes to bring you more power in combat!  You can feel evil\n"+
        "through your veins.  You can feel your heart beat harder and\n"+
        "faster, and your urge to kill is growing stronger and stronger\n"+
        "To remove the soul of your fallen foe into the sword type 'getsoul'\n");
  set_class(17);
  set_value(55000);
  set_weight(5);
  set_wield_func(this_object());
  set_hit_func(this_object());
}
 
init() {
  ::init();
  add_action("remove_corpse_soul"); add_verb("getsoul");
  add_action("count_souls");        add_verb("countsouls");
}
 
/* remove the soul of the corpse */
 
remove_corpse_soul() {
  if(!present("corpse",ENV(TP))) {
    write("Your sword respondss violently to your attempt to feed it nothing\n");
    return 1;
  }
  write("You stab your sword violently into the now dead body.\n");
  write("The sword drains its remaining soul\n");
  say(CAP(TP->query_name())+" violently sticks their sword into the corpse\n");
  deaths++;
  if(deaths > 200) deaths = 200;
  destruct(present("corpse",ENV(TP)));
  return 1;
}
 
count_souls() {
  write("The sword has drained "+deaths+" souls.\n");
  return 1;
}
 
wield() {
  if(ENV(TO)->query_alignment() <= - 500) {
    write("You are taken aback by the evilness of the weapon as you take\n"+
          "hold of it in your hand.\n");
    say("You see "+CAP(TP->query_name())+"'s grin grow extremely evil as they\n"+
        "wield the Sword of Death.\n");
    wielded_by = this_player();
    call_other(TP,"wield",TO);
    wielded = 1;
    return 1;
  }
  write("You feel a tremendous evil take control of your body\n"+
        "as the sword crumbles to dust in your fingers.\n");
  say("You see "+CAP(TP->query_name())+" get a glitter of evil in\n"+
      "their eye as their sword crumbles to dust in their hands.\n");
  destruct(TO);
  return 1;
}  
 
weapon_hit(attacker) {
  int align, third, fifth, dam;
  
  dam = 0;
  align = TP->query_alignment();
  fifth = (deaths / 3); /* total number of return points possible */
  third = (fifth / 3);   /* a third of the return is set */
 
/* If the player's alignment goes over -500 while wielding the weapon */
/* in combat it will self destruct */
 
  if(align > -500) {
    write("You feel a tremendous evil take control of your body\n"+
          "as the sword crumbles to dust in your fingers.\n");
    say("You see "+CAP(TP->query_name())+" get a glitter of evil in\n"+
        "their eye as their sword crumbles to dust in their hands.\n");
    destruct(TO);
    return 1;
  }
  
  if(!attacker->query_npc()) {
    if(random(100) < 10) {
      write("As you are in combat with another player the sword\n");
      write("strikes with less force!\n");
    }
    return 0;
  }
  if(TP->query_pl_k() && !attacker->query_npc()) {
    if(random(100) < 80) {
      if(random(100) < 15) {
        write("You feel your sword draw more life from the enemy!\n");
      }
      dam += random(third) + ((1/2) * third);
    }
  }
  if(random(100) < 70) {
    write("You feel the sword strike "+CAP(attacker->query_name())+
          " removing part of their soul!\n");
    say(CAP(TP->query_name())+"'s sword strikes "+CAP(attacker->query_name())+
        "removing part of their soul!\n");
    dam += random(third) + random(third) + third;
  }
  return dam;
}

