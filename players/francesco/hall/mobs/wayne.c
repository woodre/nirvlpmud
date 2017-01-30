#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()

inherit "obj/monster";

reset(arg){
  object skates;
  ::reset();
  if(arg) return;
   set_name("Wayne");
   set_race("human");
   set_alias("wayne");
   set_gender("male");
     set_short("Wayne Gretzky");
     set_long("Wayne Gretzky is the greatest ice hockey player of all times, \n"+
              "according to several polls made by specialized magazines.  He\n"+
              "played in the NHL for several seasons, until the age of 38.  He\n"+
              "broke Gordie Howe's all-time NHL goal scoring record of 801 on \n"+
              "Mar. 23, 1994. All-time NHL leader in points (2857), goals (894)\n"+
              "and assists (1963).  He led Edmonton to 4 Stanley Cups (84-85,87-88).\n");
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
   skates= clone_object("/players/francesco/hall/items/skates1.c");
   move_object(skates,this_object());
   init_command("wear skates");
}

id(str) {return str=="wayne" || str=="gretzky" || str=="wayne gretzky" ;}

