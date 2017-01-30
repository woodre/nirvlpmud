
#include "std.h"

#define LEVEL 100
static int rank, level, next_exp, quest_num;

reset(arg) {
    if(!arg)
      set_light(1);
    extra_reset();
}


object board;
extra_reset() {
     if(!present("board")) {
       board = clone_object("players/deathmonger/ASSASSIN/bull_board");
       move_object(board, this_object());
     }
}

init() {
   if(!present("license", this_player()) && 
      this_player()->query_level() < 21) {
       write("You're not a assassin!\n");
       move_object(this_player(), "room/church");
       return 1;
     }
    add_action("frog", "frog");
     add_action("east","east");
     add_action("advance","advance");
     add_action("north","north");
     add_action("west", "west");
     add_action("read","read");
     add_action("donate", "donate");
}


west(){
      this_player()->move_player("west#players/catt/ASSASSIN/portal_room");
    return 1;
}

church(){
   this_player()->move_player("church#room/church");
   return 1;
}

shop(){
   this_player()->move_player("shop#room/shop");
   return 1;
}


frog(){
   this_player()->move_player("frog#players/deathmonger/ASSASSIN/bounty");
    return 1;
}
east() {
     this_player()->move_player("east#players/deathmonger/ASSASSIN/tavern");
     return 1;
}

south(){
     this_player()->move_player("south#players/deathmonger/CASTLE/complaint_room");
    return 1;
}

north() {
       this_player()->move_player("north#players/deathmonger/ASSASSIN/voting");
       return 1;
     }

donate(str){
     int amount;
int money;
     object guild;
     guild = present("license", this_player());
       if(!str) { 
          write("donate <amount>\n");
     return 1;
      }
     if(sscanf(str, "%d", amount) == 1){
money = this_player()->query_money();
if(amount > money) {
write("Nice try, Even assassins shouldnt cheat!\n");
this_player()->add_hit_point(-20);
return 1;}
       guild->set_guild_exp(amount + guild->query_guild_exp());
if(amount < 0) {
write("Nice try, Even assassins shouldnt cheat!.\n");
this_player()->add_hit_point(-20);
return 1;}
       this_player()->add_money(-amount);
       write("Thank you for your donation of "+amount+" gold coins.\n");
       return 1;
      }
      write("Donate how much?\n");
      return 1;
}
advance() {
     int exp, gexp;
     int quest, quest_num;
     object me, guild, questob;

     me = this_player();
     guild = present("license", me);
     gexp = guild->query_guild_exp();

     quest_num = guild->query_guild_quest();
     quest = guild->query_guild_quest();

     get_next_exp();
     if(gexp < next_exp) {
     write("You have not donated enough money to advance.  See 'levels'.\n");
       return 1;
     }
     if(quest == 1 && present("Grendel's Claws", this_player())){
       write("Congratulations, you have solved the first guild quest.\n");
       write("You are now a journeyman assassin.  There is another guild quest\n");
       write("for the next level, master assassin (see 'levels').\n");
       guild->set_guild_quest(2);
       guild->set_guild_name();
       write_file("/players/deathmonger/ASSASSIN/ADVANCED",
     this_player()->query_real_name()+" advanced to "+
     guild->query_guild_name()+"\n");
       questob = present("Grendel's Claws", this_player());
       destruct(questob);
       return 1;
       }
       if(quest == 2 && present("horn", this_player())){
         write("Congratulations, you have solved this guild quest.\n");
         write("You are now an master assassin.  Try the next quest if you\n");
         write("dare.\n");
       guild->set_guild_quest(3);
       guild->set_guild_name();
       questob = present("horn", this_player());
       destruct(questob);
       return 1;
     }
       if(quest == 3 && present("rusty sword", this_player())){
         write("You are now a Godfather of Assassins.  You have reached \n");
         write("the highest echelon of the assassins guild, and are enti-\n");
         write("tled to the best the guild has to offer. Congratulations.\n");
         guild->set_guild_quest(4);
         guild->set_guild_name();
          questob = present("rusty sword", this_player());
         destruct(questob);
         return 1;
       }
       else {
       write("You have not solved the quest to advance.  Type 'quest'.\n");
       return 1;
        }
     write_file("/players/deathmonger/ASSASSIN/ADVANCE",
           capitalize(me->query_real_name())+" advanced to "+
              guild->query_guild_name()+
          " "+ctime(time())+"\n");
     say(capitalize(me->query_name())+" is now a "+
        guild->query_guild_name()+".\n");
     command("save", this_player());
     return 1;
}

get_next_exp() {
     int quest;
     object guild;
     guild = present("license", this_player());

     quest = guild->query_guild_quest();


     if(quest == 1){ next_exp = 30000; }
     if(quest == 2){ next_exp = 60000; }
}

read(str){
     if(str == "sign"){
    write("GRAND MASTER ADEPT: DEATHMONGER\n");
     write("GRAND ELDER ASSASSINS:\n");
   write("Catt, Emanon, Silent, Vlad, Zone\n");
     write("GODFATHERS:\n");
     write("Krago, Nonashi, Kiljoy\n");
   write("MASTER ASSASSINS:\n");
     write("Gleandor   Shade    Caliber    Predator\n");
    write("JOURNEYMAN ASSASSINS:\n");
     write("Macros\n");
   write("APPRENTICE ASSASSINS:\n");
     write("Mccleod     Cidster     Onus     Zorgon\n");
     write("Phrack     Soultaker     Taziar      \n");
     write("Snakeyes     Zyrtx     Nuna\n");

     return 1;
}
}
short() { return "A storage locker"; }

long() {
     write("You enter the secret gathering place of the Guild of Assassins.\n");
     write("Here is where you come to advance within the guild and this is\n");
     write("also where messages will be posted considering the guild.\n");
    write("  There are three obvious exits: east, west, and north.\n");
     write("Commands: advance, donate <amount>\n");
     write("A black sign with white letters.\n");
}

