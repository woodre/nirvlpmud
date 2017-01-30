/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "players/cosmo/dc/dcroom";

reset(arg) {
  if(arg) return;
  set_light(1);
  set_room_type("street");
  short_desc=GRN+"Upper East Side"+NORM;
  long_desc=
"  You continue down the sidewalk of this long street on the\n"+
"upper east side.  The traffic has picked up and is quite heavy\n"+
"here.  Despite the large number of cars on the road, they still\n"+
"seem to drive at a rapid pace.  Shops and apartment buildings\n"+
"line the sides of the streets.  On the other side of the street\n"+
"you notice a street-side flower shop.\n",

  items= ({
    "buildings","Old dirty buildings. Who knows what you might find in them",
    "street","You could probably cross the street to reach the flower shop",
    "shops","All of the typical city shops may be found along this street",
    "shop","Cross the street if you want to buy some flowers",
  });

  dest_dir= ({
    "players/cosmo/apt/rooms/rs4", "east",
    "players/cosmo/apt/rooms/rs8", "west",
  });
}

init() {
  ::init() ;
  add_action("cross","cross");
}

cross(arg) {
int hit,amt;
  if(!arg) { write("Cross what?\n"); return 1; }
  if(arg !="street") { write("You can't cross that.\n"); return 1; }
  hit = random(10);
  if (hit == 4) {
    amt = -1*(random(10)+10);
    say(capitalize(tp)+" cries out in pain as a car strikes "+
      this_player()->query_possessive()+".\n");
    write(RED+"Look out!!!!\n\nC R A S H !!!!"+NORM+"\n\n"+
      "One of the passing cars hits you, knocking you to the ground.\n");
    call_other(this_player(),"heal_self",amt);
    command("mon",this_player()); }
  else {
    say(capitalize(tp)+" walks bravely across the street.\n");
    mp("across the street#/players/cosmo/apt/rooms/rflower"); }
  return 1;
}
