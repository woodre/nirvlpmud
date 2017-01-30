#include "/players/earwax/lib/ansi.h"

string Lasttell; /* For 'retell' command */

int do_tell(string arg) {

  string name, tc, who, msg, myname, msgs;
  int level, mylevel, a;
  object player;

  a = random(20); 

  if (query_verb() == "retell" && Lasttell) {
    who = arg;
    arg = Lasttell;
    if (!who) {
      notify_fail("Usage: retell <player>\n");
      return 0;
    }
    if (!Lasttell) {
      notify_fail("You haven't sent a tell yet.\n");
      return 0;
    }
  }
  else
  if ((!arg) || sscanf(arg,"%s %s",who,arg) != 2) {
    write("Usage: tell <player> <message>\n");
    return 1;
  }

  Lasttell = arg;
  who = lower_case(who);
  player = find_living(who);

  if (!player) {
    write("Nobody logged on with that name.\n");
    return 1;
  }

  level = (int)player->query_level();
  if (!interactive(player)) {
    write("That recipient is not interactive.\n");
    return 1;
  }
  if (level >= 21 && player->query_tellblock()) {
    write("That person is blocking tells.\n");
    return 1;
  }
  if (this_player()->query_invis() && level < 20)
    myname = "(Chip)";
  else
    myname = "Chip";
  player->Replyer("chip");

  switch(a)
  {
    case 0:  msgs = "I <3 the man meat!!!"; break;
    case 1:  msgs = "Why is my schlong not so long?"; break;
    case 2:  msgs = "Want to come over later and play who's in my mouth?"; break;
    case 3:  msgs = "Got cock?  Want some?"; break;
    case 4:  msgs = "God I could go for some pork sausage about now."; break;
    case 5:  msgs = "Cock goooooood."; break;
    case 6:  msgs = "Why does nacho cheese burn my nut sack?"; break;
    case 7:  msgs = "You know you want my Chip sausage."; break;
    case 8:  msgs = "Why can't I be as fucking awesome as Shinshi?"; break;
    case 9:  msgs = "I hate you.  I'm not kidding either.  You're an ass."; break;
    case 10: msgs = "I fought the cock, and the cock won.  It was glorious."; break;
    case 11: msgs = "Did you know if smear peanut butter in the right area your dog will lick it off for hours?"; break;
    case 12: msgs = "My nuts itch.  I think I caught something."; break;
    case 13: msgs = "Ever got your junk caught in your zipper?  It's a rush!"; break;
    case 14: msgs = "I think I got my gerbil pregnant."; break;
    case 15: msgs = "Why do grandma's have to be so damn sexy!"; break;
    case 16: msgs = "Have you ever admired a baboon's nuts.  They're fricken' huge!"; break;
    case 17: msgs = "This little latino midget I met in Tulsa taught me more about love than you ever could...."; break;
    case 18: msgs = "Don't get mad......get sexy."; break;
    case 19: msgs = "Fred is a god!  Seriously, best prank ever."; break;
  }

  player->add_tellhistory(myname+" : "+msgs);
  tc = (string)player->get_ansi_pref("tell");
  if (tc) 
    msg = tc + myname + " : " + msgs + NORM + "\n";
  else {
    tc = NORM;
    msg = HIK + myname + NORM + " : " + msgs + "\n";
  }

  tell_object(player,msg);
  write("You tell " + tc + capitalize(who) + NORM + ": "+arg+".\n");
  return 1;
}

int get() { return 1; }
int drop() { return 1; }

void init() {
  add_action("do_tell", "tell");
  add_action("do_tell", "retell");
}

string short() { return "Chip's GINOURMOUS Schlong (lashing around wildly)"; }
void long() { write("You can use 'tell <player> <what>' or 'retell <player>'\n"); }

status id(string arg) { return ( arg == "teller" || arg == "wizteller" || arg == "tool" ); }
