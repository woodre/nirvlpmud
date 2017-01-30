
#pragma strict_types
#pragma save_types
#include "spell_list.h"
#include "magesoul.h"
inherit "cast-target.c";

object spell_ob, target;
int monitor, casting_spell, casting_timer, casting_time, joining;
int guild_level, charge_timer, spell_level, muffled, entering_game, ansi;
int guild_master;
static int charge;
string current_spell, bing1, bing2, *spells_learned;

object player();
int valid_target(string *props);
object set_target(string *props);
int deduct_cost(int cost);
int try_spell();
int clear_spell();
int set_spell_heart_beat();
int earn_experience(int lev, int in, int ma, int cost);
int guild_save();
int think(string mess);

int get() { return 1; }

int drop() { return 1; }

int short() { return 0; }

int long() {
     write("Your sensitive mind detects an aura of octarine.\n");
     write("\nType \"info\" and \"info <topic/spell>\" for help on " +
           "commands.\n");
     return 1;
}

int id(string str) { return str=="magesoul" || str=="guild_death_object" ||
    str=="ND"; 
}

string query_auto_load() {
  return "players/bastion/guild/magesoul:";
}

void reset(int arg) {
}

void init() {
     string name;
     if(this_player()!=player())
          return 0;
     name=(string)this_player()->query_real_name();
     if(member_array(name, BANISHED)!=-1) {
       write("You are no longer welcome in the guild.\n");
       destruct(this_object());
     }
     if(!joining) {
       restore_object("players/bastion/guild/save/" + name);
       if((int)this_player()->query_invis() < 20)
         think("~enters the game.\n");
     }
     act("read_info", "info");
     act("cast", "cast");
     act("try_spell", "try_spell");
     act("think"); add_xverb("*");
     act("set_term", "ansi");
     act("charge_soul", "charge");
     act("teach", "teach");
     act("recruit", "recruit");
     act("update_guild_object", "renew");
     act("list_spells", "spells");
     act("monitor", "monitor");
     act("monitor", "mon");
     act("emote", "emote");
     act("interrupt_spell"); add_xverb("");
     act("guild_save","save");
     act("guild_quit", "quit");
     guild_level=player()->query_level() + player()->query_extra_level();
     if(!sizeof(spells_learned))
       spells_learned=default_spells;
     entering_game=0;
     joining=0;
     set_heart_beat(1);
}

int set_joining() { joining=1; }

int query_guild_level() { return guild_level; }
int add_charge(int c) {
     int temp, excess, limit;
     limit = (guild_level - 1) * 50 + 50;
     excess = (charge + c) - limit;
     if (excess < 1) excess = 0;
     temp = c - excess;
     if(excess) {
          write("You're soul cannot store that much magical essence.\n");
     }
     player()->add_spell_point(excess);
     charge += temp;
     return - temp;
}
int query_charge() { return charge; }

int read_info(string topic) {
     string mess;
     object ob;
     if(!topic) {
          cat("/players/bastion/guild/doc/general");
          return 1;
     }
     if(member_array(topic, known_spells)!=-1) {
       ob=("players/bastion/guild/spell/" + topic);
       mess=((string)ob->short() + ":\n\n" + (string)ob->query_info());
       write(format(mess));
       return 1;
     }
     cat("/players/bastion/guild/doc/"+topic);
     return 1;
}

int think(string mess) {
     object *ob, soul;
     int x;
     if(!mess) mess="";
     if(mess[0]==':' || mess[0]=='~')
       mess="(sorcerer) " + player()->query_name() + " " +
        mess[1..strlen(mess)] + "\n";
     else
       mess=player()->query_name() + " (sorcerer): " + mess + "\n";
     ob=users();
     for(x=0; x < sizeof(ob); x++) {
       soul=present("magesoul", ob[x]);
       if(soul && !soul->query_muffled() && !in_editor(ob[x]))
         tell_object(ob[x], format(mess));
     }
     return 1;
}

