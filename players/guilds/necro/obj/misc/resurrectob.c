id(str){ return str == "necro_resurrect"; }
init(){
  add_action("raiseme","necroresurrectme");
}

raiseme(){
  call_other(this_player(), "remove_ghost", 0);
  return 1;
}
