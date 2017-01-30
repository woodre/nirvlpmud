#include "/players/pavlik/guild/mages/rooms/ROOMS"
#include "/players/pavlik/guild/mages/macs"
#include "/players/pavlik/guild/mages/rooms/GUILD_COSTS"
#include "/room/tune.h"
#define ADV "/room/adv_guild.c"
inherit "room/room";
object obj;
reset(arg){
 if(!arg){
 set_light(1);
 short_desc="The Training Chamber";
 long_desc=
 "You descend that stairs and enter the chambers of Zhendras the\n"+
 "Weapons Master.  Although Magic is the life and blood of a Mage,\n"+
 "knowledge of physical weapons can be handy in crucial situations.\n"+
 "Thus, Zhendras is a well repsected member of the Mages Guild.\n"+
 "The walls of this chamber are filled with innumerable weapons.\n"+
 "Each intrument is a deathly tool when held by a trained hand.\n"+
 "There is a sign on the wall.\n";

items=({
"sign",
"\n"+
"  You are in Zhendras' training chamber.  Master Zhendras can\n"+
"  train your standard levels or attributes.  Zhendras has also \n"+
"  been known to provide valuable quest information to the worthy.\n"+
"      cost           - cost to advance to next level.\n"+
"      advance        - advance to next level.\n"+
"      raise <attrib> - raise a standard attribute.\n"+
"      list <#>       - ask for quest knowledge.\n"+
"\n",
"wall",
"The walls are covered with weapons of all different sorts.  They\n"+
"gleam wickedly in the torchlight",
"walls",
"The walls are covered with weapons of all different sorts.  They\n"+
"gleam wickedly in the torchlight",
"weapons",
"Weapons of all different sorts line the walls.  They gleam wickedly\n"+
"in the torchlight",
});

dest_dir=({
  "players/pavlik/guild/mages/rooms/masters_hall2", "up",
});

if(!present("zhendras", this_object())){
  obj = clone_object("players/pavlik/guild/mages/rooms/npc/zhendras");
  move_object(obj, this_object());
  }

    }
}

query_mguild(){ return "Zhendras's Chamber"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("raise","raise");
  add_action("list_quests","list");
  add_action("advance","advance");
  add_action("cost_for_level","cost");
  mage_check();
}


int next_level;
int valexp;
int next_exp;
int level;
int exp;
string title;         /* now with arrays. :) */
string guname;
object player_ob;

/* Couple emotes added by Pavlik, otherwise this is a copy of
 * of the adentures guild: /room/adv_guild.c
*/
get_new_title(str){
  return ADV->get_new_title(str);
}

get_next_exp(str){
  return ADV->get_next_exp(str);
}

