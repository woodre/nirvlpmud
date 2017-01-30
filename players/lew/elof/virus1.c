inherit "obj/monster";

int move;

reset(arg) {
::reset(arg);

  if(!arg) {

    set_name("zombie");
    set_alias("virus");
    set_long("This is an active anti-personell program.\n");
    set_level(3);
    set_hp(1000);
    set_wc(5);
    set_ac(12);
   set_aggressive(1);
call_out("random_move",10);
}
}
random_move() {
if(!environment(this_object())) return 1;
move = random(7);
if (move == 0)
   command("north");
else if (move == 1)
   command("south");
else if (move == 2)
   command("east");
else if (move == 3)
   command("west");
else if (move == 4)
   command("northeast");
else if (move == 5)
   command("southeast");
else if (move == 6)
   command("southwest");
else if (move == 7)
   command("northwest");
call_out("random_move",10);
return 1;
}

heart_beat() {
    int point;
  ::heart_beat();
   if(!environment(this_object())) return;
    point=random(100);
  if(!attacker_ob) return;
  if(attacker_ob->query_npc()) return;
    if(point<10) {
   if(call_other(attacker_ob, "query_attrib", "int") > 8) {
     call_other(attacker_ob, "raise_intelligence", -1);
/* Added this to put stats back, mob not worth enough xp to take them 
   permanently - Rumplemintz.
*/
     call_out("put_stat_back", 60, attacker_ob);
  tell_object(attacker_ob, "You feel a lose of intelligence as zombie blasts your mind.\n");
}
}
}

int put_stat_back(object ob) {
  if(!ob) return 0;
  tell_object(ob, "Your intelligence returns.\n");
  ob->raise_intelligence(1);
  return 1;
}
