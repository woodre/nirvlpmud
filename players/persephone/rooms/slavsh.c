inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
  if(!present("Jaundice")){
     move_object(clone_object("players/persephone/monster/jaund"),TOB);
  }
 if(!arg) {
  set_light(1);
  short_desc="Slave Shop";
  long_desc="The atmosphere in this shop is extremely unholesome, perhaps this is\n" +
            "caused by the pungent aroma of sweat. Directly in front of you is a\n" +
            "large counter behind which stands the Slavetrader. On the wall of the\n" +
            "shop is a large sign that is held in place by some strange looking\n" +
            "nails.\n";
  items=({"counter","A shop counter that is made completely out of black marble\n" +
                    "with strange looking legs and a large plate of glass behind\n" +
                    "which are some manacles and handcuffs",
          "sign","This gives a list of the price of slaves for Pirate ships",
          "nails","Well these are not steal nails but look to be made of bone",
          "bone","Well to be exact the bone looks as if it comes from humans their\n" +
                 "index fingers to be exact",
          "legs","Well human skulls to be precise but they do seem to do the job\n" +
                 "extremely well",
          "glass","You know the stuff you can see through that is primarily silicon\n" +
                  "and actually a liquid",
          "marble","This marble is so black you can barely make out any distinguishable\n" +
                   "features in it",
          "handcuffs","You know the things that police use when they catch criminals.\n" +
                      "In fact these look like standard Police Handcuffs",
          "manacles","Well leg Irons might be a better word they are used to stop\n" +
                     "slaves from running away"});
  dest_dir=({"players/persephone/rooms/square2","east",
  });
 }
}
realm() { return "NT"; }
