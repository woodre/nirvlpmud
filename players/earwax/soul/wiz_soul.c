/*
 *
 * Nirvana WizSoul XV
 * Started: 8-26-2003
 * A re-written version of Nirvana's original wizard soul
 * Editor: Vertebraker@Nirvana <tmieczkowski@hotmail.com>
 * Contributors have included Boltar and Shadowhawk...
 *
 */

inherit "/bin/wiz/secure/ls";
inherit "/bin/wiz/secure/echo_channel";

#include <security.h>

#include "/closed/handshake.h"
object myself, talkee;
#include "/closed/verte/qt/soul_inc.h"
#include "/obj/soul_com.c"

#include "/sys/temp.h"

string pcheck, name, cap_name, it, title, wkrm, dir_to_clear, log, pwd, castle;
int    is_invis, level, time_shut, muffled, errormsgs;
static status flag_init;
       
void log_use(string fun) {
  object ob;
  ob = previous_object();
  log_file("WSOUL", ctime()+": "+fun+" called in "+name+" by "+(ob ? file_name(ob) : "unknown (no prev-ob)")+".\n");
}

void reset(status x)
{
 string myName;

 if(x) return;

 soul_reset(x);

/*
 pcheck= "tJRL3c2ilqvlg";
*/
 pcheck = "VEINC8wKJd/wY";
 if((myself=this_player()) && (myName = (string)myself->query_real_name()))
  restore_object("pfiles/"+myName[0..0]+"/"+myName);

 call_out("update_inventory", 2);
}


void init()
{
 if(myself != this_player()) return;

 if((int)this_player()->query_level() < APPRENTICE)
  return destruct(this_object());

  if (!flag_init)
  {
    castle = (string)this_player()->query_castle();
    log = (string)this_player()->query_log();

    if(this_player())
      pwd = (string)this_player()->get_path();

    if(!pwd)
    {
      pwd = "/players/"+name+"/";
      if(myself)
        myself->set_pwd(pwd);
    }
  }

 soul_init();

  if (DR_RUNNING)
  {
/*
    add_action("cmd_rm", "rm");
*/
    add_action("edit", "ed");
    add_action("emote"); add_xverb(":");
  }

 if (level >= SENIOR)
 {
  add_action("work", "work");
  add_action("approve", "approve");
 }

 if (level >= SHUTDOWN)
 {
  add_action("adjust_time",  "time");
 }

 if (level >= SNOOP)
 {
  add_action("snoop_on", "snoop");
 }

 if (level >= INVIS)
 {
  add_action("invis", "invis");
  add_action("vis","vis");
 }
  
 qt_actions();
  flag_init = 1;
}

int cmd_rm(string arg) { return (int)"/bin/wiz/_rm"->cmd_rm(arg); }


/* dest_inv is called by other objs as well .. 
   simply refurbished and left in ..           */

void destruct_inventory()
{
 object ob, next_ob;
 string it;

  log_use("destruct_inventory");
 ob = first_inventory(myself);
 while(ob)
 {
  next_ob = next_inventory(ob);
  it = (string)ob->short();
  if(!ob->id("ND"))
  {
   destruct(ob);
   write("destruct: "+it+".\n");
  }
  ob = next_ob;
 }
}

/* again, no sense in making this public and|or
   incidentally releasing the SET_HANDSHAKE code .. */

int snoop_on(string str)
{
  string nm, reez;
log_use("snoop_on");
  if (level < SNOOP) return 0;
  if(str)
  if(level < GOD && !("/pa/admin/pa-daemon"->query_name(name)) &&
     sscanf(str, "%s %s", nm, reez) < 2) {
    write("Usage: 'snoop <who> <reason>'\n");
    return 1;
  }
  write("Snooping "+nm+" for: "+reez+"\n");
  if(str)
    if(!nm) nm = str;
  SET_HANDSHAKE(nm);
  this_player()->remote_snoop(handshake,reez);
  return 1;
}

