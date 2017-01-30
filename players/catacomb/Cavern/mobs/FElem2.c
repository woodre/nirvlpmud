#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object armor;


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("elemental");
set_race("creature");
set_short("A "+RED+"fire"+NORM+" elemental");
set_long(
  "  The creature is the embodiment of fire.  The elemental stands\n"+
  "at least six feet tall with flames leaping off of its body.  It\n"+
  "stands ready to destroy everything in its path.\n");
 
set_level(19);
set_hp(450);
set_al(-100);
set_wc(28);
set_dead_ob(this_object());
set_aggressive(1);

armor = clone_object("/players/catacomb/Cavern/items/FireArmor.c"); 
move_object(armor, this_object());
init_command("wear armor", this_object());
set_ac(16);
}

heart_beat()
{
  int chance;
  chance = random(20);
 ::heart_beat();
  if(!environment())
    return;
  if(!ATTACKED)
    return;
  
  if(chance >= 15)
  {
    write("\n\n    A pillar of "+RED+"flame"+NORM+" rises up and through you.\n"+
          "            "+HIY+"INTENSE PAIN"+NORM+" overcomes you!\n\n");
    say("\n\n    A large pillar of flame consumes the area.\n\n");
    ATTACKED->hit_player(random(10)+ 10, "other|fire");
    return 1;
  }
  return 1;
}
 
monster_died()
{
  object orb;
  tell_object(ATTACKED,
   "The fire elemental collapses upon itself and forms an orb that falls to the ground.");
  orb = clone_object("/players/catacomb/Cavern/items/Forb.c");  
  move_object(orb, this_object());
}   