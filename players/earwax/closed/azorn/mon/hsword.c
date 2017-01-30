/* holy_sword.c
 * Example of a sword that does additional good damage, but only if it's
 * wielded by a good-aligned player against an evil-aligned monster
 * Illarion (6/04)
 */

inherit "/obj/weapon.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("sword");
  set_short("A holy sword");
  set_long("While to casual observation this is just another sword, it\n"+
           "exudes an aura of holiness.\n");
/* physical damage */
  set_class(16);
/* Good damage type with no class but with a function name */
/*
  set_params("other|good",20,"holy_hit");
*/
  set_params("other|evil",20,"evil_hit");
  
  set_weight(3);
  set_value(2000);
}


/* This function deals the actual damage if the wielder and attacker qualify */
int holy_hit(object attacker) {
  if(!attacker || !wielded_by)
    return 0;
  if(attacker->query_alignment() < -100 && wielded_by->query_alignment() > 100) {
    tell_object(wielded_by,"Your sword shines with a holy light.\n");
    tell_object(attacker,wielded_by->query_name()+"'s sword shines with a holy light.\n");
    if(environment())
      tell_room(environment(),
      wielded_by->query_name()+"'s sword shines with a holy light.\n",
      ({wielded_by,attacker}));
    return 20; /* auto-randomized into 0-5 damage */
  }
  return 0;
}
int evil_hit(object ob) {
  if (!ob || !wielded_by) return 0;
    return 20;
}
  
