#define tp this_player()->query_name()
#define POSS this_player()->query_possessive()

int w;

inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("battle charger");
    set_alias("battlecharger");
    set_type("charger");
    set_short("Battle Charger");
    set_long("A unique weapon forged in the elemental fires of another plane,\n"+
             "the Battle Charger is a small steel ball that pulses with\n"+
             "an electrical life of its own. Lightning runs back\n"+
             "and forth along its diameter, a dangerous sign.\n");
    set_class(20);
    set_weight(3);
    set_value(5500);
    set_hit_func(this_object());
}


weapon_hit(attacker){

 if(call_other(this_player(), "query_attrib", "wil") > random (90)) {

  say("\n"+tp+" spins the Battle Charger about "+POSS+" grasp.\n"+
   "An electrical flash comes from the Charger and strikes "+attacker->query_name()+"\n\n");

 write("\nThe Battle Charger flares with a bright electrical flash.\n"+
    "An expression of pain and rage comes over "+attacker->query_name()+".\n\n");
  if(random(3) == 0) {
  this_player()->heal_self(-random(8) - 1);
  write("The electrical flash burns your hands slightly.\n");
  return 0; }
  tell_room(environment(this_player()),
    attacker->query_name()+" stumbles backwards from the force of the flash.\n"+
    "The smell of burnt flesh fills the area.\n");
  return 5;
        }
    return;
        }

query_save_flag()  { return 1; }
