
#include "std.h"

object contract, zentradi, zor, bioroid, invid, drone;

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
  add_action("list", "list");
  add_action("hire", "hire");
  add_action("read", "read");
}

ONE_EXIT("/players/cyrex/hire/level4", "down",
         "Mercenary Chamber <down>",
"You are standing in the Mercenary Chamber. The awesome powers of Cyrex\n"+
"has called upon and hired the most awesome warriors across the universe\n"+
"to aid various adventurers. Type [list] to see the list of mercenary's you\n"+
"can hire, [hire <name>] to hire a mercenary for approximately an hour.\n"+
"There is a plaque hanging on the wall that has more information.\n",1)

read(arg) {
  if (arg == "plaque")
  {
    write("Information on Mercenaries:\n");
    write("Just say 'Mercenary name, command' or you may whisper and tell\n");
    write("the command to it. ie: 'say cyrex, drop sword'. You may also\n");
    write("command them to 'stay' and 'follow' to keep them in one place\n");
    write("as well. If you should go linkdead, whisper 'rejoin' to them.\n");
    return 1;
  }
  else
    return 0;
}
warn(arg) {
  if (arg->query_master())
  {
    tell_object(arg->query_master(), arg->query_name() + " whispers: " +
    "The hour is at hand, master.\n");
  }
}
cut(arg) {
  tell_room(environment(arg), arg->query_name() + " says: Farewell.\n");
  tell_room(environment(arg), arg->query_name() + " has left.\n");
  destruct(arg);
 destruct("contract", this_player());
}
list() {
  write("The current mercenaries are available:\n");
  if (!zentradi)
    write("Breetai the Zentradi Commander    4,000 coins/hour\n");
  if (!zor)
    write("Zor Prime the Master              3,500 coins/hour\n");
  if (!bioroid)
    write("Red Bioroid Guardian              2,500 coins/hour\n");
  if (!invid)
    write("Invid Shock Trooper               2,000 coins/hour\n");
  if (!drone)
    write("Lunk the Drone                    1,500 coins/hour\n");
  return 1;
}

confirm(arg) {
  int money;
  money = this_player()->query_money();
  if (arg > money)
  {
    write("You can't afford such a powerful mercenary.\n");
    return 0;
  }
  else
    return 1;
}

hire(str) {
    if(!str) {
      write("Hire whom?\n");
      return 1;
    }
if(present("contract", this_player())) {
    write("You already have a mercenary.\n");
     return 1;
  }

  if (str == "breetai" || str == "zentradi")
  {
    if (!confirm(4000))
      return 1;
    if (zentradi)
    {
      write("Breetai the Zentradi Commander has already been hired.\n");
      return 1;
    }

    log_file("cyrex.guard",call_other(this_player(), "query_name") +
    " hired Breetai the Zentradi Commander at " + ctime(time()) );
    contract=clone_object("players/cyrex/hire/contract");
    transfer(contract, this_player());
    this_player()->add_money(-4000);
    write("You hire Breetai the Zentradi Commander\n");
    zentradi = clone_object("players/cyrex/hire/zentradi");
    move_object(zentradi, environment(this_player()));
    zentradi->set_master(this_player());
    tell_room(environment(zentradi), "Breetai stomps into the room!\n");
    call_out("warn",5700,zentradi);
    call_out("cut",6000,zentradi);
  }
  if (str == "zor" || str == "master")
  {
    if (!confirm(3500))
      return 1;
    if (zor)
    {
      write("Zor Prime the Master has already been hired.\n");
      return 1;
    }
    log_file("cyrex.guard",call_other(this_player(), "query_name") +
    " hired Zor Prime the Master at " + ctime(time()) );
    contract=clone_object("players/cyrex/hire/contract");
    transfer(contract, this_player());
    this_player()->add_money(-3500);
    write("You hire Zor Prime the Master.\n");
    zor = clone_object("players/cyrex/hire/zor");
    move_object(zor, environment(this_player()));
    zor->set_master(this_player());
    tell_room(environment(zor), "Zor Pime walks in.\n");
    call_out("warn",5700,zor);
    call_out("cut",6000,zor);
  }
  if (str == "bioroid" || str == "guardian")
  {
    if (!confirm(2500))
      return 1;
    if (bioroid)
    {
      write("Red Bioroid Guardian has already been hired.\n");
      return 1;
    }
    log_file("cyrex.guard",call_other(this_player(), "query_name") +
    " hired  Red Bioroid Guardian at " + ctime(time()) );
    contract=clone_object("players/cyrex/hire/contract");
    transfer(contract, this_player());
    this_player()->add_money(-2500);
    write("You hire the Red Bioroid Guardian.\n");
    bioroid = clone_object("players/cyrex/hire/bioroid");
    move_object(bioroid, environment(this_player()));
    bioroid->set_master(this_player());
    tell_room(environment(bioroid), "Bioroid hovers in.\n");
    call_out("warn",5700,bioroid);
    call_out("cut",6000,bioroid);
  }
  if (str == "invid" || str == "shock" || str == "trooper")
  {
    if (!confirm(2000))
      return 1;
    if (invid)
    {
      write("Invid Shock Trooper has already been hired.\n");
      return 1;
    }
    log_file("cyrex.guard",call_other(this_player(), "query_name") +
    " hired Invid Shock Trooper at " + ctime(time()) );
    contract=clone_object("players/cyrex/hire/contract");
    transfer(contract, this_player());
    this_player()->add_money(-2000);
    write("You hire Invid Shock Trooper\n");
    invid = clone_object("players/cyrex/hire/invid");
    move_object(invid, environment(this_player()));
    invid->set_master(this_player());
    tell_room(environment(invid), "Invid Shock trooper stalks into the room\n");
    call_out("warn",5700,invid);
    call_out("cut",6000,invid);
  }
  if (str == "lunk" || str == "drone")
  {
    if (!confirm(1500))
      return 1;
    if (drone)
    {
      write("Lunk the drone has already been hired.\n");
      return 1;
    }
    log_file("cyrex.guard",call_other(this_player(), "query_name") +
    " hired Lunk the drone at " + ctime(time()) );
    contract=clone_object("players/cyrex/hire/contract");
    transfer(contract, this_player());
    this_player()->add_money(-1500);
    write("You hire Lunk the drone.\n");
    drone = clone_object("players/cyrex/hire/drone");
    move_object(drone, environment(this_player()));
    drone->set_master(this_player());
    tell_room(environment(drone), "Lunk drops into the room.\n");
    call_out("warn",5700,drone);
    call_out("cut",6000,drone);
  }
  return 1;
}

