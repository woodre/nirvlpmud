
/* Declarations */
#pragma strict_types
#pragma save_types
#define NAME query_name()
#define HIS player->query_possessive()
#define me this_player()
#define secure if(me!=player && me->query_level() < 100) return 0
string new_name, new_short, new_long;
int invisible, invisible_duration, mute, blind, impotent, new_ac;
int armor_duration, shield, shield_duration, muffled, contingency;
int disguise_duration, mute_duration, blind_duration, impotent_duration;
object player;
/*
inherit "players/bastion/closed/womble";
*/

string query_name();
int query_level();
string query_real_name();
int query_invis();
int glance();

/* Set variables */

int set_new_name(string name) { secure; new_name=name; }
int set_new_short(string short) { secure; new_short=short; }
int set_new_long(string long) { secure; new_long=long; }
int set_disguise_duration(int d) { disguise_duration=d; }
int set_invisibility(int invis, int duration) {
  invisible=invis; invisible_duration=duration; 
}
int set_mute(int i, int d) { mute=i; mute_duration=d; }
int set_blind(int i, int d) { blind=i; blind_duration=d; }
int set_impotent(int i, int d) { impotent=i; impotent_duration; }
int set_armor(int ac, int duration) {
  new_ac=ac; armor_duration=duration; 
}
int set_shield(int i, int duration) {
  shield=i; shield_duration=duration;
}
int set_muffled(int i) { muffled=i; }
int set_contingency(int i) { contingency=i; }

/* start shadow */

int valid_shadow() { return 1; }

int start_shadow(object who) {
  if(efun::shadow(who, 0)) {
    write("Second shadow attempted. Please report.\n");
    destruct(this_object());
  }
  efun::shadow(who, 1);
  write("Magesoul enabled.\n");
  player=who;
  set_heart_beat(1);
  return 1;
}

void reset(int arg) {
  if(player)
    player->reset(arg);
}

void init(int arg) {
  if(player)
    player->init(arg);
  set_heart_beat(1);
}

void heart_beat() {
  object ob;
  if(!interactive(player))
    destruct(this_object());
  if(shield_duration) shield_duration-=1;
  if(!shield_duration && shield) {
    say(format("A blue hue surrounding " + NAME + " flickers and fades.\n"));
    tell_object(player, "Your shield flickers and fades.\n");
    shield=0;
  }
  if(armor_duration) armor_duration-=1;
  if(!armor_duration && new_ac) {
    tell_object(player, "Your skin softens again.\n");
    new_ac=0;
  }
  if(mute_duration) mute_duration-=1;
  if(mute_duration < 1 && mute) mute=0;
  if(impotent_duration) impotent_duration=-1;
  if(impotent && !impotent_duration) impotent=0;
  if(blind_duration) blind_duration-=1;
  if(blind_duration < 1 && blind) {
    tell_object(player, "You can see again.\n");
    blind=0;
  }
}

void haste_heart_beat() {
  player->heart_beat();
}

/* Identify Ourselves */

int id(string name) {
  if(!interactive(player))
    return (int)player->id(name);
  if(this_player() && interactive(player) && ((query_invis() &&
   query_level() > 99) || (invisible && this_player()->query_level() < 21)) &&
   this_player()!=player && query_verb()!="tell")
    return 0;
  if(this_player() && query_verb()=="tell" && query_invis() &&
   query_level() > 99 && this_player()->query_level() < 21)
    return 0;
  if(new_name && name==new_name)
    return 1;
  return (int)player->id(name);
}

string short() {
  if(query_invis()) {
    if(this_player()!=player && this_player()->query_level() < 21)
      return 0;
  }
  if(new_short) {
    if(this_player() && this_player()->query_level() > 19 &&
     query_level() < 100)
      write(player->query_name() + ": ");
    if(player->query_ghost())
      return ("Ghost of " + query_name() + "\n");
    else
      return new_short;
  }
  return (string)player->short();
}

int long() {
  if(new_long) {
    if(this_player() && this_player()->query_level() > 19 &&
     query_level() < 100)
      write(player->query_name() + ": ");
    write(new_long + "\n");
  }
  else
    player->long();
}

string query_name() { 
  if(new_name)
    return capitalize(new_name);
  return (string)player->query_name();
}

string query_real_name() {
  if(new_name && this_player() && player->query_level() > 99)
    return new_name;
  return (string)player->query_real_name();
}

/* Object queries */

int query_invis() {
  if(player->query_invis() > 20 && this_player()->query_level() < 21)
    return 100;
  if(invisible) 
    return invisible;
  return (int)player->query_invis();
}

int query_level() {
  if(this_player() && this_player()==player && efun::query_verb()=="try_spell"
   && (int)player->query_level() < 21) {
    return 20;
  }
  return (int)player->query_level();
}

int query_sorcerer() { return 1; }

int query_sorcerer_level() {
  return (int)player->query_level() + (int)player->query_extra_level();
}

int is_player() { return 1; }