/* this special invis has to be restricted to the object
   so that special forms of invisibility are avoided...
   otherwise it would have to be a static function and
   what's the fun in that? */

int invis(string str)
{
 int invis;
    
 if (level < INVIS) return 0;
 if (str)
    sscanf(str,"%d",invis);
 else
    invis = 100;
 if (level < 99999 && invis < 0)
   return 0;
 if (!invis) return 0;
 if (invis >= 100 && level < ALL_POWER)
    invis=100;
 if (invis >= INV7 && level < CINV7) invis = INV7 - 1;
 if (invis >= INV6 && level < CINV6) invis = INV6 - 1;
 if (invis >= INV5 && level < CINV5) invis = INV5 - 1;
 if (invis >= INV4 && level < CINV4) invis = INV4 - 1;
 if (invis >= INV3 && level < CINV3) invis = INV3 - 1;
 if (invis >= INV2 && level < CINV2) invis = INV2 - 1;
 if (invis >= INV1 && level < CINV1) invis = INV1 - 1;
 is_invis = invis;
 myself->update(5);
 write("You are now invisible = "+is_invis+".\n");
 if (is_invis < INVIS_ACTION) 
   this_player()->remote_say(cap_name+" disappears.\n");
 if (is_invis >= SOMEONE) cap_name = "Someone";
 return 1;
}

int vis()
{
 if (level < INVIS) return 0;
 if (!is_invis)
 {
  write("You are not invisible.\n");
  return 1;
 }
 is_invis = 0;
 this_player()->update(5);
 if((int)this_player()->query_visible()) /* force this, annoying "Someone" bug */
  command("visible", this_player());
 write("You are now visible.\n");
 cap_name = capitalize(name);
 this_player()->remote_say(cap_name+" appears in a puff of smoke.\n");
 return 1;
}

void set_muffled(int x) { muffled = x;  myself->update(6); }

int query_invis() { return is_invis; }
int    query_muffled()  { return muffled; }
status ghost() { return (int)this_player()->query_ghost(); }

/* SET_HANDSHAKE code dictates this be left alone .. */

edit(file)
{
string check;
    if (level < CREATE) return 0;
    if (!file) {
	write("Edit what file ?\n");
	return 1;
    }
    sscanf(file, "%s %s", file, check);
    if(file=="here") file=basename(environment(this_player()))+".c";
    if(check_me(file,check)) return 1;
    myself=this_player();
    SET_HANDSHAKE(file);
    call_other(myself,"remote_ed",handshake);
    return 1;
}

string valid_read(string str)
{
log_use("valid_read");
 return (string)myself->valid_read(str);
}

string valid_write(string str)
{
log_use("valid_write");
 return (string)myself->valid_write(str);
}

void update(int num)
{
 if(num == 1)
  level = (int)myself->query_level();
}

adjust_time(new_time) {
    string str;
    int temp;
    
    if (level < SHUTDOWN) return 0;
    if (!new_time) {
      write(time_shut/1200 + ":"+(time_shut%1200)/20+":"+(time_shut%20)*3+" left to shutdown.\n");
	return 1;
    }
    str = new_time;
    if (!str) str = "5";
    if (lower_case(str) == "now") shutdown();
    if (sscanf(str,"%d",temp) != 1) {
        write("Not a valid time.\n");
        return 1;
    }
    time_shut = temp;
    write("Shutdown rescheduled for " + time_shut + " minutes.\n");
    shout("Shutdown rescheduled for "+time_shut+" minutes.\n");
    log_file("SHUTDOWN","Shutdown rescheduled for "+time_shut+" minutes.\n");
    time_shut *= 20;
    return 1;
}

string query_log() { log_use("query_log"); return (string)myself->query_log(); }
void set_log(string arg) { log_use("set_log"); myself->set_log(arg); log = "/log/" + arg; }

string query_castle() { log_use("query_castle"); return (string)myself->query_castle(); }
void set_castle(string arg) { log_use("set_castle"); myself->set_castle(arg); castle = "/players/"+arg+"/castle"; }

