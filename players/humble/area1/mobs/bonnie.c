/*HUMBLE CORPS 2004*/
#include "../defs.h"

inherit "/obj/monster";

reset(arg) {
    object gold;
    ::reset(arg);
    if (!arg)  {
    gold = clone_object("obj/money");
    money=3800+random(800);
       move_object(gold,this_object());
    move_object(clone_object("/players/humble/area1/objs/apron1.c"));
    init_command("wear apron");
    set_name("Bonnie");
    set_alt_name("bonnie");
    set_alias("bonnie");
    set_short(HIW+"Bonnie"+NORM);
    set_race("human");
    set_long(
    "Bonnie appears to be in her early 40s.  She is a healthy woman\n"+
    "with an incredible smile and the greatest ass you've ever seen.\n"+
    "She looks like she could really fuck you up though, I'd leave her alone.\n");
    set_gender("female");
    set_level(20);
    set_ac(17+random(2));
    set_wc(29+random(3));
    set_hp(475+random(75));
    set_al(0);
    set_chat_chance(6);
    load_chat(HIW+"Bonnie sighs and says:"+NORM+" Dood, I know, I know.\n");
    load_chat(HIW+"Bonnie takes a drag from her cigarette and while exhaling says:"+NORM+" Dood, whatever.\n");
    set_a_chat_chance(7);
    load_a_chat(HIW+"Bonnie grins and says:"+NORM+" Dood, I'm gonna fuuuuuuck you up soo bad.\n");
    load_a_chat(HIW+"Bonnie grits her teeth and says:"+NORM+" Dood, I was a marine.\n");
    set_chance(15);
    set_spell_dam(50+random(30));
    set_spell_mess1(
    HIW+"Bonnie grabs her attacker with a fierce grip and begins to knock the living\n"+NORM+
    HIW+"snot out of them. Looks painful.\n"+NORM);
    set_spell_mess2(
    HIW+"Bonnie slides her hands smoothly up your body and before you know it she has you by the neck.......\n"+NORM+
    HIB+"    *****************************************************\n"+NORM+
    BLU+"    !*************************!BAM!********************! \n"+NORM+
    HIB+"    *****************************************************\n"+NORM);
    }
}
