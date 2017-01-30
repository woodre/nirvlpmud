int hbon;
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(2);
    short_desc = RED+"HB ROOM"+NORM;
    long_desc =
    "A ROOM WITH HB\n";
    hbon = 0;
} }

init() { 
  if(!hbon) {
    if(this_player()->is_player()) {
      hbon = 1;
       set_heart_beat(1);
    }
 }
}

heart_beat() {
  if(!test_if_any_here()) { hbon = 0; set_heart_beat(0); return;}
  /* do whever .. i.e do checks etc */
  
  
}

test_if_any_here() {     /* taken directly from living.c */
  object ob;
  if(!environment(this_object())) return 0;
  ob = first_inventory(environment());
  while(ob) {
    if (ob != this_object() && living(ob) && !call_other(ob, "query_npc"))
      return 1;
    ob = next_inventory(ob);
  }
  return 0;
} 