inherit "/obj/monster.c";

#include "../defs.h"
string COLOR;
int a;

reset(arg) {
   ::reset(arg);
   if(arg) return;

    a = random(13);
    switch(a)
  {
    case 0: COLOR = HIR; break;
    case 1: COLOR = HIC; break;
    case 2: COLOR = HIW; break;
    case 3: COLOR = HIG; break;
    case 4: COLOR = HIY; break;
    case 5: COLOR = HIM; break;
    case 6: COLOR = HIB; break;
    case 7: COLOR = GRN; break;
    case 8: COLOR = YEL; break;
    case 9: COLOR = MAG; break;
    case 10: COLOR = RED; break;
    case 11: COLOR = CYN; break;
    case 12: COLOR = BLU; break;
}
    {
    set_name(COLOR+"Sprite"+NORM);
    set_short(COLOR+"Sprite"+NORM);
    set_long(
    "This is a sprite. They are magical creatures with mystical abilities.\n"+
    "The thing that is strange about these creatures is they seem very angry\n"+
     "about one thing or another. They whirl about at incredible speeds blurring\n"+
    "vision.  They have tiny wings that enable them to speed about and avert danger.\n");
    set_name(COLOR+"Sprite"+NORM);
    set_alt_name("sprite");
    set_alias("sprite");
    set_race("sprite");
    set_gender("female");
    set_level(8);
    set_wc(12);
    set_ac(7);
    set_hp(120);
    set_aggressive(1);
add_money(150+random(200));
    set_chat_chance(4);
    set_a_chat_chance(4);
    load_chat(COLOR+"Sprite screams:"+NORM+" Creatures like you ruin our garden and mischief!\n");
    load_a_chat(COLOR+"Sprite screams:"+NORM+" We hate fowl creatures like you and those dwarves!\n");
  }
}
