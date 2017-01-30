#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg){
    ::reset(arg);
   if(arg) return;
    set_name("jennie");
    set_alias("child");
    set_long("\
This small child stands about 4 ft tall and is shivering with\n\
fear.  Tears stream down her dirt stricken face.  Her soft blonde\n\
curls have gone limp as her hair is caked with muck.  The blue\n\
dress she wears is torn in many places and scratches fill her arms\n\
and legs.  You might wish to 'free' Jennie.\n");
    set_level(1);
    set_hp(1);
    set_ac(0);
    set_wc(3);
    set_al(500);
    set_race("human");
    set_gender("female");
    set_chat_chance(3);
    load_chat("Jennie says: please free me\n");
    load_chat("Jennie says: I have been a prisoner for 3 months.  If only i could escape.\n");
}

init(){
    add_action("free","free");
}

int free(string str){
  object lt;
  if (!str || str != "jennie"){
    notify_fail("What would you like to free?\n");
    return 0; 
  } 
  say(this_player()->query_name()+" frees Jennie.\nJennie give "+this_player()->query_name()+" a kiss.\nJennie runs out of the cave.\n");
  lt = clone_object("/obj/monster");
  lt->set_name("guard");
  lt->set_short("A "+GRN+"captain of the nonge"+NORM+" guard");
  lt->set_long("\
This fine nonge towers over you.  He is half dressed but his\n\
markings and demeanor show he was responsible for Jennie.\n\
He wears a fine suit of armor and his fur is in shambles.\n");
  lt->set_al(1000);
  lt->set_race("seussian");
  lt->set_alias("nonge");
  lt->set_level(22);
  lt->set_hp(700);
  lt->set_wc(50);
  lt->set_ac(25);
  lt->add_money(2500);
  lt->set_aggressive(1);
  move_object(lt,environment(this_object()));
  say("A guard lunges into the room and notices that Jennie is missing.\n");
  lt->attack_object(this_player());
  move_object("/players/wocket/mushrooms/armor.c",lt);
  destruct(this_object());
  return 1;
}
