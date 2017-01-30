
#include "/players/jaraxle/define.h"

id(str) { return str == "TC" || str == "tc" || str == "thunder cat patch" || str == "patch"; }
long(){ write("A ThunderCats arm patch. This is a symbol of your alliance to the\nThunderCats. "+HIW+"<"+HIR+"t_help"+HIW+">"+NORM+" for rules.\n"); }
short(){ return ""+RED+"(="+BOLD+"("+BLK+"TC"+RED+")"+NORM+RED+"=)"+NORM+""; }
somefunction() {
write("A bright red beam glows in the middle of the sky!\nA lion's head in a red circle!\nTHUNDER CATS... HO!!\n");
return 1; }
drop(){ return 1;}

query_auto_load(){ return "players/jaraxle/3rd/lair/items/t_patch.c:";}

