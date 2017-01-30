#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

int a;

reset(arg){
  object skates;
  ::reset();
  if(arg) return;
   set_name("Katarina");
   set_race("human");
   set_alias("katarina");
   set_gender("female");
     set_short("Katarina Witt");
     set_long("Katarina Witt, born in the former DDR (East Germany) is an athlete, \n"+
              "an artist, an actress, a television personality and a business woman.\n"+
              "In the course of a truly unique career, she's won more titles than \n"+
              "anyone else before her and become the most successful figure-skater of \n"+
              "all time.  Memorable are her victories at The Olympics in Sarajevo,\n"+
              "1984 and in Calgary, 1988.  Meet her at http://www.katarinawitt.de \n");
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
   skates= clone_object("/players/francesco/hall/items/skates2.c");
   move_object(skates,this_object());
   init_command("wear skates");
}

id(str) {return str=="katarina" || str=="katarina witt" || str=="witt" ;}

