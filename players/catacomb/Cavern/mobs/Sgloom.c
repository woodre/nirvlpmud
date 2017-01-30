inherit "obj/monster.c";
#include <ansi.h>
#define TPN this_player()->query_name()
#define ATTACKED (this_object()->query_attack())
object shield,amulet;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("shimmergloom");
  set_alt_name("dragon");
  set_race("dragon");
  set_short(HIB+"Shimmergloom"+NORM);
  set_long(
  HIW+"  A cloud of darkness surrounds this dragon.  It's large\n"+
  "leathery wings leave a mist of blackness with each beat. \n"+
  "Shimmergloom is the shadow king of the Durkor.  The dragon\n"+
  "is from another dimension, that has now invaded the caverns.\n"+
  "As the cloud of darkness lifts you face into your worst\n"+
  "nightmare and now must defeat it before it devours you.\n"+NORM);

  set_level(26);
  set_hp(1200);
  set_al(-1000);
  set_ac(24);
  add_money(3000 + random(2000));
  set_aggressive(1);
  set_wc(48);
  set_hp_bonus(450);       /*roughly 10 hp per round, 60 rounds, happening 75% of time*/
  set_dead_ob(this_object());
  set_heart_beat(1);
  set_chance(20);
  set_spell_dam(45);  
  set_spell_mess1(
    "\nThe dragon's tail crushes into its foe, breaking some bones.\n");
  set_spell_mess2(
    "\nThe dragon's tail crushes into you, breaking some bones.\n"); 

  shield = clone_object("/players/catacomb/Cavern/items/Sscale.c");
  move_object(shield,this_object());

  amulet = clone_object("/players/catacomb/Cavern/items/SGfang.c");
  move_object(amulet,this_object()); 
}
heart_beat()
{
  int chance,heal,HEALAMT;
  chance = random(100);
  heal = random (20);
  HEALAMT = random (20);
    ::heart_beat();
  if(!environment())
    return;
  if(!ATTACKED)
    return;
  if (heal > 5)
  {
     write("Shimmergloom absorbs the dark mist.\n");
     say("Shimmergloom absorbs the dark mist.\n");
     heal_self(HEALAMT);
     if (chance >= 25)
     {
       DO_SPECIALS(chance);
       return 1;
     }    
  }
  else
  {
    if (chance <= 10)
    {
  	DEATH_AWAITS_YOU();
 	return 1;
    }
    if ((chance > 15) && (chance < 25))
    {
     	WITH_BIG();
  	return 1;
    }
    if ((chance > 35) && (chance < 45))
    {
      SHARP();
	return 1;
    }
    if ((chance > 75) && (chance < 80))
    {
	POINTY_TEETH();
	return 1;
    }
    else
    {
	write("\nShimmergloom "+HIR+"HOWLS"+NORM+" in rage.\n\n");
	say("\nShimmergloom HOWLS in rage.\n\n");
      return 1;
    }
  }
}

DO_SPECIALS(int chance)
{
   if (chance > 85)
   {
     	DEATH_AWAITS_YOU();
     	return 1;
   }
   if (chance <= 40)
   {
	ALTOIDS();
	return 1;
   }
   return 1;
}

DEATH_AWAITS_YOU()
{
  write("\nShimmergloom "+RED+"RIPS"+NORM+" a deep gash into your flesh.\n\n");
  say("\nShimmergloom RIPS a deep gash into its foe.\n\n");
  ATTACKED->hit_player(40 + random(40));
  return 1;
}

WITH_BIG()
{
  write(RED+"\nYou "+GRN+"REEL IN PAIN"+NORM+RED+" as Shimmergloom releases a pillar of flames.\n\n"+NORM);
  say("\nShimmergloom's foe reels in pain as they are consumed in fire.\n\n");
  ATTACKED->hit_player(random (20)+ 30, "other|fire");       
  return 1;
}

SHARP()
{
  write(HIB+"\nYou are consumed in a black mist that "+HIB+"DRAINS"+NORM+HIB+" your energy.\n\n"+NORM);
  say("\nShimmergloom emits a black mist that consumes its foe.\n\n");
  ATTACKED->hit_player(random (25) + 30, "other|evil");
  return 1;
}

POINTY_TEETH()
{
  write("\n\nShimmergloom sweeps its massive claw, "+HIC+"DISEMBOWELING"+NORM+"you!\n\n");
  say("\nShimmergloom sweeps its claw disemboweling its enemy.\n\n");
  ATTACKED->hit_player(50 + random(50));
  return 1;
}

ALTOIDS()
{
  write("\nShimmergloom beats his leathery wings, "+HIM+"SMASHING"+NORM+" you into the wall.\n\n");
  say("\nShimmergloom's foe smashes into the wall.\n\n");
  ATTACKED->hit_player(20 + random (30));
  return 1;
}

monster_died()
{
  object gem1,gem2,gem3,spear;
  tell_object(ATTACKED,
   "\n  The dragon is engulfed in a "+BLK+"mist"+NORM+" that pollutes the room.\n"+
   "               The mist chokes the life out of you.\n"+
   "\n  The dark mist dissipates as Shimmergloom's corpse falls to the ground.\n");
  ATTACKED->hit_player(100 + random(75));
  gem1 = clone_object("/players/catacomb/Cavern/items/gem1.c");  
  move_object(gem1, this_object());
  gem2 = clone_object("/players/catacomb/Cavern/items/gem2.c");
  move_object(gem2, this_object());
  gem3 = clone_object("/players/catacomb/Cavern/items/gem3.c");  
  move_object(gem3, this_object());
  spear = clone_object("/players/catacomb/Cavern/items/dragonbane.c");
  move_object(spear, this_object());
  write_file("/players/catacomb/logs/Sgloom_death",ctime(time())+"    "+
    (this_object()->query_attack())->query_real_name()+"     "+
    (this_object()->query_attack())->query_level()+"\n");

}   
