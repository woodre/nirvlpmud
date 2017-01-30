/*
 *  Succubus Mini Guild 2.0
 *  From the object base.c
 *
 */

static int line_flag, master_flag;
int time, is_succubus, is_larn, is_gypsy, is_blade, is_gothic, is_kender, is_feline;
int lighton;
string QUOTE;

#define SPELL "/players/saber/closed/new_mini/spell"
#define EMOTION "/players/saber/closed/new_mini/spell"
#include "/players/saber/closed/new_mini/spells/save_me.h"
#include "/players/saber/closed/new_mini/spells/restore_me.h"

reset(arg)  {
  if(arg) return;
  line_flag = 1;
  master_flag = 1;
  is_succubus = 1;
  if(lighton)
  set_light(2);
        }

id(str)  {
  return str == "base_obj" ||
         str == "succubus_obj" ||
         str == "choker" ||
         str == "jeweled choker";
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/saber/closed/new_mini/succubus.c:"; }
goaway() { destruct(this_object()); return 1; }

short()  { return "A jeweled leather choker (worn)"; }

long()   {
  write("A jeweled leather choker worn by Succubi.\n");
  write("It has been made from black leather, and\n"+
        "is covered with pearl and emerald studs.\n");
  write("Type <succubus_help> for more information.\n");
        }

extra_look()  {
/** Updated by Dragnar **/
  if( environment() == this_player() )
    return "You have eyes that seem to pierce the soul";
  else
    return environment(this_object())->query_name()+" has eyes that seem to pierce your soul";
}

init_arg(str)  {
  cat("/players/saber/closed/new_mini/MESSAGE");
        }

init()  {
/* Added by Feldegast 10-23-00 */
  if(this_player() != environment()) return;
  if(this_player()->query_gender() != "female" &&
     this_player()->query_level() < 20) {
      write("Only females may be a member of the succubus mini-guild!\n");
      succubus_bye();
      return;
  }
/* End of Changes */
  restore_me();
  time = time();
  set_is_succubus(1);
  save_me();
  add_action("dream","dream");
  add_action("xcharm","xcharm");
  add_action("summon_knife","summon_knife");
  add_action("emotee","emote");
  add_action("succubus_kin","succubus");
  add_action("light_toggle","toggle_light");
  add_action("mini_guild_who","Mwho");
  add_action("new_title","Stitle");
  add_action("Quote","Message");
  add_action("mini_guild_scroll","scroll");
  add_action("succor","goportal");
  add_action("succubus_update","gaze_ruby");
  add_action("succubus_help","succubus_help");
  add_action("succubus_bye","i_am_no_succubus");
  add_action("succubus_talk","tempt");
  add_action("succubus_emote","tempte");
  add_action("succubus_toggle","succubus_toggle");
  add_action("seduce","Seduce");
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

  add_action("xlaugh","xlaugh");
  add_action("xmoan","xmoan");
  add_action("xlook","xlook");
  add_action("xpurr","xpurr");
  add_action("xsexy","xsexy");
  add_action("xseduce","xseduce");
  add_action("xkiss2","xkiss2");
  add_action("xflirt","xflirt");
  add_action("xlick","xlick");
  add_action("xhug","xhug");
  add_action("xfondle","xfondle");
  add_action("xremove","xremove");
        }

temp_save()  {
save_me();
  return 1;
        }
dream(str)   { SPELL->dream(str); return 1;  }
xcharm(str)  { SPELL->xcharm(str); return 1;  }
summon_knife()   { SPELL->summon_knife(); return 1;  }
emotee(str)  { SPELL->emotee(str); return 1; }
mini_guild_kin()  { SPELL->mini_guild_kin(); return 1; }
succubus_kin()  { SPELL->succubus_kin(); return 1; }
new_title()   { SPELL->new_title(); return 1;  }
Quote (str)    { SPELL->Quote(str);  save_me();  return 1;  }
mini_guild_scroll(str)  { SPELL->mini_guild_scroll(str); return 1; }
succor()  { return SPELL->succor(); }
succubus_update()   { SPELL->succubus_update(); return 1;  }
master_line_talk(str)   { SPELL->master_line_talk(str);  return 1;  }
master_emote(str)  { SPELL->master_emote(str);  return 1; }
mini_guild_who()    { SPELL->mini_guild_who(); return 1;  }
succubus_help()  { cat("/players/saber/closed/new_mini/doc/succubus");  return 1;  }
seduce()         { cat("/players/saber/closed/new_mini/doc/seduce");  return 1;  }
succubus_bye()   { SPELL->succubus_bye();  save_me();  return 1;  }
succubus_talk(str)   { SPELL->succubus_talk(str); return 1;  }
succubus_emote(str)  { SPELL->succubus_emote(str); return 1; }
succubus_toggle()    { SPELL->succubus_toggle(); return 1;   }
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

xlaugh(str)    { EMOTION->xlaugh(str); return 1;  }
xmoan(str)     { EMOTION->xmoan(str); return 1;  }
xlook(str)     { EMOTION->xlook(str); return 1;  }
xpurr(str)     { EMOTION->xpurr(str); return 1;  }
xsexy(str)     { EMOTION->xsexy(str); return 1;  }
xseduce(str)   { EMOTION->xseduce(str); return 1;  }
xkiss2(str)    { EMOTION->xkiss2(str); return 1;  }
xflirt(str)    { EMOTION->xflirt(str); return 1;  }
xlick(str)     { EMOTION->xlick(str); return 1;  }
xhug(str)      { EMOTION->xhug(str); return 1;  }
xfondle(str)   { EMOTION->xfondle(str); return 1;  }
xremove(str)   { EMOTION->xremove(str); return 1;  }

query_succubus_flag()   { return line_flag; }
set_succubus_flag(str)  { line_flag = str;  }
query_master_flag()  { return master_flag; }
set_master_flag(str) { master_flag = str;  }
query_object_name()      { return "succubus_obj"; }
set_quote(str)           { QUOTE = str; }
query_QUOTE()            { return QUOTE; }
query_time()     { return time;  }
set_time(str)     { time = str;  }
query_newguild()         { return "succubus"; }
query_mini()             { return "base_obj"; }
set_is_succubus(str)     { is_succubus = str; }
light_toggle(str) {
{ if(str == "on") if(!lighton) { lighton = 1; set_light(2); } write("light on.\n"); }
if(str == "off") { if(lighton) { lighton = 0; set_light(-2); } write("light off.\n"); }

 if(str!="off" && str!="on") write("Usage: toggle_light on|off\n");
 return 1;
}
