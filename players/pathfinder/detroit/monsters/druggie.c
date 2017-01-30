inherit "obj/monster";
 
reset(arg){
   object gold,armor,weapon;
   int i;
   ::reset(arg);
   if(arg) return;
   set_name("druggie");
   set_race("human");
   set_alias("pothead");
   set_alias("dopehead");
   set_short("A stoned druggie");
   set_long("\n"+
"  You see a very stoned druggie standing before you.  You have made him\n"+
"set down his joint and he looks very, very upset.  You see him reach for\n"+
"something and point it at you.\n");
   set_level(16);
   set_hp(200+random(400));
   set_aggressive(1);
   set_al(-500);
   set_wc(25);
   set_ac(15);
   set_chance(20);
   set_spell_dam(11);
   set_spell_mess1("Druggie blows smoke in your face!");
   set_spell_mess2("Druggie lets loose with the 9mm, blowing chunks out of you!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(1000)+500);
   move_object(gold,this_object());
   i = random(6) + 1;
   if(i > 0 && i < 3) {
    move_object(clone_object("players/pathfinder/detroit/weapons/uzi"), this_object());
    move_object(clone_object("players/pathfinder/detroit/weapons/clip"), this_object());
    move_object(clone_object("players/pathfinder/detroit/weapons/clip"), this_object());
    } else {
    move_object(clone_object("players/pathfinder/detroit/weapons/9mm"), this_object());
    move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
    move_object(clone_object("players/pathfinder/detroit/weapons/clipb"), this_object());
}
}
