#include "/obj/security.h"
#include <ansi.h>
#define MYNAME "vital"


#define COMPAT
#define PROGRAM_NAME	program_name
#define IS_NOT_WIZARD    (this_player()->query_level<=20)

#define LIGHT		set_light(0)
#define SET_LIGHT	set_light
#define MOVE(x,y)	move_object(x,y)
#define DESTRUCT(ob)	destruct(ob)

#define C		capitalize
#define L		lower_case
#define ME		this_object()
#define MEMBER(x,arr)	(member_array(x,arr)>=0)
#define MUDHOST		query_host_name()
#define PL		this_player()
#define TP          this_player()
#define TPN         TP->query_real_name()
#define LEVEL       TP->query_level()
#define TO          this_object()
#define OUT(str)	write(str+"\n")
#define FOREACH(arr,i)	for(i=0;i<sizeof(arr);i++)
#define FORALL(x, y) for(x=first_inventory(y);x;x=next_inventory(x))
#define FILTER(set)	if (!str)return 0;if(!MEMBER(L(str),(explode(set,"#"))))return 0
#define NOTIFY(mes)	{OUT(mes);return 1;}
#define GETENV(x)	x=environment(ME);if(!x)return
#define OWNER(ob)	L(environment(ob)->query_real_name())
#define H_BANNER	1
#define H_CENTER	2
#define HEADLINE(x)	write (headline(x,0));
#define CENTER(x)	write (headline(x,H_CENTER));
#define BANNER(x)	write (headline(x,H_CENTER|H_BANNER));


#define NULL			0
#define INTEGER			1
#define STRING			2
#define OBJECT			3
#define ARRAY			4
#define SLOT			5
#define INDEX			6
#define ASTERISK		7
#define MAPPING			8
#define RESULT			9
#define CLOSURE			10
#define SYMBOL			11
#define FLOAT			12
#define DELAY			13
#define S_ARRAY			14
#define S_MAPPING		15
#define S_CLOSURE		16
#define S_SYMBOL		17
#define S_FLOAT			18
#define S_STRING		19
#define S_OBJECT		20
#define S_EFUN			21
#define SUBCALL			22
#define MULTIARG		23

#define INDEXTYPE_UNKNOWN	"unknown"
#define INDEX_PLAIN		"plain"
#define INDEX_INTERVAL		"interval"
#define INDEX_RIGHTBORDER	"rightborder"
#define INDEX_RBORDER		"rborder"
#define INDEX_LEFT		"left"
#define INDEX_RIGHT		"right"

        mapping slot;
        mixed   result_slot;
static  int     active_slot;
static  object  *indexlist;
static  object  marked;
static  string  *eval_array;
static  string  *callargs;

        string  lang;
        int     lightlevel;
        int     tracelevel;
static  string  tprefix;
        string  *dir_array;
        string  *expect_list;
static  string  *command_array;
static  mixed   *help_array;
static  mixed   *info_array;
static  object  mtarget;
static  mapping shadows;
static  mapping watches;

object  get_object (string str, int skip);
string  get_file (string str, string *dirs, int mode);
int     valid_filepath (string str);
mixed   translate (mixed arg, int type, int briefmode);
mixed   translate_phrase (mixed arg, int type, int briefmode);
mapping translate_mapping (mixed arg, int briefmode);
string  dump_argument (mixed arg, int indent);
string  short_dump (mixed ob);
string  blanks (int nr);
string  char_tab (int nr, string char);
string  format (int mode, string text, int len, string ch);
string  skipspaces (string str);
mixed   *actions_probe (object ob, string com, int force);
static  mixed   call_function (mixed argv, int briefmode);
static  mixed   call_lfun (mixed *arr, int briefmode);
static  mixed   call_efun (mixed *arr, int briefmode);
int     execute_cd (string str);
int     list_watches (object *ob);
int     remove_watches (object ob, int silent);
void    clean_loop (object *top);
void    prepare_eval (mixed *arr);
int     compute_eval (string out);
static  void    write_eval (string str, object ob);
string  locate_function (string fun, object ob);
void    help_out (string mess, string str);
string  lookup_check (string str, string func);
string  make_shared (string s);
string  handle_slot (mixed *argv, string key, int i, mixed entry);
string  *deep_update (object item);
int     list_shadows (object *ob);
int     remove_shadow (object ob, int silent);
string  add_varlist (int num);
int     parameter_number (object ob, string fun);
int     More (string str);

int x;

init() {
    if(TPN != MYNAME) { DESTRUCT(TO); }
    add_action("commands", "commands");
    add_action("write_filer","wr");
    add_action("write_note","note");
    add_action("wiz_tell", "wt");
    add_action("wiz_emote", "wte");
    add_action("shuttle_remote", "press");
    add_action("shuttle_time", "times");
    add_action("drop", "drop");
    add_action("drop", "give");
    add_action("get", "get");
    add_action("update_dir","Update");
}

