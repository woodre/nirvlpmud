#include <ansi.h>
#include "/players/khrell/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

/* extra weapons destroyed when the monster dies */
object blade2,blade3;

reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name(HIK+"Deathmaster Snikch"+NORM);
  set_short(0);
  set_alias("snikch");
  set_race("skaven");
  set_long("\
      The feared chief assassin of Clan Eshin.  The Right hand of\n\
 the Nightlord.  He is the most successful skaven assassin of all\n\
 time.  Garbed all in tattered black cloth and wearing a hooded \n\
 cloak that seems to draw in the light, it is no wonder he can \n\
 seemingly vanish in plain sight.  His furred body is well muscled\n\
 and his fur seemes to have an oiled sheen to it\n");
  set_gender("male");
  set_hp(2000);
  set_level(28);
  set_al(-1000);
  move_object(clone_object("/players/khrell/weapons/skaven/weepingblade.c"));
  init_command("wield blade");
  /* clone the additional blades and offwield them as appropriate*/
  blade2=clone_object("/players/khrell/weapons/skaven/weepingblade.c");
  move_object(blade2);
  blade2->set_class(40);
  blade2->offwield(this_object());
  blade3=clone_object("/players/khrell/weapons/skaven/weepingblade.c");
  move_object(blade3);
  blade3->set_offwield_desc("tailwielded");
  blade3->set_class(40);
  blade3->offwield(this_object());
  /* tone down a bit for the extra weapons
  set_wc(52);
   */
  set_wc(42);
  set_wc_bonus(50);
  set_ac(26);
  set_aggro(1, 10, 100);
  add_money(6000);
  set_heal(50,1);
  set_wander(10, 0,({}));
  set_chat_chance(10);
  set_a_chat_chance(25);
  load_chat(RED+"Red"+NORM+" eyes stare out at you from the shadows.\n");
  load_chat("The shadows seem to be moving.\n");
  load_a_chat("The deathmaster parries your attack.\n");

/* needed so the extra weapons will be dested when the monster dies */
  set_dead_ob(this_object());
    
  set_multi_cast(1);
  
  add_spell("eshin eight-slash",
"#MN# draws his blade back, then quickly spins a vicious\n"+
"figure-eight, $HR$S L I C I N G$N$  you multiple times!\n",
"#MN# draws his blade back, then quickly spins a vicious\n"+
"figure-eight, $HR$S L I C I N G$N$ #TN# multiple times!\n",
15,({20,20}),({"physical","other|poison"}));

  add_spell("shuriken cyclone",
"#MN# quickly reaches into his cloak then quickly spins about\n"+
"          he tosses something towards you and......\n"+  
"A number of $G$warpstone$N$ shuriken slice into you!\n",
"#MN# becomes a blur of motion as it spins suddenly about releasing many glittering $G$shrukien$N$!\n",
20,({65,65}),({"other|physical","other|poison"}),1);

  add_spell("shadow-strike kick",
"#MN# leaps into the air.\n"+
"#MN# squeaks: \"$HK$Shadow$N$-$R$Strike$N$ Kick\"!\n",
"#MN# leaps into the air, then quickly lashes out with his foot.\n",
25,({15,15}),({"physical","other|evil"}));

}

monster_died() {
  if(blade2) destruct(blade2);
  if(blade3) destruct(blade3);
  tell_room(environment(this_object()),
  "\n"+HIK+"Deathmaster Snikch"+NORM+" gurgles and coughs up dark "+RED+"blood"+NORM+" staggers then collaspes dead!\n");
    return 0; 
}
