#include "../defs.h"

inherit "/room/room.c";

#define LOAN 1000
#define LEVEL 100

/* Prototype Declarations */
int get_next_exp();

/* Global Variables */
static int rank, level, next_exp;
int treasury;

void reset(status arg) {
    if(arg)
      return;
      
  set_light(1);
  restore_object(DATA_TREASURY);
  short_desc = "The Guild Lodge"; 
  long_desc = "\
You are in the meeting hall of the Guild.  A large vaulted\n\
ceiling rises up to an elaborate stained glass skylight\n\
depicting two figures clad in sun god robes fighting their\n\
way to glory.  Hanging on a wall of black and white marble is\n\
a solid gold plaque.  In the center of the room on a raised\n\
dias is an item of great importance to the guild.\n\
COMMANDS:  advance, treasury, donate <amt>, borrow <amt>, repay\n";

  dest_dir = ({
    RPATH+"guild_hall", "north",
    EXIT_TO_REALM,      "south",
  });

  move_object(clone_object(OBJPATH+"plaque"), this_object());
  move_object(clone_object(OBJPATH+"stone"), this_object());
  move_object(clone_object(OBJPATH+"new_board"), this_object());
}

void init() {
  
  if(!present("seal", this_player()) && this_player()->query_level() < LEVEL) {
    write("You're not a member!\n");
    move_object(this_player(), "room/church");
    return;
  }
  
  ::init();
  add_action("contribute","donate");
  add_action("advance","advance");
  add_action("pay","repay");
  add_action("loan","borrow");
  add_action("contribute","contribute");
  add_action("treasury","treasury");
}

status pay(string arg) {
  int amt;
  string name;
  object gob;
     
  name = (string)this_player()->query_real_name();
  gob = present(MGOB_ID, this_player());
  amt = (int)gob->query_loan(name);
  
  if(!amt) {
    write("You do not owe any money.\n");
    return 1;
  }
  if(amt > (int)this_player()->query_money()) {
    write("You do not have enough money to repay the loan.\n");
    return 1;
  }
  this_player()->add_money(-amt);
  gob->set_loan(0);
  write("You repay your loan of "+amt+" gold coins.\n");
  treasury += amt;
  save_object(DATA_TREASURY);
  write_file(LOGPATH+"LOANS",ctime()+": "+
    capitalize(name)+" repaid a loan of "+amt+" gold coins.\n");
  return 1;
}

status loan(string str) {
  int amt, old_amt, avail;
  object ob;
  
  ob = present(MGOB_ID, this_player());
  
  if(!str || sscanf(str, "%d", amt) != 1) {
    write("How much money do you need to borrow?\n");
    return 1;
  }
  if((int)this_player()->query_level() >= 20 && (string)this_player()->query_real_name()
    != "earwax") {
    write("Wizards cannot borrow money!\n");
    return 1;
  }
  if((int)this_player()->query_level() <= 2) {
    write("you are not mature enough to borrow money!\n");
    return 1;
  }
  if((string)this_player()->query_real_name() == "guest") {
    write("You cannot borrow money.\n");
    return 1;
  }
  if(amt < 0) {
    write("You can't borrow "+amt+".\n");
    return 1;
  }
  if((int)this_player()->query_money() > 5000) {
    write("You have plenty of money!\n");
    return 1;
  }
  if(amt > treasury) {
    write("There is not that much money in the guild treasury.\n");
    return 1;
  }
  old_amt = (int)ob->query_loan();
  avail = LOAN - old_amt;
  if(!avail) {
    write("You have drawn your maximum amount from the Guild.\n");
    return 1;
  }
  if(amt > avail) {
    write("You are only allowed to draw out "+avail+" gold coins.\n");
    return 1;
  }
  treasury -= amt;
  ob->set_loan(old_amt+amt);
  this_player()->add_money(amt);
  write("You have drawn out "+amt+" from the guild treasury.\n");
  say((string)this_player()->query_name()+" took out a loan from "+
    "the guild treasury.\n");
  save_object(DATA_TREASURY);
  write_file(LOGPATH+"LOANS", ctime() + ": "+
    capitalize((string)this_player()->query_real_name()) + " took out a loan of "+
    amt +" gold coins.\n");
  return 1;
}

int treasury() {
   write("The guild has "+treasury+" gold coins in its treasury.\n");
   return 1;
}

status contribute(string str) {
  int amt, gexp, old_exp;
  object ob;
  
  ob = present(MGOB_ID, this_player());
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
  old_exp = (int)ob->query_gexp();
  treasury += amt;
  ob->add_gexp(amt / 5);
  write("Thank you for your contribution of "+amt+" gold coins.\n");
  say((string)this_player()->query_name()+
    " donates some money to the guild.\n");
  save_object(DATA_TREASURY);
  write_file(LOGPATH+"donate", ctime() + ": "+
    capitalize((string)this_player()->query_real_name())+" donated "+amt+
    " gold coins.\n");
  return 1;
}

status advance() {
  int exp, gexp;
  object me, guild;
  
  next_exp = 0;
  me = this_player();
  level = (int)this_player()->query_level();
  guild = present(MGOB_ID, me);
  gexp = (int)guild->query_gexp();

  rank = (int)guild->query_glevel();
  exp = (int)me->query_exp();

  get_next_exp();
  if (rank >= 20) {
      if ((int)this_player()->query_level() < 20)
        guild->set_glevel(20);
      tell_object(this_player(), "You have already attained the maximum level!\n");
      return 1;
  }
/*
    guild->set_glevel(30);
    write("You now have a Guild rank of 30.\n");
    say((string)me->query_name()+" advanced to rank 30.\n");
    return 1;
  }
*/
  if(exp < next_exp) {
    write("You do not have enough experience to advance.\n");
    return 1;
  }
  if(level < (rank - 2)) {
    write("You must be a higher level before you can increase your"+
          "guild rank.\n");
    return 1;
  }
  guild->set_glevel(rank+1);
  guild->add_gexp(next_exp);
  write("You are now guild rank "+(rank+1)+".\n");
  call_other(this_player(),"add_exp", -next_exp);
  write_file(LOGPATH+"ADVANCE", ctime()+": "+
    capitalize((string)me->query_real_name())+
    " advanced to rank "+(rank+1)+ ".\n");
  say(me->query_name()+" is now rank "+(rank+1)+".\n");
  command("save", this_player());
  return 1;
}

int get_next_exp() {

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
