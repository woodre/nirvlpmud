/*
* LIGHT spell for the Shardak guild
* by Drag and Bal, '95
* msgs/cost changed by verte
*/
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../macros.h"
#include "../tasks.h"
#include "/players/vertebraker/ansi.h"
inherit CMD;

#define COST 20

status
main(string arg)
{
   if (arg) return 0;
   needrank(3);
   needmana(COST);
   needtask(FLAMES_TASK);
   if (present("flame_obj", this_player())) {
      write("You are already carrying a flame.\n");
      return 1;
   }
   clone_object(OBJDIR + "flame")->move(this_player());
   write("You raise your hands to the sky and make a circular gesture,\n"+
      "dropping your right fist to your side, clenching tightly...\n");
   write(
      RED+"\tHeat rises around the room.....\n"+NORM+
      "A blazing geyser of fire explodes from your fist, forcing it\n"+
      "open and cauterizing the blasted Mark further...\n");
   say(
      capname + " raises " + possessive(this_player()) + " hands to the sky and makes "
      + "a circular gesture,\ndropping "+possessive(this_player())+" fist to "
      + possessive(this_player()) +" side, clenching tightly...\n");
   say(RED+"\tHeat rises around the room....\n"+NORM);
   say("A blazing geyser of fire explodes from "+possessive(this_player())+" fist, forcing\n"+
      "it open and brightening the room in a shower of sparks!\n");
   this_player()->add_spell_point(-COST);
   return 1;
}
