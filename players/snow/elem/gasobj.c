id(str) {return str == "gasobj";}
get() {return 1;}
can_put_and_get() {return 0;}
reset(arg) {
   if(arg) return;
 
call_out("gashurt",10);
call_out("cough",2);
}

gashurt() {
object ob;
ob = first_inventory(environment(this_object()));
    while (ob) {
  if (ob->is_ghost()) {ob = next_inventory(ob);}
call_other(ob,"hit_player",5);
ob = next_inventory(ob);
  }
say(
"The acidic gas burns your skin!\n");
call_out("gashurt",10);
return 1;
}

cough() {
object ob;
ob = first_inventory(environment(this_object()));
    while (ob) {
  if(ob->query_level() > 20) {ob = next_inventory(ob);}
  if(ob->is_player()) {
command("cough",ob);
     }
ob = next_inventory(ob);
  }
call_out("cough",2);
return 1;
}
