#include "/players/mythos/closed/ansi.h"
#define bug if(find_player("mythos")) tell_object(find_player("mythos")
#define tp this_player()
#define tpn tp->query_real_name()
#define ALL 6
#define NUM (ALL)*3/4

static string namep, placep;
static string rewardp, levelp;
string name, level, place, reward;

short() { return "Collection Office "+
           BOLD+"["+NORM+RED+"Bounty Hunters"+NORM+BOLD+"] "+NORM; }

long() { write("You step into a rather dark room.  Oak wood floor dulls the\n"+
               "sounds of your footsteps and the faint smell of pine needles\n"+
               "is in the air.  You have entered the Bounty Hunter's Collection\n"+
               "Office.  Do not anger the Officer on Duty.\n"+
               "The only exit is a door 'out'.\n");
       }

init() {
  add_action("out","out");
}

realm() { return "NT"; }

out() { tp->move_player("out#players/mythos/enterance.c"); return 1; }

reset(arg) {
  if(!present("wanted ad")) 
     move_object(clone_object("/players/mythos/bounty/note.c"),this_object());
  if(!present("bounty_officer_69")) 
     move_object(clone_object("/players/mythos/bounty/officer.c"),this_object());
  if(!arg) {
    set_light(1);
    generate();
  }
}

generate() {
int check,ran,reserve;
int j;
/* 
   oks here is where the list of monsters is placed 
   format will be   NAME      LEVEL      PLACE      REWARD
*/

rm("/players/mythos/bounty/wanted.o");
check = 0;

namep = allocate(ALL);    levelp = allocate(ALL);
placep = allocate(ALL);   rewardp = allocate(ALL);
name = allocate(NUM);     level = allocate(NUM);
place = allocate(NUM);    reward = allocate(NUM);

reserve = allocate(ALL);  for(j=0;j<ALL;j++) reserve[j] = 69;

/* place where monster files are stored */

namep[0] = "demon"; levelp[0] = "low"; placep[0] = "mythos"; rewardp[0] = "100 coins";
namep[1] = "harry"; levelp[1] = "low"; placep[1] = "mythos"; rewardp[1] = "200 coins";
namep[2] = "ryo"; levelp[2] = "med"; placep[2] = "mythos"; rewardp[2] = "300 exp";
namep[3] = "ryu"; levelp[3] = "med"; placep[3] = "mythos"; rewardp[3] = "400 exp";
namep[4] = "dread"; levelp[4] = "high"; placep[4] = "mythos"; rewardp[4] = "500 exp";
namep[5] = "oorochi"; levelp[5] = "high"; placep[5] = "mythos"; rewardp[5] = "600 coins";


while(check < NUM) {
  ran = random(ALL);
  if(reserve[ran] == 69) {
    if(!name[check] || name[check] == "EMPTY") {
      
      name[check] = namep[ran];
      level[check] = levelp[ran];
      place[check] = placep[ran];
      reward[check] = rewardp[ran];
      
      reserve[ran] = 666;
      check = check + 1;
      
    }
  }
}
save_object("players/mythos/bounty/wanted");
return 1; }

bounty(str,ob) {
int h,i;
i = 0;
  for(h=0;h<NUM;h++) {
   if(name[h] == str) { 
     if(present("bounty_officer_69")) 
         present("bounty_officer_69")->bounty_ok(reward[h],ob);
     name[h] = "EMPTY";
     i = 1;
     save_object("players/mythos/bounty/wanted"); 
     break; } 
   }
   if(!i) { 
     if(present("bounty_officer_69")) 
         present("bounty_officer_69")->bounty_reject(str,ob);
   }
return 1; }

query_names() { return name; }

clean_up() { return 1; }
dest_inv() { return 1; }
