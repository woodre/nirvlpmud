/* nimh rat gobj */

#include "x.h"

inherit N_EFUN;

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

/* inclusive spell array */
mixed *spells;

/* special attribs */
int arcana;

/* racial skills */
status feline_sense;
static object *felines_present;
static string glowing_eyes;

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
 spells = ({ });
 felines_present = ({ });

 sponsorees = ({ });
 set_heart_beat(1);
}

void heart_beat()
{
 if(!ENVTO) return destruct(TO);

 if(!ENV(ENVTO) || !interactive(ENVTO)) return;


 beats ++;
 ENVTO->set_race("rodent");
 MASTER->feline_sense(TO, ENVTO);
 if(sizeof(felines_present))
 {
  if(!random(20))
   TL(ENVTO, HIR+"[FELINE SENSE]"+NORM+" You are on guard in the presence of a "+HIK+"FELINE"+NORM+"!\n");
 }
}

void extra_look()
{
 if(ENVTO == TP)
 {
  write("You are a "+BOLD+"Rat of NIMH"+NORM+"!\n");
  write("You have a long, thin tail.\n");
  write("You have strong front teeth.\n");
  write("Your body is covered with soft, brown fur.\n");
  if(glowing_eyes)
   write("Your eyes are glowing "+a_or_an(glowing_eyes)+" "+str_to_ansi(glowing_eyes)+glowing_eyes+NORM+" color.\n");
  if(sizeof(felines_present))
   write("Your ears are perked up.\n");
 }
 else
 {
  string tmp;
  tmp = (string)ENVTO->QN;
  if((string)TP->query_guild_name() == GUILDNAME)
   write(tmp+" is a fellow "+BOLD+"Rat of NIMH"+NORM+"!\n");
  write(tmp+" has a long, thin tail.\n");
  write(tmp+"'s front teeth jut out slightly.\n");
  write(tmp+" has soft brown fur covering "+possessive(ENVTO)+" body.\n");
  if(glowing_eyes)
   write(tmp+"'s eyes are glowing "+a_or_an(glowing_eyes)+" "+str_to_ansi(glowing_eyes)+glowing_eyes+NORM+" color.\n");
  if(sizeof(felines_present))
   write(tmp+"'s ears are perked up.\n");
 }
}

status id(string str)
{
 return (str=="gob"||str=="guild_object"||
         str==OBJID||str=="no_mini");
}

string short()
{
 if(TP && IS_NIMH_TESTER(TP))
 {
  return "nimh_rat_object";
 }
}

void init()
{
 string *b; int a;
 if(!ENVTO) return;
 if(!load)
 {
  load ++;
/*
  if((int)ENVTO->QL < APPRENTICE)
*/
   ENVTO->set_guild_file(0);
   ENVTO->set_guild_name(GUILDNAME);


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
 }
/*
 add_action("cmd_say",    "say");
 add_action("cmd_say"); add_xverb("'");
 add_action("cmd_say"); add_xverb("\"");

 add_action("cmd_tell",   "tell");

 add_action("cmd_emote",  "emote");
 add_action("cmd_emote"); add_xverb(":");
*/
 a = sizeof(b = get_dir(N_BIN));
 while(a --)
  if(sscanf(b[a],"_%s.c",b[a]))
  add_action("cmd_hook", b[a]);
}

void save_me()
{
 if(ENVTO)
  save_object(N_SAVE+(string)ENVTO->RN);
 else if(TP)
  save_object(N_SAVE+(string)TP->RN);
}

void backup_me()
{
 if(ENVTO)
  save_object(N_BACKUP+(string)ENVTO->RN);
 else if(TP)
  save_object(N_BACKUP+(string)TP->RN);
}

void restore_me()
{
 if(ENVTO)
  restore_object(N_SAVE+(string)ENVTO->RN);
 else if(TP)
  restore_object(N_SAVE+(string)TP->RN);
}

int drop() { return 1; }
int get()  { return 1; }  /* for cloning purposes */

object * query_felines_present() { return felines_present; }
void set_felines_present(object *x) { felines_present = x; }
status query_chan_muffle() { return chan_muffle; }
void set_chan_muffle(status x) { chan_muffle = x; }
string query_login_msg() { return login_msg; }
void set_login_msg(string x) { login_msg = x; }
string query_logout_msg() { return logout_msg; }
void set_logout_msg(string x) { logout_msg = x; }
string query_glowing_eyes() { return glowing_eyes; }
void set_glowing_eyes(string x) { glowing_eyes = x; }

void remove_object()
{
 if(ENVTO)
 {
  save_me();
  MASTER->delete_rat(ENVTO);
  if(genshadow) genshadow->end_shadow();
 }
 if(!ENVTO) MASTER->delete_rat(0);
}

int cmd_hook(string str)
{
 return (int)call_other(N_BIN+"_"+query_verb(), "cmd_"+query_verb(), str);
}

void mini_dest(string str)
{
 write("\n\
  A voice rumbles:\n\
      As a Rat of NIMH, you owe NO allegiance to miniguilds!\n\n");
}

string query_auto_load()
{
 return OBJFILE+":0";
}

mixed init_arg(mixed x)
{
 TO->restore_me();
 if(!MASTER->query_rat(TP)) MASTER->add_rat(TP);
 MASTER->broadcast(login_msg, 1);
}

void light_up(int x)
{
 set_light(x);
}

int query_prevent_shadow()
{
 return 1;
}
