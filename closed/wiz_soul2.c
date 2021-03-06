/*
 *
 * Nirvana WizSoul XV
 * Started: 8-26-2003
 * A re-written version of Nirvana's original wizard soul
 * Editor: Vertebraker@Nirvana <tmieczkowski@hotmail.com>
 * Contributors have included Boltar and Shadowhawk...
 *
 */

inherit "/closed/wiz/unixcmds/_rm";
inherit "/closed/wiz_soul/ls";
inherit "/closed/wiz_soul/echo_channel";

#include <security.h>

#include "/closed/handshake.h"
#include "/closed/wiz_soul/run.c"
object myself, talkee, grantee;
#include "/closed/verte/qt/soul_inc.h"
#include "/obj/soul_com.c"


string pcheck, msgin, msgout, mmsgin, mmsgout, msghome, name, cap_name,
       it, title, al_title, wkrm, dir_to_clear, log, pwd, castle;
int    is_invis, level, alignment, muffled, time_shut, errormsgs;
int    soul_light;
       

void reset(status x)
{
 string myName;

 if(x) return;

 soul_reset(x);

/*
 pcheck= "tJRL3c2ilqvlg";
 pcheck = "VEINC8wKJd/wY";
*/
  pcheck = "BozZqyY6uZw9U";
 if((myself=this_player()) && (myName = (string)myself->query_real_name()))
  restore_object("pfiles/"+myName[0..0]+"/"+myName);

 call_out("update_inventory", 2);
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

void init()
{
 if(myself != this_player())
  return;

 soul_init();

 if((int)this_player()->query_level() < APPRENTICE)
  return destruct(this_object());

 castle = "/players/"+name+"/castle";
 log    = "/log/"+name;

 if(this_player())
  pwd = (string)this_player()->get_path();
 if(!pwd)
 {
  pwd = "/players/"+name+"/";
  if(myself)
   myself->set_pwd(pwd);
 }
 
 soul_init();
/*
 add_action("imprison", "imprison");
*/
 add_action("cmd_rm", "rm");
 add_action("emote"); add_xverb(":");
/*
 add_action("free_prisoner", "free");
*/
/*
 add_action("remove_file",   "rm");
 add_action("cmd_clear_dir", "clear_dir");
 add_action("rename_file", "mv");
 add_action("copy_file",   "cp");
*/
 add_action("edit", "ed");
/*
*/
 add_action("cd", "cd");

 if (level >= SENIOR)
 {
  add_action("grant_level", "promote");
  add_action("work", "work");
  add_action("approve", "approve");
 }

 if (level >= SHUTDOWN)
 {
  add_action("shut_down_game", "shutdown");
  add_action("adjust_time",  "time");
 }

 if (level >= OUT_OF_BODY)
 {
  add_action("in_room", "in");
  add_action("at_player", "at");
 }

 if (level >= ITEM_OVER)
 {
  add_action("power_trans", "trans!");
  add_action("power_get",   "get!");
  add_action("power_drop",  "drop!");
  add_action("power_put",   "put!");
  add_action("power_give",  "give!");
 }

  add_action("exec_code", "exec");
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
}

/* Restrict this, no sense in having it public .. */

mixed shut_down_game(string str)
{
 if(level < SHUTDOWN)
  return 0;
 if(!str) str = "5";
 else if(lower_case(str) == "now")
  return shutdown();
 else if(sscanf(str, "%d", time_shut) != 1)
 {
  write("Not a valid time.\n");
  return 1;
 }

 shout("!Game is being shut down by "+cap_name+" in "+
  str+" minutes.\n");
 write("Game will shut down in "+time_shut+" minutes.\n");
 log_file("SHUTDOWN",
  "Game is being shut down by " + capitalize(name)+
  " in "+str+" minutes.\n");
 "/obj/shut"->shut(time_shut);
 return 1;
}

/* Fun with power movement !
   Left in for solidarity  .. */

power_trans(str) { return trans("! "+str); }
power_get(str)   { return (int)this_player()->pick_up("! "+str); }
power_drop(str)  { return (int)this_player()->drop_thing("! "+str); }
power_put(str)   { return (int)this_player()->put("! "+str); }
power_give(str)  { return (int)this_player()->give_object("! "+str); }

/* the old, clunky trans function.  Not totally necessary,
   but didn't feel like adding power support to
   _trans.c .. */

int trans(string str)
{
  object ob;
  string out,power;

  if (!str || level < CONTROL)
    return 0;
  if (level >= ITEM_OVER)
    if (sscanf(str,"! %s",power) == 1)
      str = power;
  ob = find_player(str);
  if (!ob) ob = find_living(str);
  if (!ob) {
    write("No such living thing.\n");
    return 1;
  }
  it = str;

  tell_object(ob, "You are magically transfered somewhere.\n");

  if(!(out = (string)ob->query_mmsgout()))
   out = (string)ob->query_name()+" disappears in a puff of smoke.\n";
  else
   out = (string)ob->query_name()+" " + out + ".\n";

  tell_room(environment(ob), out);

  if(!(out = (string)ob->query_mmsgin()))
   out = (string)ob->query_name()+" arrives in a puff of smoke.\n";
  else
   out = (string)ob->query_name()+" "+out+".\n";

  tell_room(environment(this_player()), out);

  if(power)
   move_object(ob, this_player());
  else
   move_object(ob, environment(this_player()));

  return 1;
}

/* dest_inv is called by other objs as well .. 
   simply refurbished and left in ..           */

void destruct_inventory()
{
 object ob, next_ob;
 string it;

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

/* static fun.. for obvious reasons */

int remove_file(string str)
{
 string check,file;
 if (level < CREATE) return 0;
 if (!str)
 {
  write("Usage: 'rm <file>'\n");
  return 1;
 }
 sscanf(str, "%s %s", str, check);
 if(this_object()->check_me(str, check)) return 1;
 rm(str);
 return 1;
}

/* some gets 'n sets .. */

void set_msgin(string x) { msgin = x; }
void set_mmsgin(string x) { mmsgin = x; }
void set_msgout(string x) { msgout = x; }
void set_mmsgout(string x) { mmsgout = x; }
void set_msghome(string x) { msghome = x; }
void set_al_title(string x) { al_title = x; }
void set_alignment(int x) { alignment = x; }
void set_muffled(int x) { muffled = x;  myself->update(6); }

int query_invis() { return is_invis; }
string query_msgin() { return msgin; }
string query_mmsgin() { return mmsgin; }
string query_msgout() { return msgout; }
string query_mmsgout() { return mmsgout; }
string query_msghome() { return msghome; }
string query_al_title() { return al_title; }
int query_alignment() { return alignment; }
int    query_muffled()  { return muffled; }
status ghost() { return (int)this_player()->query_ghost(); }

/* SET_HANDSHAKE code dictates this be left alone .. */

in_room(str)
{
    object room;
    object old_room;
    string cmd;
    if (level < OUT_OF_BODY)
	return 0;
    if (!str || sscanf(str, "%s %s", room, cmd) != 2) {
	notify_fail("Usage: 'in <file> <cmd>'\n");
	return 0;
    }
    room = valid_read(room);
    if (!room) {
	notify_fail("Invalid file name.\n");
	return 0;
    }
    old_room = environment(myself);
    move_object(myself, room);
    SET_HANDSHAKE(cmd);
    call_other(myself,"remote_cmd",handshake);
    move_object(myself, old_room);
    return 1;
}

at_player(str)
{
    object other_player;
    object old_room;
    string cmd, who;
    if (!str || level < OUT_OF_BODY)
	return 0;
    if (sscanf(str, "%s %s", who, cmd) != 2) {
	write("Usage: 'at <player> <cmd>'\n");
	return 1;
    }
    other_player = find_living(who);
    if (!other_player) {
      write("There is no living creature named " + who + ".\n");
      return 1;
    }
    old_room = environment(myself);
    move_object(myself, environment(other_player));
    SET_HANDSHAKE(cmd);
    call_other(myself,"remote_cmd",handshake);
    move_object(myself, old_room);
    return 1;
}


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

/* New _light cmd allows for near infinite light sources
   and resetting on the fly .. */

int query_soul_light() { return set_light(0); }

void set_soul_light(int x)
{
 int curr_light;
 
 curr_light = set_light(0);

 set_light(-curr_light);

 if(x)
  set_light(x);
 soul_light = x;
}

/* Promotion stuff.. left untouched. */

grant_level(str) {
    int rec_lev;
    
   if (!str) {
   write ("You must name someone.\n");
   return 1;
   }
    grantee = present(str,environment(myself)) /*find_player(str)  uncomment when command avail*/;
    if (!grantee) {
        write(str+" is not within range.\n");
	return 1;
    }
    rec_lev = call_other(grantee,"query_level",0);
    if (rec_lev >= GOD) {
        write("You can't mess with a god!\n");
	return 1;
    }
    if (rec_lev > level) {
        write("You can't change a more powerful wizard!\n");
	return 1;
    }
    if (level < SENIOR) {
        write("You are still a junior wizard and can't grant power!\n");
	return 1;
    }
    if ((level < GOD && rec_lev >= ELDER) ||
        (level < ELDER && rec_lev >= SENIOR)) {
	    write("You may not grant power to your peers\n");
	    return 1;
    }
    write("What level do you want to grant "+str +"?\n"+
          str + " is level "+rec_lev+" now.\n");
    input_to("grant_level2");
  return 1;
}

grant_level2(str) {
    int rec_lev;
    if (!str) {
        grantee = 0;
	write("Aborted.\n");
	return 1;
    }
    if (!grantee || this_player() != myself) {
        write("Level setting eror.\n");
	illegal_patch("grant_level2");
    }
    sscanf(str,"%d",rec_lev);
    if (!rec_lev) {
        write("Invalid integer.\n");
	return 1;
    }
    if(grantee->query_level() > 20 && rec_lev<20 && level < ELDER) {
        write("Only a god can take away wizard status");
	return 1;
    }
    if ((level < GOD && rec_lev >= ELDER) ||
        (level < ELDER && rec_lev >= SENIOR)) {
	    write("You may not promote someone to the status of a peer"+
	          " or higher.\n");
 	    return 1;
    }
    SET_HANDSHAKE(str);
    call_other(grantee,"set_wiz_level",handshake);
    write("level "+str+" granted.\n");
    tell_object(grantee, "soul off / soul on to enjoy your new abilities.\n");
    grantee->save_me(1);
    return 1;
}

string valid_read(string str)
{
 return (string)myself->valid_read(str);
}

string valid_write(string str)
{
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

string query_log() { return log; }
void set_log(string x) { log = x; }

void set_castle(string x) { castle = x; }
string query_castle()     { return castle; }

int work(string str)
{
 if (level < SENIOR) return 0;
 if (!str) str=name;
 write("Working on the property of: "+capitalize(str)+".\n");
 pwd = "/players/"+str+"/";
 castle = "/players/" + str + "/castle";
 log = "/log/"+str;
 myself->set_pwd(pwd);
 return 1;
}

int cd(string str)
{
 int qqq;
 string temp,junk;
 if (level < CREATE) return 0;
 qqq = 0;
 if(!str) 
  str = "~";
 if (str == "..")
 {
  int i;
  qqq = 1;
  i = strlen(pwd) - 2;
  while(i > 0 && pwd[i] != '/')
   i -= 1;
  if (!i)
   str = "/";
  else
  {
   str = pwd[0..i-1];
   if(pwd[0] != '/')
    str = "/"+str;
  }
 }
 if(str)
 {
  if(!qqq)
  {
   if (str == "~")
    str = "/players/" + name;
   if (sscanf(str,"~%s",temp))
    str = "/players/" + name + temp;
  }
  if(!(temp = (string)myself->valid_read(str+"/")))
  {
   write("Illegal path!\n");
   return 1;
  }
  if(file_size("/"+temp) != -2)
  {
   write("That directory does not exist.\n");
   return 1;
  }
  pwd = temp;
  myself->set_pwd(pwd);
 }
 write("pwd: "+pwd+"\n");
 return 1;
}

copy_file(str) {
    string check,src, dst;
    
    if(!str || sscanf(str, "%s %s", src, dst) != 2)
    {
     write("Usage: 'cp <file1> <file2>'\n");
     return 1;
    }
    sscanf(dst, "%s %s", dst,check);
    if(check_me(dst,check)) return 1;
    cp(src, dst);
    return 1;
}

rename_file(str) {
    string check,src, dst;
    
    if (sscanf(str, "%s %s", src, dst) != 2)
        return 0;
    if(!this_player()->valid_write(src))
    return 0;
    sscanf(dst, "%s %s", dst,check);
    if(check_me(dst,check)) return 1;
    if(check_me(src,check)) return 1;
    if(!this_player()->valid_write(dst))
    return 0;
    rename(src, dst);
    return 1;
}

query_alt_wkrm() {return wkrm; }
set_alt_wkrm(x) { wkrm = x; }

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

#define DUMMY_FILE "/players/"+myself->query_real_name()+"/exec_temp.c"

exec_code(str)
{
    object ob;
    string tsp1, tsp2, err;
    mixed  mixedResult;

    rm(DUMMY_FILE);

    if(this_player()->query_real_name() != "boltar" &&
         (sscanf(str,"snoop%s",tsp1)==1 ||
          sscanf(str,"%ssnoop%s",tsp1,tsp2)==2))
      {
        write("Failed.\n");
        return 1;
      }

    while(find_object(DUMMY_FILE)) destruct(find_object(DUMMY_FILE));


    write_file(DUMMY_FILE,"#include <ansi.h>\nexec_function()\n{\n"+str+"\n}\n");

  if(!errormsgs)
  {
    if(err = catch(ob = clone_object(DUMMY_FILE)))
      return (write(err + "\n"), 1);
    ob->exec_function();
  }


   else
    ob->exec_function();
/*
    if(!errormsgs)
    if(err = catch(mixedResult = ob->exec_function())) return (write(err + "\n"), 1);
    else mixedResult=ob->exec_function();
*/
    write("Returned : " + mixedResult + "\n");
    while(find_object(DUMMY_FILE)) destruct(find_object(DUMMY_FILE));
    rm(DUMMY_FILE);
    return 1;
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

imprison(arg) {
  string prisoner,reason;
  string aload;
  object pris;
  if(!arg || sscanf(arg,"%s %s",prisoner,reason) != 2) {
    write("Usage: 'imprison <victim> <reason>\n");
    return 1;
   }
  pris=find_player(prisoner);
  if(!pris) {
    write("Cannot find "+prisoner+".\n");
    return 1;
  }
  if(this_player()->query_level() < pris->query_level()+1) {
    write("You cannot imprison "+prisoner+".\n");
    return 1;
   }
  pris->move_player("in bright flash of light#room/prison/dump");
  command("drop all", pris);
  write("Forcing prisoner to drop all objects in /room/prison/dump\n");
  pris->move_player("in bright flash of light#room/prison");
  tell_object(pris, "You have been imprisoned.\n");
  log_file("PRISON", prisoner+" imprisoned by "+this_player()->query_real_name()+" for "+reason+" "+ctime(time())+"\n");
   pris->set_home("/room/prison");
   pris->save_me();
   aload = pris->send_auto_load();
   call_other("room/prison/item_storage", "set_autol", aload);
   call_other("room/prison/item_storage", "set_filen", prisoner);
   call_other("room/prison/item_storage", "save_me", 0);
   pris->add_prison("PRISON%"+this_player()->query_real_name());
   pris->destruct_inventory();
   write("Prisoner autoloads saved, remaining inventory destructed.\n");
   pris->save_me();
   call_other("/room/prison","add_prisoner",prisoner,this_player()->query_real_name());
  write("You have imprisoned "+prisoner+"\n");
  return 1;
}
free_prisoner(arg) {
  string prisoner, reason;
  string autol;
  object pris;
  if(!arg || sscanf(arg,"%s %s",prisoner,reason) != 2) {
    write("Usage: 'free <victim> <reason>'\n");
    return 1;
   }
  pris=find_player(prisoner);
  if(!pris) {
    write("Cannot find "+prisoner+".\n");
    return 1;
  }
  if(object_name(environment(pris))!="room/prison") {
    write(prisoner+" is not in prison.\n");
    return 1;
   }
  pris->move_player("in bright flash of light#room/police");
  call_other("room/prison/item_storage", "set_filen", prisoner);
  call_other("room/prison/item_storage", "restore_me", 0);
  autol=call_other("room/prison/item_storage", "send_autol", 0);
  if(autol) {
  pris->receive_auto_load(autol);
  pris->load_auto_obj(autol);
  write("Prisoner autoloads restored.\n");
  }
  pris->save_me();
  tell_object(pris, "You have been released from prison.\n");
  log_file("PRISON", prisoner+" released by "+this_player()->query_real_name()+" for "+reason+" "+ctime(time())+"\n");
   pris->set_home(0);
   if(call_other("/room/prison","free_prisoner",prisoner))
  write("You have released "+prisoner+"\n");
   else write("You cannot release "+prisoner+"\n");
  return 1;
}

int
cmd_clear_dir(string str)
{
    string directory;

    if(!str) directory = (string)this_player()->get_path();
    else directory=resolv_path(str + "/");
   
    if(file_size(directory) != -2)
      return (notify_fail("\
Unable to properly clear_dir...\n\
String is not a directory.\n"), 0);
    dir_to_clear=directory;
    write("Are you SURE you want to remove all files in: " + directory + " ?\n");
    input_to("okay_clear_it");
    return 1;
}

int
okay_clear_it(string arg)
{
    string directory;
    int x;
    string *files;
    object poop;

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
        remove_file(directory + files[x]);
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
  
query_errormsgs() { return errormsgs; }
set_errormsgs(x) { errormsgs = x; }

more(str)
{
 return (int)"/bin/wiz/_more"->cmd_more(str);
}
emote(str){
  if(!str)
    return 0;
 str = format(str,60);
  write("You "+str+"\n");
  say(call_other(this_player(), "query_name", 0) + " "+ str +"\n");
  return 1;
}
