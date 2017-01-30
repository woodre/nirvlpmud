#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
  t = 0;
short_desc="Orin's Common/Bar Room- Ruins";
long_desc=
"This was the common room of Orin's Inn, where adventurers of all stations and\n"+
"status socialized in comfort, before its tragic destruction.  Now what you \n"+
"see that is left of the once beautiful and glorious Inn is desolution.  The \n"+
"cherished wooden floors have been scarred and torn, the bar has been hacked\n"+
"apart and burned, the shelves that lined the walls have been shattered, and\n"+
"the tables and chairs are all but ashes.\n";

  dest_dir=({
 "/players/saber/ryllian/orin1.c","west",
 "/players/saber/ryllian/orin_ruin3.c","east",
 "/players/saber/closed/old_bard/room/ent.c","up",
           });
		   call_out("flicker",5);
  }   }

flicker() {
  tell_room(this_object(),
  "You feel a great warmth coming down from above.\n");
call_out("flicker",5+random(100));

return 1; }

