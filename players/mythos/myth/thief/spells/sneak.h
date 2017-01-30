#define SNEAKCOST 70

sneak(string str,int chance) {
string dir;
object dest;
 if(!str) { write("sneak <dir>\n"); return 1; }
 if(tsp < SNEAKCOST) { write("You dont have enough sp.\n"); return 1; }
 if(!etp->query_shad()) {
 if(chance < random(100)) {
   write("You fail to sneak "+str+"\n");
   say(capitalize(tpn)+" stumbles.\n");
   command(str,tp);
 return 1; }
 dir = etp->query_dest_dir();
 if(member_array(str,dir) != -1) {
   write("You sneak "+str+"\n");
   tp->move_player("by sneaking "+str+"#" + dir[member_array(str,dir)-1]);
   tp->add_spell_point(-SNEAKCOST);
 } else write("There is no direction of "+str+"\n");
 } else {
   if(chance < random(100)) {
   write("You fail to sneak "+str+"\n");
   dest = environment(etp);
   move_object(tp,dest);
   say(capitalize(tpn)+" stumbles out from the shadows.\n");
   destruct(dest);
   return 1; }
 dir = environment(etp)->query_dest_dir();
 if(member_array(str,dir) != -1) {
   write("You sneak "+str+"\n");
   move_object(etp,"/"+dir[member_array(str,dir)-1]);
   etp->set_mp(1);
   command("look",tp);
   tp->add_spell_point(-SNEAKCOST);
   etp->set_mp(0);
 } else write("There is no direction of "+str+"\n");
 }
return 1; }
  