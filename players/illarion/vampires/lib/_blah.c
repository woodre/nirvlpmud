#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ "xlevel" : ({100,"You are not powerful enough to use this ability.\n"}),
                     "special_function" : ({0,"You did not pass the special function.\n"})
                   ]);
}

main(str, targ, usr, gob) {
  write("blah: "+targ+"\n");
  return 1;
}

special_function(cmp, msg, target, usr, gob) {
  write("special function called.\n");
  return 0;
}