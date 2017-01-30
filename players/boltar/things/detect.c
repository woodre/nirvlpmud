string who;
init() {
add_action("setwho","setwho");
}
setwho(str) {
  who = str;
  write("detect set to "+who+"\n");
  call_out("find",3);
  return 1;
}
find(){
object bb;
bb=find_player(who);
if(!bb){ call_out("find",3);
return 1;
}
write(who+" is NOW ON!\n");
return 1;
}
id(str) {
  return str =="detect";
}
get(){return 1;}
