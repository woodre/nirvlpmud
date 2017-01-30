inherit "obj/monster.c";
object weapon, coins;  
reset(arg) {
::reset(arg);
if(arg) return;
set_name("monkey");
set_short("Monkey");
set_long("He is truly a unique being.  Once he was an official of the Celestial.\n"+  
         "Bureaucracy in the outer planes.  However for his tricks and mischief,\n"+
         "the Celestial Empire stripped him of much of his power and banished him\n"+
         "to this world.  He will only fight to embarrass you then kill you.  He\n"+
         "He is dress very fine robes.  You notice he has no weapons.\n");
set_al(0);
set_level(20);
set_wc(35);
set_ac(20);
set_hp(550);
set_aggressive(0);
coins=clone_object("obj/money");
coins->set_money(3000);
move_object(coins,this_object());
weapon = clone_object("players/mouzar/castle/armor/robe");
move_object(weapon,this_object());
}
 
