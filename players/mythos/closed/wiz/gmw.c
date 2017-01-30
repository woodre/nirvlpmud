#include "config.h"
inherit room/room;

string invites;
string whos_in;
int secured;

init() {
  ::init();
  add_action("invite", "invite");
  add_action("show_invites", "invites");
  add_action("boot_me", "boot");
  add_action("secure", "secure");
  add_action("unsecure", "unsecure");
  add_action("commands", "commands");
  add_action("prevent_update", "Update");
  add_action("prevent_update", "update");
  add_action("prevent_update", "ud");
  add_action("prevent_update", "Ud");
  add_action("prevent_update", "UD");
  add_action("prevent_update", "dest");
  add_action("prevent_update", "Dest");
  add_action("prevent_update", "destruct");
  add_action("prevent_update", "Destruct");
  check_invited();
}

reset(arg) {
    ::reset();
    set_short("Hawkeye's workroom");
  set_long (
"This is Gemini's workroom. He comes here to relax and code. The\n"+
"walls are covered with shelves with many weapons, armours, and\n"+
"other treasures that she has collected in her travels as a player.\n"+
"Hovering above the room is a green orb which casts\n"+
"a soft glow about the room.\n");
    set_listen("You can hear the lag boiling over.");
    set_smell("You can smell the lagmonsters sweat.");
    set_items(({ "shelves#huge shelves", "They contain many treasures",
                 "walls", "They have many huge shelves on them",
                 "weapons#armours#treasures#other treasures", "It looks to be a fine collection of stuff",
                 "huge stone table#stone table#table", "It is what Nymph plans her mud on",
                 "map", "Perhaps you can read it",
                 "green orb#orb", "It keeps the room lit",
             }));
    set_exits(({ "/room/post", "post",
                 "/room/church", "church",
                 "/room/adv_guild", "guild",
             }));
    set_sign(({ "map",
"                                    Realtor Gem's Castle\n" +
"                                       |           |\n" +
"                                   Bard|-- Inn ----|\n" +
"                                       |           |\n" +
"                                 Wizard|Mage       |\n" +
"                                       |  Warrior  |\n" +
"                                General|-----------|\n" +
"                                       |  Fighter  |\n" +
"                                  Magic|Alchemist  |\n" +
"                                       |Pub        |\n" +
"                       Church Sheriff  |     Shop  |Newbie Beach\n" +
"west harbour ------------|-------|-----|-----------|--|------|---east harbour\n" +
"                       House  Lockers  |     Guild\n" +
"                               Armourer|Bank\n" +
"                                       |\n" +
"                               Weaponer|__Cleric\n" +
"                                       |  |\n" +
"                                     Post |\n" +
"                           south harbour__|\n", }));
    set_light(1);
    invites = ({});
    whos_in = ({});
}

static commands() {
 if(this_player()->query_real_name() != "gemini") return;
  write("Current workroom commands are:\n\n");
  write("Invites          - Shows who is invited.\n");
  write("Invite <player>  - Gives player access.\n");
  write("Boot <player>    - Deny player access.\n");
  write("Secure           - Won't allow people to leave here.\n");
  write("Unsecure         - Allows people to leave.\n");
  write("Commands         - Umm, you just typed it in.\n");
return 1; }

static invite(str) {
  int i;
 if(this_player()->query_real_name() != "gemini") {
    write("Gemini tells you: Huh uh, I've already thought of that!!\n");
    boot(this_player()->query_real_name());
  return 1; }
  for(i=0;i<sizeof(invites);i++) {
    if(invites[i] == str) {
      write(capitalize(str) + " has already been invited.\n");
    return 1; }
}
  invites += ({ str });
  write("You have invited " + capitalize(str) + " into your workroom.\n");
  if(find_living(str))
   tell_object(find_living(str), "Gemini has invited you to his workroom.\n");
return 1; }

static boot(str) {
  object me;
  int i;
  for(i=0;i<sizeof(invites);i++) {
    if(invites[i] == str)
      invites -= ({ str });
  }
  say(capitalize(str) + " is booted from the workroom.\n");
  if(present(str)) {
    tell_object(find_living(str), "You have a sudden desire to go to the church.\n");
    move_object(find_living(str), "/room/church");
  }
  if(present(str)) {
    if(present("gemini")) {
      me = find_living("gemini");
      move_object(me, "/room/church");
      destruct(this_object());
    move_object(me, "/players/gemini/workroom");
    } else
      destruct(this_object());
  }
return 1; }

