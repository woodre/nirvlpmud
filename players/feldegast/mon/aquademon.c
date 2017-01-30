/*
File: aquademon.c
Author: Feldegast
Date: 3/16/02
Description:
  A water demon found near the orc encampment in Caladon.
He guards a room where the loot can be found.
*/
#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("aquademon");
  set_alt_name("water demon");
  set_short(HIC+"Aqua"+NORM+BLU+"demon"+NORM);
  set_long(
"This demonic creature shapes the water itself to its will.  It\n"+
"appears vaguely manlike with a muscular torso, and a fang-toothed\n"+
"face.  Its legs, assuming there are any, remain hidden beneath\n"+
"the water.\n"
  );
  set_gender("male");
  set_race("demon");
  set_level(20);
  set_wc(42);
  set_ac(22);
  set_hp(1000);
  set_al(-1000);
  set_wc_bonus(25); /* 2 water-based attacks and enemy switching */

}

void heart_beat()
{
  object ob,next;
  ::heart_beat();
  if((alt_attacker_ob && !random(5)) || (attacker_ob && !random(10))) {
    already_fight=0;
    say("The Aquademon sprays a torrent of...\n"+
        HIB+"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    say("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
        "\t~~~~~~~~~~~~~~~~~~~~ "+CYN+"WATER!"+HIB+" ~~~~~~~~~~~~~~~~~~~~~~\n"+
        "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
        "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM
    );
    ob=first_inventory(environment(this_object()));
    while(ob) {
      next=next_inventory(ob);
      if(ob && living(ob) && ob!=this_object() && !ob->query_ghost()) {
        say(CYN+ob->query_name()+" is hit by the blast!\n"+NORM);
        ob->attacked_by(this_object());
        ob->hit_player(80, "other|water");
      }
      ob=next;
    }
  }
  else if(attacker_ob && random(100) > 25)
  {
    tell_object(attacker_ob, HIC+"The Aquademon grabs hold of you and holds you beneath the water!\n"+NORM);
    tell_room(environment(), HIC+"The Aquademon grabs hold of "+(string)attacker_ob->query_name()+" and holds "+(string)attacker_ob->query_objective()+" beneath the water!\n"+NORM, ({ attacker_ob }));
    attacker_ob->do_damage(60, "other|water");
  }

  if(attacker_ob && alt_attacker_ob && !random(4))
  {
    tell_room(attacker_ob, BOLD+"\nThe Aquademon switches opponents!\n\n"+NORM);
    ob=alt_attacker_ob;
    alt_attacker_ob=attacker_ob;
    attacker_ob=ob;
  }

}
