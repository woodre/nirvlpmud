inherit "room/room";
#include "/players/heroin/closed/guild/delay.c"
static int rank, level, next_exp, min_exp, next_money;
   string ME;
 object board;
 reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Inner chamber: Bio-replacement";
long_desc="You have enter the inner chamber of the Merchant's\n"+
 "area.  Here is where you come to prove your loyalty and\n"+
 "improve your political influence in the guild.  You come here to\n"+
 "sacrifice your own inferior body parts for more advance biomechanical\n"+
 "ones.  The operation is fairly simple really...It will only hurt for a\n"+
 "year or two.  You can ask the Masters for either: influence, armor, or\n"+
 "weapons. For complete instructions and requirements refer to your contract.\n";
 
dest_dir=({
 "players/heroin/closed/guild/main_hall1.c", "out",
 "players/heroin/closed/guild/merchbar.c", "north",
 "players/heroin/closed/guild/mershop.c", "south",
});
 
   }
}
 
init() {
   ::init();
  add_action("advance","influence");
  add_action("exchange","exchange");
  add_action("armor","armor");
  add_action("weap","weap");
}
 
/* --- EXCHANGE --- */
exchange(str) {
     int amt, gexp, old_exp;
     object ob;
     ob = present("watch", this_player());
     if(!str || sscanf(str, "%d", amt) != 1) {
  write("How much experience would you like to trade for influence?\n");
        return 1;
     }
 
check_lvl();
 
     if(this_player()->query_exp() < amt) {
  write("You cannot afford to exchange "+amt+" experience!\n");
       return 1;
     }
     if(amt < 0) {
  write("You can't exchange experience you don't have!\n"+
   "\nWE MAY BE THIEVES but NEVER LIARS\nYou lose some experience for your attempted deceit!\n");
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
write("You call the elders to share your experience and ask for influence.\n");
write("From the shadows appears the elders...One by one the take their places.\n");
delay();
write("Upon hearing aboout your successes, the elders call for a vote.\n");
write("The masters seem pleased with you, they all agree.\n");
 write("You exchange "+amt+" of experience for guild influence.\n");
command("save", this_player());
     return 1;
}
 
/* -- Influence -- */
advance() {
   int exp, gexp, rank1;
   object me, guild;
     next_exp = 0;
   next_money = 0;
 
     me = this_player();
level = this_player()->query_level();
     guild = present("watch", me);
gexp = this_player()->query_guild_exp();
rank1 = guild->query_guild_rank();
rank = this_player()->query_guild_rank();
     exp = me->query_exp();
 
     get_next_exp();
   if(rank >= 10) {
write("You are already influence 10. You can go no further without\n"+
     "the direct intervention of Heroin or Unsane.  If you feel, your\n"+
     "skills at leading the merchants are worthy of attention; you\n"+
     "may write Heroin or Unsane about availability.\n");
     return 1;
       }
     if(gexp < next_exp) {
 write("Your current guild influence is too low. In order to gain \n"+
       "your next levvel of influence, You need to \n"+
       "accumlate "+next_exp+" influence points.\n");
       return 1;
     }
    if(this_player()->query_money() < next_money) {
  write("You don't have enough money to advance.\n"+
   "Gaining influence is expensive. There are many pockets to line on\n"+
    "your way up. You still need "+next_money +" coins.\n"+
   "Please come back later when you have the proper amount.\n");
       return 1;
     }
write("You have successfully gained a level of political influence\n");
write("With your new influence, you can rip off more people, and kill\n");
write("countless more humans.  Keep up the good work.\n");
this_player()->add_guild_rank(1);
guild->seguild_rank(rank1+1);
 this_player()->add_money(-next_money);
     write("Your new influence level is "+(rank+1)+".\n");
     say(capitalize(me->query_name())+" is now influnece "+(rank+1)+".\n");
     command("save", this_player());
   ME = this_player()->query_real_name();
   tell_members();
write_file("/players/heroin/closed/guild/PROMOS",
this_player()->query_real_name()+" has been raised to influence rank: "+
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
if(elvl == 6) {min_exp =3900000; }
if(elvl == 7) { min_exp = 4200000; }
if(elvl == 8) { min_exp = 4500000; }
if(elvl == 9) { min_exp = 4800000; }
if(elvl == 10) { min_exp = 5100000; }
}
 
tell_members() {
   object ob, guild, merch;
    int i;
 
   ob = users();
    for(i = 0; i < sizeof(ob); i++) {
    guild = present("watch", ob[i]);
  if(guild && guild->query_muffled() == 0) {
  tell_object(ob[i],
   "Raise your glasses: "+capitalize(ME)+" has raised their influence.\n");
     }
   }
   return 1;
}
 
 
 
 
             
