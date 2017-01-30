inherit "obj/treasure";
query_auto_load(){return("/players/rumplemintz/obj/bracelet.c:");}
string pre, post;

reset(arg){
  if(arg){return;}
}

init(){
  add_action("msg","msg");
  add_action("beep","beeprump");
  add_action("beep","brump");
}

short(){return "A Friendship Bracelet (Rumplemintz)";}
long(){
  write("This is a symbol of Friendship from Rumplemintz.\n"+
        "To talk to him simply type 'msg' and your message.\n"+
        "You can emote with  'msg :(message)' and beep him\n"+
        "by typing 'beeprump or brump' .  To get rid of the\n"+
        "bracelet just drop it.\n");
}
id(str){return (str == "F_B" || str == "bracelet" ||
                str == "friendship bracelet");}

int drop() {
  this_object()->remove();
  write("You drop the bracelet, and it vanishes.\n");
  say("A creepy lookin dude comes up and snatches a bracelet.\n");
  destruct(this_object());
  return 1;
}

msg(str){
  if(!str) return;
    if(sscanf(str,":%s",post)==1)
      pre="(Friend) "+capitalize(this_player()->query_real_name())+" ";
      else {
      pre="[Friend "+capitalize(this_player()->query_real_name())+" >> "; post=str; }
      tell_object(find_player("rumplemintz"),pre+post+"\n");
      write("Your message has been sent.\n");
  return 1;
}

beep(){
  pre=capitalize(this_player()->query_real_name());
  tell_object(find_player("rumplemintz"),pre+" is Bracelet Beeping you.\n");
  write("You just beeped him... maybe that'll wake him up!\n");
  return 1;
}
