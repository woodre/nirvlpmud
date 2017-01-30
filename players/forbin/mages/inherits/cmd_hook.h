#include "../def.h"

mixed cmd_hook(string str)
{
  string go;
  go = CMDDIR+query_verb()+".c";
  if(file_size(go) > 0)
    return (mixed) go->main(str, this_object(), this_player());
  return 0;
}