#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
QRangerInfo() { return 0; }

status
RangerInfo() { return 0; }

status
RangerPower(string str, string type)
{
  string *rangers;
  string *msg;
  string ranger1, ranger2, ranger3, ranger4, ranger5;
  int i,j;
  object comm;
  object MegRanger;
  rangers = ({}
  );
  msg = ({}
  );
  if(!str)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You must specify 4 rangers to use in the \
megazord.\"\n");
    return 1;
  }
  if(!COMM->QMorphed())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You must be morphed to call the \
Thunder Megazord.\"\n");
    return 1;
  }
  if(sscanf(str, "%s,%s,%s,%s", ranger1, ranger2, ranger3, ranger4) != 4)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You must choose 4 other people to call \
the megazord.\"\n");
    return 1;
  }
  if(find_living("RangerMegazord"))
  {
    tell_object(this_player(),
      "Zordon tells you: \"The Thunder Megazord has already been called \
by other Rangers.\"\n");
    return 1;
  }
  if(MASTER->QPowerPoints(type) < 3000)
  {
    tell_object(this_player(),
      "Zordon tells you: \"There are not enough power points to call the \
Thunder Megazord.\"\n");
    return 1;
  }
  rangers += ({ ranger1 }
  );
  rangers += ({ ranger2 }
  );
  rangers += ({ ranger3 }
  );
  rangers += ({ ranger4 }
  );
  for(i = 0; i<sizeof(rangers); i++)
  {
    if(!present(rangers[i], environment(this_player())))
    {
      notify_fail(rangers[i]+" is not here.\n");
      return 0;
    }
    MegRanger = present(rangers[i], environment(this_player()));
    if(!present("RangerCommunicator",MegRanger))
    {
      tell_object(this_player(),
       "Zordon tells you: \"" + rangers[i] + " is not a Power Ranger.\n");
      return 1;
    }
    comm = present("RangerCommunicator",MegRanger);
    if(!comm->QMorphed())
    {
      tell_object(this_player(),
        "Zordon tells you: \"" + rangers[i] + " is not morphed.\n");
      return 1;
    }
    tell_room(rangers[i], capitalize(rangers[i]) + " yells: " +
      "/players/guilds/Rangers/Commands/Zord.c"->query_zord_msg(
      find_player(rangers[i])) + "\n");
    tell_room(rangers[i], capitalize(rangers[i]) + " yells: " +
      "/players/guilds/Rangers/Commands/Zord.c"->query_zord_call(
      find_player(rangers[i])) + "\n");
  }
  move_object("/players/guilds/Rangers/ThunderMegazord.c",
    environment(this_player()));
  for(j=0; j<sizeof(rangers); j++)
  {
    if(rangers[j] != (string) this_player()->query_name())
    {
      call_other(present(rangers[j],
        environment(this_player())),"move_player",
        "megazord#/players/guilds/Rangers/ThunderMegazord.c");
    }
  }
  call_other(this_player(),"move_player",
    "megazord#/players/guilds/Rangers/ThunderMegazord.c");
  tell_room(environment(environment(this_player())),
    "The Power Rangers yell: Thunder Megazord...Power Up!\n");
  MASTER->APowerPoints(-3000,type);
  return 1;
}