int query_ac() {
  if(new_ac) return new_ac;
  return (int)player->query_ac();
}


/* Spell functions */

mixed *query_disguise_info() {
  return ({ new_name, new_short, new_long, disguise_duration });
}

int *query_blind() { return ({ blind, blind_duration }); }
int *query_mute() { return ({ mute, mute_duration }); }
int *query_impotent() { return ({ impotent, impotent_duration }); }

int query_shield() { return shield; }

/* Communication */

int communicate(string what) {
  if(!what) {
    notify_fail("Say what?\n");
    return 0;
  }
  if(mute) {
    notify_fail("Your lips move, but nothing comes out.\n");
    return 0;
  }
  if(player->query_ghost()) {
    if(new_name)
      say(format("Ghost of " + query_name() + " says: " + what + "\n"));
    else
      say(format(short() + " says: " + what + "\n"));
    if(player->query_brief())
      write("Ok.\n");
    else
      write(format("You say: " + what + "\n"));
    return 1;
  }
  say(format(query_name() + " says: " + what + "\n"));
  if(player->query_brief())
    write("Ok.\n");
  else
    write(format("You say: " + what + "\n"));
  return 1;
}

int tell(string what) {
  object ob;
  string who, mess, name, tell;
  if(player->query_ghost()) {
    notify_fail("You cannot do that in your current state.\n");
    return 0;
  }
  if(player->query_sp() < 5) {
    notify_fail("You are too low on power.\n");
    return 0;
  }
  if(!what || sscanf(what, "%s %s", who, mess)!=2) {
    notify_fail("Tell who what?\n");
    return 0;
  }
  name=lower_case(who);
  ob=find_player(name);
  if(!ob)
    ob=find_living(name);
  if(!ob) {
    notify_fail("No player with that name.\n");
    return 0;
  }
  if(!interactive(ob) && ob->is_player()) {
    notify_fail("That player is disconnected.\n");
    return 0;
  }
  if(ob->query_invis() > 99) {
    notify_fail("No player with that name.\n");
    return 0;
  }
  if(in_editor(ob) && query_level() < 100) {
    notify_fail("That wizard is busy editing.\n");
    return 0;
  }
  name=query_real_name();
  if(mess[0]==':')
    tell="(tell) " + capitalize(name) + " " + mess[1..strlen(mess)];
  else
    tell=capitalize(name) + " tells you: " + mess;
  tell_object(ob, format(tell + "\n"));
  if(player->query_brief())
    write("Ok.\n");
  else if(mess[0]==':')
    write(format(tell + "\n"));
  else
    write(format("You tell " + capitalize(who) + ": " + mess + "\n"));
  if(interactive(ob) && query_idle(ob) > 180)
    write(capitalize(who) + " seems to be idle.\n");
  return 1;
}

/* Movement */

int move_player(string what) {
  string dir, dest;
  int is_light;
  if(player->query_ghost())
    return (int)player->move_player(what);
  if(!what)
    return 0;
  if(sscanf(what, "%s#%s", dir, dest)!=2) {
    notify_fail("Bad destination or direction.\n");
    return 0;
  }
  is_light=!player->test_dark();
  if(invisible && query_level() < 21) invisible_duration-=1;
  if(!invisible_duration && invisible) {
    say(NAME + " appears.\n");
    write("You are no longer invisible.\n");
    invisible=0;
  }
  if(new_name && query_level() < 21) disguise_duration-=1;
  if(!disguise_duration && new_name) {
    say(capitalize(new_name) + " is transformed into " + NAME + ".\n");
    write("You resume your true form.\n");
    new_name=0; new_short=0; new_long=0;
  }
  if(!new_name && !invisible)
    return (int)player->move_player(what);
  if(query_invis() < 40) {
    if(dir=="X")
      say(query_name() + " " + player->query_mmsgout() + ".\n");
    else if(is_light)
      say(query_name() + " " + player->query_msgout() + " " + dir + ".\n");
  }
  move_object(player, dest);
  is_light=!player->test_dark();
  if(query_invis() < 40) {
    if(dir=="X")
      say(query_name() + " " + player->query_mmsgin() + ".\n");
    else if(is_light)
      say(query_name() + " " + player->query_msgin() + ".\n");
  }
  if(!is_light) {
    write("A dark room.\n");
    return 1;
  }
  player->glance();
  player->set_part(dest);
  return 1;
}

/* Armor and weapons functions */

int hit_player(int hit, object zap) {
  if(new_ac && !shield) 
    hit-=random(new_ac + 1);
  if(shield) {
    tell_object(player, "Your shield absorbs a hit.\n");
    hit -= (hit / shield);
  }
  return (int)player->hit_player(hit, zap);
}

int wield(object w) {
  player->wield(w);
  if(w->weapon_class() > 15) {
    tell_object(player, "Your weapon slips from your grasp!\n");
    say(NAME + " drops " + HIS + " weapon.\n");
    w->drop(1);
  return 1;
  }
}

/* Let players read guild files */

