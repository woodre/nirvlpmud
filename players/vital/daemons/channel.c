#include <ansi.h>
#include <security.h>
#include "/players/vital/closed/headers/channel.h"

string get_emotional(string channel, string msg);
string get_player_name(string channel);
int valid_channel(string channel);
int cmd_channel(string channel, string msg);

int
main(string str)
{
  string a, b;
  sscanf(str, "%s %s",a,b);
  cmd_channel(a, b);
  return 1;
}

int
cmd_channel(string channel, string msg)
{
  string verb, player_name, ansi;
  if(member_array(channel, ALL_CHANNELS) )
    if( !valid_channel(channel) )
    {
      tell_object(this_player(), "What?\n");
      return 1;
    }
  if(this_player())
  {
    if( !CHANNELD->query_channel(channel, this_player()) )
    {
      tell_object(this_player(), "You are not a member of the " + channel +
        " channel.\n");
      return 1;
    }
    if(!msg)
    { 
      tell_object(this_player(), "Hmm? Did you want to say something?\n");
      return 1;
    }
    if( !(player_name = get_player_name(channel)) )
      player_name = "";
  }
  if(msg[0] == ':')
  {
    msg = get_emotional(channel, msg);
    msg = "(" + channel + ")" + player_name + " " + msg + "\n";
    CHANNELD->channel_message(channel, msg);
    return 1;
  }
  else if(msg == "history")
  {
    CHANNELD->query_history(channel);
    return 1;
  }
  else if(msg == "list") /* this is screwed up */
  {
    string *talkers;
    int x, y;
    msg = "On channel " + channel + ": ";
    talkers = (array) CHANNELD->on_channel(channel);
    x = sizeof(talkers);
    tell_object(find_player("vital"), msg + "\n" + x + " members\n");
    if( !x && this_player())
    {
      tell_object(this_player(), "There is no one on that channel\n");
      return 1;
    }
    for(y = 0; y < x; y++)
    {
      msg += capitalize( (string) talkers[y]->query_real_name() );
      if( y < (x - 1) ) msg += ", ";
    }
    msg += "\n";
    tell_object(this_player(), msg);
    return 1;
  }
  msg = player_name + " " + channel + "s: " + msg + NORM + "\n";
  if( member_array(channel, CENSORED_CHANNELS) )
  {
    msg = (string)"/obj/verte/text_sanitizer"->sanitize_text(msg);
  }
  CHANNELD->channel_message(channel, msg);
  return 1;
}


/* The /bin/std.c will need code to just return the formated message */
string
get_emotional(string channel, string msg)
{
  string emotion, target, temp;
  temp = msg[1..strlen(msg)-1];
  sscanf(msg, "%s %s", emotion, target);
  if(emotion)
  {
    string a, b;
    while( sscanf(emotion, "%s.%s", a, b) )
    {
      if(!a) a = "";
      if(!b) b = "";
      emotion = ( a + b );
    }
  }
  if( file_size("/bin/soul/_" + emotion + ".c") > 1)
  {
/*     if( call_other("/bin/soul/_" + emotion, "channel_emote", channel, target) ) */
      msg = (string) call_other("/bin/soul/_" + emotion, "channel_emote",
      channel, target);
  }
  else
    msg = temp;
  return msg;
}

/* This is not working right */
string
get_player_name(string channel)
{
  string name;
  if( (member_array(channel, OPEN_CHANNELS)) != -1 ||
    !this_player()->query_invis())
  {
      name = (string) this_player()->query_name();
  }
  else
  {
    name =  "(Invis) " + capitalize( (string) this_player()->query_real_name());
  }
  return name;
}

int
valid_channel(string channel)
{
  if (member_array(channel, OPEN_CHANNELS) != -1)
    return 1;
  if (member_array(channel, DEVELOPER_CHANNELS) != -1)
    /* Only wizards have access to these channels. */
    return (this_player()->query_level() > 20);
  if(channel == "admin") return (this_player()->query_level() > 99);
  return 0;
}
