#include "../def.h"

inherit "/players/vertebraker/closed/std/monster";

#define armors ({"do","kabuto","mabisashi","sode","shikoro","udewa",\
                 "hakama","obi","kote","nishiki","bu-tsu","mempo"})

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("Miyamoto Musashi");
  set_alias("musashi");
  set_alt_name("miyamoto");
  set_short("Miyamoto Musashi");
  set_long("\
The famed swordsman Miyamoto Musashi was born Shinmen Takezo\n\
in Harima Province and may have fought at Sekigahara under the\n\
Ukita as a common soldier.\n\
Musashi the man must have cut a forbidding appearance: he was\n\
said to have rarely bathed or changed his clothes as well as\n\
suffering from a somewhat disfiguring skin condition. Following\n\
his duel with Sasaki, he seems to have focused his energies on\n\
perfecting his style of swordsmanship, spending much time in \n\
travel and reflection - thus epitomizing the much-beloved image\n\
of the brooding wanderer samurai.\n");
  set_race("human");
  set_gender("male");

  if(!present("sword"))
  {
    move_object(clone_object("/players/vertebraker/obj/hanzo_sword"), this_object());
    command("wield sword");
  }
  if(!present("armor"))
  {
    int s;
    s = sizeof(armors);
    while(s--)
    {
      move_object(clone_object(ROOTDIR+"armor/"+armors[s]), this_object());
      command("wear "+armors[s], this_object());
    }
  }
  set_level(30);
  set_wc_bonus(60);
  set_wc(120);
  set_ac(0);
  set_hp(5000);
  set_dead_ob(this_object());
  set_no_exp_value();
}

void heart_beat()
{
  ::heart_beat();
  
  set_ac(0);
  if(attacker_ob)
  {
    already_fight = 0;
    attack();
  }
}

monster_died()
{
  object c;
  if(c = present("corpse", ENV())){
    destruct(c);
  }
  if(c = present("hanzo_sword", ENV())) {
    destruct(c);
  }
}
