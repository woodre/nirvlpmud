#include <ansi.h>

inherit "/room/room";

#define LOAN 1000
#define LEVEL 100
static int rank, level, next_exp;
int treasury;

reset(arg)
{
  ::reset(arg);
  restore_object("players/angel/masons/treasury");
  if(!present("plaque"))
     move_object(clone_object("/players/angel/masons/PLAQUE"), this_object());
  if(!present("stone"))
     move_object(clone_object("/players/angel/masons/stone"), this_object());
  if(!present("board"))
     move_object(clone_object("/players/angel/masons/bull_board2"), this_object());

  if(arg) return;
  set_light(1);
  short_desc = "The Guild Lodge";
  long_desc =
"    You are in the meeting hall of the Guild. A large vaulted\n\
ceiling rises up to an elaborate stained glass skylight that\n\
depicts two figures clad in sun god robes fighting their way to\n\
glory. Hanging on a wall of black and white marble is a solid\n\
gold plaque. In the center of the room on a raised dias is an\n\
item of great importance to the guild.\n";

  items =
  ({
  });
  dest_dir =
  ({
    "/players/angel/masons/ghall",  "north",
  });
}

init() {
    ::init();
      if(!present("seal", this_player()) && this_player()->query_level() < LEVEL) {
        write("You're not a member!\n");
        move_object(this_player(), "/players/angel/area/town/room/foyer");
return 1;
     }
     add_action("contribute","donate");
     add_action("advance","advance");
     add_action("pay","repay");
     add_action("loan","borrow");
     add_action("contribute","contribute");
     add_action("treasury","treasury");
}

pay() {
     object ob;
     int amt;
     ob = present("seal", this_player());

     amt = ob->query_guild_loan();
     if(amt == 0) {
       write("You do not owe any money.\n");
       return 1;
     }
     if(amt > this_player()->query_money()) {
       write("You do not have enough money to repay the loan.\n");
       return 1;
     }
     this_player()->add_money(-amt);
     ob->set_guild_loan(0);
     write("You repay your loan of "+amt+" gold coins.\n");
     treasury += amt;
     save_object("players/angel/masons/treasury");
     write_file("/open/GUILDLOGS/LOANS",
          capitalize(this_player()->query_real_name())+" repaid a loan of "+
          amt+" gold coins : "+ctime(time())+"\n");
     return 1;
}

loan(str) {
     int amt, old_amt, avail;
     object ob;
     ob = present("seal", this_player());
     if(!str || sscanf(str, "%d", amt) != 1) {
       write("How much money do you need to borrow?\n");
       return 1;
     }
     if(this_player()->query_level() >= 20 && this_player()->query_real_name()
       != "sandman") {
       write("Wizards cannot borrow money!\n");
       return 1;
     }
     if(this_player()->query_level() <= 2) {
       write("you are not mature enough to borrow money!\n");
       return 1;
     }
     if(this_player()->query_real_name() == "guest") {
       write("You cannot borrow money.\n");
       return 1;
     }
     if(amt < 0) {
       write("You can't borrow "+amt+".\n");
       return 1;
     }
     if(this_player()->query_money() > 5000) {
       write("You have plenty of money!\n");
       return 1;
     }
     if(amt > treasury) {
       write("There is not that much money in the guild treasury.\n");
       return 1;
     }
     old_amt = ob->query_guild_loan();
     avail = LOAN - old_amt;
     if(avail == 0) {
       write("You have drawn your maximum amount from the Guild.\n");
       return 1;
      }
     if(amt > avail) {
       write("You are only allowed to draw out "+avail+" gold coins.\n");
       return 1;
     }
     treasury -= amt;
     ob->set_guild_loan(old_amt+amt);
     this_player()->add_money(amt);
     write("You have drawn out "+amt+" from the guild treasury.\n");
     say(capitalize(this_player()->query_name())+" took out a loan from "+
        "the guild treasury.\n");
     save_object("players/angel/masons/treasury");
     write_file("/players/angel/masons/LOANS",
          capitalize(this_player()->query_real_name())+" drew out "+amt+
          " gold coins : "+ctime(time())+"\n");
     return 1;
}

treasury() {
     write("The guild has "+treasury+" gold coins in its treasury.\n");
     return 1;
}

contribute(str) {
     int amt, gexp, old_exp;
     object ob;
     ob = present("seal", this_player());
     if(this_player()->query_level() >= 20 && this_player()->query_level() < 100) {
        write("Wizards may not contribute money to the Guild.\n");
        return 1;
      }
     if(!str || sscanf(str, "%d", amt) != 1) {
        write("Contribute how many gold coins?\n");
        return 1;
     }
     if(this_player()->query_money() < amt) {
       write("You do not have "+amt+" gold coins.\n");
       return 1;
     }
     if(amt < 0) {
       write("You can't do that!\n");
       return 1;
     }
     this_player()->add_money(-amt);
     old_exp = ob->query_guild_exp();
     treasury += amt;
     gexp = amt/5;
     ob->set_guild_exp(gexp+old_exp);
     write("Thank you for your contribution of "+amt+" gold coins.\n");
     say(capitalize(this_player()->query_name())+" donates some money "+
              "to the Guild.\n");
     save_object("players/angel/masons/treasury");
     write_file("/open/GUILDLOGS/DONATE",
          capitalize(this_player()->query_real_name())+" donated "+amt+
          " gold coins : "+ctime(time())+"\n");
     return 1;
}

advance() {
     int exp, gexp;
     object me, guild;
     next_exp = 0;

     me = this_player();
     level = this_player()->query_level();
     guild = present("seal", me);
     gexp = guild->query_guild_exp();

     rank = guild->query_guild_rank();
     exp = me->query_exp();

     get_next_exp();
     if(rank >= 20) {
       if(gexp < 10000) {
         write("You do not have enough guild experience points to advance.\n");
         return 1;
       }
       guild->set_guild_rank(30);
       write("You now have a Guild rank of 30.\n");
       say(capitalize(me->query_name())+" advanced to rank 30.\n");
       return 1;
     }
     if(exp < next_exp) {
       write("You do not have enough experience to advance.\n");
       return 1;
     }
     if(level < (rank - 2)) {
       write("You must be a higher level before you can increase your"+
             "guild rank.\n");
       return 1;
     }
     guild->set_guild_rank(rank+1);
     write("You are now guild rank "+(rank+1)+".\n");
     call_other(this_player(),"add_exp", -next_exp);
     write_file("/players/angel/masons/ADVANCE",
          capitalize(me->query_real_name())+" advanced to rank "+(rank+1)+
          " "+ctime(time())+"\n");
     say(capitalize(me->query_name())+" is now rank "+(rank+1)+".\n");
     command("save", this_player());
     return 1;
}

get_next_exp() {

     if(rank == 3) { next_exp =   300; }
     if(rank == 4) { next_exp =   500; }
     if(rank == 5) { next_exp =  1000; }
     if(rank == 6) { next_exp =  1600; }
     if(rank == 7) { next_exp =  2000; }
     if(rank == 8) { next_exp =  2400; }
     if(rank == 9) { next_exp =  3000; }
     if(rank == 10) { next_exp =  3500; }
     if(rank == 11) { next_exp =  4250; }
     if(rank == 12) { next_exp =  5000; }
     if(rank == 13) { next_exp =  6000; }
     if(rank == 14) { next_exp =  7100; }
     if(rank == 15) { next_exp =  8200; }
     if(rank == 16) { next_exp =  9300; }
     if(rank == 17) { next_exp = 10000; }
     if(rank == 18) { next_exp = 12000; }
     if(rank == 19) { next_exp = 15000; }
}