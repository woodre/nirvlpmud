id(str) { return str == "light_dam"; }

reset(arg) { 
  if(arg) return;
  call_out("checks",5);
}

checks() {
int n;
 n = 0;
 n = set_light(0);
 environment(this_object())->heal_self(-n);
 if(n<0) tell_object(environment(this_object()),"You are healed."+n+"\n");
 if(n>0) tell_object(environment(this_object()),"You are hurt."+n+"\n");
 if(n ==0) tell_object(environment(this_object()),"You are fine."+n+"\n");
call_out("checks",5);
return 1;}
