/*
 * (c) Vertebraker@Nirvana 3-14-2003
 * Standard guild object.
 * Allows easy id, unique id, guild file,
 * and member dirs, among others..
 * Stores general diagnostic stuff as well.
 */

#define USER environment()
#define RN   query_real_name()

inherit "/players/vertebraker/closed/std/cmd_dir_obj";

static string *ids, guild_file, unique_id, member_path, guild_name,
              guild_news;
static status LoggedIn;

string  join_date;
int     beats;

void reset(status x)
{
 ::reset(x);
 if(x || root()) return;
 ids =     ({ "guild_object", "ND", "GI" });
 guild_file = "/players/example/guild/guild_object";
 unique_id  = "guildname_objectname";
 member_path = "players/example/guild/member_files/";
 guild_name = "guildname";

 call_out("fake_beat", 2);
}

void fake_beat()
{
 beats ++;
 call_out("fake_beat", 2);
}

status restore_me()
{
 return restore_object(member_path+(USER->RN));
}

void save_me()
{
 save_object(member_path+(USER->RN));
}

void init()
{
 if(!LoggedIn)
 {
  if(!restore_me())
   join_date=ctime();
  USER->set_guild_name(guild_name);
  USER->set_guild_file(guild_file);
  call_out("guild_news", 1);
  LoggedIn=1;
 }
 ::init();
 add_action("cmd_save", "quit");
 add_action("cmd_save", "save");
}

void guild_news()
{
 tell_object(USER, read_file(guild_news));
}

void add_id(string str)
{
 ids += ({ str });
}

string * query_ids()
{
 return ids;
}

void set_guild_file(string path)
{
 guild_file=path;
}

string query_guild_file()
{
 return guild_file;
}

void set_unique_id(string str)
{
 ids += ({ str });
 unique_id = str;
}

string query_unique_id(string str)
{
 return unique_id;
}

void set_member_path(string str)
{
 member_path = str;
}

string query_member_path()
{
 return member_path;
}

void set_guild_name(string gname)
{
 guild_name = gname;
}

string query_guild_name()
{
 return guild_name;
}

void set_guild_news(string gnews)
{
 guild_news = gnews;
}

string query_guild_news()
{
 return guild_news;
}

status id(string str)
{
 return (member_array(str, ids) > -1);
}

status is_guild_object()
{
 return 1;
}

void remove_object()
{
 save_me();
}

status cmd_save()
{
 tell_object(USER, "Saving guild statistics... ");
 save_me();
 tell_object(USER, "Ok.\n");
 return 0;
}
