#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/monster.c";


reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("skwik");
  set_alt_name("bar_owner");
  set_alias("bartender");
  set_short("Skwik the bartender");
  set_long(
"This is the bartender Skwik.  Not gifted with wits or cunning, he\n"+
"barely makes a living as the other skaven extort money from him.\n");
  set_gender("male");
  set_race("skaven");
  set_level(1);
  set_wc(500);
  set_ac(300);
  set_hp(2000);
  set_al(0);
  set_aggro(0, 0, 0);
  add_money(1);  
/* Deliberate bad grammer here */
  set_chat_chance(5);
load_chat(
   "Skwik twitches his whiskers.\n");
load_chat(
   "Skwik squeaks: You look for somethin'?\n");
load_chat(
   "Skwik squeaks: Hey you!  Buy now or leave!\n");
load_chat(
   "Skwik squeaks: You buy now or leave!\n");

}
