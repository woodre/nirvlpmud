#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  t = 0;
  set_light(1);
short_desc="Bard Common Room- Ruins";
long_desc=
 "The hand of destruction was thorough, and little remains of the bards\n"+
 "guild hall.  This was once the main area.  Now, rock and wooden splinters\n"+
 "cover a blasted floor.  Paper is scattered about, torn and burned.  The\n"+
 "unthinking violence which exploded here lingers, lending an aura of death\n"+
 "to an open area which was once a cozy place filled with song.\n";

items=({
  "rock","The blast blew apart the stone fondations of the\n"+
         "hall, leaving jagged edges and piles of stone",
  "wood","The once beautiful wood paneling of the main room\n"+
         "of the guild hall is now but broken splinters strewn\n"+
         "about like a giant's game of pick up sticks",
  "floor","The floor has been charred, scorched black by a destructive fire",
  "paper","Picking up a scrap of paper, you make out lines of poetry,\n"+
          "probably some bard's entry into a now dead journal",
 });

  dest_dir=({
 "/players/saber/closed/old_bard/room/tel.c","north",
 "/players/saber/ryllian/orin_ruin2.c","down",
 "/players/saber/closed/old_bard/room/lo.c","west",
           });
  call_out("flicker",5);
  }   
  
}

flicker() {
  tell_room(this_object(),
  "The heat is immense in this room.  The roaring of flame\n"+
  "deafens the ears and the brilliiance coming from the north\n"+
  "blinds the eyes.\n");
 call_out("flicker",5+random(100));
return 1; }
