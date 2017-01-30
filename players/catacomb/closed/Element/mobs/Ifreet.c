#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
int mp;
int skill;
object stone;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("ifreet");
set_type("creature");
set_short(RED+"Ifreet"+NORM+", ruler of the flame");
set_long(
 "  The ruler of fire stands before you.  Large horns stretch from its\n"+
 "head at least three feet.  Its mane of fire stretches the entire lenght\n"+
 "of its back.  With every exhale of breath small bursts of flames shoot\n"+
 "from its nostrils.  The heat eminates from its body, scorching all who\n"+
 "come close.\n");
 
set_level(27);
set_hp(1750);
set_al(0);
set_ac(25);
set_wc(44);
set_dead_ob(this_object());
set_aggressive(1);
mp = 100;
skill = 35;
set_a_chat_chance(5);
  load_chat(RED+"Ifreet"+NORM+" paralyzes you with its stare.\n");
}

heart_beat()
{
  int q;
  q = random(100);
    ::heart_beat();

  if(!environment())
    return;
  if(!ATTACKED)
    return;

  if (mp != 100)
  {
    mp = mp + 2;
  }

  if (skill != 35)
  {
    skill = skill + 1;
  }

  if (q > 50)
  {
    if(mp > 10)
    {
      UseMP(q);
    }
    else
    {
      UseSkill(q);
    }
  }
  if (q < 50)
  {
    if (skill > 3)
    {
      UseSkill(q);
    }
    else
    {
      UseMP(q);
    }
  }
  if (q == 50)
  {
    HealAndKill();
  }  
}

UseMP(int q)
{
  if (mp < 10)
  {
     say(
      "          Ifreet "+YEL+"HOWLS"+NORM+" in rage!!!!\n");
     write(
      "          Ifreet "+YEL+"HOWLS"+NORM+" in rage!!!!\n");
     return 1;
  }			
  if ((q >= 90) && (mp >= 10))
  {
    say(
     "\n\n    Smoke barrels out of Ifreet's nose consuming its face.\n"+
     "    Soon Ifreet's whole body is consumed in flame.  An\n"+
     "    evil grin can be seen just before it charges you.\n"+
     "          You reel in pain from the attack.\n\n");
    write(
     "\n    Ifreet consumes himself in flame just before charging\n"+
     "              into its foe with full force.\n");
    mp = mp - 10;
    ATTACKED->heal_self(random(20) - 40);
    return 1;
  }  
  if ((q <= 60) && (mp >=10))
  {
    say(
     "\n\n    Ifreet slowly brings his hand up above his head.\n"+
     "    A sudden rush of flesh-burning lava comes out of.\n"+
     "    the ground beneath, devouring you in magma.\n");
    write(
     "\n    Ifreet calls upon a wall of lava to devour its foe.\n");
    mp = mp - 10;
    ATTACKED->heal_self(random (10) - 40);
    return 1;
  }
  if (((q > 70) && (q < 80)) && (mp >= 20))
  {
    say(
     "\n\n    Ifreet rises above the ground on a large fiery boulder.\n"+
     "    Rising to the top of the room on the boulder, it brings \n"+
     "    its massive arms above his head, slowly consuming them\n"+
     "    in fire.  Suddenly, Ifreet brings them down on the boulder\n"+
     "                  sending it directly at you.\n"+
     "    The fiery boulder smashes into you scalding everything it touches.\n");
    write(
     "\n    Ifreet rises to the top of the room on a fiery boulder.\n"+
     "           Then pounds it directly at its foe.\n");
    mp = mp -20;
    ATTACKED->heal_self(random(10) - 75);
    return 1;
  }
}

UseSkill(int q)
{
  if (skill < 3)
  {
    write(
     "\n\n       Ifreet "+RED+"SCREAMS"+NORM+" out in rage!!!\n");
    say(
     "\n\n       Ifreet "+RED+"SCREAMS"+NORM+" out in rage!!!\n");
    return 1;
  }
  if ((q >= 40) && (skill >= 5))
  {
    say(
     "\n\n     Ifreet brings its massive claws across your body.\n"+
     "     Its mighty claws consumed in flames cut deep into \n"+
     "     your flesh leaving scalded scars.\n");
    write(
     "\n     Ifreet cuts deep into its foe leaving scalded scars.\n");
    skill = skill - 5;
    ATTACKED->heal_self(random(20) - 80);
    return 1;
  }
  if ((q <= 10) && (skill > 3))     
  {
    say(
     "\n\n    Ifreet drops its head, exposing it enormous horns.\n"+
     "     Ifreet builds up a head of steam charging at you.\n"+
     "     "+RED+"You begin to feel weak as the blood gushes out\n"+NORM+
     "     "+RED+"of the fresh wound created from the impaling.\n"+NORM);
    write(
     "\n     Ifreet lowers its head and charges at its foe, "+RED+"IMPALING\n"+NORM+
     "                its foe.\n");
    skill = skill - 3;
    ATTACKED->heal_self(random(30) - 50);
    return 1;
  }
}

HealAndKill()
{
  write(
   "\n\n\n        "+RED+"Ifreet calls down a shower of fire."+NORM+"\n");
  say(
   "\n\n\n        "+RED+"Ifreet calls down a shower of fire."+NORM+"\n");
  ATTACKED->heal_self(random(10) - 75);
  hit_point = hit_point + (random(50) + 30);
  return 1;
}
     
monster_died()
{
  tell_object(ATTACKED,
  "The fires slowly die out on "+RED+"Ifreet's"+NORM+" manes.\n");
  stone = clone_object("/players/catacomb/closed/Element/items/Fstone.c");
  move_object(stone, this_object());
}   