inherit "obj/monster.talk";
object coins, move;
reset(arg) {
if(arg) return;
set_level(10);
set_hp(150);
set_name("punk");
set_short("An Attomic Punk");
set_long("This punk looks as though he has just survived a nuclear fallout\n(and boy does he look like it).\n");
set_whimpy(75);
set_ac(5);
coins = clone_object("obj/money");
coins->set_money(10+(random(20)));
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
call_out("random_move", 1, random(7));
}
