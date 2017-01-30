object room;
object player;
shadow_room(obj){
  room = obj;
  shadow(room,1);
  player = this_player();
}

unshadow_room(){
  shadow(room,0);
  destruct(this_object());
  return 1;
}

init(){
  if(this_player() == player){
  return ;
  }
  else
  if(room) room->init();
}

