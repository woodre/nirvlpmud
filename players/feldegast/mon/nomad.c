/*
A neat little monster at the entrance to the Jal-Hab.  Keeps
track of who he's introduced himself to so that he won't
repeat himself.  Also sells maps which come in handy when
navigating around the Jal-Hab.  He's also my test monster
for conversations.
*/
#include "defs.h"

inherit MONSTER;

object *greeted;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sadik");
  set_alt_name("nomad");
  set_alias("");
  set_short(YEL+"A desert nomad"+NORM);
  set_long(
"The nomad is a thin fellow of medium height with a salt\n\
and pepper beard.  He wears loose dun colored clothing\n\
that billows in the desert wind and a blue cloth wound\n\
around his head to protect his face from the sand.\n"
  );
  set_gender("male"); /* "male","female" */
  set_race("human");
  set_level(12);
  set_wc(15); /* -1 */
  set_ac(10); /* +1 */
  set_hp(195); /* +15 */
  set_al(50); /* Not angelic, but honest */
  set_chat_chance(5);
  load_chat("Sadik drinks deeply from the pool.\n");
  load_chat("Sadik stares out into the desert.\n");
  set_a_chat_chance(4);
  load_a_chat("Sadik begins to howl like the desert wind!\n");
  load_a_chat("Sadik screams a battle cry in the desert tongue.\n");
  greeted=({ });
  add_talk("quest","Sadik says: I do not know of any quest.\n");
  add_talk("feldegast","Sadik says: The Great One?  No one has seen or heard from him in many moons.\n");
  add_talk("p'kalians","Sadik says: The P'kalians are a peaceful folk.  We often trade with them.\n");
  add_talk("myrmidar",
    "Sadik says: The myrmidar are scavengers, though they rarely venture outside\n"+
    "  of their mound.  They seem strange and out of place, even for this unholy\n"+
    "  place.\n");
  add_talk("keys","Sadik says: Legends tell of the four keys, but no one knows where they lie.\n");
  add_talk("greetings", "#list_greets");
  add_talk("desert", "Sadik says: This is a hellish place, a hairs-breadth away from the demon\n"+
                     "plane.  Be careful if you travel in this land.\n");
  add_talk("cactipods", "Sadik says: They are cunning plants, magically changed by Jal-Hab's evil\n"+
                        "\tinfluence.  They'll attack you when you least expect.\n");
  add_talk(({ "portal", "azure portal" }),
           "Sadik says: The azure portals were built by my people's ancestors, the\n"+
           "\tMajiri.  We lost the craft of creating them long ago.\n");
  add_talk("map", "Sadik says: The map will prevent you from getting lost in\n"+
                  "\tthe desert as well as show you were to go.\n");
  add_talk("wocket", "Sadik says: Legends speak of The Strange One and his Mighty\n"+
                     "\tSnail of Death.\n");
}

void long(string str) {
  ::long(str);
  call_out("hello",3,this_player());
}

string short() { 
  if(TP && member_array(TP,greeted)!=-1)
    return HIB+"Sadik"+NORM+YEL+" the Nomad"+NORM;
  else
    return (string)::short();
}

void hello(object hi) {
  if(member_array(hi,greeted)==-1) {
    greeted+=({ hi });  
    tell_object(hi,
"\nThe Nomad says: Greetings, Traveller.  My name is Sadik.  Judging from your\n\
\trather...unusual...arrival, I am guessing that you are a newcomer to\n\
\tthis land.  If I am incorrect, please forgive me.  But if you should\n\
\tfind yourself in need of direction, then I would be happy to sell you a\n\
\tmap for your journeys here in the Jal-Hab region.  A great boon for a\n\
\tmere 50 coins.\n"
    );
    tell_room(environment(),"The nomad and "+(string)hi->query_name()+" step a little bit away\n"+
                            "from the oasis and have a brief conversation.\n",({ hi }));
  } else {
    tell_object(hi,"Sadik nods to you in greeting.\n");
    tell_room(environment(),"Sadik nods to "+(string)hi->query_name()+" in greeting.\n",({ hi }));
  }
}

void init() {
  ::init();
  add_action("cmd_buy","buy");
  add_action("cmd_buy","purchase");
}

int cmd_buy(string str) {
  if(!str || str!="map") {
    notify_fail("Sadik asks: What would you like to buy?  A map is all I have to sell.\n");
    return 0;
  }
  if((int)this_player()->query_money() < 50) {
    write("Sadik frowns at your lack of funds and then loses interest in you.\n");  
    return 1;
  }
  if(!((int)this_player()->add_weight(1))) {
    write("Sadik looks flustered.  \"I am sorry, but I cannot in good conscience\n"+
          "add another straw to your back lest I break it!\"\n");
    return 1;
  }
  this_player()->add_money(-50);
  move_object(clone_object(OBJ_PATH+"map-jalhab.c"),this_player());
  write("Sadik puts your coins away, and then takes a scroll from his\n"+
        "pouch and places it in your hand.\n");
  tell_room(environment(),TPN+" buys a map from the nomad.\n",({ TP }));
  return 1;
}

heart_beat() {
  ::heart_beat();
  if(!name_of_weapon && attacker_ob && !present("scimitar")) {
    move_object(clone_object(WEP_PATH+"scimitar.c"),this_object());
    tell_room(environment(),short()+" draws a scimitar from his belt.\n");
    init_command("wield scimitar");
    set_wc(15);
  }
}

/* This is just a test of the conversation function calling. */
list_greets() {
  int i;
  write("Sadik says: I have greeted the following people:\n");
  for(i=0; i < sizeof(greeted); i++)
    if(greeted[i]) write(greeted[i]->query_name()+"\n");
  return 1;
}
