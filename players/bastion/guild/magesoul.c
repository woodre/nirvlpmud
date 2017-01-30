
#pragma strict_types
#pragma save_types
#include "spell_list.h"
#include "magesoul.h"

object spell_ob, *target;
static object shadow;
int monitor, casting_spell, casting_timer, casting_time, joining;
int guild_level, charge_timer, spell_level, muffled, entering_game, ansi;
int guild_master;
static int charge;
string current_spell, bing1, bing2, *spells_learned;
mixed *spellcraft;
/* effects variables */
string new_name, new_short, new_long;
int disguise_duration, blind, blind_duration, mute, mute_duration;
int impotent, impotent_duration;

object player();
int valid_target(string *props);
object *set_target(string *props);
int deduct_cost(int cost, string *props);
int try_spell();
int clear_spell();
int set_spell_heart_beat();
int earn_experience(int lev, int in, int ma, int cost);
int guild_save();
int get_effects();
int set_effects(string name, string short, string long, int disguise_d,
 int blind, int blind_d, int mute, int mute_d, int imp, int imp_d);
int do_effects();
int think(string mess);

int get() { return 1; }

int drop() { return 1; }

int short() { return 0; }

int long() {
     write("Your sensitive mind detects an aura of octarine.\n");
     write("\nType \"info\" and \"info <topic>\" for help on " +
           "commands.\n");
     return 1;
}

int id(string str) { return str=="magesoul" || str=="guild_death_object" ||
    str=="ND" || str=="notarmor" || str=="guild";
}

string extra_look() {
  if(player()->query_shield())
    return (NAME + " is surrounded by a glowing, blue aura");
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
     act("set_term", "ansi", 2);
     act("charge_soul", "charge", 2);
     act("teach", "teach", 2);
     act("recruit", "recruit", 3);
     act("guild_promote", "gpromote", 3);
     act("update_guild_object", "renew", 3);
     act("list_spells", "spells", 2);
     act("monitor", "monitor", 3);
     act("clear_spell", "clear");
     act("emote", "emote", 2);
     act("interrupt_spell", "abort", 2);
     act("guild_save","save");
     act("guild_quit", "quit");
     add_action("remove", "sremove");
     guild_level=player()->query_level() + player()->query_extra_level();
     if(!sizeof(spells_learned))
       spells_learned=default_spells;
     if(!sizeof(spellcraft))
       spellcraft=({"alchemy", 0, "alteration", 0, "astrology", 0, 
        "conjuration", 0, "demonology", 0, "enchantment", 0, "necromancy",
        0 });
     joining=0;
     ("players/bastion/guild/advance")->correct_level(player());
     cat("/players/bastion/guild/doc/news");
/*
     shadow=clone_object("players/bastion/guild/magesoul/shadow");
     shadow->start_shadow(player());
     if(!joining) do_effects();
*/
     set_heart_beat(1);
}

int set_joining() { joining=1; }

int set_guild_level(int i) { guild_level=i; }
int query_guild_level() { return guild_level; }

int add_charge(int c) {
     int temp, excess, limit;
     limit = (guild_level - 1) * 30 + 100;
     excess = (charge + c) - limit;
     if (excess < 1) excess = 0;
     temp = c - excess;
     if(excess) {
          write("You're soul cannot store that much magical essence.\n");
     }
     player()->add_spell_point(excess);
     charge += temp;
     if(efun::query_verb())
       player()->add_spell_point(-temp);
     return 1;
}
int query_charge() { return charge; }
int set_charge(int i) { charge=i; }

int read_info(string topic) {
     string mess;
     object ob;
     if(!topic) {
          ("closed/wiz_soul")->more("/players/bastion/guild/doc/general");
          return 1;
     }
     if(member_array(topic, known_spells)!=-1) {
       ob=("players/bastion/guild/spell/" + topic);
       mess=((string)ob->short() + ":\n\n" + (string)ob->query_info());
       write(format(mess));
       return 1;
     }
     if(file_size("/players/bastion/guild/doc/" + topic) < 0) {
       notify_fail("No information available on \"" + topic + "\".\n");
       return 0;
     }
     ("closed/wiz_soul")->more("/players/bastion/guild/doc/" + topic);
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
       if(soul && !ob[x]->query_muffled() && !in_editor(ob[x])) {
         if(ob[x]!=player())
           tell_object(ob[x], "\n" + format(mess) + "->> ");
         else
           tell_object(ob[x], format(mess));
       }
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
     add_charge(x);
     write("New charge: " + charge + "\n");
     return 1;
}

