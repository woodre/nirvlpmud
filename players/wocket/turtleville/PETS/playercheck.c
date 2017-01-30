playercheck(str){
call_out("destme",2);
  if(!restore_object(str)){ return 0;} return 1; }

destme(){
  destruct(this_object());
}
