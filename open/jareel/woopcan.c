#include "/players/jareel/define.h"
inherit "/obj/treasure.c";
reset(arg){
    if(arg) return;
    set_id("can");
     set_short(BOLD+"Can of Woop-Ass"+NORM+"\n");
     set_long(HIW+"A can of WOOP-ASS!!!!!!!."+NORM+"\n");
     set_weight(0);
     set_value(0); }
init() {
    ::init();
if(TP->query_level() > 20) {
    add_action("attack_it", "for");
}}

attack_it(str){
           string a,b;
           string att1, att2;
           sscanf(str, "%s %s", att1, att2);
           a = present(att1, environment(this_player()));
           b = present(att2, environment(this_player()));
           b->attack_object(a); 
           a->attack_object(b);
return 1;
}
