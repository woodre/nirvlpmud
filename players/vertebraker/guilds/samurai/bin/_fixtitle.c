#include "../def.h"
cmd_fixtitle()
{
  string title;
  switch(TP->query_guild_rank())
  {
    case 0:
      title = "the Samurai Janitor";
      break;
    case 1:
      title = "the Initiate of Bushido";
      break;
    case 2:
      title = "the Lower Buke";
      break;
    case 3:
      title = "the Upper Buke";
      break;
    case 4:
      title = "the Mononofu";
      break;
    case 5:
      title = "the Uruwashii";
      break;
    case 6:
      title = "the Samurai";
      break;
    case 7:
      title = "the Lord Musha";
      break;
    case 8:
      title = "the Eighth Shi";
      break;
    case 9:
      title = "the Tsuwamono";
      break;
    case 10:
      title = "the Shogun";
      break;
    case 11:
      title = "the Emperor";
      break;
  }
  TP->set_title(title);
  write("You set your title to "+title+".\n");
  return 1;
}
