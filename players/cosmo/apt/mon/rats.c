#include "/players/cosmo/closed/ansi.h"
#define TOOLS "/players/cosmo/closed/tools.c"
#define MAX_RATS 30

int rat_area_count;   /* Number of rats currently in the area */
string *names;        /* Array of short names */
string *room_msgs;    /* Array of rat entrance messages */
string *chats;        /* Array of rat chat messages */

reset(arg) {
   rat_area_count=0;
   if(sizeof(room_msgs) == 0) set_msgs();
}

query_rats() {
   /* If more than 30 rats already, return 0, else return 1 */
   if(rat_area_count < MAX_RATS) return 1;
   else return 0;
}

make_rat(n) {
object rat, prize;
string MONCOL, SNAME;
  rat = clone_object("/obj/monster");
  rat_area_count++;

  rat->set_alias("rat");
  rat->set_race("rodent");
  rat->set_al(50-random(700));
  rat->set_chat_chance(5);
  SNAME = random_name();
  rat->load_chat("The "+SNAME+" rat "+random_chat()+".\n");
  rat->set_a_chat_chance(5);
  rat->load_a_chat("The "+SNAME+" rat scurries up your leg.\n");
  rat->set_message_hit(({"leaps up and gouges its snarling teeth into","",
                         "scratches"," across the face",
                         "whips"," with its tail",
                         "scratches"," in the chest",
                         "scratches","",
                         "nibbles on","",
                         "squeaks at",""}));

  prize = clone_object("/obj/food");
  prize->set_name("cheese");
  prize->set_alias("block");
  prize->set_alt_name("food");
  prize->set_short(YEL+"A block of cheese"+NORM);
  prize->set_long("A chunk of half-eaten cheese.  It looks good enough to eat, or even sell.\n");
  prize->set_eater_mess("You chow down on the cheese block and feel much better.\n");
  prize->set_eating_mess(" nibbles on the cheese block, dropping crumbs everywhere.\n");

  switch(n) {
    case 0..5:
      rat->set_level(3+random(4));  /* Lvl 3-6 */
      MONCOL=TOOLS->query_color(rat);
      rat->set_hp(40+random(41));
      rat->set_wc(7+random(3));
      rat->set_ac(4+random(2));
      rat->set_name(MONCOL+"Small "+SNAME+" rat"+NORM);
      rat->set_alt_name("rodent");
      rat->set_short("A small "+SNAME+" rat");
      rat->set_long(
        "A poor little rat that seems to have wandered too far from\n"+
        "its hole.  It looks so small and innocent, perhaps you\n"+
        "should let it run away.  Or perhaps you should crush it like\n"+
        "a grape since you know rats are evil, disgusting creatures.\n");
      prize->set_value(50+random(151));
      prize->set_weight(1);
      prize->set_strength(1+random(5));
    break;

    case 6..8:
      rat->set_level(7+random(4));  /* Lvl 7-10 */
      MONCOL=TOOLS->query_color(rat);
      rat->set_hp(100+random(51));
      rat->set_wc(11+random(4));
      rat->set_ac(6+random(3));
      rat->set_aggressive(random(2));      /* 50% chance */
      rat->set_name(MONCOL+capitalize(SNAME)+" rat"+NORM);
      rat->set_alt_name("rodent");
      rat->set_short("A "+SNAME+" rat");
      rat->set_long(
        "A snarling, dribbling rat who seems to be looking for more\n"+
        "food.  Its incessant squeaking is beginning to give you a\n"+
        "fierce headache.  Perhaps you should kill it before it crawls\n"+
        "up your leg and mistakes you for its next meal.\n");
      prize->set_value(250+random(201));
      prize->set_weight(2);
      prize->set_strength(4+random(6));
    break;

    case 9:
      rat->set_level(11+random(3));  /* Lvl 11-13 */
      MONCOL=TOOLS->query_color(rat);
      rat->set_hp(165+random(31));
      rat->set_wc(15+random(3));
      rat->set_ac(8+random(3));
      if (random(10) > 1) rat->set_aggressive(1);  /* 80% chance */
      rat->set_name(MONCOL+"Large "+SNAME+" rat"+NORM);
      rat->set_alt_name("rodent");
      rat->set_short("A large "+SNAME+" rat");
      rat->set_long(
        "A fully-grown two-foot long rat.  Just looking at it gives you\n"+
        "the creeps.  Its long skinny tail swishes ominously back and\n"+
        "forth.  The beady little eyes trace your every move.  It\n"+
        "certainly looks like it could pounce on you at any moment.\n");
      prize->set_value(450+random(251));
      prize->set_weight(3);
      prize->set_strength(8+random(5));
   break;
  }
  move_object(prize, rat);
  return rat;
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

