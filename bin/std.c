/* tmieczkowski@hotmail.com [v] */

#define DAEMON "/bin/std_daemon.c"
#define EMOTER(a,b,c) (string)call_other("/obj/user/parse_emote","parse_emote",a,b,c)

/*
 * Room [nontarget]
 * a[0]= What you see
 * a[1]= What room sees
 *
 * Room [target]
 * a[2]= What you see
 * a[3]= What room sees, except target
 * a[4]= What target sees
 *
 *
 * Afar
 * a[5] = What you see
 * a[6] = What target sees
 */

mixed *a;

varargs void reset(int x) { if(!x) a=allocate(7); }

void
nontarget(string d, string e)
{
    a[0]=d;
    a[1]=e;
}

void
target(string d, string e, string f)
{
    a[2]=d;
    a[3]=e;
    a[4]=f;
}

void
afar(string d, string e)
{
    a[5]=d;
    a[6]=e;
}

mixed * query_junk() { return a; }

string
x(string arg, object target)
{
  return EMOTER(arg, this_player(), target);
}

status
do_cmd(string arg)
{
  return (status)DAEMON->do_cmd(arg, a);
}

int guildcast(string channel, string who)
{
  return (int)DAEMON->guildcast(channel, who, a);
}

int broadcast(string channel, string who)
{
  return (int)DAEMON->broadcast(channel, who, a);
}


