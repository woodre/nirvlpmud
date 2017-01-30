#include "../defs.h"
cmd_be(str) {
  object ob;
  ob = OBJ+"/chatob";
  ob->emote(str);
  return 1;
}
