#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";

reset(arg){
  object kale;
  ::reset();
  if(arg) return;
   set_name("city-dweller");
   set_race("human");
   set_alias("city-dweller");
   set_gender("female");
     set_short(HIC+"A city-dweller"+NORM+"");
     set_long("The city-dweller is wearing an elegant dress, most likely from a fashion\n"+
              "house.  She is carrying a small handbag  hanging on her shoulder.  Softly\n"+
              "smiling around she lowers her eyes when talking to others.\n");
   set_level(5);
   set_hp(100);
   set_wc(7);
   set_ac(12);
   set_chat_chance(1);
   load_chat("The city-dweller whispers to her companion: I was with Ceres in Hoover High School.\n");
   load_chat("The city-dweller smiles and wipes away a small tear off her cheek.\n");
   kale = clone_object("/players/francesco/wedding/invite.c");
   move_object(kale,this_object());
}

id(str) {return str=="city-dweller" ;}

