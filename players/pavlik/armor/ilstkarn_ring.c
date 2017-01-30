inherit "obj/armor";
#include "/players/pavlik/closed/colors.h"
#define ME capitalize(this_player()->query_name())
#define PO this_player()->query_possessive()

reset(arg){
 ::reset(arg);
 set_short("A topaz ring");
 set_long(
 "A small golden ring with a topaz stone setting.  The stone twinkles\n"+
 "magically.  You wonder what might happen if you were to twist the stone.\n");
 set_name("Topaz Ring");
 set_ac(1);
 set_weight(1);
 set_value(100);
 set_alias("topaz ring");
 set_arm_light(0);
 set_type("ring");
}

init() {
  ::init();
  add_action("twist","twist");
}

twist(str) {
  if(str == "ring" || str == "stone" || str == "topaz") {
    if(!worn && !present("notarmor", this_player())) {
      write("You must wear the ring first.\n");
      return 1;
    }

    write("You twist the topaz stone.\n");
    write("A brilliant flash of light blinds you!\n");
    say(ME+" twists plays with "+PO+" ring.\n");
    say("A brilliant flash of leaps blinds you!\n");

    if(environment(this_player())->realm() == "NT") {
      write("When you can see again you notice nothing has changed.\n");
      say("When you can see again you notice nothing has changed.\n");
      return 1;
    }

    write("When you can see again you are in a new place!\n");
    say("When you can see again you notice "+ME+" is gone!\n");

    if(present("ilstkarn_portal", environment(this_player()))) {
      move_object(this_player(), "room/church");
    }
    else {
      move_object(this_player(), "players/pavlik/ilstkarn/ilstkarn_portal");
      move_object(this_player(), environment(environment(this_player())));
    }
    say(ME+" appears in a brilliant flash of light!\n");
    return 1;
  }
}


quest_item() { return 1; }

