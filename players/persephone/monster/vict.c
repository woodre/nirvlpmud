inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object ttube;
   ttube = clone_object("players/persephone/obj/ttube.c");
   move_object(ttube, TOB);
   set_name("victoria");
   set_alias("womble");
   set_short("Victoria Womble");
   set_long("A motherly looking Womble small but slightly chubby\n" +
            "normally you think she would wear an apron but she is not today.\n");
   set_level(5);
   set_wc(9);
   set_ac(5);
   set_hp(80);
   set_al(800);
   set_aggressive(0);
   set_gender(0);
   set_chance(0);
   set_spell_dam(0);
   set_chat_chance(50);
    load_chat("Victoria sighs: Oh Einstein always leaves stuff lying around\n");
    load_chat("Victoria scurries around looking for a safe place to put something.\n");
    load_chat("Victoria scurries around looking for something.\n");
  }
}