static boot_me(str) {
  object me;
  int i;
  if(this_player() && this_player()->query_real_name() != "gemini") {
    write("Gemini tells you: Huh uh, I've already thought of that!!.\n");
    boot(this_player()->query_real_name());
  return 1; }
  for(i=0;i<sizeof(invites);i++) {
    if(invites[i] == str)
      invites -= ({ str });
  }
  say(capitalize(str) + " is booted from the workroom.\n");
  if(present(str)) {
    tell_object(find_living(str), "You have a sudden desire to go to the church.\n");
    move_object(find_living(str), "/room/church");
  }
  if(present(str)) {
    if(present("gemini")) {
     me = find_living("gemini");
      move_object(me, "/room/church");
      destruct(this_object());
    move_object(me, "/players/gemini/workroom");
    } else
      destruct(this_object());
  }
return 1; }

static check_invited() {
  object me;
  string who;
  int i;
  who = this_player()->query_real_name();
  if(!who)
 return;
  if(who == "gemini" {
    write("Workroom tells you: Welcome home!!!\n");
  return; }
  if(!find_living("gemini")) {
    write("Gemini is not playing right now, so you shouldn't be here!\n");
    write("You feel a sudden desire to visit the church.\n");
    move_object(this_player(), "/room/church");
  return; }
  for(i=0;i<sizeof(invites);i++) {
    if(invites[i] == who) {
      write("Welcome to Gemini's Workroom!\n");
      if(!present("gemini")) {
        write("Workroom says: Sorry, but Gemini is not in at the moment.\n");
        write("Workroom says: If you will wait a moment I will page him for you.\n");
        tell_object(find_living("gemini"), "Workroom tells you: " +
                    capitalize(who) + " is here visiting.\n");
      }
    return; }
  }
  write("Workroom tells you: You have not been invited in here!\n");
  write("You have a sudden desire to visit the church.\n");
#ifdef DF
  SHOUT("Gemini's workroom shouts: Someone help! " + capitalize(who) +
        " is trying to break in!!!\n");
#else
  if(find_living("gemini"))
    tell_object(find_living("gemini"), capitalize(who) +
                " is trying to break in!!!\n");
#endif
  move_object(this_player(), "/room/church");
  if(present(who)) {
    if(present("gemini")) {
      me = find_living("gemini");
      move_object(me, "/room/church");
      destruct(this_object());
      move_object(me, "/players/gemini/workroom");
    } else
      destruct(this_object());
  }
return; }


static show_invites() {
  int i;
  if(invites == ({})) {
    write("Nobody!\n");
  return 1; }
  for(i=0;i<sizeof(invites);i++) {
    write(invites[i] + ".\n");
  }
return 1; }

static secure() {
  object ob;
  if(this_player()->query_real_name() != "gemini") {
    write("Gemini tells you: How dare you!\n");
    boot(this_player()->query_real_name());
  return 1; }
  if(secured == 1) {
    write("Workroom says: I am already secured.\n");
  return 1; }
  write("Workroom says: I am secure now.\n");
  ob = first_inventory(this_object());
  while(ob) {
    if(living(ob) && !ob->query_npc())
      whos_in += ({ ob->query_real_name() });
    ob = next_inventory(ob);
  }
  secured = 1;
  set_heart_beat(1);
return 1; }

static unsecure() {
  if(this_player()->query_real_name() != "gemini") {
    write("Gemini tells you: How dare you!\n");
    boot(this_player()->query_real_name());
  return 1; }
  if(secured == 0) {
    write("Workroom says: I am not secured.\n");
  return 1; }
  write("Workroom says: I am not secure now.\n");
  whos_in = ({});
  secured = 0;
  set_heart_beat(0);
return 1; }

static heart_beat() {
  int i;
  for(i=0;i<sizeof(whos_in);i++) {
    if(!present(whos_in[i])) {
      if(!find_living(whos_in[i]))
        whos_in -= ({ whos_in[i] });
      else {
        move_object(find_living(whos_in[i]), this_object());
        tell_object(find_living(whos_in[i]), "Workroom says: You can't leave!\n");
      }
    }
  }
}

static prevent_update(str) {
  string garb, garb2;
  if(this_player()->query_real_name() == "gemini")
    return;
  if(!str) return 1;
 if(str == "here") return 1;
  if(sscanf(str, "%snymph%s", garb, garb2)) return 1;
return; }


