#include "/obj/user/shout_only.c"
inherit "room/room";
int lit;
int coord;
int delay;

reset(arg) {
  if(arg) return;
  short_desc="Cannon Room";
  long_desc="You are in a rather large room.  There is a huge cannon in\n"
    +"the center of the room pointing to somewhere across the chasm.\n";
  dest_dir=({"players/grimm/rooms/haphaz_l12","northwest",
             "players/grimm/rooms/haphaz_l13","west"});
  items = ({"cannon","The cannon is large enough for a human to enter it.\n"
   +"Maybe you could light it and try it.\n"});
  set_light(0);
 }
init() {
  add_action("light","light");
  add_action("enter","enter");
  add_action("set_can","SET");
  add_action("set_can","set");
  ::init();
 }
light(str)  {
  if (!this_player()->query_ghost()) {
  if (str=="cannon" || str=="fuse") {
    say(this_player()->query_name()+" lights the cannon.\n");
    write("The cannon fuse sizzles for a second and is lit...\n");
    lit=1;
    return 1; }
   } else
    { write("You can't do that in your present state!\n"); }
 return 1;
  }
enter(str)  {
  if (!this_player()->query_ghost()) {
  if (str=="cannon") {
    if (lit==1) {
      say(this_player()->query_name()+" enters the cannon.\n");
      chan_msg("You hear a cannon go off in the distance and a second later "
      +"you see "+this_player()->query_name()+"\nfly through the air with"
      +" the greatest of ease (kicking and screaming the\nentire way).\n");
      write("You enter the cannon.\n"+
        "The cannon goes off hurling you across the chasm.\n");
        write("You land on the other side of the chasm with a thump.\n");
        lit=0;
        if (coord==1)
          this_player()->move_player("screaming#players/grimm/closed/room1");
        else
          this_player()->move_player("screaming#room/shop");
        coord=0;
  return 1; }
  else {
    write("You enter the cannon, realize it isn't lit, and climb back out.\n");
   return 1;
    }
  }
   }
   else
     write("You cannot do that in your present state!\n");
return 1;
}

set_can(str) {
  int i,j,k;
  i="players/grimm/closed/coord"->i_coord();
  j="players/grimm/closed/coord"->j_coord();
  k="players/grimm/closed/coord"->k_coord();
    if (!str) {
      write("What do you want to set?\n");
      return 1;
     }
    if (str=="coordinates") {
      write("What coordinates do you want to set the cannon to?\n");
      return 1;
      }
    if (str=="coordinates "+i+"'"+j+"."+k+"''"){
      write("You set the coordinates of the cannon and watch it whirl"+
            " around and face a new direction.\n");
      coord=1;
      return 1;
      }
return 0;
}