int cast(string str) {
     string spell, what, *properties;
     int spell_cost, chance;
     if(casting_spell) {
          write("You are already casting a spell.\n");
          return 1;
     }
     if(!str) {
          write("Cast <spell> (<arg1>) (<arg2>)\n");
          return 1;
     }
     if(sscanf(str, "%s %s", spell, what)==2) {
          if(sscanf(what, "%s %s", bing1, bing2)!=2)
               bing1=what;
     }
     else
          spell=str;
     if(member_array(spell, spells_learned)==-1) {
          write("You know of no such spell.\n");
          clear_spell();
          return 1;
     }
     spell_ob="players/bastion/guild/spell/" + spell;
     properties=(string*)spell_ob->query_property();
     if(me->query_attack() && 
       member_array("no_attack", properties)!=-1) {
          write("You are too busy fighting to concentrate!\n");
          clear_spell();
          return 1;
     }
     if(!valid_target(properties)) {
          clear_spell();
          return 1;
     }
     target=set_target(properties);
     spell_level=(int)spell_ob->query_spell_level();
     if(spell_level > guild_level) {
          write("You are not skillful enough to cast that spell.\n");
          clear_spell();
          return 1;
     }
     spell_cost=(int)spell_ob->query_spell_cost();
     if(!deduct_cost(spell_cost, properties)) {
          clear_spell();
          return 1;
     }
     current_spell=spell;
     spell_ob->cast_spell(target, bing1, bing2);
     set_spell_heart_beat();
     return 1;
}

int set_spell_heart_beat() {
  casting_time=(int)spell_ob->query_casting_time();
  casting_spell=1;
}

int valid_target(string *props) {
  object here;
  here=environment(player());
  if(bing1 && member_array("no_target", props)!=-1 &&
    member_array("non_parsed", props)==-1) {
    write("That spell doesn't require a target.\n");
    return 0;
  }
  if(!bing2 && member_array("two_arguments", props)!=-1) {
    write("You need to supply more information to cast that.\n");
    return 0;
  }
  if(member_array("nonliving_target", props)!=-1 &&
    member_array("living_target", props)==-1) {
    if(!bing1) {
      write("You need to specify a target.\n");
      return 0;
    }
    if(!present(bing1) || !present(bing1, here)) {
      write("That is not here.\n");
      return 0;
    }
  }
  if(member_array("living_target", props)!=-1 &&
    member_array("nonliving_target", props)==-1) {
    if(bing1 && !present(bing1, here) && 
     member_array("distant_target", props)==-1) {
      write("That person is not here.\n");
      return 0;
    }
    if(bing1 && !find_player(bing1) &&
     member_array("distant_target", props)!=-1) {
      write("That person is not logged in.\n");
      return 0;
    }
    if(!bing1 && !player()->query_attack() && 
     member_array("attack_spell", props)!=-1) {
      write("You need to specify a target.\n");
      return 0;
    }
    else if(!bing1 && member_array("attack_spell", props)==-1 &&
     member_array("self_target", props)==-1) {
      write("You need to specify a target.\n");
      return 0;
    }
  }
  if(member_array("living_target", props)!=-1 &&
   member_array("nonliving_target", props)!=-1) {
    if(!bing1 && member_array("self_target", props)==-1) {
      write("You need to specify a target.\n");
      return 0;
    }
    if(!present(bing1) && !present(bing1, here)) {
      write("That person or item is not here.\n");
      return 0;
    }
  }
  return 1;
}

object *set_target(string *props) {
  object here, *temp, *all;
  int i;
  here=environment(player());

  if(member_array("non_parsed", props)!=-1 ||
   member_array("no_target", props)!=-1)
    return ({ player() });
  if(member_array("nonliving_target", props)!=-1 &&
   member_array("living_target", props)==-1) {
    if(bing1 && present(bing1))
      return ({ present(bing1) });
    else if(bing1 && present(bing1, here))
      return ({ present(bing1, here) });
  }
  if(member_array("living_target", props)!=-1 && 
   member_array("nonliving_target", props)==-1) {
    if(member_array("area_effect", props)!=-1) {
      if(!bing1 && member_array("attack_spell", props)!=-1)
        temp=({ (object)player()->query_attack() });
      else
        temp=({ present(bing1, here) });
      all=all_inventory(here);
      for(i=0; i < sizeof(all); i++) {
        if(all[i]!=player() && all[i]!=temp[0] && all[i]->query_hp())
          temp+=({ all[i] });
      }
      return temp;
    }
    if(!bing1 && member_array("attack_spell", props)!=-1)
      return ({ (object)player()->query_attack() });
    else if(bing1 && present(bing1, here))
      return ({ present(bing1, here) });
    else if(bing1 && find_player(bing1))
      return ({ find_player(bing1) });
    else
      return ({ player() });
  }
  if(member_array("living_target", props)!=-1 &&
   member_array("nonliving_target", props)!=-1) {
    if(bing1 && present(bing1))
      return ({ present(bing1) });
    else if(bing1 && present(bing1, here))
      return ({ present(bing1, here) });
    else if(bing1 && find_player(bing1))
      return ({ find_player(bing1) });
    else
      return ({ player() });
  }
  write("Error: Set_target().\n");
  log_file("players/bastion/guild/log/error","Error: Set_target() -- magesoul.c");
}

