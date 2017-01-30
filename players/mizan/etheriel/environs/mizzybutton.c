int counting;
#include "/players/boltar/things/esc.h"
#define BLINK esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"
#define UNBLINK esc+"[0m"

id(str) { return str == "bomb"; }
short() { return "A HUGE bomb"; }
long() {
  write("Encased within a massive alloy shell, this thing would make one\n"+
	"HELL of an explosion if you happened to light it...\n");
}

reset() {
  counting=11;
}

init() {
  add_action("lightme","light");
}

lightme(str) {
  if(!str || str != "bomb") return 0;
  if(!present("Mi002033", this_player())) {
    write("You need a portable butane torch to light this thing.\n");
    return 1;
  }
  write("You successfully light the bomb...\n");
  say("Head for the hills!\n"+
  (this_player()->query_name())+" lights the freaking bomb!\n");
  call_out("countdown", 1);
  return 1;
}

countdown() {
  counting = counting - 1;
  say(counting+"...\n");
  if(counting = 0) {
    say("AAAUGH!!!! RUN FOR YOUR LIFE!!!\n");
    call_out("armageddon_time", 1);
    return 1;
  }
  call_out("counting",1);
  return 1;
}

armageddon_time() {
  int index;
  int i;
  string random_go;
  object people;
  people = users();
  say("\n\n\n\n"+BLINK+"BOOM!"+UNBLINK+"\n\n"+
  "What feels like the hand of God smacks you clear across the realm...\n\n");
  for(index = 0; index < sizeof(people); index++) {
    if(people[index]->on_channel("junk")) {
      tell_object(people[index], "A "+BLINK+"HUGE"+UNBLINK+" explosion rocks the orange jello tub...\n");
    }
    if(sscanf((environment(people[index])->short()), "Plane of Etheriel %s", i) == 1) {
      random_go=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
      tell_object(people[index], "\n\nA suits you, followed by a thundering *BOOM*\n\n"+
        "What feels like the hand of God smacks you clear across the realm...\n\n"+
	"You come to, and see figures near what looks like the epicenter of the blast.\n"+
	"They must have done it...\n");
      command(random_go, people[index]);
    }
  }
  return 1;
}
