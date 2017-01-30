id(str) { return str == "dester"; }

get() { return 1; }

drop() { return 0; }

reset(arg) {
  if(arg) return;
  call_out("destt",200);
}

destt() { 
  destruct(environment(this_object())); 
  destruct(this_object()); 
return 1;}

