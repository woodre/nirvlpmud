id(str) { return str=="heh"; }

init() {
  add_action("hheh","woot");
}

hheh(arg){
  int x, y;
if(!arg) return 0;
  x=atoi(arg);
  if(x==1) y=50;
  else y=x+50;
  while(x<y){
    command("make "+x,this_player());
  x += 1;
  }
  return 1;
}