int try_spell() {
     int chance, intel, mag, wil, cost;
     if(!casting_spell || (casting_timer && casting_timer < casting_time))
       return 0;
     intel=(int)player()->query_attrib("int");
     mag=(int)player()->query_attrib("mag");
     wil=(int)player()->query_attrib("wil");
     chance=(int)spell_ob->query_base_chance();
     chance+=(4 * (guild_level - 1)) + ((intel + mag) / 2);
     cost=(int)spell_ob->query_spell_cost();
     earn_experience(spell_level, intel, mag, cost);
     if(chance < (random(100))) 
       ("players/bastion/guild/spell/fail_spell")->fail_spell(spell_level,wil);
     else
       spell_ob->heart_beat_spell(target, bing1, bing2);
     clear_spell();
     return 1;
}

int deduct_cost(int cost, string *props) {
     if(member_array("area_effect", props)!=-1)
       cost=cost * (sizeof(target) > 3 ? sizeof(target) : 3);
     if(cost <= charge)
          charge-=cost;
     else if(!charge) {
          if(cost > (me->query_spell_point())) {
               write("You lack the energy.\n");
               return 0;
          }
          me->add_spell_point(-cost);
     }
     else {
          if(cost > (charge + me->query_spell_point())) {
               write("You lack the energy.\n");
               return 0;
          }
          me->add_spell_point(-(cost - charge));
          charge=0;
     }
     return 1;
}

int earn_experience(int lev, int in, int ma, int cost) {
     int amt;
     amt=(lev + in + ma) / 10;
     amt=(amt * cost) / 2;
     player()->add_exp(amt);
     return 1;
}

int interrupt_spell() {
     if(casting_spell && casting_timer < casting_time) {
          write(capitalize(current_spell) + " interrupted.\n");
          clear_spell();
          return 1;
     }
}

int clear_spell() {
  casting_spell=0; casting_time=0; casting_timer=0; spell_ob=0;
  target=0; bing1=0; bing2=0; current_spell=0; spell_level=0;
  if(query_verb() && query_verb()=="clear")
    write("All spell values cleared.\n");
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
     display+=("  " + (ansi ? (BLUE + BOLD) : OFF) + "  CHARGE: " + charge +
      "(" + ((guild_level -1) * 30 +100) + ")" + OFF);
     say(display + "\n");
     return 1;
}

