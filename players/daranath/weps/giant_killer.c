/*
 *  The Hammer "Giant Killer"
 *  Forged by Daranath and Saber
 *  8.13.95
 */

#define tp this_player()->query_name()
#define POSS this_player()->query_possessive()

int w;

inherit "obj/weapon.c";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("giant killer");
    set_alias("hammer");
    set_alt_name("killer");
    set_short("Giant Killer");
    set_long("A large two-handed dwarven forged warhammer.\n"+
             "Runes run down its hilt.\n");
    set_read("Forged by Krill Kegbarrel, son of Drakkar.\n"+
             "Used in defense during the great Giant Raids.\n");
    set_class(17);
    set_weight(3);
    set_value(7700);
    set_hit_func(this_object());
}


weapon_hit(attacker){

 if(call_other(this_player(), "query_attrib", "str") > random (100)) {

  say("\n"+tp+" spins Giant Killer high over "+POSS+" head.\n"+
      tp+" launches Gaint Killer into "+attacker->query_name()+"\n\n");

  write("\nYou spin Giant Killer high over your head.\n"+
    "You launch Giant Killer into "+attacker->query_name()+".\n\n");

  if(call_other(attacker,"id","giant") ||
     call_other(attacker,"id","ogre"))    {

  write("You scream \"\GIANT KILLER\"\.\n"+
      "The hammer radiates a deep blue aura as it whistles through the air.\n"+
      "There is a deafening clap of thunder.\n\n");
  say(tp+" screams \"\GIANT KILLER\"\.\n"+
      "The hammer radiates a deep blue aura as it whistles through the air.\n"+
      "There is a deafening clap of thunder.\n\n");
  attacker->heal_self(-random(15));
       }

  tell_room(environment(this_player()),
      attacker->query_name()+" stumbles backwards from the force of the blow.\n"+
      "The hammer returns to "+tp+"'s hand.\n");
  return 8;
        }
    return;
        }

query_save_flag()  { return 0; }
