#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/crypt1.c";

reset(arg){
  ::reset(arg);
  if(arg) return ;
dest_dir = ({
  PATH+"crypt2b.c","down",
  PATH+"gr8.c","out",
});
}
