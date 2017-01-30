#pragma strict_types
#pragma save_types

string get_root(string path) {
  int i;
  string *foo,t,foo2,tm;
  foo = explode(path, "/");
  i = sizeof(foo);
  if(strlen(path) == 1) /* root */
    return path;
  i = sizeof(foo) - 1;
  foo[i] = 0;
  tm = "/"+implode(foo,"/")+"/";
  sscanf(tm, "%s/0/%s", foo2, tm);
  return foo2+"/"+tm;
}
