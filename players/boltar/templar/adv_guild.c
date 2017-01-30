/* Orginal code from Bern's Templars, 
   Modified to become The Knight's Templar by Boltar.
*/
#include "std.h"
#include "tune.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define num_skill 7

extra_reset(arg) {
   object ob;
   if (arg)
      return;
   start_titles();
   skill_setup();
}

#undef EXTRA_INIT
#define EXTRA_INIT my_init();

my_init() {
/*
    if(!this_player()) return;
    if(this_player()->query_guild_file() != "players/boltar/templar/templar" && this_player()->query_level() < 21) {
      if(!this_player()->query_ok()) {
         if(!this_player()->query_npc()) {
            write("You do not belong to this guild.\n");
            this_player()->move_player("north#players/boltar/templar/recruit");
            return 1;
         }
         }}
         add_action("cost_for_level"); add_verb("cost");
         add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
     add_action("look", "read");
         add_action("advance"); add_verb("advance");
         add_action("raise"); add_verb("raise");
         add_action("cross","cross");
         add_action("train","train");
         add_action("south","south");
*/
if(this_player()){
tell_object(this_player(),
"The old guild hall is now shut down.\n");
if(this_player()->query_guild_name() == "Knights Templar"){
  this_player()->set_home(0);
  }
move_object(this_player(), "/room/church.c");
tell_room(environment(this_player()), this_player()->query_name()+" arrives.\n");
command("look", this_player());
 }
}

THREE_EXIT("players/boltar/templar/recruit", "north",
         "players/boltar/templar/private", "east",
         "players/boltar/templar/sponsorroom", "up",
   "The Knights Templar",
   "This is the main hall of the Knights Templar.\n"+
   "Here you may work to advance your level.\n" +
   "You can also buy points for a new level.\n" +
   "Commands: cost, advance, advance rank, train <skill>, train cost, \n"+
   "raise <attrib>, and cross (to get a new one).\n"+
   "This room is much like the others of the castle, large stone walls\n"+
   "rise to a high ceiling. High upon the wall are statues depicting the\n"+
   "the training and daily life of the Knights Templar.\n"+
   "You notice a strange plaque on the wall.\n"+
   "The inner chamber is to the south.\n",
   1)

int next_level;
int valexp;
int next_exp;
int rankxp;
int level;
int exp;
string guild_title;
string title;         /* now with arrays. ! */
object player_ob;
string skills;
string banished_by;

/* called by the fixtitle function */

query_title(ob) {
   int i;
   i = ob->query_level();
   if (i>19) return ob->query_title();
   return guild_title[i-1];
}

cross() {
   object cross;
   if (this_player()->query_guild_file() != "players/boltar/templar/templar") {
      write("You do not belong to this guild.\n");
      this_player()->move_player("north#players/boltar/templar/recruit");
      return 1;
   }
   cross = present("KnightTemplar", this_player());
   if (!cross) {
      write("You get your new cross.\n");
      move_object(clone_object("players/boltar/templar/templar"), this_player());
      return 1;
   }
   destruct(cross);
   move_object(clone_object("players/boltar/templar/templar"), this_player());
   write("You get your new cross.\n");
   return 1;
}

get_new_title(str)
{
   if (!guild_title) start_titles();
   return guild_title[str];
}
start_titles() {
   guild_title = allocate(20);
   guild_title[19] = "the apprentice Wizard";
   guild_title[18] = "the Seneschal";
   guild_title[17] = "the Adept of Wisdom";
   guild_title[16] = "the Commander of the Kingdom of Jerusalem";
   guild_title[15] = "the Commander of the City of Jerusalem";
   guild_title[14] = "the Seeker of Wisdom";
   guild_title[13] = "the Drapier";
   guild_title[12] = "the Commander of Houses";
   guild_title[11] = "the Commander of Knights";
   guild_title[10] = "the Knights Brother";
   guild_title[9] = "the Sergeant of the Convent";
   guild_title[8] = "the Turcoplier";
   guild_title[7] = "the Under-Marshal";
   guild_title[6] = "the Standard-Bearer";
   guild_title[5] = "the Sergeant Brother";
   guild_title[4] = "the Rural Brother";
   guild_title[3] = "the Monk";
   guild_title[2] = "the Brother";
   guild_title[1] = "the Young Templar";
   guild_title[0] = "the Templar Squire";
}

int exp_str;

advance(str) {
if(!str || str!="rank") {
call_other("room/adv_guild","advance",0);
if(this_player()->query_level() < 21)
{
this_player()->set_title(guild_title[this_player()->query_level() - 1]);
write("You are now "+this_player()->short()+"\n");
}
return 1;
}
if(str=="rank") {
int minexp,expcost;
int current;
object guild_ob;
guild_ob=present("KnightTemplar",this_player());
if(!guild_ob) {
  write("You do not have the symbol of the Knights Templar.\n");
  return 1;
}
current = this_player()->query_guild_rank();
if(current > 7) {
write("You have reached the highest of Templar ranks.\n");
return 1;
}
expcost = get_rank_exp(current + 1)-get_rank_exp(current);
if(this_player()->query_extra_level() < 1 && this_player()->query_level() < 21)
minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",this_player()->query_level()-1);
if(this_player()->query_extra_level() > 0 && this_player()->query_level() < 21)
minexp = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);
if(this_player()->query_level() > 20) minexp = 7000000;
if(expcost > minexp) {
  write("You do not have enough available experience to to advance your templar rank.\n");
   return 1;
}
this_player()->add_guild_rank(1);
this_player()->add_guild_exp(expcost);
this_player()->add_exp(-expcost);
this_player()->save_me();
write("You advance your rank within the Templars.\n");
say(this_player()->query_name()+" advances within the Knights Templar.\n");
return 1;
}
}
south() {
object tcc;
  tcc = present("KnightTemplar",this_player());
  call_other(this_player(), "move_player", "south#players/boltar/templar/adv_inner");
  return 1;
}

