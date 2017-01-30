inherit "obj/monster.talk";
 object coins, move, battery;
reset(arg) {
::reset(arg);
if(arg) return;
set_level(16);
set_hp(450);
set_name("A Wandering Ghost");
set_short("A Ghost");
set_alias("ghost");
set_long("A wandering ghost forever cursed to wander a world it no longer\n"+
"belongs to.\n");
set_whimpy(20);
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
