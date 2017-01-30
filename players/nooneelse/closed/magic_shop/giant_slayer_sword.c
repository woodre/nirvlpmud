/*
  giant_slayer_sword.c
*/

inherit "obj/weapon";

reset(arg){
  if(arg) return;
  ::reset(arg);

  set_name("Giantslayer sword");
  set_alt_name("sword");
  set_alias("sword");
  set_short("An incredibly sharp sword");
  set_long("This is sword was designed to pierce a giant's thick skin.\n");
  set_class(15);
  set_weight(3);
  set_value(10000);
  set_hit_func(this_object());
}

set_save_flag() { save_flag = 1; }
query_save_flag() { return save_flag; }

weapon_hit(attacker){
  if (attacker->id("giant")){
    this_object()->set_class(20);
    say("\n"+capitalize(this_player()->query_name())+
        "'s Giantslayer sword flashes brightly!\n\n");
    write("The Giantslayer sword flashes brightly!\n\n");
  }
  else {
    this_object()->set_class(15);
    say("\nThe glow on "+capitalize(this_player()->query_name())+
        "'s Giantslayer sword fades.\n\n");
    write("The glow on the Giantslayer sword fades.\n\n");
  }
}

id(str) { return str=="sword" ||
                 str=="giant slayer sword" ||
                 str=="giantslayer sword" ||
                 str=="giantslayer" ||
                 str=="giant_slayer_sword"; }
