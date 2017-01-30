#include "/players/vertebraker/define.h"
inherit NPC
reset(x) {
   if(x) return;
   ::reset();
   set_short("A gorilla");
   set_name("gorilla");
   set_level(5);
   set_hp(100); }

heart_beat() {
   int x; object *inv;
   ::heart_beat();
   if(!attacker_ob) {
      inv = all_inventory(USER);
      for(x=0;x<sizeof(inv);x++) {
         if(inv[x]->id("gorilla") && inv[x]->query_attack()) {
            tell_room(USER,"The gorilla beats its chest franticly and attacks!\n");
            attack_object(inv[x]->query_attack());
            return 1; } } }
}
