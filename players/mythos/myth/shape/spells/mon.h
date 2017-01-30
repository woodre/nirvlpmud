string animal; string an_short; 
int an_level; int an_hp; int an_wc; int an_ac;
int an_chance; int an_dam; string an_tell; string an_mess;
int an_chat_chance; int an_chat_att_chance; string an_chat;
string an_att_chat;

#include "/players/mythos/myth/shape/spells/an_set.h"
set_what(str) {
int wha,k;
  wha = member_array(str,animal);
  set_name(str);
  set_short(an_short[wha]);
  set_level(an_level[wha]);
  set_hp(an_hp[wha]);
  set_wc(an_wc[wha]);
  set_ac(an_ac[wha]);
  k = 0;
  while(k < MAXSPELL) {
  set_chance(an_chance[wha][k],k);
  set_spell_dam(an_dam[wha][k],k);
  set_spell_tell(an_tell[wha][k],k);
  set_spell_mess(an_mess[wha][k],k);
  k = k + 1; }
  k = 0;
  while(k < MAXCHAT) {
  set_chat_chance(an_chat_chance[wha],k);
  set_chat_att_chance(an_att_chance[wha],k);
  set_chat_mess(an_chat[wha][k],k);
  set_chat_att_mess(an_chat_att[wha][k],k);
  k = k + 1;
  }
  set_al(0);
  set_race("spirit");
}

set_who(ob) {
  summoner = ob; 
}