int charge_soul(mixed num) {
     int x, temp;
     if(!num) {
          write("Current charge: " + charge + "\n");
          return 1;
     }
     if(sscanf(num, "%d", x)!=1) {
          write("Charge <num>\n");
          return 1;
     }
     if(x < 0) {
          notify_fail("You must charge a postive amount.\n");
          return 0;
     }
     if(x > player()->query_sp()) {
          notify_fail("You don't have that many spell points.\n");
          return 0;
     }
     player()->add_spell_point(add_charge(x));
     write("New charge: " + charge + "\n");
     return 1;
}

int monitor() {
     if(monitor) {
          write("Monitor off.\n");
          monitor=0;
          return 1;
     }
     write("Monitor on.\n");
     monitor=1;
     set_heart_beat(1);
     return 1;
}

int display_monitor() {
     int max_hp, max_sp, hp, sp;
     string display;
     max_hp=(int)player()->query_mhp();
     max_sp=(int)player()->query_msp();
     hp=(int)player()->query_hp();
     sp=(int)player()->query_sp();
     display="";
     if(ansi) {
       if(hp < max_hp/5) display+=(BLINK + BOLD + RED);
       else if(hp < (max_hp/5) * 2) display+=(RED);
       else if(hp < (max_hp/5) * 3) display+=(YELLOW);
       else if(hp < (max_hp/5) * 4) display+=(YELLOW + BOLD);
       else display+=(GREEN);
     }
     display+=("HP: " + hp + "(" + max_hp + ")" + OFF);
     if(ansi) {
       if(sp < max_sp/5) display+=(BLINK + BOLD + RED);
       else if(sp < (max_sp/5) * 2) display+=(RED);
       else if(sp < (max_sp/5) * 3) display+=(YELLOW);
       else if(sp < (max_sp/5) * 4) display+=(BOLD + YELLOW);
       else display+=(GREEN);
     }
     display+=("  SP: " + sp + "(" + max_sp + ")" + OFF);
     display+=("  " + (ansi ? (BLUE+BOLD) : OFF) + "  CHARGE: " + charge + OFF);
     say(display + "\n");
     return 1;
}

void heart_beat() {
     charge_timer+=1;
     if(charge_timer>=5) {
        int bonus;
        bonus=player()->query_attrib("int") + player()->query_attrib("mag");
        bonus=(bonus / 2) / 4;
        add_charge(bonus);
        charge_timer=0;
     }
     if(monitor) display_monitor();
     if(casting_spell)
          casting_timer+=1;
     if(casting_spell && casting_timer >= casting_time) {
          command("try_spell", player());
     }
}

object player() { return environment(this_object()); }

int guild_death() { 
    call_other("players/bastion/guild/advance","correct_level",me);
    return 1;
}

string *query_spells_learned() { return spells_learned; }
int query_known_spells() {
     string *all_spells;
     int i;
     all_spells=known_spells + spells_learned + spells_learned;
     for(i=0; i<sizeof(all_spells); i++) {
          write(all_spells[i] + " ");
     }
}

int update_guild_object(string master) {
     object ob, *temp;
     int i;
     if(master=="all" && guild_level > 29) {
       temp=users();
       for(i=0; i < sizeof(temp); i++) {
         if(present("magesoul", temp[i]) && temp[i]!=this_player()) {
           present("magesoul", temp[i])->guild_save();
           present("magesoul", temp[i])->update_guild_object();
         }
        }
        write("All guild objects replaced.\n");
        return 1;
     }
     ob=clone_object("players/bastion/guild/magesoul");
     ob->update_guild_object_two(player());
     ob->set_joining();
     move_object(ob, player());
     if(this_player()!=player())
          tell_object(player(), this_player()->query_name() +
            " replaced your guild object.\n");
     else
          write("Guild object renewed and restored.\n");
     destruct(this_object());
     return 1;
}

int update_guild_object_two(object player) {
  restore_object("players/bastion/guild/save/" +
    player->query_real_name());
  return 1;
}

