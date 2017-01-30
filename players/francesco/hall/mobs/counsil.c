#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

int a;

reset(arg){
  object chrono;
  ::reset();
  if(arg) return;
   set_name("Doc");
   set_race("human");
   set_alias("doc");
   set_gender("male");
     set_short("James (Doc) Counsilman");
     set_long("James (Doc) Counsilman coached Indiana men's swim team to 6 NCAA\n"+
              "championships (1968-73); coached the '64 and '76 U.S. men's Olympic \n"+
              "teams that won a combined 21 of 24 gold medals; in 1979 became oldest \n"+
              "person (59) to swim English Channel; retired in 1990 with dual meet \n"+
              "record of 287-36-1.\n");
   set_level(16);
   set_hp(300+ random(40));
   set_wc(22+random(2));
   set_ac(13+random(2));
   set_chat_chance(10);
   set_heal(2,2);
   set_chance(10);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(10);
   chrono= clone_object("/players/francesco/hall/items/chrono.c");
   move_object(chrono,this_object());
}

id(str) {return str=="doc" || str=="james" || str=="james counsilman" || str =="counsilman";}

