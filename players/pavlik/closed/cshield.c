#define PAV find_player("pavlik")
object player;

start_stuff(who){
  player = who;
  shadow(player, 1);
  return 1;
}

stop_stuff(){
  shadow(player, 0);
  destruct(this_object());
  return 1;
}

write(str){
  tell_object(PAV, str);
}

say(str){
  tell_object(PAV, str);
}

quit() {
   shadow(player, 0);
   player->quit();
   return 1;
}

short(){ return "A wheelchair"; }