int guild_save() {
  if(this_player()==player())
    write("Guild object saved.\n");
  save_object("players/bastion/guild/save/" + 
    (string)player()->query_real_name());
}

int guild_quit() {
  guild_save();
  think("~leaves the game.");
}

int teach(string what) {
  string who, spell;
  object ob, soul;
  if(!what || sscanf(what, "%s %s", who, spell)!=2) {
    notify_fail("Teach <who> <spell>\n");
  }
  if(member_array(spell, spells_learned)==-1) {
    write("You don't know that spell!\n");
    return 1;
  }
  ob=present(who, environment(player()));
  if(!ob || !ob->is_player()) {
    write("That person is not here.\n");
    return 1;
  }
  soul=present("magesoul", ob);
  if(!soul) {
    write(capitalize(who) + " is not a practitioner of sorcery.\n");
    return 1;
  }
  soul->learn_spell(spell);
  return 1;
}

int learn_spell(string spell) {
  int level;
  if(member_array(spell, spells_learned)!=-1) {
    write(NAME + " already knows that spell.\n");
    return 1;
  }
  level=(int)("/players/bastion/guild/spell/" + spell)->query_spell_level();
  if(((guild_level * 2) + 3) <= sizeof(spells_learned)) {
    write(NAME + " cannot learn any more spells yet.\n");
    tell_object(player(), TEACHER + " tries to teach you one more spell " +
     "than you can learn.\n");
    return 1;
  }
  if(level > ((guild_level + 1) /2)) {
    write("That incantation is too complex for " + NAME + ".\n");
    tell_object(player(), TEACHER + "tries to teach you " + spell +
     " but it is too complex for you.\n");
    return 1;
  }
  spells_learned+=({ spell });
  write("You teach " + spell + " to " + NAME + ".\n");
  tell_object(player(), TEACHER + " teaches you " + spell + ".\n");
  return 1;
}

int set_term(string setting) {
  if(!setting) {
    write("Ansi sequences are " + (ansi ? "enabled" : "disabled") + ".\n");
    return 1;
  }
  if(setting=="on") ansi=1;
  else if(setting=="off") ansi=0;
  else {
    notify_fail("Ansi <on/off>.\n");
    return 0;
  }
  write("Ansi " + (ansi ? "enabled" : "disabled") + ".\n");
  return 1;
}

int list_spells() {
  int i;
  string list;
  for(i=sizeof(spells_learned) - 1; i>=0; i--) {
    list+=spells_learned[i] + (i ? ", " : ".");
  }
  list=list[1..strlen(list)];
  write("Spells learned:\n\n");
  write(format(list));
  return 1;
}

int set_guild_master(int bit) {
  if(bit) {
    guild_master=1;
    spells_learned=known_spells;
  }
  else
    guild_master=0;
}
int query_guild_master() { return guild_master; }

int recruit(string who) {
  object soul, recruit;
  if(!guild_master) {
    notify_fail("Only the guild master may recruit.\n");
    return 0;
  }
  if(!who) {
    notify_fail("Recruit <name>\n");
    return 0;
  }
  if(!present(who, environment(player()))) {
    notify_fail("That person is not here.\n");
    return 0;
  }
  soul=clone_object("players/bastion/guild/magesoul");
  recruit=present(who, environment(player()));
  (int)soul->set_joining();
  write("You recruit " + capitalize(who) + ".\n");
  tell_object(recruit, "You are now a sorcerer.\n");
  move_object(soul, recruit);
  ("players/bastion/guild/advance")->correct_level(recruit);
  recruit->set_guild_name("sorcerers");
  recruit->set_home("players/bastion/guild/advance");
  command("save", recruit);
  (int)soul->think("~joins the guild.\n");
  return 1;
}

int emote(string mess) {
  if(guild_level < 5) {
    notify_fail("You must be at least fifth level to emote.\n");
    return 0;
  }
  if(!mess) {
    notify_fail("Emote <message>\n");
    return 0;
  }
  tell_room(environment(player()), format(NAME + " " + mess + "\n"));
  return 1;
}
