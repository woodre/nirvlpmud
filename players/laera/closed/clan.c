#include "/players/vertebraker/define.h"

#define Allowed ({ "vital", "maledicta", "softly", "fred", "vertebraker" })

int privacy;

status id(string str) 
{
    return str == "vertefakirdicta" || str == "symbol"; 
}

string short()
{
    return "A dark symbol of the WizClan";
}

status drop() { return 1; }

status get() { return 1; }

void init()
{
    add_action("tell_us","clan",2);
    add_action("hist_cl", "clhistory");
    add_action("priv_mode", "privacy_mode");
}

status
priv_mode()
{
    if(privacy)
    { 
      write("Privacy mode "+HIB+"OFF"+NORM+"\n");
      privacy = 0; return 1; 
    }
    else
    { 
      write("Privacy mode "+HIR+"ON"+NORM+"\n");
      privacy = 1; return 1; 
    }
}


hist_cl()
{ 
    write(HIR+"Clan History:"+NORM+"\n");
    tail("/players/maledicta/history"); 
    return 1;
}

msg_us(str);

int tell_us(string str)
{
   string name;
   if(!str)
      {
      write("Clan <msg>\n");
      return 1;
   }
   name = (string)TPRN;

   if(name == "vertebraker") name = "v";

   if(str[0] == ':') msg_us(RED+"[wizclan]"+NORM+" "+CAP(name) + " " +
 NORM + str[1..(strlen(str) -1)] + NORM + "\n");
   else msg_us(RED+"[wizclan]"+NORM+" "+CAP(name)+" says: " + NORM + str +
NORM +"\n");
   return 1;
}


int msg_us(string str)
{
  int s;
  object x;
  if(privacy) str = HIB+"(P)"+NORM+str;
  s = sizeof(Allowed);

  while(s--)
    if(x = find_player(Allowed[s]))
      tell_object(x, str);

  if(!privacy)
    write_file("/players/maledicta/history", str);

   return 1;
}

long()
{
   write("A symbol of your devotion to the wizclan.\n"+
         "'clhistory' for a history of the channel.\n"+
         "'privacy_mode' will turn on privacy for no history recording.\n"+
      "You can 'clan' <msg> to tell the clan a message.\n");
}

query_auto_load() { return "/players/maledicta/closed/clan:"; }
