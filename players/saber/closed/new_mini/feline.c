/*
 *  Feline Mini Guild 2.0
 *  From the object base.c
 *
 */

static int line_flag, master_flag;
int time, is_succubus, is_larn, is_gypsy, is_blade, is_gothic, is_kender, is_feline;
int ste;
string QUOTE;

#define SPELL "/players/saber/closed/new_mini/spell"
#define EMOTION "/players/saber/closed/new_mini/spell"
#include "/players/saber/closed/new_mini/spells/save_me.h"
#include "/players/saber/closed/new_mini/spells/restore_me.h"
#include "/players/saber/closed/new_mini/spells/snick.h"

reset(arg)  {
  if(arg) return;
  line_flag = 1;
  master_flag = 1;
  is_feline = 1;
        }

id(str)  {
  return str == "base_obj" ||
         str == "feline_obj" ||
         str == "ball" ||
         str == "meow_obj"  ||
         str == "string";
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/saber/closed/new_mini/feline.c:"; }

short()  { return "A ball 'o string"; }

long()   {
  write("A ball 'o string carried by felines and cat dancers.\n");
  write("The ball is of wound silk, light and soft, and absolutly\n"+
        "perfect for batting around.\n");
  write("Type <feline_help> for more information.\n");
        }

extra_look()  {
/** Updated by Dragnar **/
  if( environment() == this_player() )
    return "You have a long tail and whiskers";
  else
    return environment(this_object())->query_name()+" has a long tail and whiskers";
}

init_arg(str)  {
  cat("/players/saber/closed/new_mini/MESSAGE");
        }

ste_raised() { return ste; }
set_ste(arg) { ste = arg;}
init()  {
  int xx;
  restore_me();
  time = time();
  set_is_feline(1);
/* changed by wocket 9/21/2003 */
if(this_player()){
  xx = this_player()->query_attrib("ste");
  if(xx > 35){
    call_other(this_player(),"raise_stealth",(35-xx));
    write("Your stealth has been readjusted to the max.\n");
    write("Please contact a wizard to find out how you went over the limit.\n");
  }
}
/* obsolete -wocket 9/21/2003
  if(this_player()) {
  if(!ste && this_player()->query_attrib("ste") < 25)ste = this_player()->query_attrib("ste");
  xx = this_player()->query_attrib("ste");
  if(xx > 35) call_other(this_player(), "raise_stealth", 35-xx);
  if(this_player()->query_level() < 20) 
    if(this_player()->query_attrib("ste") ==25 && !ste) {
     ste = 20;
     call_other(this_player(), "raise_stealth", -5);
      write("Stealth reset to 20.\n"+
          "You can use 'increase_stealth' anytime you have stealth of 20-30.\n"+
          "You will get an increase of 5 points. You can do it only once,\n"+
          "and cannot buy points once you reach a stealth of 30 or greater.\n"+
          "If you use it at 20, you'll go from 20 to 25, with a 30 max.\n"+
          "If you use it at 28, you'll go from 28 to 33, with a 33 max.\n"+
          "If you use it at 30, you'll go from 30 to 35, with a 35 max.\n");
    }}
*/
/*
  if(this_player()->query_attrib("ste") > 20 && this_player()->query_attrib("ste") != 25) {
this_player()->set_attrib("ste",20-(25-this_player()->query_attrib("ste")));
if(this_player()->query_attrib("ste") > 20) this_player()->set_attrib("ste",20);
}
*/
  save_me();
  add_action("snick_claws","snick");
  add_action("increase_stealth","increase_stealth");
  add_action("spc_look","look");
  add_action("spc_look","examine");
  add_action("spc_look","l");
  add_action("spc_look","exa");
  add_action("emotee","emote");
  add_action("meow_kin","litter");
  add_action("mini_guild_who","Mwho");
  add_action("new_title","Mtitle");
  add_action("Quote","Message");
  add_action("mini_guild_scroll","scroll");
  add_action("succor","goportal");
  add_action("meow_update","meow_ball");
  add_action("meow_help","feline_help");
  add_action("meow_bye","i_am_no_feline");
  add_action("meow_talk","meow");
  add_action("meow_emote","meowe");
  add_action("meow_toggle","meow_toggle");
  add_action("meow_emotions","Meows");
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

  add_action("tail","xtail");
  add_action("nibble","nibble2");
  add_action("scratch","scratch");
  add_action("mew","mew");
  add_action("purr","purr2");
  add_action("shed","shed");
  add_action("pounce","pounce");
  add_action("groom","groom");
  add_action("rub","rub2");
  add_action("lick","lick2");
  add_action("chase","chase");
  add_action("tail2","xtail2");
  add_action("chomp","chomp");
        }

temp_save()  {
save_me();
  return 1;
        }

spc_look(str)  {
  if(present("kitty_claws", this_player()))  {
    if(str == "claws" || str == "at claws")  {
      write("A razor sharp pair of feline claws extending from your hands.\n");
      return 1;
        }
        }
        }

increase_stealth()  { SPELL->stealth();  return 1;  }
snick_claws()     { snick(); return 1;  }
emotee(str)  { SPELL->emotee(str); return 1; }
mini_guild_who()  { SPELL->mini_guild_who(); return 1; }
meow_kin()  { SPELL->meow_kin(); return 1; }
new_title()   { SPELL->new_title(); return 1;  }
Quote (str)    { SPELL->Quote(str);  save_me();  return 1;  }
mini_guild_scroll(str)  { SPELL->mini_guild_scroll(str); return 1; }
succor()  { return SPELL->succor(); }
meow_update()   { SPELL->meow_update(); return 1;  }
master_line_talk(str)   { SPELL->master_line_talk(str);  return 1;  }
master_emote(str)  { SPELL->master_emote(str);  return 1; }
meow_help()  { cat("/players/saber/closed/new_mini/doc/feline");  return 1;  }
meow_emotions()         { cat("/players/saber/closed/new_mini/doc/meow");  return 1;  }
meow_bye()   { SPELL->meow_bye();  save_me();  return 1;  }
meow_talk(str)   { SPELL->meow_talk(str); return 1;  }
meow_emote(str)  { SPELL->meow_emote(str); return 1; }
meow_toggle()    { SPELL->meow_toggle(); return 1;   }
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

tail(str)      { EMOTION->tail(str); return 1;  }
nibble(str)    { EMOTION->nibble(str); return 1;  }
scratch(str)   { EMOTION->scratch(str); return 1; }
mew(str)       { EMOTION->mew(str); return 1;  }
purr(str)      { EMOTION->purr(str); return 1;  }
shed(str)      { EMOTION->shed(str); return 1;  }
pounce(str)    { EMOTION->pounce(str); return 1;  }
groom(str)     { EMOTION->groom(str); return 1;  }
rub(str)       { EMOTION->rub(str); return 1;  }
lick(str)      { EMOTION->mlick(str); return 1; }
chase(str)     { EMOTION->chase(str); return 1;  }
tail2(str)     { EMOTION->tail2(str); return 1;  }
chomp(str)      { EMOTION->chomp(str); return 1;  }

query_meow_flag()   { return line_flag; }
set_meow_flag(str)  { line_flag = str;  }
query_master_flag()  { return master_flag; }
set_master_flag(str) { master_flag = str;  }
query_object_name()      { return "meow_obj"; }
set_quote(str)           { QUOTE = str; }
query_QUOTE()            { return QUOTE; }
query_time()     { return time;  }
set_time(str)     { time = str;  }
query_newguild()         { return "feline"; }
query_mini()             { return "base_obj"; }
set_is_feline(str)     { is_feline = str; }
