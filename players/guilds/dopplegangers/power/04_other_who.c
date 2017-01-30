/*
 * Other Who (ow)
 * Doppleganger other who command (guilds)
 */

#include <ansi.h>

status main(string str) {
  string result, enviro;
  string gname;
  object *people;
  int i;

  if (str) return 0;

  if (this_player()->query_guild_rank() < 4) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  result = "";

  result += "\nPerson\t\tSex\tPK\tGuild\t\tLocation\n";
  result += "-----\t\t---\t--\t------\t\t--------\n";

  people = users();

/* Iterate through array and remove invisible people that we shouldn't see */
  for (i=0; i<sizeof(people); i++) {
    if (people[i]->query_invis() > this_player()->query_level())
      people -= ({ people[i] });
  }

  for (i=0; i<sizeof(people); i++) {
    if (!people[i]->query_guild_name()) gname = "None";
    else
    switch(people[i]->query_guild_name()) {
      case "doppleganger":     gname = "DOPPLE!";   break;
      case "Knights Templar":  gname = "Knight";    break;
      case "necromancer":      gname = "Necro";     break;
      case "black circle":     gname = "BC Mage";   break;
      case "cyberninja":       gname = "Cybers";    break;
      case "neo symbiote":     gname = "Neos";      break;
      default:
        gname = capitalize((string)people[i]->query_guild_name());
        break;
    }
    
    if (!people[i]->query_invis())
      result += (string)people[i]->query_name();
    else if (people[i]->query_invis())
      result += "(" + people[i]->query_real_name() + ")";
    
    if (strlen((string)people[i]->query_name()) > 7) result += "\t";
    else if(people[i]->query_invis() &&
            strlen((string)people[i]->query_name()) > 6) result += "\t";
    else result += "\t\t";

    if ((string)people[i]->query_gender() == "male") result += "M\t";
    else if ((string)people[i]->query_gender() == "female") result += "F\t";
    else result += "C\t";

    if (people[i]->query_pl_k()) result += "Y \t";
    else result += "N \t";

    result += gname;
    if (strlen(gname) > 7) result += "\t";
    else result += "\t\t";

    if (!environment(people[i])) result += "<Logging In>\n";
    else {
      enviro = (string)environment(people[i])->short();
      if (ansi_strlen(enviro) > 27) {
#ifndef __LDMUD__
        result += enviro[0..-(ansi_strlen(enviro) - 26)] + "\n";
#else
        result += enviro[0..<(ansi_strlen(enviro) - 26)] + "\n";
#endif
      } else result += enviro + "\n";
    }
  }
  write(result);
  return 1;
}
