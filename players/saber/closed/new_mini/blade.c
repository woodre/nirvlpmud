/*
  *  The Blade Mini Guild 2.0
 *  From the object base.c
 *
 */

static int line_flag, master_flag;
int time, is_succubus, is_feline, is_larn, is_gypsy, is_gothic, is_kender, is_blade;
string QUOTE;

#define SPELL "/players/saber/closed/new_mini/spell"
#define EMOTION "/players/saber/closed/new_mini/spell"
#include "/players/saber/closed/new_mini/spells/save_me.h"
#include "/players/saber/closed/new_mini/spells/restore_me.h"

reset(arg)  {
  if(arg) return;
  line_flag = 1;
  master_flag = 1;
  is_blade = 1;
        }

id(str)  {
  return str == "base_obj" ||
         str == "blade_obj" ||
         str == "scabbard" ||
         str == "scabbard";
        }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }
query_auto_load()  { return "/players/saber/closed/new_mini/blade.c:"; }

short()  { return "The scabbard of a dueling knife";  }

long()   {
  write("The scabbard of a dueling knife.\n");
  write("An elaborately worked scabbard for a dueling knife.  It is a\n"+
        "constant companion against those who would offend your honor.\n");
  write("Type <blade_help> for more information.\n");
        }

extra_look()  {
  /** Updated by Dragnar **/
  if( environment() == this_player() )
    return "You have an air of flamboyance about yourself";
  else
    return environment(this_object())->query_name()+" has an air of flamboyance about "+environment(this_object())->query_objective();
}

init_arg(str)  {
  cat("/players/saber/closed/new_mini/MESSAGE");
        }
/*
luc_raised() { return luc; }
set_luc(arg) { luc = arg;}
*/

init()  {
  restore_me();
  time = time();
  set_is_blade(1);
/*
    if(this_player()) {
  if(!ste && this_player()->query_attrib("ste") < 25)ste =
this_player()->query_attrib("ste");
  if(this_player()->query_level() < 20) 
    if(this_player()->query_attrib("ste") ==25 && !ste) {
     ste = 20;
     call_other(this_player(), "raise_stealth", -5);
      write("Luck reset to 20.\n"+
          "You can use 'increase_luck' anytime you have luck of 20-30.\n"+
          "You will get an increase of 5 points. You can do it only once,\n"+
          "and cannot buy points once you reach a stealth of 30 or greater.\n"+
          "If you use it at 20, you'll go from 20 to 25, with a 30 max.\n"+
          "If you use it at 28, you'll go from 28 to 33, with a 33 max.\n"+
          "If you use it at 30, you'll go from 30 to 35, with a 35 max.\n");
    }}
*/
  save_me();
  add_action("draw_knife","draw_knife");
  add_action("blade_twirl","blade_twirl");
  add_action("blade_wipe","blade_wipe");
  add_action("blade_display","blade_display");
  add_action("juggle_blades","juggle_blades");
  add_action("fix_blade","fix_blade");
  add_action("value_weapon","inspect");
  add_action("tie_shoes","tie_laces");
  add_action("untie_shoes","untie_laces");
  add_action("emotee","emote");
  add_action("blade_kin","blades");
  add_action("mini_guild_who","Mwho");
  add_action("new_title","Mtitle");
  add_action("Quote","Message");
  add_action("mini_guild_scroll","scroll");
  add_action("succor","goportal");
  add_action("blade_update","clean_blade");
  add_action("blade_help","blade_help");
  add_action("blade_bye","break_knife");
  add_action("blade_more","blade+");
  add_action("blade_talk","brag");
  add_action("blade_emote","brage");
  add_action("blade_toggle","blade_toggle");
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

draw_knife()      { SPELL->draw_knife(); return 1; }
blade_twirl(str)   { EMOTION->blade_twirl(str); return 1; }
blade_wipe(str)    { EMOTION->blade_wipe(str); return 1; }
blade_display(str) { EMOTION->blade_display(str); return 1; }
juggle_blades(str)    { SPELL->juggle_blades(str); return 1;  }
fix_blade(str)   { SPELL->fix_blade(str); return 1;  }
tie_shoes(str)    { SPELL->tie_shoes(str); return 1;  }
untie_shoes(str)  { SPELL->untie_shoes(str);  return 1;  }
value_weapon(str)  { SPELL->value_weapon(str); return 1;  }
emotee(str)  { SPELL->emotee(str); return 1; }
mini_guild_who()  { SPELL->mini_guild_who(); return 1; }
blade_kin()  { SPELL->blade_kin(); return 1; }
new_title()   { SPELL->new_title(); return 1;  }
Quote (str)    { SPELL->Quote(str);  save_me();  return 1;  }
mini_guild_scroll(str)  { SPELL->mini_guild_scroll(str); return 1; }
succor()  { return SPELL->succor(); }
blade_update()   { SPELL->blade_update(); return 1;  }
master_line_talk(str)   { SPELL->master_line_talk(str);  return 1;  }
master_emote(str)  { SPELL->master_emote(str);  return 1; }
blade_help()  { cat("/players/saber/closed/new_mini/doc/blade");  return 1;  }
blade_bye()   { SPELL->blade_bye();  save_me();  return 1;  }
blade_talk(str)   { SPELL->blade_talk(str); return 1;  }
blade_emote(str)  { SPELL->blade_emote(str); return 1; }
blade_toggle()    { SPELL->blade_toggle(); return 1;   }
new_emotions()     { cat("/players/saber/closed/new_mini/doc/emotion"); return 1;  }
blade_more()       { cat("/players/saber/closed/new_mini/doc/blade_tricks"); return 1; }

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

query_blade_flag()   { return line_flag; }
set_blade_flag(str)  { line_flag = str;  }
query_master_flag()  { return master_flag; }
set_master_flag(str) { master_flag = str;  }
query_object_name()      { return "blade_obj"; }
set_quote(str)           { QUOTE = str; }
query_QUOTE()            { return QUOTE; }
query_time()     { return time;  }
set_time(str)     { time = str;  }
query_newguild()         { return "blade"; }
query_mini()             { return "base_obj"; }
set_is_blade(str)     { is_blade = str; }