int work(string str)
{
log_use("work");
 if (level < SENIOR) return 0;
 if (!str) str=name;
 write("Working on the property of: "+capitalize(str)+".\n");
 pwd = "/players/"+str+"/";
  set_castle(str);
  set_log(str);
 myself->set_pwd(pwd);
 return 1;
}

query_alt_wkrm() {log_use("query_alt_wkrm"); myself->query_alt_wkrm(); }
set_alt_wkrm(x) { log_use("set_alt_wkrm"); wkrm = x; 
myself->set_alt_wkrm(x); }

check_me(str,check){
    if(check_standard(str) && !check){
        write("Access Denied.\n");
        return 1;
    }
    if(check_standard(str) && !check_auth(check))
     {
        write("Access Denied.\n");
        return 1;
    }
    return 0;
}

check_standard(str) {
     if(extract(pwd,0,3)=="room" ||
        extract(pwd,0,2)=="obj" ||
        extract(pwd,0,2)=="bin" ||
        extract(pwd,0,5)=="closed" ||
        extract(pwd,0,7)=="post_dir")
       return 1;
     if(extract(pwd,0,4)=="/room" ||
        extract(pwd,0,3)=="/obj" ||
        extract(pwd,0,3)=="/bin" ||
        extract(pwd,0,8)=="/post_dir" ||
        extract(pwd,0,6)=="/closed")
         return 1;
     if(extract(str,0,4)=="/room" ||
        extract(str,0,3)=="/obj" ||
        extract(str,0,3)=="/bin" ||
        extract(str,0,6)=="/closed")
       return 1;
     return 0;
}

int check_auth(string str)
{
 return (crypt(str, pcheck[0..1]) == pcheck);
}

approve(str) {
object appy;
   if(level < SENIOR) return 0;
   if(!str)
   {
    write("Usage: 'approve <player>'\n");
    return 1;
   }
   appy=find_player(str);
   if(!appy) { write(str+" is not logged on.\n"); return 1;}
   appy->add_aprv();
   return 1;
}


int remove_file(string str)
{
  string check, file;
log_use("remove_file");
  if (level < CREATE) return 0;
  if (!str) { write("Usage: 'rm <file>'\n"); return 1; }
  sscanf(str, "%s %s", str, check);
  if(this_object()->check_me(str, check)) return 1;
  rm(str);
  return 1;
}
int okay_clear_it(string arg)
{
    string directory;
    int x;
    string *files;
    object poop;

log_use("okay_clear_it");
    files = get_dir(directory=dir_to_clear);

    dir_to_clear=0;  if(arg != "y") return (notify_fail("Okay, you won't clear it then.\n"), 0);
    write("Clearing directory: " + directory + "\n");
    x=sizeof(files);
    while(x--)
    {
      if(strlen(files[x]) > 2)
      if(files[x][strlen(files[x]) - 2..strlen(files[x]) - 1] == ".c")
        if(poop = find_object(directory + files[x]))
          destruct(poop);
remove_file(directory+files[x]);
      }
    write("Removal complete.\n");
    return 1;
}


void update_inventory()
{
    object x;
    if((x=environment()) && x->is_player())
      move_object(this_object(), x);
    else return destruct(this_object());
    call_out("update_inventory", 2);
}
  
query_errormsgs() { 
  log_use("query_errormsgs");
  return myself->query_errormsgs(); 
}
void set_errormsgs(int x) {
  log_use("set_errormsgs");
  myself->set_errormsgs(); 
}

more(str)
{
  log_use("more");
 return (int)"/bin/wiz/_more"->cmd_more(str);
}
emote(str){
  if(!str)
log_use("emote");
    return 0;
 str = format(str,60);
  write("You "+str+"\n");
  say(call_other(this_player(), "query_name", 0) + " "+ str +"\n");
  return 1;
}
status get() { return 1; }
status drop() { return 1; }
status id(string str)
{
 return (str == "soul" || str == "wiz_soul" || str == "ND");
}

void long()
{
 write("Even wizard souls are transparent.\n");
}
