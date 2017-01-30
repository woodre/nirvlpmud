#include "/players/guilds/bards/def.h"

status main(string str) {
  return (status)call_other(SPELLS+"05_farsinging","main",str,1);
}
