inherit "players/snow/closed/cyber/objects/monster";

reset(arg){

   if(!present("_drivers_seat_")) {
     move_object(clone_object(
     "/players/snow/closed/cyber/objects/seat.c"),
     this_object()); }

   do_check();

   if(arg) return 0;
   ::reset(arg);
   set_alias("_hide_in_shadows_vehicle_");
   set_level(10);
   enable_commands();
   set_can_kill(0);
   set_aggressive(0);
}

do_check() {
  if(!present("_drivers_seat_")) {
    destruct(this_object());
    return 1; }
  call_out("do_check", 10);
}

catch_tell(string str) {
  tell_room(this_object(), str);
  return 1;
}


realm() { return "NT"; }
