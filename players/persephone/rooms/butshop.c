inherit "/players/persephone/closed/thingys";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("Abdhulla")){
  move_object(clone_object("players/persephone/monster/abd"),TOB);
 }
 if(!arg) {
  set_light(1);
  short_desc="Butcher Shop";
  long_desc="This is unbelievable you walk into this butcher shop\n" +
            "and you see a vast array of carcases that do not look\n" +
            "like bovines, sheep or pigs but they do seem strangely\n" +
            "familiar.  Right in front of you before these carcases\n" +
            "is a large bench and display case which looks like\n" +
            "it has not been cleaned in years you seem to be in luck\n" +
            "the butcher is in\n\n";
  items=({"carcases","They look like they are human cadavers actually\n" +
                     "but they do appear to be quite fresh",
          "bodies","They look like they are human cadavers actually\n" +
                   "but they do appear to be quite fresh",
           "bench","This is a standard butchers bench and has blood\n" +
                     "stains on it.",
           "display","You can see specialty cuts in it like human tongue\n" +
                   "and liver",
           "case","You can see specialty cuts in it like human tongue\n" +
                   "and liver"});
  dest_dir=({"players/persephone/rooms/square6","north",
  });
 }
}
