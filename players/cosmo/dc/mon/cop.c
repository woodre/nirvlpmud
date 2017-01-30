#include "/players/cosmo/closed/dfns.h"
#include "/players/cosmo/closed/ansi.h"
#define TOOLS "/players/cosmo/closed/tools.c"
#define MAX_COPS 30

int cop_area_count;   /* Number of cops currently in the area */
string *names;        /* Array of short names */
string *room_msgs;    /* Array of entrance messages */
string *chats;        /* Array of chat messages */

reset(arg) {
   cop_area_count=0;
   if(sizeof(room_msgs) == 0) set_msgs();
}

query_mon() {
   if(cop_area_count < MAX_COPS) return 1;
   else return 0;
}

make_mon(n, tp) {
  object cop;
  string MONCOL;
  cop = clone_object("/obj/monster");
  cop_area_count++;
  cop->set_alias("cop");
  cop->set_race("human");
  cop->set_al(300-random(400));
  cop->set_level(8+(n*4));
  MONCOL=TOOLS->query_color(cop);
  cop->set_hp(120+(n*n*60));
  cop->set_wc(8+((n+1)*4));
  cop->set_ac(7+(n*2));
  cop->set_chat_chance(10);
  cop->load_chat("The officer looks around suspiciously.\n");
  cop->set_a_chat_chance(10);
  cop->load_a_chat("The officer screams out for reinforcements.\n");
  cop->set_message_hit(({"blasted"," in the skull",
                         "shot"," in the chest",
                         "shot"," with severe force",
                         "shot"," with force",
                         "shot","",
                         "grazed"," with a flesh wound",
                         "slightly grazed",""}));

  switch(n) {
    case 0:
      cop->set_name(MONCOL+"Park Ranger"+NORM);
      cop->set_alt_name("ranger");
      cop->set_short("A park ranger");
      cop->set_long(
        "One of the District's finest park rangers.  Dressed in a khaki\n"+
        "uniform and carrying a pistol at his side, this ranger serves\n"+
        "to protect the National Park areas around DC, including most of\n"+
        "the monuments and Smithsonian museums.\n");
    break;
    case 1:
      cop->set_name(MONCOL+"City Policeman"+NORM);
      cop->set_alt_name("policeman");
      cop->set_short("A city policeman [on foot]");
      cop->set_long(
        "A D.C. city policeman.  This cop wears a standard-issue navy\n"+
        "blue uniform, with a night stick on one side and a pistol on\n"+
        "the other.  He walks the streets of D.C. in a constant fight\n"+
        "to preserve justice.\n");
    break;
    case 2:
      cop->set_name(MONCOL+"City Policeman"+NORM);
      cop->set_alt_name("policeman");
      cop->set_short("A city policeman [mounted]");
      cop->set_long(
        "A D.C. city policeman.  This cop wears a standard-issue navy\n"+
        "blue uniform, with a night stick on one side and a pistol on\n"+
        "the other.  He is mounted on a sturdy horse, making his presence\n"+
        "even more formidable.\n");
   break;
  }
  return cop;
}

set_msgs() {
  room_msgs = ({ "A putrid rodent scurries into the room.\n",
                 "You feel something furry brush across your leg.\n",
                 "You hear the pitter-patter of little feet race across the floor.\n",
                 "A rat rushes into the room through a hole in the wall.\n",
                 "You suddenly smell cheese.\n",
                 "EEK! It's a rat!!\n",
                 "The hair on the back of your neck stands up; your sixth-sense"+
                   " tells you\nthat a rat is staring directly at you.\n",
                 "You hear a loud "+CYN+"SQUEAK"+NORM+" as a rat enters the room.\n",
                 "A rat enters the room and stands up in front of you on its hind legs.\n"
              });
  names = ({ "white", "black", "brown", "rabid", "long-haired", "short-haired",
             "spotted", "dirty", "smelly", "mangled", "sewer", "hungry", "fat",
             "skinny", "scrawny", "bony", "evil", "long-tailed", "sneaky", "fanged"
          });
  chats = ({ "looks around suspiciously",
             "nibbles on a block of cheese",
             "scurries off into the corner",
             "begins chasing its tail",
             "releases an ear-piercing: "+CYN+"SQUEAK SQUEAK"+NORM,
             "drops some dung in the corner",
             "claws away viciously at the wall",
             "runs up the side of the wall",
             "stares at you with its beady little eyes  "+RED+"^._.^"+NORM,
             "paces back and forth directly in your path"
          });
}

string random_room_msg() {
return room_msgs[random(sizeof(room_msgs))];
}

string random_name() {
return names[random(sizeof(names))];
}

string random_chat() {
return chats[random(sizeof(chats))];
}
