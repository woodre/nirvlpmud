
/* 
 * MARK (2/12/94)
 * Placed on monster to notify marker if another player is
 * attacking their monster. Lasts 5 minutes.
 */

#define DURATION 300
#define MARKER find_player(marker)
#define NOTIFY_INTV 30

string marker;
object monster;
int notified;

query_marked() { return 1; }

query_marker() { return marker; }

start_mark(who,player) {
   monster = who;
   marker = player;
   shadow(monster,1);
   call_out("remove_mark", DURATION);
   return 1;
}

remove_mark() {
   if(MARKER)
     tell_object(MARKER, "*** Your marker has worn off ***\n");
   shadow(monster,0);
   destruct(this_object());
   return 1;
}

short() { return monster->short()+" [MARKED BY "+capitalize(marker)+"]"; }

hit_player(dam) {
   
   if(!MARKER) {
     remove_mark();
     return 1;
   }
   if(monster->query_attack() != MARKER && !notified) {
     notify_marker();
     notified = 1;
   }
   dam = monster->hit_player(dam);
   return dam;
}

notify_marker() {
   string att;

   if(!monster->query_attack() || 
                !present(monster->query_attack(),environment(monster))) {
     notified = 0;
     return 1;
   }
   att = (monster->query_attack())->query_real_name();
   if(!att) att = "something";
   tell_object(MARKER, "*** "+capitalize(att)+
                                " is attacking your monster. ***\n");
   call_out("notify_marker", NOTIFY_INTV);
   return 1;
}


