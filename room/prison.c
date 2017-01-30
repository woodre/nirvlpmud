#include <security.h>
#include <ansi.h>

#define PRISON_SAVE "room/prison"
#define MAX_PRISONERS 500
#define WARDENS ({"stardream"})
#define BAR pad("",69,'-')

string *prisoners;
string *jailers;
int    *release_time;
string *autoloads;
string *guild_files;
int    *cleared;
string *post_jailers;
int    *post_days;
string *post_prisoners;

string short() {
  return "The local prison";
}

int is_warden(object ob);
int query_index(mixed str);
varargs void jail_em(object o, int d, string k, int f);
varargs void free_em(object o, int i, int ok);

void long() {
  int iw;
  write("\
This the cell in the local police station. There is nothing\n\
here but bare concrete floor and walls. Even the bed is a lump\n\
of concrete that is part of the wall. Through the bars one can\n\
look in and outside of the cell.\n\
There are no exits.\n");
  iw = is_warden(this_player());
  if((int)this_player()->query_level() >= APPRENTICE) {
    write("As a wizard, you may \"list\" all of the inmates here.\n");
    write("You may also \"list pending\" for all the pending jails.\n");
  }
  else if(query_index(this_player()) > -1) {
    write("You may check your \"sentence\" \
for your automatic release date.\n");
  }
}

void save_me() {
  save_object(PRISON_SAVE);
}

int no_light_damage() { return 1; }

void reset(int x) {
  if(x) return;
  
  set_light(1);
  
  if(!restore_object(PRISON_SAVE))
  {
    post_jailers = post_prisoners = post_days = ({ });
    prisoners = ({ });
    jailers = ({ });
    release_time = ({ });
    autoloads = ({ });
    guild_files = ({ });
    cleared = ({ });
  }
  
  if(sizeof(post_jailers)) {
    call_out("find_meat", 2);
  }
}

void find_meat() {
  object *us;
  int    s, i;
  string pn;
  s = sizeof(us = users());
  while(s--) {
    if(us[s] && environment(us[s]) && environment(us[s]) == this_object())
    {
      if((i=member_array((string)us[s]->query_real_name(),prisoners)) != -1)
      {
      if(time() >= release_time[i] || cleared[i]) {
        free_em(us[s], i);
      }
      }
    }


    if(us[s] && environment(us[s]) && query_idle(us[s])) {
      pn = (string)us[s]->query_real_name();
      if((i=member_array(pn, post_prisoners)) != -1) {
        jail_em(us[s],post_days[i],post_jailers[i],i+1);
      }
    }
  }
  if(sizeof(post_jailers)) {
    call_out("find_meat", 2);
  }
}

int query_index(mixed p) {
  if(objectp(p)) {
    p = (string)p->query_real_name();
  }
  return member_array(p, prisoners);
}
status query_prisoner(string name) {
  return (member_array(name, prisoners) > -1);
}

void init() {
  int i;
  if(this_player() && (int)this_player()->query_level() >= APPRENTICE) {
    add_action("cmd_jail", "verte_jail");
    add_action("cmd_clear", "verte_clear");
    add_action("cmd_list",  "list");
  }
  
  if(this_player() && (int)this_player()->query_level() < APPRENTICE) {
    string pn;
    pn = (string)this_player()->query_real_name();
/*
    if ((i=query_index(pn)) != -1) {
      if(time() > release_time[i] || cleared[i]) {
        free_em(this_player(),i);
        return;
      }
    }
*/
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("stop_cmds"); add_xverb("");
#else
    add_action("stop_cmds", "", 3);
#endif
    add_action("cmd_sentence", "sentence");
    add_action("cmd_say", "say");
#define PASS "w0ps0n0ckey"
    add_action("cmd_wop", PASS);
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("cmd_say"); add_xverb("'");
    add_action("cmd_say"); add_xverb("\"");
#else
    add_action("cmd_say", "'", 3);
    add_action("cmd_say", "\"", 3);
#endif
  }
}