commands() {
  OUT("Commands:\n\n  wr <string>      :to write a work report\n");
  OUT("  note <string>    :to write to note\n");
  OUT("  wt <who> <msg>   :to send a tell\n");
  OUT("  wte <who> <msg>  :to emote\n\n");
  OUT("  times            :list shuttle names/destination/times\n");
  OUT("  press            :load a shuttle into the game\n");
  return 1;
}

id(str) { 
    FILTER("computer#tell#teller#filer#laptop#laptop computer");
    return 1;
}


int get () {
	if (LEVEL <= 20) {
		OUT ("When you reach out for the computer, it dissolves.");
		DESTRUCT(ME);
		return 0;
	}
	return 1;
}

int drop (int silently)
{
	if (!silently)
	{
		if (query_verb()=="drop")
			NOTIFY ("You cannot drop the Robe of Sorcery !");
		if (query_verb()=="give")
			NOTIFY ("You cannot give away the Robe of Sorcery !");
	}
	return 1;
}

string short ()
{
	return (HIR+C(MYNAME)+NORM+"\'s Laptop Computer");
}


long() {
    OUT("A Wizardly Looking Laptop Computer");
    if(TP == environment(ME))
        OUT("This is "+HIW+C(MYNAME)+"\'s "+HIR+"Laptop Computer"+NORM+".\nType \'commands\' to learn more.\n");
}

mixed query_result() { return result_slot; }

write_filer(str) {
  if(!str) { tail("/players/"+OWNER(TO)+"/logs/work.log"); return 1; }
  else
  write_file("/players/"+OWNER(TO)+"/logs/work.log",ctime(time())+" "+HIB+"-->"+NORM+" "+str+"\n");
  write_file("/log/WR/"+OWNER(TO)+"_workreport",ctime(time())+" "+HIB+"-->"+NORM+" "+str+"\n");
  NOTIFY("Log entered")
}

write_note(str) {
  if(!str) { tail("/players/"+OWNER(TO)+"/logs/notes.log"); return 1; }
  else
  write_file("/players/"+OWNER(TO)+"/logs/notes.log",ctime(time())+" "+RED+"-->"+NORM+" "+str+"\n");
NOTIFY(HIB+"Note completed."+NORM+"\n")
}

wiz_tell(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { NOTIFY("Tell what?\n") }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Tell <who> <what>.\n"); return 1; }
    plyr = find_living(who);
    myname = capitalize(TPN);
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
  plyr->add_tellhistory(myname + " didst tell thee something");
  tell_object(plyr, "You hear "+BWHT+BLK+myname+NORM+HIW+": "+NORM+HIB+what+NORM+"\n");
  NOTIFY("You whisper to "+capitalize(who)+": "+HIB+what+NORM+"\n")
}

wiz_emote(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { write("Emote what?\n"); return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Emote <what> <who>.\n"); return 1; }
    plyr = find_living(who);
    myname = capitalize(TPN);
  if(!plyr) { write(capitalize(who)+" is not online now.\n");
              return 1; }
  tell_object(plyr, ""+BWHT+BLK+myname+NORM+HIW+" "+NORM+HIB+what+NORM+".\n");
  NOTIFY("You emote to "+capitalize(who)+": Vital "+HIB+what+NORM+".\n")
}

shuttle_remote() {
    "/players/vital/dest/spaceport/shuttles/shuttle_daemon.c"->make_shuttle();
    return 1;
}

shuttle_time() {
    "/players/vital/dest/spaceport/shuttles/shuttle_daemon.c"->liftoff_timer();
    return 1;
}

/*  the real v: */

status update_dir(string str)
{
    string directory;
    int x;
    string *files;
    object poop;

    if(!str) directory = (string)this_player()->get_path();
    else directory = str;
    
    if(directory[0] == '~')
      directory = "/players/" + (string)this_player()->query_real_name() + 
                  directory[1..(strlen(directory) - 1)];
  
    if(directory[0] != '/')
      directory = "/" + directory;
    if(directory[strlen(directory) - 1] != '/')
      directory = (directory[0..strlen(directory) - 1] + "/");
   
    if(file_size(directory) != -2)
    {
      notify_fail("Unable to properly upd_dir...\n " +
                  "String is not a directory.\n");
      return 0;
    }

    files = get_dir(directory);

    write("Updating directory: " + directory + "\n");
    for(x = 0; x < sizeof(files); x ++)
    {
      if(files[x][strlen(files[x]) - 2..strlen(files[x]) - 1] == ".c")
      {
        if((poop = find_object(directory + files[x])))
          destruct(poop);
        poop = directory + files[x];
        poop->load_file(0);
        poop->reset(0);
      }
    }
    write("Update complete.\n");
    return 1;
}

