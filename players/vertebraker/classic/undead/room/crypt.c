#include <ansi.h>
#include "../lib/guild_defs.h"

inherit G_HALL;

void reset(status arg)
{
   if(arg) return;
   set_light(-5);
   set_short(HIK + "Dark Crypt" + NORM);
   set_long("\
   You are in the " + HIK + "Dark Crypt" + NORM + 
", shelter of the Undead souls.\n\
No one else can intrude here- thus it is peaceful. Ancient magical\n\
runes engraved over the stone walls speak of the history of the\n\
Undead guild- born from the yoke of Gorhurtrix the Damned as servants\n\
for the evil god who remains Nameless. Prophecy speaks one day the\n\
god will awake from His slumber, destroy the unfaithful; and give\n\
His chosen breed the world to rule for eternity.\n");
   add_exit(ROOMDIR + "f6", "south");
   add_exit("/room/church","church");
   add_exit_msg("church", ({"\n\tYou step onto holy ground.\n\n","leaves to the Village Church.\n"}));
   add_exit_msg("south", ({"\n\tYou exit back to the " + CEN + ".\n\n","enters the " + CEN + ".\n"}));
}

void init()
{
  ::init();
  if(find_call_out("heal_us") == -1 && guys > 1)
    call_out("heal_us", 20);
}

void heal_us()
{
  object ob, oc;
  if(guys <= 1) return;
  tell_room(TO, "\
United with your undead brethren, you feel the warming\n\
grasp of the dark gods.\n");
  ob = first_inventory(TO);
  while(ob)
  {
    oc = next_inventory(ob);
    if(ob->is_player())
      ob->heal_self(guys);
    ob = oc;
  }
  call_out("heal_us", 20);
}