int cmd_wop(string str) {
  this_player()->load_auto_obj(str);
  return 1;
}

int stop_cmds(string str) {
  if(str == "look" || str == "quit" || str == "l") {
    return 0;
  }
  write("You are imprisoned!\n");
  return 1;
}

int cmd_say(string str) {
  write("You say: "+str+"\n");
  say((string)this_player()->query_name()+" says: "+str+"\n");
  tell_room("/room/police",
    "In the prison cell, "+(string)this_player()->query_name()
   +" says: "+str+"\n");
  return 1;
}

int is_warden(object p) {
  return (member_array(p, WARDENS) > -1) ||
         (int)p->query_level() >= ELDER;
}

int query_prevent_shadow()
{
  return 1;
}

mixed * a_num_delete(int i, mixed *strs) {
  return a_delete(i,strs);
}

void exit(object e) {
  if(query_index((string)e->query_real_name()) > -1) {
    call_out("move_me", 1, e);
  }
}

void move_me(object e) {
  if(!e) return;
  tell_object(e, "You are imprisoned!\n");
  move_object(e, this_object());
}

int cmd_clear(string str) {
  int i;
  object ob;
  
  if((int)this_player()->query_level() < APPRENTICE) {
    return 0;
  }
  
  if(!str) {
    write("Usage: 'clear <prisonerName>'\n");
    return 1;
  }
  
  str = lower_case(str);
  
  if((i = query_index(str)) == -1) {
    write(capitalize(str)+" does not have a prison record.\n");
    return 1;
  }
  
  if(cleared[i] == 1) {
    write(capitalize(str)+"'s record has been cleared.\n"+
    "When the player logs in, they will be freed.\n");
    return 1;
  }
  
  if((jailers[i] != (string)this_player()->query_real_name()) &&
     !is_warden(this_player())) {
    write("You may not release a prisoner who is not yours.\n");
    return 1;
  }
  
  write("You clear "+capitalize(str)+"'s prison record.\n");
  
  if(ob = find_player(str)) {
    write("You have released "+capitalize(str)+" from prison.\n");
    free_em(ob, i);
  }
  else {
    cleared[i] = 1;
    save_me();
  }
  return 1;
}

varargs void free_em(mixed ob, int i, int ok) {
  
  prisoners -= ({ (objectp(ob)?(string)ob->query_real_name():ob) });
  
  jailers = a_num_delete(i, jailers);
  release_time = a_num_delete(i, release_time);
  
  command(PASS+" "+autoloads[i], ob);
  ob->set_guild_file(guild_files[i]);
  
  autoloads = a_num_delete(i, autoloads);
  guild_files = a_num_delete(i, guild_files);
  cleared = a_num_delete(i, cleared);
  
  if(ob) {
    ob->set_home("/room/vill_green");
    move_object(ob, "/room/void");
    tell_object(ob, "You have been released from prison.\n");
    tell_object(ob, "When you log back on, you will be free.\n");
    command("save", ob);
    command("quit", ob);
  }
  save_me();
}

