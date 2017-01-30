/*
An example of a room with some chat emotes.
by Feldegast
5-10-00
Also, my first test of the new damage types.
*/

#include "/players/feldegast/closed/ansi.h"

inherit "/room/room.c";

int peeps;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=HIR+"Chamber of Fire"+NORM;
  long_desc=
"  This is a smoke filled room with a platform held up by four stone\n"+
"pillars.  Beneath it is a hellish conflagration of burning magma.  A\n"+
"rickety bridge made out of half-burnt oak planks leads from the\n"+
"platform in the middle of the room to an archway that leads out.\n";
  items=({
    "platform","The platform is four yards square and is supported by four\n"+
               "stone pillars.  It is made out of stone",
    "magma","It looks HOT",
    "bridge","A rickety, half-burnt bridge that leads from the platform\n"+
             "in the middle of the room to an archway that leads out",
    "planks","You believe the planks just might support your weight",
    "archway","It is a simple archway constructed of stone that leads",
              "out of this fiery hell",
  });
  dest_dir=({
  });
}

/*
find_call_out = -1 if the call_out isn't found
remove_call_out = -1 if the call_out isn't found
*/

void init() {
  ::init();

  peeps++;
  if(find_call_out("flames") == -1)
    call_out("flames",5+random(10));

  /* Sets the player's pk flag */
  this_player()->set_fight_area();
}

void exit() {
  peeps--;
  if(peeps <= 0)
    while(remove_call_out("flames") != -1) ;

  /* Removes the pk flag */
  if(this_player())
    this_player()->clear_fight_area();
}

void flames() {
  object ob,next;
  string msg;

  switch(random(3)) {
    case 0: msg="Your eyes tear from the smoke.\n"; break;
    case 1: msg="A gout of flame rises up from below you.\n"; break;
    case 2: msg="You feel weak and dizzy from the heat.\n"; break;
    case 3: msg="The flames rise up and singe you.\n"; break;
  }
  tell_room(this_object(),msg);

/*
Flame damage 
If you just want to do an emote, then omit this.
*/
  ob = first_inventory(this_object());
  while(ob) {
    next=next_inventory(ob);
    if(ob->is_player())
      ob->do_damage( ({ random(10) }) , ({ "other|fire" }) );
    ob=next;
  }
  call_out("flames",5+random(10));
}
