#include <security.h>

#include <user/dt_stamp.h>

#define TESTCHAR_DATA "/log/user/testChars.txt"
#define TIME_TO_UPDATE 1800

static string text;


void reset(status arg) {
  if(arg) return;
  text = read_file(TESTCHAR_DATA);
}

string * query_testchars(string nm)
{
  string *indices, a, b, c, newText, dt;
  indices = ({ });
  if(!text) text = read_file(TESTCHAR_DATA);
  newText = text;
  while(sscanf(newText,"%s\n%s",a,newText))
    if(stringp(a) && sscanf(a,"[%s]%s:%s",dt,b,c)==3 && nm==c)
      indices += ({b});
  return indices;
}

status query_prevent_shadow()
{
  return 1;
}

string query_owner(string nm)
{
  string newText, a, b, c, dt;
  if(!text) text = read_file(TESTCHAR_DATA);
  newText = text;
  while(sscanf(newText,"%s\n%s",a,newText))
    if(stringp(a) && sscanf(a,"[%s]%s:%s",dt,b,c)==3 && nm==b)
      return c;
  return 0; /* Rumplemintz */
}

status add_testchar(string nm)
{
  string wizNm;
  object targ;
  if(!nm)
    return (notify_fail("You must specify an argument.\n"), 0);
  if(!(targ=find_player(nm)))
    return(notify_fail(capitalize(nm)+" is not logged on.\n"),0);
  if(wizNm=query_owner(nm))
  {
    notify_fail(capitalize(nm)+" already belongs to "+
     (wizNm==(string)this_player()->query_real_name()?"YOU":
         capitalize(wizNm))+".\n");
    return 0;
  }
  if((int)this_player()->query_level() < ELDER)
  if(query_ip_number(targ) != query_ip_number(this_player()))
    return (notify_fail("\
For the initial registration, your prospective test character\n\
must be active from the computer you are using right now.\n"), 0);

  if(targ == this_player())
    return(notify_fail("\
You dork.\n\
You can't make YOURSELF a test character.\n\
What da hizell?\n"),0);
  write_file(TESTCHAR_DATA, "["+DTSTAMP+"]"+
    lower_case(nm)+":"+
    (wizNm=(string)this_player()->query_real_name())+"\n");
  emit_channel("wiz", "\
(wiz) "+capitalize(wizNm)+" registered "+capitalize(nm)+" as a"+
    " test character!\n");
  "/bin/wiz/_wlog"->cmd_wlog("\
Registered Test Character: "+capitalize(nm));
  text = read_file(TESTCHAR_DATA);
  /* added by illarion may 2005 */
  targ->testchar_check();
  write("Done.\n");
  return 1;
}

mapping query_info()
{
  mapping m;
  string a,b,c,newText,dt;
  m = ([ ]);
  if(!text) text = read_file(TESTCHAR_DATA);
  newText = text;
  while(sscanf(newText,"%s\n%s",a,newText))
    if(stringp(a) && sscanf(a,"[%s]%s:%s",dt,b,c)==3)
   {
      if(!m[c]) m[c] = ({ });
      m[c] += ({ b });
    }
  return m;
}
