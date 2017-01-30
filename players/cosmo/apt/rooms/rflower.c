/* Apartment Room */
#define tp this_player()->query_name()
#define mp this_player()->move_player
#include "/players/cosmo/closed/ansi.h" 
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BLU+"Flower Stand"+NORM;
  no_castle_flag = 0;
  long_desc=
"  You manage to dodge the passing cars and make it safely to\n"+
"the other side of the street.  Looks like there is a small stand\n"+
"here where a vendor is selling flowers.  Wouldn't you like to\n"+
"buy one of the lovely flowers? [only 50 coins]  An old man and a\n"+
"young lady stand in line to purchase some.  You do a double-\n"+
"take at them and realize that it's Jerry's uncle and George's\n"+
"ex-girlfriend.  It looks like you'll have to cross the street\n"+
"again to get back to the other side.\n",

  items=
  ({
    "flowers","The roses are in full bloom and may be purchased for 50 coins each",
  });

  if(!present("leo", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/leo.c"), this_object());
  }
  if(!present("susan", this_object())){
    move_object(clone_object("/players/cosmo/apt/mon/susan.c"), this_object());
  }
}

init() {
  ::init() ;
  add_action("blah","buy");
  add_action("blah","purchase");
  add_action("cross","cross");
}

cross(arg) {
int hit, amt;
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
    say(capitalize(tp)+" walks bravely back across the street.\n");
    mp("across the street#/players/cosmo/apt/rooms/rs6"); }
  return 1;
}

blah(arg) {
  if(!arg) {
    write("What would you like to purchase?\n"); return 1; }
  if(arg == "flower" || arg == "rose") {
    if(this_player()->query_money() < 50) {
      write("Show me the money!\n");
      return 1; }
    if(!call_other(this_player(),"add_weight",1)) {
      write("You cannot carry that much.\n");
      return 1; }
    this_player()->add_money(-50);
    move_object(clone_object("/players/cosmo/apt/obj/rose.c"), this_player());
    say(capitalize(tp)+" purchases a rose.\n");
    write("You purchase a rose.\n");
  return 1; }
  else { write("The "+arg+" is not for sale.\n"); }
return 1; }

