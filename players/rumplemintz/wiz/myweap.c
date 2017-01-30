/* ========================================================================== */
/*  myweap.c - Rumplemintz                                                    */
/* WIZARDS ONLY                                                               */
/*                                                                            */
/* ========================================================================== */

inherit "obj/weapon";

void reset(status arg){
  if(arg) return;
  weapon::reset(arg);
  set_id("staff");
  set_alias("sword");
  set_short("Rump's beatin staff");
  set_long("Rump's kickass weapon.\n");
  set_class(1000);
  set_weight(0);
  set_value(0);
  set_hit_func(this_object());
}

int weapon_hit(object attacker){
  attacker->do_damage(100000, "other|rumplemintz");
}
