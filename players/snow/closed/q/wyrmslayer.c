/*
Wyrmslayer is a quest weapon. It is made by the forging of three
weapons - ~/WEAPONS/ souleater and greydeath 
          ~/shadows/objects/nightshade
Each of these weapons is extremely difficult to obtain.
*/
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "obj/weapon.c";
 
int orb;
int usedup;
set_orb(int o) { orb = o; }
query_orb() { return orb; }
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("wyrmslayer");
    set_alt_name("guild_weapon");
    set_alias("blade");
    set_type("sword");
    set_short("Wyrmslayer");
    set_save_flag(0);
    set_class(21);
    set_weight(3);
    set_value(20000);
    set_hit_func(this_object());
}
 
long() {
  write("A blade forged of three. The power of the vortex, night, and soul\n"+
        "were combined in purpose. Engravings of dragons play along the \n"+
        "wicked length of keen adamantium.\n");
  if(orb) write("A glowing orb rests on the pommel.\n");
  if(!orb) write("The pommel has a spherical indentation.\n");
  if(usedup) write("The blade seems a bit rusty.\n");
  return 1;
}

query_ice_kill_wep() { return 1; }
 
weapon_hit(meat) {
  if(call_other(meat,"id","dragon") && !usedup) {
    say(TPN+"'s blade blurs in energy flashes!\n");
    write("Wyrmslayer blurs in energy flashes!\n");
      if(call_other(meat,"id","icingdeath")) {
        write("Your blade plunges into its ancient foe!\n");
        meat->heal_self(-30);
/* Don't need this. -snow
        meat->set_heal(1,20);
*/
        if(meat->query_attack() == TP) TP->add_hit_point(random(35)+10);
      }
     meat->heal_self(-5);
     return 3;
  }
  if(orb) {
    say("Blue lightning crackles along the length of "+TPN+"'s blade.\n");
    write("Blue lightning crackles along the length of Wyrmslayer.\n");
    return 3;
  }
       return;
}

quest_ob() { return 1; }
set_usedup() { usedup = 5; }

/* Added [7.25.05] for BF - Fred */
query_nonchoose(){ return 1; }
