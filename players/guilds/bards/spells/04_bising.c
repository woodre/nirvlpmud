#include "/players/guilds/bards/def.h"

status main(string str) {
  string target, mess;
  object dest;
  
  if (!str || sscanf(str, "%s %s", target, mess) != 2) 
    FAIL("Who do you want to send a bard image to?\n");

  if (spell(-100, 4, 1) == -1)
  return 0;
  
  dest = find_player(lower_case(target));
  if (!dest || dest->query_invis() > 20)
    FAIL("Your magic does not find \""+target+"\".\n");

  if (TP->query_level() < 21 && dest->query_tellblock())
    FAIL(NAME(dest)+" is blocking tells. Please try again later.\n");

  if(TP->query_tellblock() && dest->query_level() < 21 && TP->query_level() < 21)
    FAIL("You cannot send an image when your tellblock is on.\n");
  
  if (in_editor(dest))
    FAIL("Strong wizard magic blocks your image.\n");

  tell_object(dest,
    "Your ears fill with an light ethereal music which somehows suggests that\n"
    + tp + " " + mess + "\n");
  write("You sing your ethereal song to " + NAME(dest)
       +", who experiences the image of\n" + tp + " " + mess + "\n");

  call_other(TP, "add_spell_point", -1);
  return 1;
}
