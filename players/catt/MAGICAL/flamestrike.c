#include "/players/vertebraker/ansi.h"

/* added more id's, and a valid_attack() check
    and colour and a new short() and other|fire dmg.
5.31.01 [Vertebraker] */
init() {
   add_action("flame","flame");
       }
id(str) {
   return str == "flame strike spell" || str == "strike" ||
    str == "flame strike" || str == "spell" || str == "parchment";
        }
get() {return 1;}
drop() {return 0; }
short() {
    return HIR + "Flame" + NORM + " strike Spell";
        }
long() {
     write("You see an old parchment. It contains one Flame Strike Spell.\n"+
           "to use type: flame (monster)\n");
     return 1; 
       }
reset(arg) {
   if(arg) return;
           }
flame(str) {
   object victim, owner;
   owner = this_player();
   victim = present(str, environment(owner));
   if(!str) {
      write("read it again, you must have mispronounced your target\n");
      return 1; }
/*
if(victim == owner) {
   write("The gods won't let you kill yourself\n");
               }
if(!victim || !living(victim)) {
  write("You can't cast on that\n");
  return 1; }
if(victim->query_npc()==0 && victim->query_pl_k()==0) {
   write("Catt thunders: that player doesn't have his option set!\n");
   return 1;
          }
if(victim->query_npc()==0 && owner->query_pl_k()==0) {
  write("Catt thunders: you must have your option set to do that!\n");
  return 1;
   }
*/
  if(!victim) { write("they aren't here.\n"); return 1; }
if(environment(owner) == environment(victim)) {
   if(!this_player()->valid_attack(victim)) return 1;
   write("You read the yellowing parchment putting "+capitalize(str)+
         "\nin where needed and a huge rumbling takes place as a \n"+
         "column of fire strikes your opponent\n");
say(owner->query_real_name()+" reads from an old yellowing parchment.\n");
say("A large column of fire decends from the heavens engulfing "+
     victim->query_real_name()+".\n");

tell_object(victim, "A great cone of wind and fire drops from\n" +
                    "the heavens to engulf you\n");
   victim->attacked_by(owner);
   victim->hit_player(35, "other|fire");
destruct(this_object());
write("The parchment burns away leaving only ashes\n");
return 1; 
}
   write("They aren't here.\n"); return 1;
}
query_save_flag() { return 1; } /* We don't want players stocking up on these! -Feldegast July 2000 */
