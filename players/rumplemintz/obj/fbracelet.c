inherit "obj/treasure";
string owner;
object ob,ob2;
int weight;

reset(arg){
  if(arg) return;
  name = "A Friendship Bracelet";
}

extra_look(){ return (environment()->query_name()+" has a good friend in "+capitalize(owner) +" ..");}
query_auto_load(){ return("/players/rumplemintz/obj/fbracelet.c:"+owner+";");}

id(str) { return (str == "bracelet" || str == "friendship_bracelet"); }

short() { if (owner) { return name + " (" + capitalize(owner) + ")"; } else { return name; } }

long(){
  write("You run your eyes along the slender golden band that covers\n"+
        "your wrist ... It shines gently as you tilt your hand in the\n"+
        "sun, the diamonds set in it reflecting their own soft light,\n"+
        "sparkling as if to smile at you ... The bracelet is warm on your\n"+
        "wrist, and you cannot help but feel you have a good friend.\n");
}

init_arg(str)
{
  sscanf(str,"%s;",owner);
}

init(){
  add_action("msg",          "msg");
  add_action("express",      "express");
  add_action("echo_owner",  "echo");
  add_action("help",         "help");
  if (owner){
    ob = find_player(owner);
    if (ob) {
      msg(this_player()->query_name() + " has entered the game!");
    } else {
      write("Bracelet: " + capitalize(owner) + " is not playing now.\n");
    }
  }
}

get() { return 1; }
query_value() { return (0); }
query_weight(){ return (0); }

get_owner(){
  if (owner) {
    ob = find_player(owner);
    if (ob) return(1);
    write(capitalize(owner) + " tells you: I'm not here.\n");
  } else {
    write("You do not have a friend!\n");
  }
  return;
}

msg(str){
  if (!get_owner()) return(1);
  tell_object(ob, this_player()->query_name() + " (friend): " + str + "\n");
  write("You tell " + ob->query_name() + ": " + str + "\n");
  return(1);
}

local_set_owner(str) { owner = str; }

drop(str) { if (owner) { return(1); } else { return(0); } }

express(str){
  if (!get_owner()) return(1);
  tell_object(ob,this_player()->query_name() + " is glad you're friends.\n");
  write(this_player()->query_name() + " is friends with " + ob->query_name() + " ...\n");
  return(1);
}

echo_owner(str){
  if (!get_owner()) return(1);
  tell_object(ob,"\n" + str + "\n");
  write("You echo: " + str + "\n");
  return(1);
}

help(str){
  if (str == "bracelet") {
    write("With this bracelet, you can:\n"+
          "  MSG <message> - Tell your friend a message.\n"+
          "  EXPRESS - Express your friendship.\n"+
          "  ECHO - A private echo to your owner.\n"+
          " \n"+
          "If you would like to see more added, mail Rumplemintz.\n");
    return(1);
  }
  return;
}
