/* A modularized wiztool by Softly/Nirvana with
   assistance from Verte ... February, 2001
*/
#include "/players/softly/closed/ansi.h"
#define CMD_DIR "/players/softly/closed/softool/cmds/"

inherit "/obj/wiz_tool";

string owner;

void
add_softly_cmds()
{
    int i, s;
    string file, *files;

    files = get_dir(CMD_DIR);  /* see /doc/Driver/doc/efun/get_dir
                                  for more info.. dump the file names
                                  of CMD_DIR into an array */

    s = sizeof(files);

    for(i = 0; i < s; i ++)
      if(sscanf(files[i], "%s.c", file))
        add_action( "soft_hook", file);
}   

void
init()
{
  ::init();  /* call the inherited init */
    add_softly_cmds(); /* call the above function */
}

status
soft_hook(string arg)
{
  string Cmd, verb;

  verb = query_verb();  /* in the heh.c case, the verb you specified
			   would be 'heh' */

  Cmd = CMD_DIR + verb + ".c";

  if(file_size(Cmd) > 0)
    if(Cmd->main(arg))
      return 1;  
    
  return 0;
}

short()
{
  if(!this_player()) return;
  if(this_player() && this_player()->query_real_name()!="softly") tell_object(environment(this_object()),HIM+capitalize(this_player()->query_real_name())+" scanned you!\n"+NORM);

  return CYN + "Cloak of the Sea"+NORM+" (worn)";
}

string
long(){
  write ("\nA soft fluid cloak swirls around Softly, moving effortlessly.\n"+
	 "It flows near her face and gently drapes itself upon her body\n"+
	 "warming and encasing her, meeting all her needs. (cmds)\n");
}

drop()         { return 1; }
get()          { return 1; }
query_weight() { return 0; }
query_value()  { return 0; }
 
status
id(string str)
{
    return str == "tool" || str == "wiztool" || str == "cloak" || str == "sea";
}




