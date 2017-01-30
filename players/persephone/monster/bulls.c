inherit "obj/monster";
#include "/players/persephone/rooms.h"
object whip,wobble,gold;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      gold = clone_object("obj/money");
      gold->set_money(800+random(4000));
      move_object(gold, TOB);
      whip = clone_object("players/persephone/closed/wip.c");
      move_object(whip,TOB);
      init_command("wield whip");
      set_name("baldemar");
      set_alias("torturer");
      set_alias("pirate");
      set_short("Baldemar the Skinflayer");
      set_long("Perhaps the most evil looking representative\n"+
               "of human kind. He seems as if he would rather\n"+
               "remove the skin from your back than give you\n" +
               "the time of day. He definately enjoys his work\n\n");
      set_level (29);
      set_wc (48);
      set_ac (26);
      set_hp(950);
      set_al(0);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(30);
      set_a_chat_chance(30);
      load_chat("Baldemar sneers: You might as well talk!\n");
      load_chat("Baldemar walks over to the torture rack\n");
      load_chat("Baldemar cracks his Cat O'Nine Tails\n");
      load_chat("Baldemar slaps his victim\n");
      load_a_chat("Baldemar growls: You think you can stop me\n");
      load_a_chat("Baldemar glares at you wildly\n");
      load_a_chat("Baldemar froths at the mouth rabidly\n");
      set_chance(30);
      set_spell_dam(40);
      set_spell_mess1("Baldemar throws acid throughout the room");
      set_spell_mess2("Baldemar throws a glass of acid in your face burning it!!");
}
second_life(){
  wobble=clone_object("players/persephone/closed/dedy");
  move_object(wobble,TPL);
  ::second_life();
}

