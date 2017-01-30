reset(arg){
 if(arg)
   return;
 call_out("ridthis", 150);
}
short(){ return; }
long(){ write("a mages twin_obj.\n"); return; }
id(str){ return str == "twin_obj"; }
get(){ return 0; }
drop(){ return 1; }

ridthis(){
 destruct(this_object());
 return 1;
}
