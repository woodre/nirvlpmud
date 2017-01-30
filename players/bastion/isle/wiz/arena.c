#include "std.h"
int invent;
/* make a finite # of each monster. -Bp */
/* Changed invent 3,4,and 5 from 3 to 2,1,1  -Snow */

#undef EXTRA_RESET
#define EXTRA_RESET \
invent=allocate(6);\
invent[0]=3;\
invent[1]=3;\
invent[2]=3;\
invent[3]=2;\
invent[4]=1;\
invent[5]=1;
#undef EXTRA_INIT 
#define EXTRA_INIT \
     add_action("press", "press"); \
     add_action("press", "push");

#undef EXTRA_LONG
#define EXTRA_LONG \
     if(str=="sign" || str=="list") { \
          write("Monsters available for practice:\n"+ \
                "1) Goblin\n"+ \
                "2) Ogre\n"+ \
                "3) Doppleganger\n"+ \
                "4) Dragon, young\n"+ \
                "5) Vampire\n"+ \
                "6) Beholder\n"); \
          return; } \
     if(str=="panel") { \
          write("The panel consists of several numbered buttons. They\n"+ \
                "appear to correspond to the list next to them.\n"); \
          return; } 

ONE_EXIT("players/bastion/isle/wiz/base_hall3", "west",
     "Combat Arena",
     "You enter a large chamber, the walls lined with various instruments\n"+
     "of death and war. A sign is posted on the east wall, a panel fixed\n"+
     "next to it.\n",
     1)

string file, find_file;
int num;

id(str) { 
     return str=="list" || str=="sign" || str=="panel";
}

press(arg) {
     int x;
     if(!arg) {
          write("Press which button?\n");
          return 1; }
     if(sscanf(arg, "%d", x)!=1) {
          write("Push <number>.\n");
          return 1;
     }
     x-=1;
     if(x > 5 || x < 0) {
          write("Press a number from 1 to 6.\n");
          return 1;
     }
     num=x;
     if(!invent[x]) {
         write("Sorry, We are fresh out of those.\n");
         return 1;
      }
     load_monster();
     return 1;
}

load_monster() {
     object monster;
     file=get_file(num);
     write("You summon a creature to combat.\n");
     say(call_other(this_player(), "query_name") + " summons a monster.\n");
     monster=clone_object(file);
     move_object(monster, environment(this_player()));
     monster->attack_object(this_player());
     return 1;
}

get_file(arg) {
     find_file=allocate(6);
     find_file[5]="players/bastion/monster/beholder";
     find_file[4]="players/bastion/monster/vampire";
     find_file[3]="players/bastion/monster/dragon";
     find_file[2]="players/bastion/monster/doppleganger";
     find_file[1]="players/bastion/monster/ogre";
     find_file[0]="players/bastion/monster/goblin";
     invent[arg] -= 1;
     return find_file[arg];
}
