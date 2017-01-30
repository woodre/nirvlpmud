/*
** Sword of Swashbuckling
**
** This is my VERY FIRST special magical weapon.  It allows for a
** random chance (player's level out of 100) of disarming a monster
** wielding a weapon.  It also does a few room echos, to keep the
** fight lively.  
**
** Dodger
*/

#include "/players/dodger/dfun/userdefs.h"
#define WIELDED_BY_PLAYER call_other(environment(this_object()),"is_player")
#define DISARM_CHANCE USER->query_level()
inherit "/obj/weapon.c";

reset(arg) {
   if (arg) return;
   set_id("sword");
   set_short("Sword of Swashbuckling");
   set_long(
"This beautifully crafted rapier looks like it could easily have belonged\n"+
"to the famous Count of Montecristo, The Scarlet Pimpernel, or ANY of the\n"+
"Three Musketeers!!  You can almost see your reflection on the shiny,\n"+
"gold-plated handguard... How DASHING!!  How RESOURCEFUL!!\n"
);
   set_value(3000);
   set_class(16);
   set_weight(2);
   set_hit_func(this_object());
   return 1;
   }

init() {
   ::init();
   }
weapon_hit(attacker) {
   object weapon;
   int atmos;
   if (!(WIELDED_BY_PLAYER)) return;
   weapon = attacker->query_name_of_weapon();
   if (DISARM_CHANCE >= random(100) ) {
      if (weapon) {
         call_other(attacker,"stop_wielding");
         move_object(weapon,environment(attacker));
         say(
"\n"+
"With a clever thrust-parry combination stroke, "+NAME+" outwits\n"+
POS+" foe, and sends "+POS+" opponent's weapon sailing off to the\n"+
"opposite end of the floor!!\n"+
"\n"+attacker->query_name()+" drops: "+weapon->short()+".\n"
);
      write(
"Seeing your opportunity, you cleverly outwit your opponent, and manage\n"+
"to disarm your foe with a graceful stroke of swordsmanship!!\n"+
attacker->query_name()+" drops: "+weapon->short()+".\n"
);
         }
      }
   atmos = random(7);
   if (atmos==1) {
      write("You lunge forward at your foe, driving your blade fiercely\n"+
   "towards your opponent's chest!!\n");
   say(
NAME+" lunges forward at "+POS+" foe, driving "+POS+" blade fiercely\n"+
"towards "+POS+" opponent's chest!!\n"
);
return 5;
}
   if (atmos==2) {
      write(
"Your opponent violently knocks you backwards, sending you sprawling\n"+
"to the ground!!  You roll quickly to one side, narrowly escaping a\n"+
"crushing blow!! *CLANG*\n"
      );
      say(
NAME+"'s opponent violently knocks "+OBJ+" backwards, sending "+OBJ+" sprawling to\n"+
"the ground!!  "+OBJ+" rolls quickly to one side, narrowly escaping a\n"+
"crushing blow!! *CLANG*\n"
      );
   return 0;
   }
  if (atmos==3) {
      write(
"You dodge and parry your opponent's ferocious blows,\n"+
"laughing heartily!\n"
      );
      say(
NAME+" dodges and parries "+POS+" opponent's ferocious blows,\n"+
"laughing heartily!\n"
      );
      }
if (atmos==4) {
   write(
"You dive nimbly past your adversary, and spinning quickly on your\n"+
"heel, slash wildly at your foe, eyes lit up with keen delight!!\n"
   );
   say(
NAME+" dives nimbly past "+POS+" adversary, and spinning quickly on "+POS+"\n"+
"heel, slashes wildly at "+POS+" foe, eyes lit up with keen delight!!\n"
   );
   }
}
                
