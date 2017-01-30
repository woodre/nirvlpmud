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
   set_name("Mark");
   set_race("human");
   set_alias("mark");
   set_gender("male");
     set_short("Mark Spitz");
     set_long("Mark Spitz was swimming for the legendary Santa Clara Swim Club \n"+
              "under coach George Haines.  In the Olympics 1968 at Mexico City, \n"+
              "he was the favourite for several events, but the pressure took \n"+
              "him over and then he won merely (!!) two gold, one silver and \n"+
              "one bronze medals.  He moved to Indiana University under supervision \n"+
              "of James Doc Counsilman which lead him to a fantastic come back four \n"+
              "years laters, in the Olympics held in Munich (West Germany) when he \n"+
              "won the gold medal in all the seven events he participated (four \n"+
              "individual), more than any other swimmer to precede or follow him.\n"+
              "And, side, he set new world records in all the events he won.\n");
   set_level(17);
   set_hp(430+ random(40));
   set_wc(24+random(3));
   set_ac(11+random(3));
   set_chat_chance(10);
   set_heal(2,2);
   set_chance(20);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(12);
   swimsuit= clone_object("/players/francesco/hall/items/swimsuit4.c");
   move_object(swimsuit,this_object());
   init_command("wear swimsuit");
}

id(str) {return str=="mark" || str=="spitz" || str=="mark spitz" ;}

