inherit "/players/vertebraker/closed/std/room";

#include <ansi.h>

short()
{
  string sd;
  string a, b;
  sd = ::short();
  if(sscanf(sd, "%s [%s]",a,b) == 2)
    return a+" "+HIC+"("+NORM+b+HIC+")"+NORM;
  if(this_player()->query_real_name()=="vertebraker") write("Ok\n");
  return sd;
}
