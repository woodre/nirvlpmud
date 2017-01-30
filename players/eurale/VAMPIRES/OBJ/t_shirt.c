/*
 t_shirt.c
*/

#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
  ::reset(arg);

set_name("t-shirt");
set_alias("shirt");
set_short(BOLD+"Vampire Guild T-shirt"+NORM);
set_long(BOLD+
"                     Official Vampire Guild T-shirt"+NORM+"\n"+
HIR+
"                       -.                       .-\n"+
"                   _..-'(                       )`-.._\n"+
"                ./'. '||\\\\.      |\\___/|      .//||` .`\\.\n"+
"             ./'.|'.'||||\\\\|..   \\ -v- /   ..|//||||`.`|.`\\.\n"+
"          ./'..|'.|| |||||\\``````=(___)=''''''/||||| ||.`|..`\\.\n"+
"        ./'.||'.|||| ||||||||||||. V-V .|||||||||||| ||||.`||.`\\.\n"+
"       /'|||'.|||||| |||||||||||||     ||||||||||||| ||||||.`|||`\\\n"+
"     '.||| ||||||||| |/'   ``\\||``     ''||/''   "+
"`\\| ||||||||| |||.`\n"+
"     '.||| ||||||||| |/'   ``\\||``     ''||/''   `\\| ||||||||| |||.`\n"+
"     |/' \\./'     `\\./         \\!|\\   /|!/         \\./'     `\\."+
"/ `\\|\n"+
"     V    V         V          }' `\\ /' `{          V         V    V\n"+
"     `    `         `               V               '         '    '\n"+
"                       I want to suck your blood!\n"+
NORM+"\n\n");
set_value(25);
set_weight(1);
set_ac(1);
set_type("chest");
set_save_flag();
}
