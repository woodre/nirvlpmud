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
    set_name(COLOR+"Faerie"+NORM);
    set_short(COLOR+"Faerie"+NORM);
    set_long(
    "This is a Faerie, it's a creature of nature and has stupendous spiritual\n"+
    "powers.  It has small wings that allow it to hover and fly about. Faeries are\n"+
    "generally very shy creatures who keep to themselves but it appears you\n"+
    "caught them in the middle of something.\n");
    set_alt_name("faerie");
    set_alias("faerie");
    set_race("faerie");
    set_gender("female");
    set_level(8);
    set_hp(100+random(30));
    set_wc(12+random(1));
    set_ac(6+random(2));
    add_money(200+random(225));
    set_chat_chance(4);
    set_a_chat_chance(4);
    load_chat(COLOR+"Faerie whispers:"+NORM+"The wizard created this world for all of us.\n");
    load_a_chat(COLOR+"Faerie screams:"+NORM+" This place is not for creatures like you!\n");
  }
}
