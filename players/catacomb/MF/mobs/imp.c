#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object wing;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("imp");
set_race("demon");
set_short(MAG+"An Imp"+NORM);
set_long(
  "  A demon from another plane of existence left here by a summoner\n"+
  "that was not strong enough to control it.  The dark magenta body\n"+
  "looks almost skeletal.  On the back of the body a set of grotesque\n"+
  "wings beat furiously.  At the end of its tail large spikes protrude\n"+
  "warding off would be enemies.\n");
 
set_level(17);
set_hp(350);
set_al(-500);
set_ac(14);
set_wc(24);
add_money(random(1000));
set_aggressive(1);
set_chat_chance(2);
  load_chat("The imp screams at your presence\n");

wing = clone_object("/players/catacomb/MF/items/impwing.c"); 
move_object(wing, this_object());

}

heart_beat()
{
  int AMT;
  AMT = random(25);
  ::heart_beat();

  if (!environment())
  {  return;  }
  if (!ATTACKED)
  {  return;  }
  if (AMT >= 18)
  {
    tell_room(environment(),
      "\n\nThe imp lets loose a volley of flames, consuming its foe.\n\n");
    ATTACKED->hit_player(random(20)+ 10, "other|fire");
    return 1;
  }
  return 1;
} 
