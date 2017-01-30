
/*
 * VIEWING DEVICE (7/3/94)
 * Let's people in /players/molasar/sparring/balcony watch a sparring
 * match in safety.
 */

inherit "obj/monster";

reset(arg) {
   if(arg) return;
   set_name("viewer");
   set_alias("device");
   set_ac(1000000);
   set_hp(1000000);
   set_wc(0);
   set_ep(0);
   set_level(1);
   set_short(0);
   set_long("A small viewing device.");
   ::reset();
}

#define ROOM "/players/molasar/sparring/balcony"

catch_tell(str) {
   object view_room;

   view_room = find_object(ROOM);
   if(view_room) 
     tell_room(view_room,"FROM BELOW> "+str);
}


query_viewer_flag() { return 1; }
