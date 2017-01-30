inherit "obj/monster.c";
#include <ansi.h>
#define attacked (this_object()->query_attack())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("tien");
set_race("creature");
set_short("Tien");
set_long(
  "  A warrior stands tall in the face of evil.  He has a third eye in the middle\n"+
  "of his forehead.  His chest bulges out behind his green tunic.  Tien serves as\n"+
  "a bodyguard for his best friend, Chiatsu.\n");
 
set_level(19);
set_hp(450);
set_al(200);
set_ac(16);
set_wc(28);
set_dead_ob(this_object());
set_aggressive(0);
set_spell_dam(20);
set_spell_mess1(
  "        Tien flies up high putting his hands over his face.\n"+
  "\n"+YEL+"                    'SOLAR FLARE'"+NORM+"\n\n"+
  "        is all that can be heard from high above.\n");
set_spell_mess2(
  "        Tien flies away from you and up toward the sun.\n"+
  "\n"+YEL+"                    'SOLAR FLARE'"+NORM+"\n\n"+
  "        can be heard from above.  You try to look around\n"+
  "        but to no avail, you are unable to see anything!\n");
}
 
monster_died(){
  object tunic;
  tunic = clone_object("/players/catacomb/dbz/obj/ttunic.c");
  tell_object(attacked,"As Tien falls to the ground his body disappears leaving his tunic.\n");
  move_object(tunic, this_object());
}   
