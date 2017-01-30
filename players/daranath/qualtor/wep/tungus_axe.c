#define tp this_player()->query_name()
#define POSS this_player()->query_possessive()

int w;

inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("battle axe");
    set_alias("battleaxe");
    set_type("axe");
    set_short("A double bladed Battle Axe");
    set_long("A large two-handed Dwarven forged Battle Axe.\n"+
             "Runes run down its hilt.\n");
    set_read("To my son Tungus, may you smash your enemies with strength.\n");
    set_class(20);
    set_weight(3);
    set_value(5500);
    set_hit_func(this_object());
}

weapon_hit(attacker){

 if(call_other(this_player(), "query_attrib", "str") > random (100)) {

  say("\n"+tp+" turns the Battle Axe over in "+POSS+" hand.\n"+
      tp+" cuts deeply into "+attacker->query_name()+"\n\n");

  write("\nYou cut deeply into your foe.  That smarts!!!.\n"+
    "An expression of pain and rage comes over "+attacker->query_name()+".\n\n");
  tell_room(environment(this_player()),
      attacker->query_name()+" stumbles backwards from the force of the blow.\n"+
     tp+" pulls the Battle Axe out of "+attacker->query_name()+" with a mighty grunt.\n");
  return 10;
        }
    return;
        }

query_save_flag()  { return 1; }
