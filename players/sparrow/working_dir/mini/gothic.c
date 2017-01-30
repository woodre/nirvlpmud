/*
 *  The Gothic Mini Guild 2.0  (be very, very depressed..)
 *  From the object base.c
 *
 */

static int line_flag, master_flag;
int time, is_succubus, is_feline, is_gypsy, is_blade, is_larn, is_kender, is_gothic;
string QUOTE;

#define SPELL "/players/saber/closed/new_mini/spell"
#define EMOTION "/players/saber/closed/new_mini/spell"
#include "/players/saber/closed/new_mini/spells/save_me.h"
#include "/players/saber/closed/new_mini/spells/restore_me.h"

reset(arg)  {
  if(arg) return;
  line_flag = 1;
  master_flag = 1;
  is_gothic = 1;
        }

id(str)  {
  return str == "base_obj" ||
         str == "gothic_obj" ||
         str == "attitude" ||
         str == "gothic attitude";
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/saber/closed/new_mini/gothic.c:"; }

short()   { return "Attitude (depressed)"; }

long()   {
  write("Your gothic attitude.\n");
  write("You can usually tell a gothic by their attitude,\n"+
        "and you are no exception to the rule.  How depressing.\n");
  write("Type <gothic_help> for more information.\n");
        }

extra_look()  {
object ex_look;
  ex_look = environment(this_object())->query_name();
  write(ex_look+" is surrounded by a foreboding aura.\n");
        }

init_arg(str)  {
  cat("/players/saber/closed/new_mini/MESSAGE");
        }

init()  {
  restore_me();
  time = time();
  set_is_gothic(1);
  save_me();
  add_action("recite_poetry","Recite");
  add_action("dance","gothic_dance");
  add_action("bad_vibes","vibes");
  add_action("paint_face","paint_face");
  add_action("emotee","emote");
  add_action("gothic_kin","goths");
  add_action("mini_guild_who","Mwho");
  add_action("new_title","Mtitle");
  add_action("Quote","Message");
  add_action("mini_guild_scroll","scroll");
  add_action("succor","goportal");
  add_action("gothic_update","feel_depressed");
  add_action("gothic_help","gothic_help");
  add_action("gothic_bye","i_am_no_goth");
  add_action("gothic_talk","recite");
  add_action("gothic_emote","recitee");
  add_action("gothic_toggle","gothic_toggle");
  add_action("new_emotions","emotions+");
  add_action("temp_save","oooo");

  add_action("boggle","xboggle");
  add_action("kiss","xkiss");
  add_action("cheer","xcheer");
  add_action("arch","xarch");
  add_action("bashful","xbashful");
  add_action("blush","xblush");
  add_action("cold","xcold");
  add_action("coo","xcoo");
  add_action("cool","xcool");
  add_action("giggle","xgiggle");
  add_action("giggle2","xgiggle2");
  add_action("jump","xjump");
  add_action("mock","xmock");
  add_action("scoff","xscoff");
  add_action("shy","xshy");
  add_action("smile","xsmile");
  add_action("smolder","xsmolder");
  add_action("spaz","xspaz");
  add_action("twirl","xtwirl");
  add_action("wonder","xwonder");
  add_action("wry","xwry");
  add_action("relax","xrelax");
  add_action("heartbreak","xheartbreak");
  add_action("hum","xhum");
  add_action("dejected","xdejected");
  add_action("hopeful","xhopeful");
  add_action("innocent","xinnocent");
  add_action("manic","xmanic");
        }

temp_save()  {
save_me();
  return 1;
        }

paint_face(str)   { SPELL->paint_face(str);  return 1;  }
recite_poetry(str)  { SPELL->recite_poetry(str); return 1; }
bad_vibes(str)  { SPELL->bad_vibes(str); return 1;  }
dance()    { SPELL->dance();  return 1;  }
emotee(str)  { SPELL->emotee(str); return 1; }
mini_guild_who()  { SPELL->mini_guild_who(); return 1; }
gothic_kin()  { SPELL->gothic_kin(); return 1; }
new_title()   { SPELL->new_title(); return 1;  }
Quote (str)    { SPELL->Quote(str);  save_me();  return 1;  }
mini_guild_scroll(str)  { SPELL->mini_guild_scroll(str); return 1; }
succor()    { SPELL->succor(); return 1;  }
gothic_update()   { SPELL->gothic_update(); return 1;  }
master_line_talk(str)   { SPELL->master_line_talk(str);  return 1;  }
master_emote(str)  { SPELL->master_emote(str);  return 1; }
gothic_help()  { cat("/players/saber/closed/new_mini/doc/goth");  return 1;  }
gothic_bye()   { SPELL->gothic_bye();  save_me();  return 1;  }
gothic_talk(str)   { SPELL->gothic_talk(str); return 1;  }
gothic_emote(str)  { SPELL->gothic_emote(str); return 1; }
gothic_toggle()    { SPELL->gothic_toggle(); return 1;   }
new_emotions()     { cat("/players/saber/closed/new_mini/doc/emotion"); return 1;  }

boggle(str)  { EMOTION->boggle(str); return 1; }
kiss(str)    { EMOTION->kiss(str); return 1; }
cheer(str)   { EMOTION->cheer(str); return 1; }
arch(str)    { EMOTION->arch(str);  return 1; }
bashful(str) { EMOTION->bashful(str); return 1; }
blush(str)   { EMOTION->blush(str); return 1; }
cold(str)    { EMOTION->cold(str);  return 1; }
coo(str)     { EMOTION->coo(str);   return 1; }
cool(str)    { EMOTION->cool(str);  return 1; }
giggle(str)  { EMOTION->giggle(str); return 1; }
giggle2(str) { EMOTION->giggle2(str); return 1; }
jump(str)    { EMOTION->jump(str); return 1; }
mock(str)    { EMOTION->mock(str); return 1; }
scoff(str)   { EMOTION->scoff(str); return 1; }
shy(str)     { EMOTION->shy(str);   return 1; }
smile(str)   { EMOTION->smile(str); return 1; }
smolder(str) { EMOTION->smolder(str); return 1; }
spaz(str)    { EMOTION->spaz(str);  return 1; }
twirl(str)   { EMOTION->twirl(str); return 1; }
wonder(str)  { EMOTION->wonder(str); return 1; }
wry(str)     { EMOTION->wry(str); return 1; }
relax()      { EMOTION->relax(); return 1; }
heartbreak(str) { EMOTION->heartbreak(str); return 1; }
hum()        { EMOTION->hum(); return 1; }
dejected(str){ EMOTION->dejected(str); return 1; }
hopeful(str) { EMOTION->hopeful(str); return 1; }
innocent()   { EMOTION->innocent(); return 1; }
manic(str)    { EMOTION->manic(str); return 1; }

query_gothic_flag()   { return line_flag; }
set_gothic_flag(str)  { line_flag = str;  }
query_master_flag()  { return master_flag; }
set_master_flag(str) { master_flag = str;  }
query_object_name()      { return "gothic_obj"; }
set_quote(str)           { QUOTE = str; }
query_QUOTE()            { return QUOTE; }
query_time()     { return time;  }
set_time(str)     { time = str;  }
query_newguild()         { return "gothic"; }
query_mini()             { return "base_obj"; }
set_is_gothic(str)     { is_gothic = str; }
query_is_gothic() { return is_gothic; }
