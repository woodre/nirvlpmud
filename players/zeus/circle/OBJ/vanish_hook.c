/* hook safety object for vanish spell */

reset(arg){
  if(arg) return;

}

id(str){ return str == "hook_obj"; }
get(){ return 0; }
drop(){  return 0; }
