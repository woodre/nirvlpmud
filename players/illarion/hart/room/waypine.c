inherit "/players/illarion/room";
#include "/players/illarion/dfns.h"

int fire;

void reset(status arg) {
  if(arg) return;
  
  set_light(1);
  set_short("Inside a wayward "+GRN+"pine"+NORM);
  set_long("The interior of a wayward pine, the traveller's friend, "
          +"resmbles nothing so much as a tent with a roof of pine "
          +"boughs, and the nearly horizontal trunk of the pine as "
          +"the peak.  The floor of the shelter is almost entirely "
          +"covered in soft fallen needles, but in the exact center "
          +"a stone firepit has been dug out.");
  
  add_item("pine","You're actually beaneath a pine that has grown "
                 +"out along the ground, creating a natural shelter.");
  add_item("roof","The thick mass of needles overhead shuts out "
                 +"any light from outside, and seems thick enough to "
                 +"block rain and muffle sounds, as well.");
  add_item("boughs","The pine's branches strech out at a tentlke angle "
                   +"from the trunk, all the way to the ground.  Except "
                   +"for a few grown too far to the inside of the shelter, "
                   +"they look strong and healthy.");
  add_item("branches","@boughs");
  add_item("needles","The fallen needles from the pine, some old, some "
                    +"newly fallen, cover the ground like a scented, "
                    +"shifting carpet.");
  add_item("floor","@needles");
  add_item("firepit","Dug slightly below ground level, and lined with "
                    +"stones, which show ash marks from previous fires.  "
                    +"$&firepit_string$&");
  add_item("trunk","The trunk of the pine stretches overhead like a "
                  +"living roofbeam, easily visible past the few branches "
                  +"that have tried and failed to grow in the pine's "
                  +"normally dark interior.");
  add_item("traveler","That would be you.");
  
  set_etime_const(90);
  set_etime_rand(90);
  add_room_emote("A few pine needles drift down from overhead.");
  add_room_emote("The scent of pine is nearly overpowering.");
}

string firepit_string(string str) {
  if(!fire)
     return "The inside of the firepit is empty.  If you had some firewood, "
           +"you could probably "+BLD("light")+" a fire in it.";
  else
     return "A fire burns cheerfully in the firepit, filling the pine with "+
            "light and warmth.  A thoughtful traveller will always "+
            BLD("douse")+" a fire before leaving, of course.";
}

void init() {
  ::init();
  add_action("cmd_light","light");
  add_action("cmd_douse","douse");
}

status cmd_light(string str) {
  object firewood;
  if(!str || str != "fire")
     FAIL("Light what?\n");
  firewood=present("firewood",TP);
  if(fire) {
     write("The fire is already burning.\n");
     return 1;
   }
  if(!firewood) {
    write("You need wood to start a wood fire.  You'd be able to "+BLD("collect")+"\n"
         +"some in the forest outside.\n");
    return 1;
  }
  transfer(firewood,this_object());
  destruct(firewood);
  write("You put the firewood in the firepit, and light it.   ");
  say(TPN+" puts some firewood in the firepit, and lights it.  ");
  tell_room(TO,"In a\n"
       +"remarkably short time, a cheeful fire is burning, the smoke\n"
       +"vanishing through the needles above.\n");
  fire=1;
  add_room_emote("The light of the fire flickers and dances along the boughs.");
  add_room_emote("The scent of smoke mixes with the smell of pine.");
  return 1;
}

status cmd_douse(string str) {
  if(!str || str != "fire")
     FAIL("Douse what?\n");
   if(!fire) {
     write("There is no fire in the firepit.\n");
     return 1;
   }
   write("You dig some dirt out from under the pine needles and throw it\n"+
         "on the fire.  In a few moments, the fire is out.\n");
   say(TPN+" throws some dirt onto the fire.  In a few moments, it has\n"+
           "gone out.  The interior of the pine quickly becomes darker and\n"+
           "colder.\n");
  remove_room_emote("The light of the fire flickers and dances along the boughs.");
  remove_room_emote("The scent of smoke mixes with the smell of pine.");
  return 1;
}
