#include "/players/hawkeye/closed/guild/delay.c"
inherit "room/room";
static int rank, level, next_exp, min_exp, next_money;
   string ME;
 object board;
 reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The inner guild hall";
long_desc="This is the inner Guild Hall.  Here you can\n"+
 "'exchange' experience for guild experience and you may\n"+
 "'advance' your guild level.  You can go east to the guild\n"+
 "room, north to the equipment room, or south to the guild\n"+
 "shop and bar.\n";

dest_dir=({
 "players/hawkeye/closed/guild/guild_room", "east",
 "players/hawkeye/closed/guild/equip_room", "north",
 "players/hawkeye/closed/guild/mshop", "south",
});

   }
}

init() {
   ::init();
  add_action("gone","change");
  add_action("gone","select");
  add_action("advance","advance");
  add_action("exchange","exchange");
  add_action("west","west");
}

west() {
if(this_player()->query_ghost()==1) {
write("Only living persons can go into the Arena!\n"+
 "If your already dead, you obviously dont belong in there anyways!\n");
   return 1;
      }
 write("You enter the Arena!\n");
 say(capitalize(this_player()->query_name())+" enters the Arena!\n");
 move_object(this_player(),"players/hawkeye/closed/guild/arena");
command("look",this_player());
return 1;
}

/* -- GONE -- */
gone(){
 write("Sorry, this command is no longer avaliable.\n");
 return 1;
}

/* --- EXCHANGE --- */
exchange(str) {
     int amt, gexp, old_exp;
     object ob;
     ob = present("mrobe", this_player());
     if(!str || sscanf(str, "%d", amt) != 1) {
  write("How much experience would you like to exchange?\n");
        return 1;
     }

check_lvl();

     if(this_player()->query_exp() < amt) {
  write("You cannot afford to exchange "+amt+" experience!\n");
       return 1;
     }
     if(amt < 0) {
  write("You can't exchange negative experience!\n"+
   "\nNice try.\nYou lose some experience for your attempted deceit!\n");
    this_player()->add_exp(-random(500)+100);
       return 1;
     }
 if((this_player()->query_exp() + (-amt)) < min_exp) {
write("You cannot exchange that much experience!\n"+
"The most experience you may exchange is "+
(this_player()->query_exp()+(-min_exp)) + ".\n");
     return 1;
      }
this_player()->add_exp(-amt);
this_player()->add_guild_exp(amt);
write("Hawkeye puts his hands together and appears before you.\n");
write("Pain steps out of the jungle and appears before you. You cringe in Terror.\n");
delay();
write("Hawkeye says: Gimmie your experience!\n");
write("Pain says: No, it is MINE, give it to ME!\n");
write("Hawkeye kicks Pain! It Hurts!\n");
write("Pain says: Ouch... stop it damnit, the experience is mine!\n");
write("Hawkeye destructs: Pain (Senior Wizard)\n");
write("You chuckle merrily and hope that Pain isn't too pissed off.\n");
write("Hawkeye takes your experience and gives you some guild experience in exchange\n");
 write("You exchange "+amt+" of experience for guild experience.\n");
command("save", this_player());
     return 1;
}

/* -- ADVANCE -- */
advance() {
   int exp, gexp, rank1;
   object me, guild;
     next_exp = 0;
   next_money = 0;

     me = this_player();
     level = this_player()->query_level();
     guild = present("mrobe", me);
gexp = this_player()->query_guild_exp();
rank1 = guild->query_guild_rank();
rank = this_player()->query_guild_rank();
     exp = me->query_exp();

     get_next_exp();
   if(rank >= 10) {
write("You have achieved the highest position currently avialle\n"+
  "in this Guild.  You are Senior Grandmaster, guild rank 10!\n");
         return 1;
       }
     if(gexp < next_exp) {
 write("You do not have enough guild experience to advance to\n"+
       "your next level.  In order to advance you must have\n"+
       "accumlated "+next_exp+" experience points.\n");
       return 1;
     }
    if(this_player()->query_money() < next_money) {
  write("You don't have enough coins to advance.\n"+
   "In order to reach your next level you must donate "+
    next_money +" coins.\n"+
   "Please come back later when you have the proper amount.\n");
       return 1;
     }
write("Hawkeye puts his hands together and appears before you.\n");
write("Hawkeye smiles happily.\n");
write("Pain steps out of the jungle and appears before you. You cringe in Terror.\n");
write("Pain grins happily.\n");
write("Hawkeye says: So, we have another advancing monk!\n");
write("Pain says: I am so proud!\n");
write("Pain shakes hands with you.\n");
write("Hawkeye bows before you.\n");
write("Hawkeye says: Keep up the good work!\n");
write("Pain whispers to you: Go kick some ass!\n");
  write("Congragulations!  You have reached your new guild level!\n"+
  "You have donated "+next_money+" coins and the proper amount of\n"+
  "experience to advance in the guild!\n");
this_player()->add_guild_rank(1);
guild->set_guild_rank(rank1+1);
 this_player()->add_money(-next_money);
     write("You are now guild rank "+(rank+1)+".\n");
     say(capitalize(me->query_name())+" is now rank "+(rank+1)+".\n");
     command("save", this_player());
   ME = this_player()->query_real_name();
   tell_members();
write_file("/players/hawkeye/closed/guild/PROMOS",
this_player()->query_real_name()+" has been promoted to Rank "+
this_player()->query_guild_rank()+" - "+ctime()+"\n");
     return 1;
}

