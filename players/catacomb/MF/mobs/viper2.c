#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object skin;
object fang;
object fang2;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("viper");
set_alt_name("snake");
set_race("serpent");
set_short("An extremely large viper");
set_long(
  "  This serpent must be the largest you have ever seen.  Its mighty 20\n"+
  "foot length is like nothing you have ever seen before.  Although it \n"+
  "must be fed well for it to be so large, there appears to be no sign that\n"+
  "it has eaten recently.  The only thing you can think of is how to get out\n"+
  "of here before being seen by this mammoth of a snake.\n");
 
set_level(19);
set_hp(450);
set_al(-400);
set_wc(29);
set_aggressive(1);
set_chat_chance(2);
  load_chat("From deep within the snake comes a bone chilling "+BLU+"HHIIISSSS"+NORM+.\n");

skin = clone_object("/players/catacomb/MF/items/skin.c"); 
move_object(skin, this_object());

fang = clone_object("/players/catacomb/MF/items/fang.c"); 
move_object(fang, this_object());

fang2 = clone_object("/players/catacomb/MF/items/fang.c"); 
move_object(fang2, this_object());

}

heart_beat()
{
  int AMT;
  AMT = random(30);
  ::heart_beat();

  if (!environment())
  {  return;  }
  if (!ATTACKED)
  {  return;  }
  if (AMT >= 20)
  {
    tell_room(environment(),
      "\n\nThe snake coils up then it "+RED+"STRIKES"+NORM+", it's mighty maw\n"+
      "       gouging deep into its attacker.\n\n");
    ATTACKED->hit_player(random(25)+ 10, "other|poison");
    return 1;
  }
  return 1;
} 


