inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#include "/sys/lib.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("mikal");
  set_alias("vampire");
  set_race("demon");
  set_short("Mikal "+HIG+"("+HIK+"Mid Boss"+HIG+")"+NORM+"");
  set_long(
    " A sinister looking vampire stands here clad in a dark cloak and a\n"+
    " Golden ankh worn around his neck. A Golden ring shimmers from his\n"+
    " right hand. Mikal is one of the 4 servants of Vlad the impaler.\n");
  move_object(clone_object("/players/sami/area/GPO/obj/dring.c"),this_object());
  init_command("wear ring");
  move_object(clone_object("/players/sami/area/GPO/obj/lvampsword.c"),this_object());
  init_command("wield sword");
  move_object(clone_object("/players/sami/closed/cube.c"),this_object());
  move_object(clone_object("/players/sami/closed/cube.c"),this_object());
  set_level(20);
  set_hp(500+random(200));
  set_hp_bonus(650);
  set_armor_params("other|evil",0,25,0);
  set_armor_params("other|dark",0,25,0);
  set_armor_params("other|magical",0,25,0);
  set_al(-800);
  set_heal(10,10);
  set_ac(30+random(8));
  set_wc(20+random(12));
  set_aggressive(0);
  set_multi_cast(5);

/*
#MN# is the monster's name.
#TN# is the target's name.
*/
  add_spell("spell_name",
    "what to tell the player",
    "what to tell the room",
    30,
    ({25,15}),
    ({"other|evil","other|earth"}),
    1);
/*
  varargs status add_spell(
    string name,
    string mess_target, 
    string mess_room,
    int chance, 
    mixed damage, 
    mixed type, 
    status hit_all_attackers,
    string ex_fun, 
    object ex_ob)
*/
} 
