/*
 slingshot.c
*/

/*
 * This thing is used to send a message to someone without costing spell
 * points.
*/

inherit "obj/treasure";

string str, message, target_name;

object capsule, target_obj;

init() {
  ::init();

  add_action("message", "write");
  add_action("shoot",   "shoot");
  add_action("shoot",   "fire");
}

message(str) {
  if (!str) return;
  write(
    "You use the pen to write a message on one of the pieces of paper and\n"+
    "slip it into one of the capsules.\n");
  say(capitalize(this_player()->query_name())+
      " uses a pen to write a message on a piece of\n"+
      "paper and slips it into a small capsule.\n");
  message=str;
  return 1;
}

shoot(target_name) {
  string str1, str2;
  str1=file_name(environment(this_player()));
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;
  if (str2=="players/nooneelse/red/maze_8") return 0;
  if (!message) {
    write("You must write the message before you can shoot it to someone.\n");
    return 1;
  }
  target_obj=0;
  target_obj=find_living(target_name);
  if(!target_obj || target_obj->query_invis()) {
    write("You try to sight in on "+target_name+" but can't find them.\n");
    say(capitalize(this_player()->query_name())+
        " tries to sight the slingshot in on\n"+
        "someone but can't find them.\n");
    return 1;
  }
  tell_room(environment(target_obj),
            "A small message capsule sails through the air, bounces off\n"+
            target_name+"'s forehead and falls to the ground.\n");
  capsule=clone_object("players/nooneelse/obj/capsule");
  capsule->set_message(message);
  capsule->set_message_sender(this_player()->query_name());
  capsule->set_message_target(target_name);
  move_object(capsule, environment(target_obj));
  message=0;
  str=0;
  write("The rubber tube on the slingshot snaps as you fire the capsule.\n");
  say(capitalize(this_player()->query_name())+
      " fires the slingshot in a high arc.\n");
  return 1;
}


reset(arg) {
  if (arg) return;

  set_short("a blue slingshot");
  set_long(
    "It is a blue slingshot with a compartment containing small pieces\n" +
    "of light blue paper, a blue pen and some small blue capsules.\n\n"+
    "To use it, type: write <one line message>\n"+
    "                 shoot <player name>\n\n"+
    "A small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(0);
  set_weight(1);
}

id(str) { return (str=="slingshot" || str=="blue slingshot"); }
