/*
  illusion.h
*/

#include "defs.h"

string illusion_str;
object illusion_obj, my_player;
int my_level;

/* --------------- Cast a temporary illusion --------------- */
illusion(str) {
  if (MY_LEVEL < 17 || MY_GUILD_EXP < 672) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 40) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  illusion_obj=clone_object(VAMPIRE_ILLUSION);
  illusion_obj->set_owner(MY_NAME);
  move_object(illusion_obj, MY_ROOM);
  MY_PLAYER->add_spell_point(- 40);
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+" makes a few gestures and concentrates for "+
              "a moment.");
  write("You make a few gestures and concentrate for a moment and begin to\n"+
        "create an illusion here.\n\n");
  illusion_str=0;
  input_to("illusion_2");
  write("Enter the description of the illusion  (end with **):\n"+
        "ex:  A HUGE black dragon says:  I'm here to kill Hendrek!\n"+
        "<illusion text>]");
  my_level=MY_LEVEL;
  my_player=MY_PLAYER;
  return 1;
}

illusion_2(str) {
  if (str=="**") {
    illusion_obj->set_illusion(illusion_str);
    illusion_obj->start_illusion(my_level);
    tell_object(my_player, "The illusion is complete.\n");
    return 1;
  }
  if (!illusion_str)
    illusion_str=str+"\n";
  else
    illusion_str=illusion_str+str+"\n";
  input_to("illusion_2");
  write("<illusion text>]");
  return 1;
}
