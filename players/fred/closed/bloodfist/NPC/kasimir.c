inherit "/obj/monster";
#include "/players/fred/ansi.h"
int pain;

reset(arg){
  ::reset(arg);
  if(arg) return;

  pain = 2;
  set_name("spirit of kasimir");
  set_alt_name("kasimir");
  set_alias("spirit");
  set_short("The spirit of Kasimir the Lone Wolf");
  set_race("spirit");
  set_long(
"This is the spirit of Kasimir the Lone Wolf, a once great warrior whose\n"+
"party of bandits were murdered here long ago.  The spirit is clad in the\n"+
"same equipment that it was wearing when it died.  A sword hangs from its\n"+
"side and its body armor sits loosely on its shoulders.  The spirit is\n"+
"guarding the remains of his fallen comrades for all eternity.\n");
  set_level(26);
  set_ac(24);
  set_wc(42);
  set_wc_bonus(24);
  set_heal(5,1);
  set_hp(1375);
  set_al(0);
  set_gender("male");
  set_aggressive(1);
  set_chat_chance(5);
  load_chat("A spirit says, \"Noooo.......\"\n");
  set_dead_ob(this_object());
}

monster_died(){
  write("A spirit says, \"Noooo.......\"\n");
  if(present("corpse", environment()))
    destruct(present("corpse", environment()));
  return 1; 
}

void bone()
{
  tell_object(attacker_ob,
    "You step on a shard of bone that lodges into your foot.\n");
  attacker_ob->hit_player(12);
}

void claw()
{
  tell_object(attacker_ob, "\n"+
    "    The spirit claws at your face with its etherial hands...\n"+
    "    You feel pain inside your head as its fingers pass through...\n"+
    "    You fall backwards from the mental onslaught...\n\n");
  attacker_ob->hit_player(40+random(10), "other|mental");
}

void nevermore()
{
  tell_object(attacker_ob, "\n"+
    "The spirit drifts above you and passes into the darkness...\n\n\n"+
    "    Suddenly, shards of bone fly at you from every direction...\n"+
    "    Broken pieces of bone lodge themselves deep into your body...\n"+
    "    "+RED+"Blood"+NORM+" pours from the wounds, tainting the bones...\n"+
    "    You fall to the ground in a pool of "+RED+"blood"+NORM+"...\n\n");
  attacker_ob->hit_player(120 + random(50));
  pain = 1;
}

void hurt()
{
  tell_object(attacker_ob, "\n"+
    "    You feel the sadness inside your mind...\n"+
    "    You clutch at your head as the pain grows...\n"+
    "    Death surrounds you as the spirit cries...\n"+
    "    Tears of "+RED+"blood"+NORM+" fall from your eyes...\n"+
    "    You drop to your knees in anguish.\n\n");
  attacker_ob->hit_player(120 + random(40), "other|mental");
  pain = -1;
}

int cry()
{
  tell_room(environment(), "\n"+
    "A spirit says, \"Noooo.......\"\n"+
    "               \"Nooooooo.............\"\n"+
    "               \"Noooooooooooo...................\"\n\n\n"+
    "The spirit weeps softly.\n");
  pain += 2 + random(7);
  return pain;
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  if(!present(attacker_ob, environment())) return;
  if(pain < 0 && !random(3))
    nevermore();
  else if(!random(7))
  {
    if(cry() > 10)
      hurt();
  }
  else if(!random(6))
    claw();
  else if(!random(6))
    bone();
  else if(!random(3) && !attacker_ob->query_ghost())
  {
    already_fight = 0;
    ::attack();
  }
}

