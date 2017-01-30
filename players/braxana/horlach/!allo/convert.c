object para;
int conversion; /* ranging from 1 - 20 */

pursuede(str) {
object who;
  if(!str) return;
  who = present(str,environment(this_object()));
  if(!who) who = present(str,this_object());
  if(!who) return;
  if(!living(who)) return;
  if(conversion > random(20)) para += ({who});
  who->set_aggressive(1);
return 1; }

lead() {
  int h;
  for(h=0;h<sizeof(para);h++) {
   if(!para[h]) para -= ({para[h]});
   if(environment(para[h]) != environment(this_object()) &&
       !para[h]->query_attack()) {
     move_object(para[h],this_object());
   }
   if(conversion > 15) {
    if(query_attack()) {
      if(!para[h]->query_attack() ||
          para[h]->query_attack() != query_attack())
      para[h]->attack_ob(query_attack());
    }
   }
call_out("lead",3);
return 1; }


