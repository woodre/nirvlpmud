/*
 capsule.c
*/

/*
 * This is a message capsule shot from nooneelse's slingshot
*/

inherit "obj/treasure";

string message, message_target_name, message_sender_name, str;

init() {
  ::init();

  add_action("read", "read");
}

read(str) {
  if (!str) return;
  if (str!="message") return;
  if (lower_case(this_player()->query_real_name()) != "nooneelse") {
    if (lower_case(this_player()->query_name()) != message_target_name) {
      write("Hmmm.  Why are you trying to read "+message_target_name+
            "'s message?\n");
      return 1;
    }
  }
  write("The message from "+message_sender_name+" says:\n   "+message+"\n\n");
  if (lower_case(this_player()->query_real_name()) != "nooneelse") {
    write("As you read the message, the capsule and note crumble into "+
          "blue powder.\n");
    say("As "+this_player()->query_name()+
        " reads the message, the capsule and note crumble into blue powder.\n");
    destruct(this_object());
  }
  return 1;
}

reset(arg) {

  if (arg) return;

  set_short("a small blue message capsule.  Type: 'read message'");
  set_long("A small blue message capsule.  Type: 'read message'\n"+
           "A small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(0);
  set_weight(1);
}

set_message(str) { message = str; }

set_message_sender(str) { message_sender_name = str; }

set_message_target(str) { message_target_name = str; }

id(str) { return (str=="capsule" || str=="blue capsule"); }
