#include "defs.h"

inherit ROOM;

int check;

realm() {
  if(HIVEMIND->query_teleport())
    return "NT";
}

string plot_path(string dest_func)
{
  string path, dir;
  int i;

  if( check ) 
    return 0;

  check=1;

  if((int)call_other(this_object(),dest_func)==1)
  {
    check=0;
    return ".";
  }
  else
  {
    for(i=0; i < sizeof(dest_dir); i+=2)
    {
      dir=(string)(dest_dir[i])->plot_path(dest_func);
      if(dir) {
        check=0;
        return dest_dir[i+1]+","+dir;
      }
    }
  }
  check=0;
  return 0;
}
