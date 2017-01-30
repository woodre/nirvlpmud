#include "defs.h"
inherit ROOM;

string *Colors;
string *Shorts;
int Shields, Afk;

int do_afk(string arg) { Afk = 1; write("You are now afk.\n"); return 1; }
int do_back(string arg) { Afk = 0; write("You are now back from afk.\n"); return 1; }
int query_shields() { return Shields; }
int show_shields(string arg) {
  write(HIG+"Shields are currently: "+NORM+NORM+(Shields ? HIR+"ON." : HIG+"OFF")+NORM+NORM+"\n");
  return 1;
}

/*
string short() { return "Earwax's Workroom "+HIK+"[AFK: At work]"+NORM+NORM; }
string short() { return HIY+"Player Housing!"+NORM+NORM; }
*/
string short() { return "Earwax's Workroom"; }
status query_sandstorm() { return 1; }
status query_prevent_shadow() { return 1; }

status valid_enter() {
  string name; int level;

  name = (string)this_player()->query_real_name();
  level = (int)this_player()->query_level();

  if (level < 20 || level > 99) return 1;
  if (name == "earwax") return 1;
  if (name == "dhalek") return 1;
  if (name == "forbin" || name == "linus") return 1;

  return 0;
}

int do_shields(string arg) {
  if (!arg)
  {
    write(HIG+"Shields are currently: "+NORM+NORM+(Shields ? HIR+"ON." : HIG+"OFF")+NORM+NORM+"\n");
    return 1;
  }

  if (arg != "on" && arg != "off")
  {
    notify_fail("On or off?\n");
    return 0;
  }

  if (arg == "on")
  {
    write("Your shields are now on.\n");
    say("Earwax turns his shields "+HIR+"ON"+NORM+NORM+"\n");
    Shields = 1;
    return 1;
  }
  write("Shields are now off.\n");
  say("Earwax turns his shields "+HIG+"OFF"+NORM+NORM+"\n");
  Shields = 0;
  return 1;
}

void on_create() {
  Colors = ({ HIK, HIR, HIY, HIC, HIG, HIW, HIB, BLK, RED, YEL, CYN, GRN, WHT, BLU });
  Shorts = ({ "The Inner Ear", "The End of Your Finger", "Earwax's Workroom", "A Used Q-Tip", "Nowhere in Particular" });
  /*
  add_exit("assassins",GHALL);
  add_exit("shards","/players/earwax/closed/shardak/room/grotto");
  add_exit("green",GREEN);
  add_exit("area", "/players/earwax/area/fields/room/road3");
 */
  add_exit("green", "/room/vill_green");
  add_exit("post", "/room/post");
  add_exit("area", "/room/mine/tunnel_room");
  add_exit("out", TOWER+"waiting_room");
/*
  add_exit("area",AREA);
*/
  set_light(1);
  set_short("&do_short");
  /*
  set_long("This is Earwax's Workroom.  He hates doing descriptions, and enjoys cursing, so fuck you if you don't like what he has done with the place. :)");
  */
  set_long("This is Earwax's Workroom.  It's a large, almost spartan room.  There are windows that look out over the land of Nirvana, a massive desk, and a reclining chair, but nothing else here.");
/*
  add_desc("desk", "A massive affair, it's impossible to tell what material it's made of, indeed, the texture occasionally seems to shift.");
  add_desc("chair", "Earwax's chair.  It looks quite comfortable if you're Earwax.");
  add_desc("windows", "They look out over his sheep pasture and it seems as if one can see all of Nirvana from this height.");
*/
}

nomask void init() {
  object ob;

  ob = this_player();
  if (Shields && !valid_enter())
  {
    move_object(this_player(), "/room/church");
    write(HIG+"Earwax's automatic security system has moved you to the church.\n"+NORM+NORM);
    tell_room(this_object(), GRN+"Earwax's automatic security system has moved "+capitalize((string)this_player()->query_real_name())+" to the church.\n"+NORM+NORM);
    return;
  }
  else
  {
    if ((string)this_player()->query_real_name() != "earwax")
    {
      write("Earwax's shields shift around you to allow your entrance.\n");
      say(HIK+"Earwax's security system allows "+HIW+capitalize((string)this_player()->query_real_name())+HIK+" to enter.\n"+NORM+NORM);
    }
  }

  add_action("show_shields", "shields");

  if ((string)this_player()->query_real_name() != "earwax")
    if ((string)this_player()->query_real_name() != "dhalek")
      return;

  add_action("do_shields", "shields");
  add_action("do_afk", "do_afk");
  add_action("do_back", "back");

  if (!(present("qtip", ob)))
  {
    move_object(clone_object("/players/earwax/closed/obj/tool"), ob);
  }

  /* don't want this on me anymore thanks to vital :)
  */
  if (!(present("mailread", ob)))
    move_object(clone_object("/obj/mail_reader"), ob);
}

string do_short() {
  object there;
  object ob;
  string sbase, sstatus;

  sbase = HIK+"Earwax's Grotto"+NORM+NORM;
  ob = present("earwax", this_object());

/*
*/
  if (ob && !((int)ob->query_interactive()))
    sstatus = "Disconnected";
  else if (ob && in_editor(ob))
    sstatus = "Editing";
  else if (ob && query_idle(ob) >= 300)
    sstatus = "Idle";
  else if (Afk)
    sstatus = "AFK";
  else if (Shields && this_player() && this_player()->query_level() > 19)
    sstatus = "Shielded";
  else
    sstatus = "Recoding Shards";

  return sbase + " ["+HIR+sstatus+NORM+NORM+"]";

  return Colors[random(14)] + ( random(2) < 1 ? "Earwax's Workroom" : "The Inner Ear") + NORM + NORM;

  there = environment(this_player());
  if (there == this_object())
    return "Earwax's Workroom";
  else
    return (string)there->short();
}
