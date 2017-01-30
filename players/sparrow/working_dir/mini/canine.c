/*
  *  The Canine Mini Guild 2.0
 *  From the object base.c
 *
 */

static int line_flag, master_flag;
int time, is_succubus, is_feline, is_canine, is_larn, is_blade, is_gothic, is_kender, is_gypsy;
string QUOTE;

#define SPELL "/players/saber/closed/new_mini/spell"
#define EMOTION "/players/saber/closed/new_mini/spell"
#include "/players/saber/closed/new_mini/spells/save_me.h"
#include "/players/saber/closed/new_mini/spells/restore_me.h"

reset(arg)  {
  if(arg) return;
  line_flag = 1;
  master_flag = 1;
  is_canine = 1;
        }

id(str)  {
  return str == "base_obj" ||
         str == "canine_obj" ||
  str == "collar" ||  /* there was a ; */
str == "tattered collar";
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/saber/closed/new_mini/canine.c:"; }

short()  { return "A tattered collar (worn)"; }

long()   {
write("A tattered collar (worn).\n");
  write("Type <canine_help> for more information.\n");
        }

extra_look()  {
object ex_look;
  ex_look = environment(this_object())->query_name();
write(ex_look+" is wearing a tattered collar.\n");
        }

init_arg(str)  {
  cat("/players/saber/closed/new_mini/MESSAGE");
        }

init()  {
  restore_me();
  time = time();
  set_is_canine(1);
  save_me();
add_action("canine_grin","c_grin");
add_action("canine_bump","c_bump");
add_action("canine_growl","c_growl");
add_action("canine_heel","c_heel");
add_action("canine_nip","c_nip");
add_action("canine_sniff","c_sniff");
add_action("canine_speak","c_speak");
add_action("canine_tail","c_tail");
add_action("canine_toy","c_toy");
add_action("canine_whimper","c_whimper");
add_action("canine_hump","c_hump");
add_action("canine_lick","c_lick");
add_action("canine_pee","c_pee");
add_action("canine_slobber","c_slobber");
add_action("canine_emotions","woof");
add_action("canine_muzzle","muzzle");
add_action("canine_lead","sic");
  add_action("emotee","emote");
  add_action("canine_kin","pack");
  add_action("mini_guild_who","Mwho");
  add_action("new_title","Mtitle");
  add_action("Quote","Message");
  add_action("mini_guild_scroll","scroll");
  add_action("succor","goportal");
  add_action("canine_update","tug_collar");
  add_action("canine_help","canine_help");
  add_action("canine_bye","i_am_no_canine");
  add_action("canine_talk","bark");
  add_action("canine_emote","barke");
  add_action("canine_toggle","canine_toggle");
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


emotee(str)  { SPELL->emotee(str); return 1; }
mini_guild_who()  { SPELL->mini_guild_who(); return 1; }
canine_muzzle(str)  { SPELL->muzzle(str); return 1; }
canine_lead(str)  { SPELL->sic(str); return 1; }
canine_kin()  { SPELL->canine_kin(); return 1; }
new_title()   { SPELL->new_title(); return 1;  }
Quote (str)    { SPELL->Quote(str);  save_me();  return 1;  }
mini_guild_scroll(str)  { SPELL->mini_guild_scroll(str); return 1; }
succor()  { return SPELL->succor(); }
canine_update()   { SPELL->canine_update(); return 1;  }
master_line_talk(str)   { SPELL->master_line_talk(str);  return 1;  }
master_emote(str)  { SPELL->master_emote(str);  return 1; }
canine_help()  { cat("/players/saber/closed/new_mini/doc/canine");  return 1;  }
canine_bye()   { SPELL->i_am_no_canine();  save_me();  return 1;  }
canine_talk(str)   { SPELL->canine_talk(str); return 1;  }
canine_emote(str)  { SPELL->canine_emote(str); return 1; }
canine_toggle()    { SPELL->canine_toggle(); return 1;   }
new_emotions()     { cat("/players/saber/closed/new_mini/doc/emotion"); return 1;  }
canine_emotions()         { cat("/players/saber/closed/new_mini/doc/woof");  return 1;  }

canine_grin(str)  { EMOTION->c_grin(str); return 1; }
canine_bump(str)  { EMOTION->c_bump(str); return 1; }
canine_growl(str)  { EMOTION->c_growl(str); return 1; }
canine_heel(str)  { EMOTION->c_heel(str); return 1; }
canine_nip(str)  { EMOTION->c_nip(str); return 1; }
canine_sniff(str)  { EMOTION->c_sniff(str); return 1; }
canine_speak(str)  { EMOTION->c_speak(str); return 1; }
canine_tail(str)  { EMOTION->c_tail(str); return 1; }
canine_toy(str)  { EMOTION->c_toy(str); return 1; }
canine_whimper(str)  { EMOTION->c_whimper(str); return 1; }
canine_hump(str)  { EMOTION->c_hump(str); return 1; }
canine_slobber(str)  { EMOTION->c_slobber(str); return 1; }
canine_lick(str)  { EMOTION->c_lick(str); return 1; }
canine_pee(str)  { EMOTION->c_pee(str); return 1; }
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

query_canine_flag()   { return line_flag; }
set_canine_flag(str)  { line_flag = str;  }
query_master_flag()  { return master_flag; }
set_master_flag(str) { master_flag = str;  }
query_object_name()      { return "canine_obj"; }
set_quote(str)           { QUOTE = str; }
query_QUOTE()            { return QUOTE; }
query_time()     { return time;  }
set_time(str)     { time = str;  }
query_newguild()         { return "canine"; }
query_mini()             { return "base_obj"; }
set_is_canine(str)     { is_canine = str; }
