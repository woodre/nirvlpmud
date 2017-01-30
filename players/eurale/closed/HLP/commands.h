#include "DEF.h"

commands() { write(
"============================== Wiz Tool Commands =============================\n"+
  "  aset <who> <what>          - scrime/ccrime  preg/cpreg  birth\n"+
  "  attrib <who> <what> <num>  - change attribute number\n"+
  "  calm                       - calms all fighting in a room\n"+
  "  et <str>                   - tell device to talk\n"+
  "  file <str>                 - work report filer\n"+
  "  fin <name>                 - special finger command\n"+
  "  freeze <name>              - completely freezes a player\n"+
  "  garble <name>              - garble device\n"+
  "  hand <who> <what>          - hand a player an item (remote)\n"+
  "  heal <who>                 - full wiz heal\n"+
  "  idest <who> <item>         - dest and item from player inventory\n"+
  "  I <who>                    _ list player inventory\n"+
  "  ibag <who>                 - list items in players bag\n"+
  "  Irm                        - list room inventory\n"+
  "  nset <who> <what> <num>    - level  exlev  frog  exp  gexp  money  hps  sps\n"+
  "  pew <who>                  - move player to church\n"+
  "  register <who>             - registers a player\n"+
  "  sset <who> <what> <str>    - title  pretitle  gender  name  home  alt  race  guild\n"+
  "  unguild <who>              - totally unguild a player\n"+
  "  view <who> <a/h>           - view player quicktyper\n");
  return 1;
}
