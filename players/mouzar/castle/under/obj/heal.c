/*Coded by dragnar*/
int hps;
id(str) { return str == "healer"; }
reset() { 
  set_heart_beat(1);
}
short() { return "A magical healer"; }
long() {
  write("A magical healer that will heal you when your hit points fall\n" +
        "your set amout of hit points left.  To do they type sethps #.\n"+  
        "You can also 'heal' if you wish.\n");
}
init() {
  add_action("heal","heal");
  add_action("set_hitpoints","sethps");
}
set_hitpoints(str) {
  sscanf(str,"%d",hps);
  write("Healer will now heal you when your hit points fall below "+hps+"\n");
  return 1;
}
heart_beat() {
  object user;
  user=environment(this_object());
  if(environment(this_object())->query_hp() < hps)  {
    (environment(this_object())->heal_self(350));
    tell_object(user, "The healer senses your needs and heals you.\n");
    tell_object(user, "The healer vanishes.\n");
    destruct(this_object());
  }
}
heal() {
        this_player()->heal_self(35);
        write("You heal yourself with the healer.\n");
        write("The healer loses it's magic and vanishes.\n");
        say(capitalize(this_player()->query_real_name()) + " heals themself useing the healer.\n");
        destruct(this_object());
        return 1;
        }
get () { return 1; }
query_weight() { return 4; }
query_value() { return 500; }
