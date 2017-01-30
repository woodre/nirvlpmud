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
   set_name("Chet");
   set_race("human");
   set_alias("chet");
   set_gender("male");
     set_short("Chet Jastremski");
     set_long("Chet Jastremski was the world's best breaststroker in the 60's.\n"+
              "He was first to introduce a completely innovative style.\n"+
              "Won several AAU titles as a captain of the Indiana University\n"+
              "swimming team.  Participated into three Olympic Games.\n");
   set_level(19);
   set_hp(620+random(100));
   set_wc(31+random(5));
   set_ac(20+random(5));
   set_chat_chance(10);
   set_heal(2,2);
   set_chance(25);
   set_spell_mess2("");
   set_spell_mess1("");
   set_spell_dam(25);
   swimsuit= clone_object("/players/francesco/hall/items/swimsuit.c");
   move_object(swimsuit,this_object());
   init_command("wear swimsuit");
}

id(str) {return str=="chet" || str=="jastremski" || str=="chet jastremski" ;}

