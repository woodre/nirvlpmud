inherit "obj/treasure";
#include "/players/illarion/dfns.h"
string recipient,message;

void reset(int arg) {
  if(arg) return;
  
  set_id("gem");
  set_short("A message gem");
  set_long(
"A green, symetrical gem.  Although it looks semi-precious at best, you\n"+
"feel a hidden power lurking within it.\n");
  set_value(0);
  set_weight(0);
}
short() {
  return "A "+(recipient?GRN+"glowing"+NORM:"")+" message gem";
}
long() {
  ::long();
  if(!environment(this_object()) || environment(this_object()) != TP)
    return;
  if(recipient && TP->query_real_name() == recipient)
    write(
"The gem flickers slightly, as if in recognition.  To unlock the message\n"+
"within, use "+BLD("gem_message")+".\n");
  else
    write(
"The gem seems strangely empty, as if waiting.  To exploit its powers, use\n"+
BLD("impress_gem")+"  To impress the gem, you will need time to "+
"concentrate.\n");
}
void init() {
  ::init();
  add_action("cmd_message","gem_message");
  add_action("cmd_impress","impress_gem");
}
int cmd_message() {
  object env,user;
  env=environment(this_object());
  user=TP;
  if(!env || env != user) return 0;
  if((string)user->query_real_name() != recipient) {
    write("The gem glints, seeming angry, and a shock jumps to your hand,\n"+
          "forcing you to drop it.\n");
    user->hit_player(5);
    say(user->query_name()+" jumps slightly and drops a gem.\n");
    transfer(this_object(),environment(env));
    return 1;
  }
  if(!message) {
    write("The gem flashes, but nothing happens.\n");
    return 1;
  }
  write("You stare deeply into the gem, and suddenly, a message jumps into\n"+
        "your mind.\n");
  write(message);
  say(user->query_name()+" stares deeply into a green gem.\n");
  return 1;
}
int cmd_impress() {
  if(recipient && message) {
    write("The gem has already been impressed with a message.\n");
    return 1;
  }
  write("Enter the name of the recipient for the message: ");
  input_to("set_recipient");
  return 1;
}
set_recipient(str) {
  if(!str) {
    write("Aborting.\n");
    return 1;
  }
  recipient=lower_case(str);
  write("The recipient is "+recipient+".  Is this correct? <y/n>: ");
  input_to("correct_recipient");
  return 1;
}
correct_recipient(str) {
  if(str == "y" || str == "Y" || str == "yes") {
    write("You will be able to enter as many lines as you want.  End with\n");
    write("\".\" or \"**\".\n");
    write("[gem] > ");
    input_to("enter_message");
    return 1;
  } else {
    write("Enter the name of the recipient for the message: ");
    input_to("set_recipient");
    return 1;
  }
}
enter_message(str) {
  if(str == "." || str == "**") {
    if(message) {
      write("Message imprinted into the gem.  It can only be read by \n"+
            recipient+".\n");
    } else {
      recipient=0;
      write("Aborted.\n");
    }
    return 1;
  } else {
    message=(message?message:"")+format(str,70);
    write("[gem] > ");
    input_to("enter_message");
    return 1;
  }
}
