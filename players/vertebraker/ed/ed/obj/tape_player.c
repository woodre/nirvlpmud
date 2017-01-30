#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
string stopped_at;
inherit ITEM;
reset(arg) {
    if(arg) return;
    stopped_at = "first";
    set_id("tape player");
    set_alias("player");
    set_short("A tape player");
    set_long(
    "This a personal tape player.  You can 'press play' to continue a recording,\n"+
    "or 'press stop' to stop a playing in progress.\n");
    set_weight(2); }

init() {
    ::init();
    add_action("press_button","press"); }

get() { write("The tape recorder seems to be nailed to the table.\n"); return 0; }

press_button(arg) {
    if(!arg) { write("Press what?\n"); return 1; }
    if(arg == "play") {
        write("\nYou press the 'play' button...\n\n");
        say("\n"+TPN+" presses the 'play' button on the tape player.....\n\n");
        call_out(stopped_at,2);
        return 1; }
    if(arg == "stop") {
        write("\nYou press the 'stop' button...\n\n");
        say("\n"+TPN+" presses the 'stop' button on the tape player.....\n\n");
        remove_call_out("first");
        remove_call_out("second");
        remove_call_out("third");
        remove_call_out("fourth");
        remove_call_out("fifth");
        remove_call_out("sixth");
        remove_call_out("seventh");
        remove_call_out("eigth");
        remove_call_out("ninth");
        return 1; }
   }

first() {
    stopped_at = "first";
    say(
    HIW+"\n"+
"A voice speaks: '"+NORM+"It has been a number of years since I first started\n"+
"                 excavating the ruins of Con'dar with a group of\n"+
"                 my colleagues..."+HIW+"'\n\n"+NORM);
    call_out("second",7);
    return 1; }

second() {
    stopped_at = "second";
    say(
    HIW+"\n"+
"The voice continues: '"+NORM+"Now my wife and I have retreated to a small cabin\n"+
"                      in these solitary mountains... here I have continued \n");
    say(
"                      my research undisturbed by the myriad distractions of\n"+
"                      modern civilization and the groves of academe....."+HIW+"'"+NORM+"\n\n");
    call_out("third",7);
    return 1; }

third() {
    stopped_at = "third";
    say(
    HIW+"\n"+
"The voice continues: '"+NORM+"I believe I have made a significant find in the\n"+
"                      Con'darian ruins...  a volume of ancient Sumerian \n");
say(
"                      burial practices and funerary incantations... It is titled\n"+
"                      'Nonteron Demento' or, loosely translated,\n"+
"                                 'Book of the Dead'...."+HIW+"'"+NORM+"\n\n");
    say(
"There is a long pause in the recording....\n\n");
    call_out("fourth",8);
    return 1; }

fourth() {
    stopped_at = "fourth";
    say(
    HIW+"\n"+
"The voice goes on: '"+NORM+"It is.. bound in human flesh and inked in human\n"+
"                        blood.....\n");
say(
"                    The passages deal with demons, demon resurrection, and those\n"+
"                    forces that roam the forests and dark bowers of\n");
say(
"                    man's domain..."+HIW+"'"+NORM+"\n\n");
    call_out("fifth",7);
    return 1; }

fifth() {
    stopped_at = "fifth";
    say(
    HIW+"\n"+
"The voice continues: '"+NORM+"The first few pages warn that these enduring \n"+
"                      creatures of the night lie dormant but are never truly\n");
say(
"                      dead.  They may be recalled to life through the use of the\n"+
"                      incantations presented in this book.  Through recitation\n");
say(
"                      these passages, they are given license to _possess_ the\n"+
"                      living...."+HIW+"'"+NORM+"\n\n");
    call_out("sixth",6);
    return 1; }

sixth() {
    stopped_at = "sixth";
    say(
    HIW+"\n"+
"The voice rumbles: '"+NORM+"Dohrtre i'miztah berh hizartha tandeer mahneet mizantsobar\n"+
"                             somande rosaz darishteh heyka....."+HIW+"'"+NORM+"\n\n");
    call_out("seventh",4);
    return 1; }

seventh() {
    stopped_at = "seventh";
    say(
    HIW+"\n"+
"The voice rumbles: '"+NORM+"c o n ' d a r . .  .  .   ."+HIW+"'"+NORM+"\n\n");
    call_out("eighth",2);
    return 1; }

eighth() {
    stopped_at = "eighth";
    say(
    HIW+"\n"+
"The voice rumbles: '"+NORM+"c o n ' d a r . .  .  .   ."+HIW+"'"+NORM+"\n\n");
    call_out("ninth",2);
    return 1; }

ninth() {
    stopped_at = "ninth";
    say(
    HIW+"\n"+
"The voice roars: '"+NORM+"C   O   N   D   A   R"+HIW+"'"+NORM+"\n\n"+
HIY+"      A rift in reality suddenly opens!\n"+NORM);
    MOCO(ED1OBJ+"rift"),ENV(TO));
   say("    The tape player is sucked into the rift!\n");
    destruct(TO);
    return 1; }

