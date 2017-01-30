#include "defs.h"

int main(string arg) {
  object who, *obs;
  int i, siz;
  string sh;

  who = find_player(arg);
  if (!who) who = find_living(arg);
  if (!who) who = find_object(arg);

  if (!who) {
    notify_fail("Cannot find: "+arg+"\n");
    return 0;
  }

  obs = deep_inventory(who);
  write("Performing deep inventory on: "+arg+"\n");

  for (i = 0, siz = sizeof(obs); i < siz; i++) {
    write(i+"\t");
    sh = (string)obs[i]->short();
    if (!sh) sh = "INVISIBLE OBJECT";

    write((string)WAXFUNS->lalign(sh, 50));
    write(file_name(obs[i]));
    write("\n");
  }

  return 1;
}
