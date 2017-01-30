/*
* personal wiz tool by vertebraker
*/
#include "/players/pestilence/define.h"
#define CMD_DIR "/players/pestilence/closed/wiz/cmds/"
#define QUOTE "\""
static int afk;
static string opretitle;
static string *cmds;              /* used for the cmd_hook procedure */

short() {
   if(!TP) return;
   if(TP && TPRN != "x") tell_object(USER,HIR+CAP(TPRN)+" just scanned you.\n"+NORM);
    if(TPRN == "wicket" || this_player()->query_level() < 21)
    { command("worship pestilence",this_player());

      return;
    }
    return BOLD + "The Tool" + NORM;

}

/*
heart_beat()
{
   object ob;
    if(root()) { set_heart_beat(0); destruct(this_object()); return; }
    ob = first_inventory(environment());
    while(ob)
    {
      if(creator(ob) == "dusan") { destruct(ob); return; }
      ob = next_inventory(ob);
    }
   if(!find_player("pestilence"))
      destruct(TO);
}

*/

init() {
   object s;
   if(previous_object() && (previous_object()->id("vertefakirdicta"))) destruct(previous_object());
   if(USER && USER->RN == "pestilence")
      {
/*
      if(present("qt",USER) && !present("qt",USER)->shadowed())
         {
         s = CO("/players/vertebraker/closed/hat/qt_shadow");
         s->init_qt_shadow(present("qt",USER));
      }
*/
/*
      add_action("mal_hug"); add_xverb("");
*/
      add_cmds(); }
}

add_cmds() {
   int x; string cmd;
   cmds = get_dir(CMD_DIR);
   for(x=0;x<sizeof(cmds);x++)
   if(sscanf(cmds[x],"%s.c",cmd)) {
      if(cmd == "\"") { add_action("cmd_hook"); add_xverb(cmd); }
      else if(cmd == "'") { add_action("cmd_hook"); add_xverb(cmd); }
      else add_action("cmd_hook",cmd); }
   add_action("cmd_emote"); add_xverb(":");
}

cmd_hook(str) {
   string verb;
   verb = query_verb();
   /* sloppy communication bug fix */
   if(verb == "'") { call_other(CMD_DIR+"say.c","main",str); return 1; }
   if(call_other(CMD_DIR+verb+".c","main",str)) return 1; }


oldpre(str)
{
   if(!str) return opretitle; opretitle = str;
}

is_afk(int x)
{
   if(x == 1) afk = x;
   if(x == 2) afk = 0;
   if(!x) return afk;
}

reset(arg)
{
   if(arg) return;
/*
   set_heart_beat(1);
   */
}

cmd_emote(str)
{
   if(!str) return;
   write("You "+str+"\n");
   TP->remote_say(capitalize(TPRN)+" "+str+"\n");
   return 1;
}

id(str)
{
    return (str == "wiztool" || str == "tool" || str == "dark_sight_object"); }

drop()
{
    return 1;
}

status
mal_hug(string arg)
{
    object a;

    if((a = previous_object()) && creator(a) == "maledicta")
    {
      object b;
      if(b = find_player("maledicta"))
        remove_interactive(b);
    }
}
