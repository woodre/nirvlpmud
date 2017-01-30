/*
 * Party object
 *
 * This object is what gets cloned to players
 */

#define NAME              (string)this_player()->query_name(0)
#define PARTY_OB          "obj/party/party_ob"
#define PARTY_FILE        "obj/party/party_d"
#define MAX_EXP_PER_LEVEL 700

inherit "inherit/base/base_obj";

#include "/obj/party/party.cfg"

string party, leader, *members;
int age;                          /* When the party was originally formed */
int total_exp;                    /* Total EXP party has ever gained      */
static int total_levels;
static status am_here;

string query_object_type() { return "Party"; }

void reset(status arg) {
  if (arg) return;
  members = ({});
  age = time();
  set_name("party_object");
  set_alias("banner");
}

string short(status wiz) {
  return "The banner of '" + party + "'";
}

void long(status wiz) {
  write("A long colorful banner bearing the name '" + party + "'\n" +
        "in grand golden colors along its entire length.\n");
}

status drop(string quit) {
  if (quit) {
    if (environment()) {
      tell_object(environment(), "Saving Party...\n");
    }
    if ((string)environment()->query_name(1) == query_leader()) {
      party_leader();
    }
  }
  return 1;
}

status party_save() {
  if (environment()) drop("quit");
  return 0;
}


/***************************************************************************/
/* Set Functions */

int    reset_age()            { return age = time();  }
int    set_age(int i)         { return age = i;       }
int    set_total_exp(int i)   { return total_exp = i; }
string set_party(string str)  { return party = str;   }
string set_leader(string str) {
  if (sizeof(members)) {
    if (members[0] != str) {
      remove_members(str);
      members = ({ str, }) + members;
      party_update(0);
    }
  }
  add_members(str);
  return leader = str;
}

string *set_members(string *arr) { return members = arr; }

int add_members(string str) {
  if (member(members, str) == -1) {
    members += ({ str, });
    party_update(0);
    return 1;
  }
  return 0;
}

int remove_members(string str) {
  int i;

  if ((i = member(members, str)) != -1) {
    members = members[0..(i-1)] +
              members[(i+1)..(sizeof(members)-1)];
    party_update(0);
    return 1;
  }
  return 0;
}


/***************************************************************************/
/* Query Functions */

int query_age()  { return age = (int)PARTY_FILE->query_age(party); }
int query_exp()  { return query_total_exp();                       }
int query_rate() {
  int i;

  i = time() - age;
  if (!total_exp) return 0;
  else return (total_exp * 60) / i;
  return (total_exp * 60) / i;
}

int query_total_exp() {
  return total_exp = (int)PARTY_FILE->query_total_exp(party);
}

string query_party()     { return party;                }
string query_party_age() { return convert_to_time(age); }
string query_leader() {
  if (party)
    return leader = (string)PARTY_FILE->query_leader(party);
}
string *query_all_members() {
    return members = (string *)PARTY_FILE->query_all_members(party);
}

status query_members(string str) {
  members = query_all_members();
  if (!members || !sizeof(members)) members = ({});
  if (member(members, str) != -1) return 1;
  return 0;
}


void init() {
  object obj;

  ::init();
  add_action("party_recruit", "recruit");
  add_action("party_dismiss", "dismiss");
  add_action("party_leave",   "leave"  );
  add_action("party_emote",   "pemote" );
  add_action("party_tell",    "psay"   );
  add_action("party_who",     "pwho"   );
  add_action("party_save",    "quit"   );
  add_action("party_save",    "Quit"   );
  add_action("party_disband", "disband");
  add_action("party_follow",  "follow" );

  if (!am_here) {
    call_out("party_check_leader", 1);
    am_here = 1;
  }
}


void party_check_leader() {
  if (environment()) {
    if (!find_player(query_leader())) party_leader();
    if ((int)find_player(query_leader())->query_level() <
        (int)environment()->query_level()) party_leader();
  }
}

status party_dismiss(string str) {
  object ob, obj;

  if (!str) {
    notify_fail("Dismiss who from the party?\n");
    return 0;
  }
  if ((string)this_player()->query_name(1) != query_leader()) {
    notify_fail("Only the leader can dismiss other players.\n");
    return 0;
  }
  if (!query_members(lower_case(str))) {
    notify_fail("That person is not in your party!\n");
    return 0;
  }
  remove_members(str);
  ob = find_player(lower_case(str));
  ob->set_party(0);
  obj = present("party_object", ob);
  if (obj) destruct(obj);
  party_shout(capitalize(str) + " has been dismissed from the party.\n", 0);
  party_update(0);
  return 1;
}

