#include "../../defs.h"

id(str){ return str == "necro_resurrect"; }
init(){
  add_action("raiseme","necroresurrectme");
}

raiseme(){
  call_other(tp,"remove_ghost",0);
  return 1;
}