void heart_beat() {
     charge_timer+=1;
     if(charge_timer>=5) {
        int bonus;
        bonus=player()->query_attrib("int") + player()->query_attrib("mag");
        bonus=(bonus / 2) / 5;
        if(query_idle(player()) < 180)
           add_charge(bonus);
        charge_timer=0;
     }
     if(monitor) display_monitor();
     if(casting_spell)
          casting_timer+=1;
     if(casting_time > 1 && casting_timer!=casting_time) {
       string mess;
       mess=(string)spell_ob->casting_message(target, player(), casting_timer);
       tell_room(environment(player()), mess);
     }
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

int update_guild_object(string master) {
     object ob, *temp;
     int i;
     if(master=="all" && guild_master) {
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
     if(shadow) get_effects();
     if(shadow)
       destruct(shadow);
     ob->update_guild_object_two(player());
     ob->set_joining();
     ob->set_charge(charge);
     ob->set_effects(new_name, new_short, new_long, disguise_duration,
      blind, blind_duration, mute, mute_duration, impotent, impotent_duration);
     move_object(ob, player());
     ob->do_effects();
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
  get_effects();
  save_object("players/bastion/guild/save/" + 
    (string)player()->query_real_name());
}

int guild_quit() {
  guild_save();
  think("~leaves the game.");
  if(shadow)
    destruct(shadow);
}

int get_effects() {
  mixed *temp;
  temp=(mixed)me->query_disguise_info();
  new_name=temp[0]; new_short=temp[1]; new_long=temp[2]; 
  disguise_duration=temp[3];
  temp=(mixed)me->query_blind();
  blind=temp[0]; blind_duration=temp[1];
  temp=(mixed)me->query_mute();
  mute=temp[0]; mute_duration=temp[1];
  temp=(mixed)me->query_impotent();
  impotent=temp[0]; impotent_duration=temp[1];
}

int set_effects(string name, string short, string long, int disguise_dur,
    int b, int b_dur, int m, int m_dur, int imp, int imp_dur) {
  new_name=name; new_short=short; new_long=long; 
  disguise_duration=disguise_dur; blind=b; blind_duration=b_dur; mute=m;
  mute_duration=m_dur; impotent=imp; impotent_duration=imp_dur;
}

int do_effects() {
  player()->set_new_name(new_name); player()->set_new_short(new_short);
  player()->set_new_long(new_long); player()->set_disguise_duration(disguise_duration);
  player()->set_blind(blind, blind_duration); player()->set_mute(mute, mute_duration);
  player()->set_impotent(impotent, impotent_duration);
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
  int level, size, frog, x;
  string area;
  if(member_array(spell, spells_learned)!=-1) {
    write(NAME + " already knows that spell.\n");
    return 1;
  }
  level=(int)("/players/bastion/guild/spell/" + spell)->query_spell_level();
  if((guild_level * 2) <= sizeof(spells_learned)) {
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
  area=(string)("players/bastion/guild/spell/"+spell)->query_spell_type();
  x=member_array(area, spellcraft) + 1;
  size=spellcraft[x];
  if(size < 1) {
    write(format(NAME + " is too ignorant of " + area + " to learn " +
     spell + ".\n"));
    tell_object(player(), format(TEACHER + " tries to teach you " + spell +
     ", but you lack enough background in " + area + ".\n"));
    return 1;
  }
  else
    spellcraft[member_array(area, spellcraft) + 1]-=1;
  spells_learned+=({ spell });
  write("You teach " + spell + " to " + NAME + ".\n");
  tell_object(player(), TEACHER + " teaches you " + spell + ".\n");
  return 1;
}

int gain_spellcraft(string area) {
  tell_object(player(), "You are now more learned in " + area + ".\n");
  spellcraft[member_array(area, spellcraft) + 1]+=1;
  return 1;
}

int set_spellcraft(string area, int num) {
  if(!area || member_array(area, spellcraft)==-1) {
    notify_fail("That is not a known field.\n");
    return 0;
  }
  spellcraft[member_array(area, spellcraft) + 1]+=num;
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

int list_spells(string master) {
  int i;
  string list, *spells;
  object ob;
  if(master && guild_master) {
    if(!find_player(master)) {
      notify_fail("That person is not logged in.\n");
      return 0;
    }
    ob=present("magesoul", find_player(master));
    if(!ob) {
      notify_fail("That person is not a sorcerer.\n");
      return 0;
    }
    spells=(string*)ob->query_spells_learned();
  }
  else
    spells=spells_learned;
  for(i=sizeof(spells) - 1; i>=0; i--) {
    list+=spells[i] + (i ? ", " : ".");
  }
  list=list[1..strlen(list)];
  write("Spells learned:\n\n");
  write(format(list));
  return 1;
}

int guild_promote(string what) {
  object ob;
  string who;
  int bit;
  if(me->query_level() < 100) 
    return 0;
  if(!what || sscanf(what, "%s %d", who, bit)!=2) {
    notify_fail("Gpromote <who> <bit>\n");
    return 0;
  }
  if(!find_player(who)) {
    notify_fail(who + " is not logged in.\n");
    return 0;
  }
  ob=find_player(who);
  if(!present("magesoul", ob)) {
    notify_fail(who + " is not a sorcerer.\n");
    return 0;
  }
  present("magesoul", ob)->set_guild_master(bit);
  write(who + (bit ? " promoted to" :" demoted from") + " guild master.\n");
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
  recruit=present(who, environment(player()));
  if(recruit->query_guild_name() || recruit->query_guild_exp()) {
    notify_fail(recruit->query_name() + " already has a guild.\n");
    return 0;
  }
  soul=clone_object("players/bastion/guild/magesoul");
  (int)soul->set_joining();
  write("You recruit " + capitalize(who) + ".\n");
  move_object(soul, recruit);
  tell_object(recruit, "You are now a sorcerer.\n");
  soul->think("~joins the guild.\n");
  ("players/bastion/guild/advance")->correct_level(recruit);
  recruit->set_guild_name("sorcerers");
  recruit->add_guild_exp(13);
  recruit->set_home("players/bastion/guild/advance");
  if(recruit->query_attrib("sta") > 14)
    recruit->raise_stamina(-((int)recruit->query_attrib("sta") - 14));
  if(recruit->query_attrib("str") > 14)
    recruit->raise_strength(-((int)recruit->query_attrib("str") -14));
  command("save", recruit);
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

int remove() {
  if(player()->query_level() < 21)
    return 0;
  if(efun::shadow(player(), 0))
    destruct(efun::shadow(player(), 0));
  write("Shadow object destructed.\n");
  return 1;
}
