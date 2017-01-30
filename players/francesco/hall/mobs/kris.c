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
   set_name("Kristina");
   set_race("human");
   set_alias("kris");
   set_gender("female");
     set_short("Kristina Egerszegi");
     set_long("Kristina Egerszegi has been the greatest backstroker of all times.\n"+
              "She won the same event during three Olympics in a row, first one \n"+
              "at the age of 14 and totalling 5 golds.  Light as a cork, her style\n"+
              "was a pleasure at the eyes of the true connoisseurs of the swimming.\n");
   set_level(19);
   set_hp(520+random(80));
   set_wc(31+random(5));
   set_ac(20+random(5));
   set_chat_chance(10);
   set_heal(2,2);
   set_chance(25);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(25);
   swimsuit= clone_object("/players/francesco/hall/items/swimsuit2.c");
   move_object(swimsuit,this_object());
   init_command("wear swimsuit");
}

id(str) {return str=="kris" || str=="kristina" || str=="kristina egerszegi" || str=="egerszegi" ;}

