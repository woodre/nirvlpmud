int con;

id(str) { return str == "count"; }
drop() {return 1;}
get() { return 0;}

set_count(n) { con = n; 
tell_object(environment(this_object(),"Count is: "+count+"\n"+
            "Type 'final' for the execution of the link!\n");}
query_count() { return con; }

init() {
  add_action("final","final");
}

final() {
object ob, ob2, ava, com;
int power, before, hhp;
power = this_player()->query_sp();
this_player()->add_spell_point(- power + 1);
ob2 = clone_object("/players/mythos/closed/guild/spells/spr_hear.c");
ob = first_inventory(environment(this_player()));
while(ob) {
  if(present("cir_ask",ob)) { 
  before = ob->query_sp();
  hhp = ob->query_hp();
  power = power + before;
  ob->add_spell_point(-before);
  ob->add_hit_point(10 - hhp);
  tell_object(ob,"Suddenly all your energy is drained! You are very tired.\n");
  destruct(present("cir_ask",ob)); 
  move_object(ob2,ob);}
  ob = next_inventory(ob);
  }
if(count < 5) { write("The spell fails!\n");
this_player()->add_hit_point(-random(100));
ob = first_inventory(environment(this_player()));
while(ob) {
  if(present("spr_hear",ob)) { 
  destruct( present("spr_hear",ob)); }
}
}
else {
  ava = clone_object("/players/mythos/closed/guild/spells/avatar.c");
  ob2->set_hp(power/count);
  move_object(ob2,environment(this_player())); 
  com = clone_object("/players/mythos/closed/spells/spirit_con.c");
  com->set_con(ob2);
  com->set_pcheck(dpp);
  move_object(com,tp);}
  destruct(this_object());
return 1;}

