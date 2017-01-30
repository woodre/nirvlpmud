inherit "obj/weapon";
object cannon;
reset(arg) {
::reset(arg);
set_name("cannon");
set_alias("cannon");
set_class(19);
set_weight(4);
 /* set the weight to 17(from 4)  more realistic and quite frankly makes a good drawback  -mythos  <11/13/95> */
set_value(2000);
set_short("Shuriken-Pulse Cannon");
set_long("A long heavy barrel-shoulder strapped weapon. Uses during the Macross Wars by the Veritech Fighters....its a powerful weapon.\n");
set_save_flag(1);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(30) > 10) {
write(attacker->query_name()+" cringes and is blown away into bloody bits and pieces!\n");
return 2;
}
return 0;
}

