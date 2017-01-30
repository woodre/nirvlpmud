#include "/players/guilds/bards/def.h"

status main(string str) {
  return (status)call_other(SPELLS+"01_process","main",str);
}
