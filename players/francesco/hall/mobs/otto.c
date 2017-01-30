#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

int a;

reset(arg){
  object swimsuit;
  ::reset();
  if(arg) return;
   set_name("Kristin");
   set_race("human");
   set_alias("kris");
   set_gender("female");
     set_short("Kristin Otto");
     set_long("Kristin Otto reached her full maturity at the age of 22, when swam\n"+
              "in the Olympics at Seoul.  She was the first woman to win 6 golds\n"+
              "(four individual).  She was famous for her start dive by which she\n"+
              "could take the lead of the run by even 2 meters just after emerging\n"+
              "from the dive.\n");
   set_level(17);
   set_hp(350+random(30));
   set_wc(24+random(3));
   set_ac(14+random(3));
   set_chat_chance(10);
   set_heal(2,4);
   set_chance(25);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(5);
   swimsuit= clone_object("/players/francesco/hall/items/swimsuit3.c");
   move_object(swimsuit,this_object());
   init_command("wear swimsuit");
}

id(str) {return str=="kris" || str=="kristin" || str=="kristin otto" || str=="otto" ;}