cost_for_level() {
    player_ob = this_player();
    level = call_other(player_ob, "query_level", 0);
    if (level >= 20) {
	write("You will have to seek other ways.\n");
	return 1;
    }

 command("calcxp", this_player());
 write("\n");

 exp = call_other(player_ob, "query_exp", 0);
 get_level(level);
 next_exp = ADV->get_next_exp(level);

 if(next_exp <= exp){
  write(
  "Zhendras looks you over with trained Veteran's eyes.\n"+
  "Zhendras rasps: You are ready for your next level.\n");
  return 1;
 }

 if((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000){
  write(
  "Zhendras studies you carefully.  The Weapons Master frowns slightly.\n"+
  "Zhendras rasps: You are not ready to advance.  You must have more\n"+
  "                experience before I will train you.\n");
  return 1;
 }

  write(
  "Zhendras studies you carefully.\n"+
  "Zhendras rasps: I will train you now, but it will cost you "+
  (next_exp - exp) * 1000/EXP_COST+" coins.\n");
  return 1;
}

get_level(str) {
  level = str;
  next_exp   = get_next_exp(level);
  next_level = level + 1 ;
  player_ob = this_player();
  title = ADV->get_new_title(level);
}

advance(){
 string name_of_player;
 int cost;

 command("calcxp", this_player());
 write("\n"); 
 
 player_ob = this_player();
 name_of_player = call_other(player_ob, "query_name", 0);
 level = call_other(player_ob, "query_level", 0);
 if(level == -1) level = 0;
 exp = call_other(player_ob, "query_exp", 0);
 title = call_other(player_ob, "query_title", 0);

 if(level >= 20){
  write("You are still level "+level+".\n");
  return 1;
 }

 get_level(level);

 if(next_level == 20) {
  write("Zhendras rasps: I cannot train you any further.\n");
  write("Zhendras rasps: You will have to go elsewhere.\n");
  return 1;
 }
 cost = (next_exp - exp) * 1000 / EXP_COST;

 if(next_exp > exp){
  if(this_player()->query_money() < cost){
   write(
   "Zhendras studies you carefully.  The Weapons Master frowns.\n"+
   "Zhendras rasps: You cannot pay the fee for advancement.\n");
   return 1;
  }
  if((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000){
   write(
   "Zhendras shakes his head.\n"+
   "Zhendras rasps: You are not yet ready to advance.\n"+
   "Zhendras rasps: You will need more experience before I can train you.\n");
   return 1;
  }
  call_other(this_player(), "add_money", -cost);
 }
 write(
 "Zhendras rasps: You have earned the right to advance.\n"+
 "Zhendras trains you diligently until sweat pours from your body\n"+
 "and your bones beg for mercy!\n");
 write("When the Master is satifisfied he smiles proudly.\n");
 tell_room(this_object(),
 "Zhendras grants "+capitalize(this_player()->query_real_name())+
 " a new level.\n");

 call_other(player_ob, "set_level", next_level);
 if(exp < next_exp)
  call_other(player_ob, "add_exp", next_exp - exp);
 return 1;
}

list_quests(num){
  return ADV->list_quests(num);
}

query_drop_castle() {
    return 1;
}

raise(str) {
    string attrib,raise,thing;
    int new,expcost,current,minexp;
  if (str !="str" && str !="sta" && str != "wil" && str != "mag" && str !="pie" && str != "ste" && str != "luc" && str != "int")
     {
       write ("Raise what?\n");
       return 1;
     }
   if(this_player()->query_guild_name() == "paladin") {
     write("You must raise your attributes at your guild hall.\n");
     return 1;
   }
    if (call_other(this_player(), "query_level", 0) > 19) {
           write("wizards cannot advance attributes.\n");
           return 1;
         }
   if (str == "str") {
      attrib = "strength";
    }
   if (str == "sta"){
    attrib = "stamina";
    }
   if (str == "wil") attrib = "will_power";
   if (str == "mag") attrib = "magic_aptitude";
   if (str == "pie") attrib = "piety";
   if (str == "ste") attrib = "stealth";
   if (str == "luc") attrib = "luck";
   if (str == "int") attrib = "intelligence";
     raise = "raise_" + attrib;
     current = call_other(this_player(), "query_attrib", str);
     new = current + 1;
     if (current < 12) expcost = -ATTRIB_COST;
     if (current < 16 && current > 11) expcost = -ATTRIB_COST_TWO;
     if (current < 20 && current > 15) expcost = -ATTRIB_COST_THREE;
     if (current > 19) {
            write (attrib + " is at highest possible value.\n");
            return 1;
            }
    minexp = this_player()->query_exp() - get_next_exp(this_player()->query_level()-1);
    if (expcost < -minexp) {
        write ("You don't have enough experience available to raise an attribute.\n");
    return 1;
    }
     call_other(this_player(), raise, 1);
     call_other(this_player(), "add_exp", expcost);
    return 1;
}

/*
 * this is for training mage guild stats only
 */
train_weapon(str){
 int many, total, weap;
 int count, minxp;
 int cost;
 string myverb;

 myverb = query_verb();
 if(!str) many = 1;
 else sscanf(str, "%d", many);
 weap = present("mageobj", tp)->query_weapons();

 if(many > 10){
  write("Zhendras rasps: I will only teach you 10 points at a time.\n");
  return 1;
 }

 if(weap >= 50){
  write("Zhendras rasps: I have taught you all I can.\n");
  return 1;
 }

 if(weap + many > 50) many = 50 - weap;
 count = 0; total = 0; cost = 0;
 while(count < many){
  total = total + train_cost(weap + (count + 1));
  count++;
 }
 
 minxp = rank_costs(this_player()->query_guild_rank());
 minxp = tp->query_guild_exp() - minxp;
 if(total == 0) return 1;
 if(myverb == "wcost"){
  write(
  "Zhendras sizes you up with the practiced eye of a Veteran.\n"+
  "Zhendras rasps: You will need "+total+" experience points.\n");
  return 1;
 }
 if(minxp - total < 0){
  write(
  "Zhendras studies you closely.  The Weapons Master frowns.\n"+
  "Zhendras rasps: You are not prepared for this.  You need "+
  (total - minxp)+" more Xp.\n");
  return 1;
 }
 write(
 "Zhendras grabs a staff off the wall and tosses it to you.\n"+
 "The crafty Weapons Master immediately advances on you!\n"+
 "You spar with Zhendras until you fall to the ground, tired and beaten.\n"+
 "Zhendras laughs and says: Very good, You are getting better!\n"+
 "You have earned "+many+" mage weapon points.\n");
 present("mageobj", tp)->raise_weapons(many);
 tp->add_guild_exp(-total);
 return 1;
}
