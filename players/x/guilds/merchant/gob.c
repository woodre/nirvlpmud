/* Merchant gobj */

#include "x.h"

static status load;

/*  .... diagnostic tracking ....  */
int    times_died;
int    beats;
int    kills;
int    player_kills;
string big_kill_name;
int    big_kill_exp;

/* history */
string sponsor;
string *sponsorees;
string join_date;

/* GC ? */
string class;

/* channel features */
static int chan_muffle;
string login_msg;
string logout_msg;

/* genshadow */
static object genshadow;

void reset(status x)
{
 if(x) return;
 if(root())
 {
  call_other(MASTER, "???");
  return;
 }
 /* set_heart_beat(1); */
}

/*
void heart_beat()
{
 if(!ENVTO) return destruct(TO);

 if(!ENV(ENVTO) || !interactive(ENVTO)) return;

 beats ++;
}
*/

void extra_look()
{
 if(ENVTO == TP)
 {
  write("You are a member of the "+HIY+"Merchant's Guild"+NORM+".\n");
 }
 else
 {
  string tmp;
  tmp = (string)ENVTO->QN;
  if((string)TP->query_guild_name() == GUILDNAME)
   write(tmp+" is a fellow member of the "+HIY+"Merchant's Guild"+NORM+".\n");
 }
}

status id(string str)
{
 return (str=="gob"||str=="guild_object"||str==OBJID||
         str=="coin"||str=="gold coin");
}

string short()
{
 string x;
 x = "An emblazoned "+HIY+"gold coin"+NORM;
 if(TP == ENVTO)
  x += " ["+HIY+"MGoN"+NORM+"]";
 return x;
}

void init()
{
 string *b; int a;
 if(!ENVTO) return;
 if(!load)
 {
  load ++;
  ENVTO->set_guild_file(0);
  ENVTO->set_guild_name(GUILDNAME);

/*
  if(!ENVTO->query_nimh_genshadow())
  {
   genshadow = CO(N_OBJ+"genshadow");
   tell_object(ENVTO, HIG+"Starting shadow...\n"+NORM);
   genshadow->start_shadow(ENVTO);
   if(ENVTO->query_nimh_genshadow())
    tell_object(ENVTO, HIG+"SHADOW ON\n"+NORM);
   else
    tell_object(ENVTO, HIR+"SHADOW OFF\n"+NORM);
  }
*/
 }
 a = sizeof(b = get_dir(M_BIN));
 while(a --)
  if(sscanf(b[a],"_%s.c",b[a]))
  add_action("cmd_hook", b[a]);
}

void save_me()
{
 if(ENVTO)
  save_object(M_SAVE+(string)ENVTO->RN);
 else if(TP)
  save_object(M_SAVE+(string)TP->RN);
}

void backup_me()
{
 if(ENVTO)
  save_object(M_BACKUP+(string)ENVTO->RN);
 else if(TP)
  save_object(M_BACKUP+(string)TP->RN);
}

void restore_me()
{
 if(ENVTO)
  restore_object(M_SAVE+(string)ENVTO->RN);
 else if(TP)
  restore_object(M_SAVE+(string)TP->RN);
}

int drop() { return 1; }
int get()  { return 1; }  /* for cloning purposes */

status query_chan_muffle() { return chan_muffle; }
void set_chan_muffle(status x) { chan_muffle = x; }
string query_login_msg() { return login_msg; }
void set_login_msg(string x) { login_msg = x; }
string query_logout_msg() { return logout_msg; }
void set_logout_msg(string x) { logout_msg = x; }

void remove_object()
{
 if(ENVTO)
 {
  save_me();
  MASTER->delete_merchant(ENVTO);
  if(genshadow)
   genshadow->end_shadow();
 }
 if(!ENVTO) MASTER->delete_merchant(0);
}

int cmd_hook(string str)
{
 return (int)call_other(M_BIN+"_"+query_verb(), "cmd_"+query_verb(), str);
}


string query_auto_load()
{
 return OBJFILE+":0";
}

mixed init_arg(mixed x)
{
 TO->restore_me();
 if(!MASTER->query_merchant(TP)) MASTER->add_merchant(TP);
 MASTER->broadcast(login_msg, 1);
}

int query_prevent_shadow()
{
 return 1;
}
