init() {
   add_action("flame","flame");
       }
id(str) {
   return str == "spell"; 
        }
get() {return 1;}
drop() {return 0; }
short() {
    return "flame strike spell";
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
   victim = find_living(str);
   if(!str) {
      write("read it again, you must have mispronounced you target\n");
      return 1; }
if(str==owner) {
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
if(environment(owner) == environment(victim)) {
   write("You read the yellowing parchment putting "+capitalize(str)+
         "\nin where needed and a huge rumbling takes place as a \n"+
         "of fire strikes your opponent\n");
say(owner->query_real_name()+" reads from an old yellowing parchment\n");
victim->attacked_by(owner);
victim->hit_player(35);

tell_object(victim, "A great cone of wind and fire drop from\n" +
                    "the heavens to engulf you\n");
destruct(this_object());
write("The parchment burns away leaveing only ashes\n");
return 1; 
}
}
