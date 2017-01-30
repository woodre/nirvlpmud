inherit"obj/treasure";
reset(arg){
if(arg) return;
set_id("destroyer");
set_short("A---D-E-S-T-R-O-Y-E-R-!!!");
set_long("A Player Destroyer.. do not press button, or you will die!!\n");
}
get(){
return 0;
}
init() {
  add_action("press", "press");
}
press(str) {
  if(str != "button") {
    write("Press what?\n"); return 1; }
call_other(this_player(),"hit_player",500);
write("You are killed by the Destroyer, idiot!\n");
  say(this_player()->query_name()+
" pushes the button on the machine and and dies like an idiot!.\n");
  return 1;
}