get_next_exp() {

if(rank == 1) { next_exp = 20000;  next_money = 10000; }
if(rank == 2) { next_exp = 50000; next_money = 10000; }
if(rank == 3) { next_exp = 120000;  next_money = 10000; }
if(rank == 4) { next_exp = 230000;  next_money = 10000; }
if(rank == 5) { next_exp = 550000;  next_money = 20000; }
if(rank == 6) { next_exp = 840000;  next_money = 25000; }
if(rank == 7) { next_exp = 1500000;  next_money = 30000; }
if(rank == 8) { next_exp = 2600000;  next_money = 30000; }
if(rank == 9) { next_exp = 3040000;  next_money = 40000; }
/*
if(rank == 10) { next_exp = 6500000; next_money = 30000; }
if(rank == 11) { next_exp = 7750000; next_money = 30000; }
if(rank == 12) { next_exp = 9000000; next_money = 30000; }
if(rank == 13) { next_exp = 10500000; next_money = 30000; }
if(rank == 14) { next_exp = 12000000; next_money = 30000; }
if(rank == 15) { next_exp = 14000000; next_money = 30000; }
if(rank == 16) { next_exp = 17000000; next_money = 30000; }
*/
}

check_lvl() {
  int lvl, elvl;
  lvl = this_player()->query_level();
  elvl = this_player()->query_extra_level();
if(lvl == 3) { min_exp = 1771; }
if(lvl == 4) { min_exp = 2332; }
if(lvl == 5) { min_exp = 5885; }
if(lvl == 6) { min_exp = 12812; }
if(lvl == 7) { min_exp = 26662; }
if(lvl == 8) { min_exp = 39993; }
if(lvl == 9) { min_exp = 59995; }
if(lvl == 10) { min_exp = 90000; }
if(lvl == 11) { min_exp = 134998; }
if(lvl == 12) { min_exp = 195591; }
if(lvl == 13) { min_exp = 295592; }
if(lvl == 14) { min_exp = 492294; }
if(lvl == 15) { min_exp = 620026; }
if(lvl == 16) { min_exp = 820028; }
if(lvl == 17) { min_exp = 1040028; }
if(lvl == 18) { min_exp = 1367106; }
if(lvl == 19) { min_exp = 2000000; }
if(elvl == 1) { min_exp = 2500000; }
if(elvl == 2) { min_exp = 2700000; }
if(elvl == 3) { min_exp = 2900000; }
if(elvl == 4) { min_exp = 3300000; }
if(elvl == 5) { min_exp = 3600000; }
if(elvl == 6) { min_exp = 3900000; }
if(elvl == 7) { min_exp = 4200000; }
if(elvl == 8) { min_exp = 4500000; }
if(elvl == 9) { min_exp = 4800000; }
if(elvl > 10) { min_exp = 5100000; }
}

tell_members() {
   object ob, guild, monk;
    int i;

   ob = users();
    for(i = 0; i < sizeof(ob); i++) {
    guild = present("mrobe", ob[i]);
  if(guild && guild->query_muffled() == 0) {
  tell_object(ob[i],
   "[*Master Monk*]: "+capitalize(ME)+" just advanced in the Guild!\n");
     }
   }
   return 1;
}

