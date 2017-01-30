#include "std.h"
object urine, monster, feces;
string file, find_file;
int num;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     if(!urine) {
          urine=clone_object("players/bastion/obj/static");
          urine->set_name("urine");
          urine->set_alias("stain");
          urine->set_short(0);
          urine->set_object(this_object());
          urine->set_summon("summon_monster");
          urine->set_beat(15);
          move_object(urine, this_object());
          urine->start_check(); }
     if(!feces) {
          feces=clone_object("players/bastion/obj/static");
          feces->set_name("cages");
          feces->set_alias("cage");
          feces->set_short(0);
          feces->set_object(this_object());
          feces->set_beat(3);
          feces->load_chat("You hear scratching noises.\n");
          feces->load_chat("Something growls in one of the cages.\n");
          move_object(feces, this_object());
          feces->start_check(); }
     urine->load_summon();
}

summon_monster(arg) {
     object ob;
     ob=first_inventory(this_object());
     while(ob) {
          if((ob->query_hp() > 0) && (!ob->is_player())) {
               urine->unload_summon();
               return 1; }
          ob=next_inventory(ob); }
     num=random(6);
     file=get_file(num);
     say("A creature breaks loose from one of the cages!\n");
     monster=clone_object(file);
     move_object(monster, this_object());
     monster->set_aggressive(1);
     monster->set_heart_beat(1);
     monster->attacked_by(arg);
     urine->unload_summon();
     return 1;
}

ONE_EXIT("players/bastion/isle/wiz/base_hall1", "east",
     "Menagerie",
     "You have entered a narrow, but long room, the doors to cells or\n"+
     "cages on all sides. Hearing you enter, something stirs in the cages.\n"+
     "The smell of urine and growling convince you whatever is here is not\n"+
     "happy to be so.\n",
     1)

load_monster() {
     write(monster); write("\n");
}

get_file(arg) {
     find_file=allocate(6);
     find_file[5]="players/bastion/monster/beholder";
     find_file[4]="players/bastion/monster/vampire";
     find_file[3]="players/bastion/monster/dragon";
     find_file[2]="players/bastion/monster/doppleganger";
     find_file[1]="players/bastion/monster/ogre";
     find_file[0]="players/bastion/monster/goblin";
     return find_file[arg];
}
