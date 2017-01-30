/* beta potato code by vertebraker n' fakir */

#include "/players/vertebraker/define.h"
inherit TREASURE

reset(arg) {
    if(arg) return;
    set_id("potato");
    set_alias("hot potato");
    set_long(
"This is a steaming hot potato!  If you have this potato, that means you\n"+
"had better throw it fast, 'for it 'xplodes on ya!\n"+
"The stamp on the side reads:  Idaho- Packaged by the Fakibraker Co.\n");
    set_weight(0); }


init() {
    ::init();
    add_action("throw_it","throw");
    call_out("uh_oh",5);
    }

throw_it(arg) {
    int x;
    object who;
    x = random(10);
    who = find_player(arg);
    if(!who && who->query_invis()) {
        write("You can't throw the potato at them, they aren't even here!\n");
        return 1; }
    if(who->query_level() > 19) {
        write("Wizards don't wanna play Hot Potato.\n");
        return 1; }
    if(x < 2) {
        write("You throw the potato, but it just flies a few miserable yards before it falls to the earth,\n"+
              " splattering potato stuff (yum!) all over you.  Yuck!\n");
        tell_object(who,
"You hear "+CAP(USER->query_real_name())+" scream in agony as their potato detonates!\n");
        USER->set_title(HIG+"is covered in mashed potatoes!"+NORM);
        destruct(TO);
        return 1; }
    tell_object(USER,"You throw the potato to "+CAP(arg)+" and it lands in their hand! <whew>\n");
    tell_object(who,"Something just landed in your paw.  You glance down and realize it's a hot potato (tm)!\n"+
                    "You better get rid of this "+BOLD+RED+"FAST"+NORM+"!\n");
    move_object(TO,who);
    remove_call_out("uh_oh");
    return 1; }

uh_oh() {
    tell_object(USER,"The potato trembles...  Not much time left now! [_THROW IT NOW!_]\n");
    call_out("oh_god",5);
    remove_call_out("uh_oh");
    return 1; }

oh_god() {
    tell_object(USER,"This is it... RAGNAROK..... THROW IT NOW OR DIE!\n");
    call_out("make_the_hurting_stop",5);
    remove_call_out("oh_god");
    return 1; }

make_the_hurting_stop() {
    tell_object(USER,"Are you an idiot?  Throw the potato!  LAST WARNING!\n");
    call_out("judgment_day",5);
    remove_call_out("make_the_hurting_stop");
    return 1; }

judgment_day() {
    tell_room(ENV(USER),HIR+"\n\n\  K\n   A\n    B\n     L\n      O\n       O\n        E\n         Y\n\n\n"+NORM);
    tell_object(USER,"The potato just went nuclear.  Sorry, you lose.  Better luck next time in 'Hot Potato!'\n");
    USER->set_title(HIG+"is covered in mashed potatoes!"+NORM);
    destruct(TO);
    return 1; }

drop() {
    if(TP->query_level() < 20) { return 1; }
}
short() { return "A potato ("+HIR+"HOT!"+NORM+")";
}
