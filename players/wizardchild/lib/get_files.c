/* get_files.c: updated 3/23/98 for efficiency */
#include "lib.h"
 
#pragma strict_types
#pragma save_types
 
#undef get_files

string *get_files(string path) {
  int i;
  int so;
  string *out, *tmp;
  string root;
  out = ({ });
  tmp = get_dir(path);
  root = (string) get_root(path);
  for(i=0,so=sizeof(tmp);i<so;i++) {
    if(tmp[i] != "." && tmp[i] != ".." && file_size(root+tmp[i]) != -2)
      out += ({ tmp[i] });
  }
  return out;
}
