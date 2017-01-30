#pragma strict_types
#pragma save_types

string fix_path(string str) {
  string out;
  int i;
  if(str[0] != '/') 
    out = this_player()->get_path() + str;
  else
    out = str;
  i = strlen(out);
  i--;
  if(out[i] != '.' && out[i] != '*' && out[i] != '/')
    out[i] = out[i] + "/";
  return out;
}