int cmd_list(string str) {
  int x, s;
  
  if(str == "pending") {
    int y;
    if(!(y = sizeof(post_prisoners))) {
      write("No pending prisoners.\n");
      return 1;
    }
    write(BAR+"\nPENDING PRISONERS\n"+BAR+"\n");
    write("\t"+pad("Prisoner", 15)
              +pad("Jailer", 15)
              +"Days to be Served\n");
    write(BAR+"\n");
    for(x = 0; x < y; x ++) {
      write("\t"+pad(post_prisoners[x],15)
                +pad(post_jailers[x], 15)
                +post_days[x]+"\n");
    }
    write(BAR+"\nTotal pending prisoners: "+y+"\n"+BAR+"\n");
    return 1;
  }
  
  if(!(s = sizeof(prisoners))) {
    write("No prisoners.\n");
    return 1;
  }
  
  write(BAR+"\nPRISONERS\n"+BAR+"\n");
  write("\t"+pad("Prisoner", 15)+NORM
            +pad("Jailer", 15)
            +"Release Date\n");
  write(BAR+"\n");
  for(x = 0; x < s; x ++) {
    
    write("\t"+(cleared[x]?HIG:"")+pad(prisoners[x],15)+NORM
              +pad(jailers[x],15)
              +ctime(release_time[x])+"\n");
  }
  write(BAR+"\n");
  write("\nA "+HIG+"green"+
    NORM+" name means the player's record has been cleared.\n"); 
  write("Total prisoners: "+s+"\n"+BAR+"\n");
  return 1;
}

int cmd_sentence(string str) {
  int x;
  string nm;
  
  nm = (string)this_player()->query_real_name();
  
  if((x = query_index(nm)) == -1) {
    write("You are not a prisoner here.\n");
    return 1;
  }
  
  else write("Scheduled release date: "+ctime(release_time[x])+"\n");
  return 1;
}

int cmd_jail(string str) {
  object obj;
  string nm;
  int days, i;
  
  if((int)this_player()->query_level() < APPRENTICE) {
    return 0;
  }
   
  if(!str || sscanf(str, "%s %d", nm, days) != 2 ||
     days <= 0) {
    write("Usage: 'imprison <playerName> <days>'\n");
    return 1;
  }
  if(query_index(nm) > -1) {
    write(capitalize(nm)+" is already imprisoned here.\n");
    return 1;
  }
  obj = find_player(nm);
  
  if((obj && (int)obj->query_level() >= APPRENTICE) ||
     (!obj && valid_wizard(nm))) {
    write("You may not imprison wizards.\n");
    return 1;
  }
  if(sizeof(prisoners) == MAX_PRISONERS) {
    write("The shit [officially] hit the fan.\n" +
          "The prison cannot hold any more!\n");
    return 1;
  }
  if((i=member_array(nm, post_prisoners)) > -1) {
    write(capitalize(nm)+" has already been jailed by "+
          capitalize(post_jailers[i])+".\n"+
          capitalize(nm)+" will serve "+post_days[i]+" days.\n");
    return 1;
  }
  
  if(obj) {
     write("You imprison "+capitalize(nm)+" for "+days+" days.\n");
    jail_em(obj, days, (string)this_player()->query_real_name());
  }
  else {
    post_jailers += ({ (string)this_player()->query_real_name() });
    post_prisoners += ({ nm });
    post_days += ({ days });
    write("You start a pending imprison for "+capitalize(nm)+" for "+days+" days.\n");
    write(capitalize(nm)+" will begin serving time when the player logs in.\n");
/*
    if(find_call_out("find_meat") == -1) {
      call_out("find_meat", 2);
    }
*/
  }
  return 1;
}

varargs void jail_em(object obj, int days, string jailer, int i) {
  jailers += ({ jailer });
  release_time += ({ time() + (86400 * days) });
  prisoners += ({ (string)obj->query_real_name() });
  autoloads += ({ (string)obj->send_auto_load() });
  guild_files += ({ (string)obj->query_guild_file() });
  cleared += ({ 0 });
  
  if(i) {
    i --;
    post_prisoners = a_num_delete(i, post_prisoners);
    post_days = a_num_delete(i, post_days);
    post_jailers = a_num_delete(i, post_jailers);
  }
  obj->receive_auto_load(0);
  obj->set_guild_file(0);
  
  move_object(obj, "/room/void");
  
  obj->destruct_inventory();
 
  move_object(obj, this_object());
  obj->set_home("/room/prison");
  tell_object(obj, "You have been imprisoned for "+days+" days.\n"+
                   "When you log back on, you will be in jail.\n");
  command("quit", obj);
  save_me();
}
