inherit "obj/monster";
#include "/players/persephone/rooms.h"
object robe;
object dres;
object gold;
reset(arg) {
  ::reset(arg);
    if(arg) return;
    robe = clone_object("players/hat/object/hat.c");
    move_object(robe, this_object());
    dres = clone_object("players/persephone/armour/uni.c");
    move_object(dres, TOB);
    init_command("wear uniform");
    gold = clone_object("obj/money");
    gold->set_money(10000+random(3000));
    move_object(gold, TOB);
      set_name("jeny");
      set_alias("maid");
      set_alias("servant");
      set_short("A lovely looking maid");
      set_long("An elegant looking maid with a stunning figure\n"+
               "who is wearing a french maid's uniform and a\n"+
               "maids hat.  What disturbs you is her evil look\n"+
               "and well toned body.  She definately is someone\n"+
               "you would not want to mess with\n");
      set_level (50);
      set_wc (80);
      set_ac (40);
      set_hp(4000);
      set_al(-1000);
      set_aggressive(0);
      set_gender ("female");
      set_chance(10);
      set_spell_dam(10);
        set_spell_mess1("Jeny spits out a molten liquid");
        set_spell_mess2("Jeny spits acid into your face burning it.");
      set_chat_chance(20);
      set_a_chat_chance(30);
      load_chat("Jeny sneers: Soon this town will be completely deserted.\n");
      load_chat("Jeny exclaims: I will teach them how to treat me!\n");
      load_chat("Jeny asks: What now you have my orders\n");
      load_a_chat("Jeny screams: You will pay for your treatchery\n");
      load_a_chat("Jeny yells: Come to my aid men\n");
      load_a_chat("Jeny snickers: You cannot hurt me\n");
}