query_drop_castle() {
   return 1;
}
correct_level(player)
{
   level = call_other(player, "query_level", 0);
   exp = call_other(player, "query_exp", 0);
   /* Shouldn't "correct" wizards. */
   if (level >= 20)
      return;
   get_level(level);
   while (exp < next_exp) {
      level -= 1;
      get_level(level);
   }
   if (next_level == 20 && call_other("room/quest_room", "count", 0))
      next_level = 19;
   call_other(player, "set_level", next_level);
   call_other(player, "set_title", title);
}
raise(str) {
call_other("room/adv_guild","raise",str);
return 1;
}

realm() { return "NT"; }
cost_for_level() {
call_other("room/adv_guild","cost_for_level",0);
return 1;
}
train(str) {
 int minexp,expcost;
 int i,cost,new;
 int current;
 object guild_ob;
 if(!str) {
   write("Train what skill?\n");
   return 1;
 }
 if(str=="cost") {
 cost = 1;
 }
 if(!cost && str != "sword" && str != "axe" && str !="club" && str != "knife" && str != "bow" && str !="shield" && str != "polearm" && str != "horse") {
   write("You must specify sword,axe,shield,polearm,bow,club,horse,or knife.\n");
   return 1;
 }
guild_ob=present("KnightTemplar",this_player());
if(!guild_ob) {
  write("You do not have the symbol of the Knights Templar.\n");
  return 1;
}
if(!cost) {
current=guild_ob->query_skill(str);
new = current + 1;
if(this_player()->query_extra_level() < 1 && this_player()->query_level() < 21)
minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",this_player()->query_level()-1);
if(this_player()->query_extra_level() > 0 && this_player()->query_level() < 21)
minexp = this_player()->query_exp() - call_other("room/exlv_guild", "get_next_exp",this_player()->query_extra_level()-1);
if(this_player()->query_level() > 20) minexp = 7000000;
if(new < 3) expcost=SKILL_COST;
if(new > 2 && new < 5) expcost=SKILL_COST_TWO;
if(new > 4) expcost = SKILL_COST_THREE;
if(new > 6) expcost = 3*SKILL_COST_THREE/2;
if(current > 9) {
   write("You are already at the maximum possible training value.\n");
   return 1;
}
write("You have a "+str+" training value of "+current+" it costs "+expcost+" experience to raise to a value of "+new+"\n");
say(this_player()->query_name()+" trains in the methods of the "+str+"\n");
}
else {
while(i < num_skill) {
current=guild_ob->query_skill(skills[i]);
new = current + 1;
if(new < 3) expcost=SKILL_COST;
if(new > 2 && new < 5) expcost=SKILL_COST_TWO;
if(new > 4) expcost = expcost=SKILL_COST_THREE;
if(new > 6) expcost = 3*SKILL_COST_THREE/2;
if(current > 9) {
   write(skills[i]+" is at maximum.\n");
}
else
write(skills[i]+" from "+current+" to "+new+" cost: "+expcost+"\n");
i+=1;
}
return 1;
}
if(expcost > minexp) {
  write("You do not have enough available experience to train in that skill.\n");
   return 1;
}
this_player()->add_exp(-expcost);
guild_ob->add_skill(str,1);
this_player()->add_guild_exp(expcost);
this_player()->save_me();
return 1;
}
get_rank_exp(arg) {
   rankxp=allocate(10);
  rankxp[1] = 0;
  rankxp[2] = 15000;
  rankxp[3] = 60000;
  rankxp[4] = 140000;
  rankxp[5] = 460000;
  rankxp[6] = 800000;
  rankxp[7] = 1175000;
  rankxp[8] = 1600000;
  return rankxp[arg];
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at plaque" || str == "at sign") {
  write("\n"+
 "                       ---------------------\n"+
 "                       | S | A | T | O | R |\n"+
 "                       ---------------------\n"+
 "                       | A | R | E | P | O |\n"+
 "                       ---------------------\n"+
 "                       | T | E | N | E | T |\n"+
 "                       ---------------------\n"+
 "                       | O | P | E | R | A |\n"+
 "                       ---------------------\n"+
 "                       | R | O | T | A | S |\n"+
 "                       ---------------------\n"+
 "\n\n");
  say(this_player()->query_name()+" reads the plaque.\n");
   return 1;
  }
  if (str == "at statue" || str == "at statues") {
   write("These painted stone statues with bits of gold leaf show many\n"+
         "aspects of the life of the Knights Templar, through early training\n"+
         "praying and combat in the field.\n");
   write("\n");
   say(this_player()->query_name()+" looks upward towards the statues.\n");
   return 1;
   }
return 0;
}
skill_setup() {
   skills = allocate(num_skill+1);
   skills[0]="sword";
   skills[1]="knife";
   skills[2]="axe";
   skills[3]="club";
   skills[4]="bow";
   skills[5]="polearm";
   skills[6]="shield";
}
