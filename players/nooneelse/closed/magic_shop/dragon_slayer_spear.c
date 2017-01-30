/*
  dragon_slayer_spear.c
*/

inherit "obj/weapon";

reset(arg){
  if(arg) return;
  ::reset(arg);

  set_name("Dragonslayer spear");
  set_alt_name("spear");
  set_alias("spear");
  set_short("An incredibly sharp spear");
  set_long("This is spear was designed to pierce dragon scales.\n"+
           "\nA small label says: Made by Nooneelse's Doodads Inc.\n");
  set_class(15);
  set_weight(3);
  set_value(12000);
  set_hit_func(this_object());
}

set_save_flag() { save_flag = 1; }
query_save_flag() { return save_flag; }

weapon_hit(attacker){
  if (attacker->id("dragon")){
    this_object()->set_class(20);
    say("\n"+capitalize(this_player()->query_name())+
        "'s Dragonslayer Spear flashes brightly!\n\n");
    write("The Dragonslayer Spear flashes brightly!\n\n");
  }
  else {
    this_object()->set_class(15);
    say("\nThe glow on "+capitalize(this_player()->query_name())+
        "'s Dragonslayer Spear fades.\n\n");
    write("The glow on the Dragonslayer Spear fades.\n\n");
  }
}

id(str) { return str=="spear" ||
                 str=="dragon slayer spear" ||
                 str=="dragonslayer spear" ||
                 str=="dragonslayer" ||
                 str=="dragon_slayer_spear"; }