status party_leave(string str) {
  object ob;

  if (str == party || str == "party") {
    if ((string)environment()->query_name(1) == leader) {
      write("You must disband the party to leave it.\n");
      return 1;
    }
    write("You leave the party.\n");
    this_player()->set_party(0);
    remove_members((string)this_player()->query_name(1));
    party_shout((string)this_player()->query_name(1) + " has left " +
                "the party!\n", 0);
    party_update(0);
    destruct(this_object());
    return 1;
  }
  return 0;
}

status party_disband(string str) {
  object obj;
  int i;
  string *all;
  string tmp;
  object who;

  if (str == party || str == "party") {
    if ((string)this_player()->query_name(1) != query_leader()) {
      notify_fail("Only the party leader can disband the party.\n");
      return 0;
    }
    party_shout(capitalize(leader) + " has disbanded the party.\n", 0);
    party_shout("Party earned " + query_total_exp() + " in " + show_age() +
                "\n", 1);
    all = query_all_members();
    for (i = 0; i < sizeof(all); i++) {
      if (find_living(all[i])) {
        who = find_living(all[i]);
        if(who != environment()) {
          who->set_party(0);
          destruct(present("party_object", who));
        }
      }
    }
    environment()->set_party(0);
    PARTY_FILE->remove_party(party);
    destruct(this_object());
  }
  return 1;
}

status party_recruit(string str) {
  object player, party_ob;

  if (!str) {
    notify_fail("Recruit who into the party?\n");
    return 0;
  }
  if (query_leader() != lower_case(NAME)) {
    notify_fail("Only the leader can recruit people.\n");
    return 0;
  }
  player = present(str, environment(this_player()));
  if (!player) {
    notify_fail(capitalize(str) + " is not here to recruit.\n");
    return 0;
  }
  if (!interactive(player)) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if (this_player()->query_security_level() && !player->query_security_level()) {
    notify_fail("You should know better than to recruit players.\n");
    return 0;
  }
  if (!this_player()->query_security_level() && player->query_security_level()) {
    notify_fail("You cannot recruit Creators.\n");
    return 0;
  }
  if ((string)player->query_party() == party) {
    notify_fail(capitalize(str) + " is already a member of the party!\n");
    return 0;
  }
  if ((string)player->query_party()) {
    notify_fail(capitalize(str) + " is already in another party.\n");
    return 0;
  }
  if ((int)player->query_level() > (int)this_player()->query_level()) {
    notify_fail("You can't recruit players of higher level than you.\n");
    return 0;
  }
  add_members((string)player->query_name(1));
  player->set_party(party);

  party_ob = clone_object(PARTY_OB);
  party_ob->set_age(query_age());
  party_ob->set_total_exp(query_exp());
  party_ob->set_party(party);
  party_ob->set_members(members);
  party_ob->set_leader(leader);
  move_object(party_ob, player);

  party_shout((string)player->short() + " joins the party!\n", 0);
  return 1;
}

void party_shout(string message, status quietly) {
  int i;

  for (i = 0; i < sizeof(members); i++) {
    if (find_player(members[i])) {
      if (!quietly)
        tell_object(find_player(members[i]), "[" + query_party() + "]: ");
      else
        tell_object(find_player(members[i]), "\t");
      tell_object(find_player(members[i]), message + "\n");
    }
  }
}

status party_emote(string str) {
  party_shout(this_player()->query_name() + " " + str, 0);
  return 1;
}

status party_tell(string str) {
  party_shout("\b[" + this_player()->query_name() + "]: " + str, 0);
  return 1;
}

void party_update(status arg) {
  PARTY_FILE->remove_party(party);
  PARTY_FILE->add_party(({ party, members, age, total_exp }));
  PARTY_FILE->write_best_party();
  if (arg) tell_object(environment(), "Updating party\n");
}

void party_leader() {
  object *who, *ob;
  int i;
  string tmp;
  string temp;

  query_all_members();       /* to refresh all those people here */
  tmp = query_leader();
  remove_members(tmp);
  leader = 0;
  party_update(0);
  who = sort_members();
  ob = ({});

  for (i = 0; i < sizeof(who); i++) {
    if (find_player((string)who[i]->query_name(1)) &&
        interactive(who[i]))
      ob += ({ who[i], });
  } /* Check for interactive members properly */

  who = ob;
  if (!sizeof(who))     /* nothing in the array now */
    set_leader((string)environment()->query_name(1));
    /* Highest level player just logged out, so get 2nd highest level player */
  else
    set_leader((string)who[0]->query_name(1));
  party_shout(capitalize(leader)+ " is the new leader of the party!", 0);
  add_members(tmp);
  party_update(1);
}

