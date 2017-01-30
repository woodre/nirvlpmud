#define TP this_player()
#define TPN this_player()->query_name()
#define CAP capitalize
#define ENV environment
#include "/players/vertebraker/ansi.h"

inherit "/obj/treasure";

int snapped;
reset(x)
{
   if(x) return;
   set_id("glostick");
   set_alias("stick");
   set_short("A glostick");
   set_long(
      "A simple plastic glow stick.  To mix the chemicals,\n"+
      "and to light it up, just type <"+BOLD+"snap glowstick"+NORM+">\n");
   set_value(50);
}

init()
{
   ::init();
   add_action("cmd_snap","snap");
   add_action("cmd_wave","wave");
}

cmd_snap(str)
{
   if(!snapped)
      {
      write("You snap the glostick, and it cracks!\n"+
         HIM+"A penetrating glow fills the room....\n"+NORM);
      say(TPN+" snaps the glostick, and it cracks!\n"+
         HIM+"A penetrating glow fills the room....\n"+NORM);
      snapped = 1;
      set_light(1);
      return 1;
   }
}

cmd_wave(str)
{
   if(id(str) && snapped)
      {
      write("You wave the glostick all around.....\n"+
         "You trace "+HIM+"beautiful circles"+NORM+" all around the room...\n");
      say(TPN+" waves a glostick all around.....\n"+
         capitalize(subjective(TP))+" traces "+HIM+"beautiful circles"+NORM+" all around the room...\n");
      tell_room(ENV(TP),
         HIM+" O   o O  0  o  0 o      o   o  .   o 0    O .\n"+
         "   0 .  0  .   0  . 0  O o  O . O  . 0 .  O o\n"+
         " O  o   o 0  O  0   0  O    O o    oO  o .  0 o\n"+NORM);
      return 1;
   }
}

long()
{
   write(snapped ?
      "A simple plastic glow stick that has been snapped, and is alit.\n"+
      "You could <"+BOLD+"wave"+NORM+"> it around....\n":
      long_desc);
}

short()
{
   return (snapped ? HIM+"A glostick "+NORM+"("+HIM+"lit"+NORM+")": short_desc);
}
