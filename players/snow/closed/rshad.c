object room;

start_room_shadow(object ob) {
  if(!ob) return;
  room = ob;
  shadow(room, 1);
  return 1; }

stop_room_shadow() {
  shadow(room, 0);
  destruct(this_object());
  return 1; }

init() { return 1; }