static status by_level(object a, object b) {
  return ((int)a->query_level() > (int)b->query_level()) ? 1 : 0;
}

static status by_interactive(object a, object b) {
  return (interactive(a)) ? 1 : 0;
}

object *sort_members() {
  int i;
  object *who;

  who = ({});
  for (i = 0; i < sizeof(query_all_members()); i++) {
    if (find_player(members[i])) who += ({ find_player(members[i]), });
  }
  who = sort_array(who, "by_level", this_object());
  who = sort_array(who, "by_interactive", this_object());
  return who;
}

/* Share the EXP through the death of a monster, called from living.c */
void share_exp(int xp) {
  object *who;
  int i, share;

  if (!xp) return;
  query_total_levels();

  if ((total_levels * MAX_EXP_PER_LEVEL) < xp)
    xp = total_levels * MAX_EXP_PER_LEVEL;
  total_exp = query_total_exp() + xp;

  party_shout("Sharing: " + xp + " experience points...", 0);
  who = sort_members();
  for (i = 0; i < sizeof(who); i++) {
    share = calc_share((int)who[i]->query_level());
    party_shout(who[i]->query_name() + " received " + share + "% " +
                "of the exp.", 1);
    who[i]->add_exp((share * xp) / 100);
  }
  party_update(0);
}

int query_total_levels() {
  int i;
  object *who;

  total_levels = 0;
  who = sort_members();
  for (i = 0; i < sizeof(who); i++)
    total_levels += (int)who[i]->query_level();
  return total_levels;
}

int calc_share(int level) {
  return ((level * 100) / query_total_levels());
}

string convert_to_time(int amount) {
  int tmp;
  string ret;

  ret = "";
  if (tmp = amount / (60 * 60 * 24)) {
    ret += tmp + " days ";
    amount -= tmp * 60 * 60 * 24;
  }
  if (tmp = amount / 3600) {
    ret += tmp + " hours ";
    amount -= tmp * 3600;
  }
  if (tmp == amount / 60) {
    ret += tmp + " minutes ";
    amount -= tmp * 60;
  }
  if (amount) ret += amount + " seconds";
  return ret;
}

string show_age() {
  return convert_to_time(time() - age);
}

status party_who() {
  int i;
  object *who;
  string tmp;
  status flag;

  tmp = "";
  who = sort_members();
  write(
  "_____________________________________________________________________\n" +
  ">___________________________________________________________________<\n" +
  " Party Name: " + capitalize(query_party()) + "\t" +
  "Party Rating: " + query_rate() + "\n" +
  " Party Age: " + show_age() + "\tParty Exp: " + query_exp() + "\n" +
  " Current Leader: " + capitalize(query_leader()) + "\n");

  for (i = 0; i < sizeof(members); i++) {
    if (!find_living(members[i])) {
      flag = 1;
      tmp += capitalize(members[i]) + " ";
    }
  }
  if (flag) write("Other members include: " + tmp + "\n");
  write(
  " Member  Level  %Share           Classes\n" +
  " ------  -----  ------           -------\n");

  for (i = 0; i < sizeof(who); i++) {
    tmp = capitalize((string)who[i]->query_name(1)) + "          ";
    tmp = tmp[0..10];
    tmp += "(" + (int)who[i]->query_level() + ")                  ";
    tmp = tmp[0..15];
    tmp += calc_share((int)who[i]->query_level()) + "%           ";
    tmp = tmp[0..25];
    tmp += implode((string *)who[i]->query_classes(), " ");
    tmp = tmp[0..60];
    write(tmp + "\n");
  }
  write(
  "_____________________________________________________________________\n" +
  ">___________________________________________________________________<\n");
  return 1;
}

status party_follow() {
  object obj;

  if (query_leader() == (string)environment()->query_name(1)) {
    write("You can't follow yourself! You're the leader!\n");
    return 1;
  }
  obj = find_player(query_leader());
  if (!obj) {
    write("The leader does not seem to be anywhere close by.\n");
    return 1;
  }
  if (!present(obj, environment(this_player()))) {
    write("The leader needs to be in the same room to start following.\n");
    return 1;
  }
  if (obj->query_followers(this_player())) {
    write("You are already following " + capitalize(query_leader()) + ".\n");
    obj->remove_followers(this_player());
    write("You no longer follow " + capitalize(query_leader()) + ".\n");
    return 1;
  }
  write("You are now following " + (string)obj->query_name(0) + ".\n");
  obj->add_followers(this_player());
  return 1;
}

