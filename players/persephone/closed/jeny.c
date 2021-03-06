inherit "obj/monster";
#include "/players/persephone/rooms.h"
object robe;
object dres;
object wab;
object gold;
object head;
reset(arg) {
  ::reset(arg);
    if(arg) return;
    robe = clone_object("players/persephone/obj/hat.c");
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
      set_hp(10000);
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
second_life()
{
    head=clone_object("players/persephone/closed/heading");
    move_object(head, "players/persephone/rooms/attic");
    this_player()->add_exp(1000);
    write_file("/players/persephone/log/jen", capitalize(
    this_player()->query_real_name())+" killed Jeny. Level:"+
    this_player()->query_level()+". Time: "+ctime(time())+".\n");
    wab=clone_object("players/persephone/closed/wab.c");
    move_object(wab,TPL);
    ::second_life();
}
void
wibble_jeny(int amount)
{
    hit_point += amount;
    if (hit_point < 0)
        hit_point = 0;
    else if (hit_point > max_hp)
        hit_point = max_hp;
}

