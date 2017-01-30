#ifndef __LDMUD__ /* Rumplemintz - original code */
#include "/players/beck/esc.h"
#include "/players/beck/Rangers/RangerDefs.h"
/* changed NAME to OWNER to avoid conflict in the updated RangerDefs.h */
#define OWNER "Beck"
#define DEST "room/plane1"
/*
* This is just the facade to a castle. If you want to enable the
* "enter" command, move the player to a hall or something (which
   * you have to design yourself).
* The predefined string DEST is where a player should come when he
* leaves the castle.
*
* This file is loaded automatically from "init_file". We have to move
* ourself to where we are supposed to be.
*/

object autoload1_ob, autoload2_ob, karate;
object autoload3_ob;
object autoload4_ob;
object auto5, auto6;
object auto7;
id(str) { return str == "east" || str == "road"; }

short() {
   return "A road heading east";
}

long() {
   write("A creepy road that seems to dissappear off in the distance.\n");
}


reset(arg) {
   string *monsters;
object mkquest;
object decepticon;
   if (arg)
      return 1;
   move_object(this_object(), DEST);
/*
move_object("/players/beck/Rangers/RangerSpaceship.c","/players/beck/room/mountain1");
*/
   autoload2_ob = clone_object("/players/beck/Rangers/RangerCommunicator.c");
   destruct(autoload2_ob);
   autoload3_ob = clone_object("/players/beck/rangers/RangerCommunicator.c");
   destruct(autoload3_ob);
   autoload4_ob = clone_object("/players/beck/rangers/honor_ranger_communicator.c");
   destruct(autoload4_ob);
mkquest = clone_object("/players/beck/MortalKombat/QuestKey.c");
destruct(mkquest);
/*
decepticon = clone_object("/players/beck/Transformers/Decepticons/Guild/Symbol.c");
destruct(decepticon);
*/
   karate = clone_object("/players/beck/Rangers/HonorRangerCommunicator.c");
   destruct(karate);
/*
   auto5 = clone_object("/players/beck/DarkRangers/RangerCommunicator.c");
   destruct(auto5);
auto6 = clone_object("/players/beck/Rangers/DarkRangers/DarkRangerCommunicator.c");
   destruct(auto6);
*/
   auto7 = clone_object("/players/beck/closed/scar.c");
   destruct(auto7);
destruct(clone_object("/players/beck/Daemons/NightDayDaemon.c"));
   MASTER->SRangerMonsters();
/*
"/players/beck/Transformers/Decepticons/Guild/Daemons/BaseDaemon.c"->DistributeBases();
*/
}
is_castle(){return 1;}
init(){
   object hunter;
   string message;
   add_action("east","east");
   /*
   if(this_player()->query_alignment() < -900){
      if(!find_living("energy")){
         move_object("/players/beck/monster/pack.c","/room/south/sforst45.c");
         hunter = move_object("/players/beck/monster/hunter.c","/room/south/sforst45.c");
         hunter->s_hunted(this_player());
         write_file("/players/beck/closed/log/HUNT",this_player()->query_real_name()+
            " was hunted. "+ctime(time())+"\n");
         message = "An old woman comes up to you and tells you:\n"+
         "Beware! The wild hunt has begun. Run!  Run for your life!\n";
         "obj/user/one_chan.c"->chan_msg(message,"junk");
         if(!this_player()->on_channel("junk")){
            tell_object(this_player(),message);
         }
      }
   }
   */
}
east(){
   call_other(this_player(),"move_player","east#/players/beck/room/road3.c");
   return 1;
}
#else
#include "/players/beck/Rangers/RangerDefs.h"
#define OWNER "Beck"
#define DEST "room/plane1"

status id(string str) {
    return str == "east" || str == "road";
}

string short() {
    return "A road heading east";
}

void long() {
    write("A creepy road that seems to dissappear off in the distance.\n");
    return;
}

void reset(status arg) {
    string *monsters;

    if (arg)
        return;
    move_object(this_object(), DEST);
    load_object("/players/beck/Rangers/RangerCommunicator.c");
    load_object("/players/beck/rangers/RangerCommunicator.c");
    load_object("/players/beck/rangers/honor_ranger_communicator.c");
    load_object("/players/beck/MortalKombat/QuestKey.c");
    load_object("/players/beck/Rangers/HonorRangerCommunicator.c");
    load_object("/players/beck/closed/scar.c");
    load_object("/players/beck/Daemons/NightDayDaemon.c");
    MASTER->SRangerMonsters();
}

status is_castle() { return 1; }

void init() {
    add_action("east", "east");
}

status east() {
    this_player()->move_living("east#/players/beck/room/road3.c");
    return 1;
}
#endif