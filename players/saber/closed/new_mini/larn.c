/*
 *  Servants of Larn Mini Guild 2.0
 *  From the object base.c
 *
 */

static int line_flag, master_flag;
int time, is_succubus, is_feline, is_gypsy, is_blade, is_gothic, is_kender, is_larn;
int nocast;
string QUOTE;

#define ALMIN 100
#define ALCHECK if(check_al()) { write("You and the Universe are not in balance!\n"); return 1; }
#define SPELL "/players/saber/closed/new_mini/spell"
#define EMOTION "/players/saber/closed/new_mini/spell"
#include "/players/saber/closed/new_mini/spells/save_me.h"
#include "/players/saber/closed/new_mini/spells/restore_me.h"
#include "/players/saber/closed/new_mini/spells/cast_light.h"

reset(arg)  {
  if(arg) return;
  line_flag = 1;
  master_flag = 1;
  is_larn = 1;
  set_light(0);
        }

id(str)  {
  return str == "base_obj" ||
         str == "larn_obj" ||
         str == "symbol" ||
         str == "holy symbol";
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/saber/closed/new_mini/larn.c:"; }

short()   { return "A holy symbol of Larn (worn)";  }

long()   {
  write("A silver holy symbol of Larn\n");
  write("This holy symbol is carried by the Servants of Larn, an order\n"+
        "dedicated to the principles of protection, life and adventure.\n");
  write("Type <larn_help> for more information.\n");
        }

extra_look()  {
  /** Updated by Dragnar **/
  if( environment() == this_player() )
    return "You are surrounded by the aura of the righteous";
  else
    return environment(this_object())->query_name()+" is surrounded by the aura of the righteous";
}

init_arg(str)  {
  cat("/players/saber/closed/new_mini/MESSAGE");
        }

init()  {
  restore_me();
  time = time();
  set_is_larn(1);
  save_me();
  add_action("bless_corpse","bless_corpse");
  add_action("cure_target","chant");
  add_action("prayer_person","prayer");
  add_action("find_wizard","deities");
  add_action("cast_light","cast_light");
  add_action("emotee","emote");
  add_action("larn_kin","holy");
  add_action("mini_guild_who","Mwho");
  add_action("new_title","Mtitle");
  add_action("Quote","Message");
  add_action("mini_guild_scroll","scroll");
  add_action("succor","goportal");
  add_action("larn_update","new_symbol");
  add_action("larn_help","larn_help");
  add_action("larn_bye","abandon_larn");
  add_action("larn_talk","chat");
  add_action("larn_emote","chate");
  add_action("larn_toggle","larn_toggle");
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
        
check_al() {
   if(this_player()->query_alignment() < ALMIN) return 1;
}
/*
return 0; }
*/

query_nocast() { return nocast; }
set_nocast(int num) {
  nocast = 1;
  call_out("remove_nocast",num);
  return 1; }
remove_nocast() {
  nocast = 0;
  return 1; }

bless_corpse(str)    { ALCHECK SPELL->bless_corpse(str);  return 1;  }
cure_target(str)  { ALCHECK SPELL->cure_target(str); return 1; }
prayer_person(str)    { ALCHECK SPELL->prayer_person(str);  return 1;  }
find_wizard()     { ALCHECK SPELL->find_wizard();  return 1;  }
emotee(str)  {  SPELL->emotee(str); return 1; }
mini_guild_who()  { ALCHECK SPELL->mini_guild_who(); return 1; }
larn_kin()  { ALCHECK SPELL->larn_kin(); return 1; }
new_title()   { ALCHECK SPELL->new_title(); return 1;  }
Quote (str)    { ALCHECK SPELL->Quote(str);  save_me();  return 1;  }
mini_guild_scroll(str)  { SPELL->mini_guild_scroll(str); return 1; }
succor() { ALCHECK return SPELL->succor(); }
larn_update()   { SPELL->larn_update(); return 1;  }
master_line_talk(str)   { ALCHECK SPELL->master_line_talk(str);  return 1;  }
master_emote(str)  { ALCHECK SPELL->master_emote(str);  return 1; }
larn_help()  { cat("/players/saber/closed/new_mini/doc/larn");  return 1;  }
larn_bye()   { SPELL->larn_bye();  save_me();  return 1;  }
larn_talk(str)   { ALCHECK SPELL->larn_talk(str); return 1;  }
larn_emote(str)  { ALCHECK SPELL->larn_emote(str); return 1; }
larn_toggle()    { SPELL->larn_toggle(); return 1;   }
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

query_larn_flag()   { return line_flag; }
set_larn_flag(str)  { line_flag = str;  }
query_master_flag()  { return master_flag; }
set_master_flag(str) { master_flag = str;  }
query_object_name()      { return "larn_obj"; }
set_quote(str)           { QUOTE = str; }
query_QUOTE()            { return QUOTE; }
query_time()     { return time;  }
set_time(str)     { time = str;  }
query_newguild()         { return "larn"; }
query_mini()             { return "base_obj"; }
set_is_larn(str)     { is_larn = str; }
