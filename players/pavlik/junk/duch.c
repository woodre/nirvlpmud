inherit "obj/monster.talk";
 object coins, move, battery;
reset(arg) {
::reset(arg);
if(arg) return;
set_level(13);
set_hp(200);
set_name("Duchense");
set_short("Duchesne");
set_alias("duchesne");
set_long("This is Duchesne! The meanest, roughest, baddest assed player\n"+
"ever to hit the ice.  He will not hesitate to kill anyone with his godly\n"+
"slapshot or his (?illegal?) crosscheck.\n");
set_whimpy(30);
set_ac(13);
coins = clone_object("obj/money");
coins->set_money(300+(random(100)));
move_object(coins,this_object());
random_move();
}
random_move() {
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
call_out("random_move",1);
}
