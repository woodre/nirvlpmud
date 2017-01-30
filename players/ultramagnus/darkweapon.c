/* Weapon for Dark Riders -Snow 3/00 */
inherit "/obj/weapon.c";
string wep;
reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(4);
  switch(i) {
    case 1: wep = "longsword"; set_type("sword"); break;
    case 2: wep = "mace"; set_type("club"); break;
    case 3: wep = "spear"; set_type("polearm"); break;
    default: wep = "broadsword"; set_type("sword"); break;
  }
  set_name(wep);
  set_class(random(3)+15);
  set_value(class_of_weapon * 75);
  set_weight(class_of_weapon - 14);
  set_short("Dark Rider "+capitalize(wep));
  set_long("This is a "+wep+" forged by Sauron's minions for use by his\n"+
     "assassins, the Dark Riders. It is made of dark iron and pulses\n"+
     "darkly as you look at it.\n");
  set_hit_func(this_object());
  set_save_flag(1);
}
weapon_hit(ob) {
  if(!random(4)) {
    write("Your "+wep+" pulses as you swing.\n\tYour arm tingles with dark power.\n");
    say(environment()->query_name()+"'s "+wep+" pulses with dark power.\n");
    return random(4)+3; }
  return 0;
}
