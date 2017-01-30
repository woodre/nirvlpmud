#define tp this_player()->query_name()
#include "/sys/lib.h"
#define OBJ_SHITPILE
#include <ansi.h>
int w;
inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("sput sword");
  set_alias("sput");
  set_type("sword");         /* set type added by Pavlik */
  set_short(YEL+"Sput"+NORM+", the"+HIW+" Legendary"+HIR+" Longsword"+NORM);
  set_long("A large sword with a blade forged from cold steel.\n"+
          "It is covered with a smelly residue that seems to radiate.\n"+
          "a very foul smell. The swords grip is very squishy.\n");
  set_class(18);
  set_weight(2);
  set_value(5000);
  set_hit_func(this_object());
}
weapon_hit(attacker){
  if(call_other(this_player(), "query_attrib", "wil") > random (50)) {
    write("The sword of Sput shakes violently as a massive pile of crap smacks " +attacker->query_name()+".\n"+YEL+"\
ssssss     ppppp      ll       aaaaaa       tttttttt  !!!\n\
ss         pp pp      ll       aa  aa          tt     !!!\n\
ssssss     ppppp      ll       aaaaaa          tt     !!!\n\
    ss     pp         ll       aa  aa          tt        \n\
ssssss     pp         llkkk    aa  aa          tt     !!!\n"+NORM);
    say("The sword of Sput shakes violently as a massive pile of crap smacks " +attacker->query_name()+".\n"+YEL+"\
ssssss     ppppp      ll       aaaaaa       tttttttt  !!!\n\
ss         pp pp      ll       aa  aa          tt     !!!\n\
ssssss     ppppp      ll       aaaaaa          tt     !!!\n");
say("    ss     pp         ll       aa  aa          tt        \n\
ssssss     pp         llkkk    aa  aa          tt     !!!\n"+NORM);
   move_object(clone_object("/players/mizan/etheriel/items/shit-directhit-residue.c"));
   move_object(clone_object("/players/mizan/etheriel/items/shit-step-residue.c"));
    if(attacker->query_hp() > 13) 
      attacker->hit_player(13,"magical");
    return 7;
  }
  return;
}
