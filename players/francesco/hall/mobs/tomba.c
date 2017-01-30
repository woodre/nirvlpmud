#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  object skiboots;
  ::reset();
  if(arg) return;
   set_name("Alberto");
   set_race("human");
   set_alias("alberto");
   set_gender("male");
     set_short("Alberto Tomba");
     set_long("Alberto Tomba is one of the rare examples of top skiers born\n"+
              "in a plain city, outside of the mountains.  He was specialized\n"+
              "in slalom and giant slalom, and won more than fifty World Cup \n"+
              "races.  He had introduced a new ski style, which was based on\n"+
              "precise lines and very close to posts.  It was a very risky one,\n"+
              "because it was easier to make a mistake and lose the race.  Even\n"+
              "without running the dowhills, nor the supergiants nor the combineds,\n"+
              "he won one General Ski World Cup in 1994.  Also, he was the first\n"+
              "to win the same event in two consecutive Olympics namely the giant \n"+
              "slalom in Calgary 1988 and in Albertville 1992.  Sides, he won one\n"+
              "more gold and two silver metals in other events during three next\n"+
              "Olympics.  He retired at the age of 32 after leaving a deep mark of\n"+
              "his class in the alpine ski.\n");
   set_level(20);
   set_hp(520+random(100));
   set_wc(32+random(5));
   set_ac(20+random(5));
   set_chat_chance(10);
   set_heal(2,4);
   set_chance(25);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(25);
   skiboots= clone_object("/players/francesco/hall/items/skiboots.c");
   move_object(skiboots,this_object());
   init_command("wear skiboots");
}

id(str) {return str=="alberto" || str=="tomba" || str=="alberto tomba" ;}

