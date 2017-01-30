inherit "obj/monster.c";
#define STORE "/players/cosmo/hslist/exp_store.c"

int prev_hp;  /* Monster's previous round hit point total */

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Manny");
  set_alias("manny");
  set_alt_name("manny");
  set_race("human");
  set_short("Manny, the Test Monster");
  set_long("My sole purpose is to test things for Cosmo.\n");
  set_level(20);
  set_hp(500);
  set_al(0);
  set_wc(5);
  set_ac(17);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_heart_beat(0);
}

heart_beat() {
object vds_ob;
int dmg;
  ::heart_beat();
  vds_ob = present("vds", attacker_ob);
  if(vds_ob) {
    if(!prev_hp) prev_hp = max_hp;
    dmg = prev_hp - hit_point;
    prev_hp -= dmg;
    call_other(STORE, "collector", attacker_ob->query_name(), dmg);
    say(attacker_ob->query_name()+" gained "+dmg+" exp points.\n");
  }
}

monster_died() {
object vds_ob;
  vds_ob = present("vds", attacker_ob);
  if(vds_ob) {
    call_other(STORE, "collector", attacker_ob->query_name(), experience/75);
    say(attacker_ob->query_name()+" gained "+experience/75+" exp points.\n");
  }
  return 0;
}
