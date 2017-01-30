inherit "obj/treasure";

query_auto_load() { return "players/lew/closed/ravyn:"; }
drop() { return 0; }
take() { return 0; }
reset(arg) {
  if(!arg);

     set_id("ravyn");
     set_short("A large black ravyn");
     set_long("A large ravyn belonging to Bagera.\n"+
"It is said that this bird was raised by an anchient wise man in\n"+
"Tibet.  There is a legend around this bird.  Type 'legend' to see what\n"+
"it is.\n");
      set_weight(0);
      set_value(0);
     set_heart_beat(1);
}
init() {
  ::init();

    add_action("legend", "legend");
     add_action("ask", "ask");
     add_action("fetch", "fetch");
     add_action("harass","harass");
     add_action("relay", "relay");
     add_action("flyto", "flyto");
}
flyto(str) {
    object person, tp;
    person=find_player(str);
    tp=this_player();
    write("The ravyn grasps you by the shoulders and takes you to "+capitalize(str)+".\n");
     move_object(tp, environment(person));
    say(capitalize(tp->query_real_name())+" araives carried by a giant ravyn.\n");
}
relay(str) {
   string who, what;
    if(!str || sscanf(str, "%s %s", who, what) != 2) {
      write("You want me to tell who what?\n"); return 1; }
    if(!find_player(who)) { write("That person is not on.\n");
      return 1; }
    tell_object(find_player(who), "A large ravyn lands on your shoulder and tells you:\n"+
                                  what+"\n"+
                                  "It then flies away.\n");
    write("You send the ravyn off to deliver a message.\n"+
          "It quickly returns to you.\n");
    return 1;
}
fetch(str) {
    object person;
    person=find_player(str);
    if(!person) { write("I can not bring ho is not here.\n"); return 1; }
    move_object(this_object(), environment(person));
    say("A large ravyn enters the room and takes "+person->query_real_name()+
        "off to its master.\n");
    tell_object(person, "A giant black bird grabs you by the shoulders\n");
    move_object(this_object(), find_player("bagera"));
    move_object(person, environment(find_player("bagera")));
    return 1;
}

legend() {
    write("The bird turns its head to face you.\n"+
          "Suddenly you hear in your mind a deep raspy voice.\n");
    write("\n");
    write("Over one thousand years ago I was born.\n"+
          "After a few years, I felt it was time \n"+
          "to go on to my own life.  So I left the nest.\n");
    write("Little did I know how week my wings were.\n"+
          "I plumeted to the earth, screaming for my mother.\n"+
          "No one heard me, except this little old man.\n");
    write("In the following years this little man raised me.\n"+
           "Made my wings strong.  Taught me to hunt for food.\n"+
          "In time, I was able to fend for myself.\n");
    write("After many years, a man dressed in pure black\n"+
          "came to visit my master.\n");
    write("He said that he needed a guide, for a friend.\n"+
          "Someone who was wise in many things.\n");
    write("They talked for many hours.\n"+
          "Finally my master came to me.\n");
    write("He told me that when this man takes me to\n"+
          "his friend, that I am to protect her at all costs.\n"+
          "So, my lady, here I am.  Just 'ask ravyn' for all\n"+
          "I may do for you.\n");
    return 1;
}
heart_beat() {
    if(environment(this_object()) != find_player("bagera")) {
    say("The ravyn tells you: You are not my master.\n");
    if(!find_player("bagera")) destruct(this_object());
    move_object(this_object(), find_player("bagera"));
    }
    return 1;
}
ask(str) {
    if(!str) return 0;
    if(str != "ravyn") { write("Ask what?\n"); return 1; }
  write("The ravyn tells you: With me you you may do the following:\n");
  write("===================================================================\n"+
        " fetch <player>    Send me to bring someone to you.\n"+
        " harass <player>   Send me to annoy someone.\n"+
        " relay <message> <player>  Send me on a message run.\n"+
        " flyto <player>    I will take you to someone.\n"+
        "===================================================================\n");
   return 1;
}
blurp(str) {
if(!find_player("bagera")) { return 1; }
tell_object(find_player("bagera"), "The bird turns to you and says: "+str+".\n");
  return 1;
}
