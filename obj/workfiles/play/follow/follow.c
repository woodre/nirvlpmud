/*  
   follow coded by verte

   IMPLEMENTATION:
   - move /obj/follow.c to a backup file
   - cp this in its stead
   - cp /players/vertebraker/obj/ask_follow.c to
     /obj/ask_follow.c
   - rm the 'add_action("allow_follow","allow_follow")'
     line from /obj/player.c
   - update player.c

   IMPROVEMENTS OVER ORIGINAL: 
   - use of input_to to allow follow
   - typo|capitalization errors fixed 
   - gives proper notifications
   - follow stop "bug" fixed 
   - allows rooms to be non-teleport 
     but followable through 'okay_follow'
*/

static object leader;
static string *followers;
static int fstatus_flag;

int    do_follow();
status query_follower(string str);
int    ask_follow(string str);
int    accept_follow(string str);
void   set_leader(object ob);
void   add_follower(string str);
void   remove_follower(string str);
void   clear_followers();
mixed query_followers();

object query_leader(){
  return leader;
}

void end_follow_calls(){
  while(remove_call_out("do_follow") != -1);
}



void set_leader(object ob)
{
    leader = ob;
}

string *query_followers()
{
    return followers;
}

void remove_follower(string str)
{
    int x;
    if(!followers) followers = ({ });
    if((x = member_array(str, followers)) > -1)
    {
      tell_object(this_object(),
      "You are no longer leading "+capitalize(str)+".\n");
      if(followers[x] == name) followers[x] = 0;
      if(followers[x] && find_player(followers[x]))
      {

        find_player(followers[x])->set_leader(0);
        tell_object(find_player(followers[x]),
        "You are no longer following "+cap_name+".\n");
      }
      followers[x] = 0;
    }
}

void add_follower(string str)
{
    if(!followers) followers = ({ });
    if(member_array(str, followers) == -1)
      followers += ({ str });
}


void clear_followers()
{
    int x;
    if(!followers) followers = ({ });
    for(x = 0; x < sizeof(followers); x++)
    {
      if(followers[x] && find_player(followers[x]))
      {
        find_player(followers[x])->set_leader(0);
        tell_object(find_player(followers[x]),
         "You are no longer following "+cap_name+".\n");
      }
    }
    followers = 0;
}

void
clear_follow()
{
    leader = 0;
    clear_followers();
}

int do_follow()
{
    object env_l, env_m;
    if(!environment(this_object()))
    {
      if(leader) tell_object(leader,
      capitalize(name)+" has disconnected.\n"+
      "Discontinuing follow...\n");
      return 1;
    }
    if(!leader)
    {
      return 1;
    }
    if(!environment(leader))
    {
      tell_object(this_object(),
            "Your leader has disconnected.\n"+
            "Discontinuing follow...\n");
      return 1;
    }
    env_l = environment(leader);
    env_m = environment();
    if(!env_l || !env_m)
    {
      tell_object(this_object(),
            "Something strange has happened.\n"+
            "Discontinuing follow...\n");
      return 1;
    }
    if(env_l == env_m)
    {
      call_out("do_follow",4);
      return 1;
    }
    if(((string)env_m->realm() == "NT" || (string)env_m->realm() == "LA")
       && !env_m->okay_follow())
    {
      tell_object(this_object(),
            "You must leave here manually...\n"+
            "Delaying follow...\n");
      call_out("do_follow",8);
      return 1;
    }
    if(((string)env_l->realm() == "NT" || (string)env_l->realm() == "LA") 
       && !env_l->okay_follow())
    {
      tell_object(this_object(),
            "You must follow the leader manually to his location...\n"+
            "Delaying follow...\n");
      call_out("do_follow",8);
      return 1;
    }
    tell_object(this_object(),
    "You follow "+leader->query_name()+"...\n\n");
    tell_room(env_l,
    cap_name+" arrives following "+leader->query_name()+".\n", ({ leader }));
    tell_object(leader, cap_name + " arrives following you.\n");
    move_object(this_object(), env_l);
    if(!brief) command("look");
    tell_room(env_m,
    cap_name+" leaves following "+leader->query_name()+".\n");
    call_out("do_follow",4);
    return 1;
}

status
query_follower(string str)
{
    if(!followers) followers = ({ });
    if(member_array(str, followers) != -1) return 1;
    else return 0;
}


