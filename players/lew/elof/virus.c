inherit "obj/monster";

int move;
reset(arg) {
::reset(arg);

  if(!arg) {

    set_name("watchdog");
    set_alias("virus");
    set_long("This is a protection program.\n");
    set_level(5);
    set_hp(300);
    set_wc(12);
    set_ac(3);
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
