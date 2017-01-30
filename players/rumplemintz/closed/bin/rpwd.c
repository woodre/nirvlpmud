#include <security.h>
#include <ansi.h>

int rpwd() {
  object *ob;
  string pwd;
  string output;
  int x;

#if 0
  if (member(ADMINS, this_player()->query_real_name()) < 0) {
    write("You are not an admin!\n");
    return 1;
  } else
    write("Found your name in the admin list!\n");
#endif

  ob = users();
  output = "\n";
  output += HIR+"%%%%%%%%%%          PWD          %%%%%%%%%"+NORM+"\n";
  for (x = 0; x < sizeof(ob); x++) {
    if (ob[x]->query_level() > 19) {
      output += " "+pad(capitalize((string)ob[x]->query_real_name()), 13);
      output += "\n          ";
      output += " "+(string)ob[x]->query_pwd()+"\n";
    }
  }
  output += HIR+"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"+NORM+"\n";
  write(output+"\n");
  return 1;
}
