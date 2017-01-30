inherit "obj/monster";
object wep, elf, gold;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("elf");
   set_alias("noble");
   set_short("Dinin the Drow Noble");
   set_long("This is an member of one of the most feared of all races."+
" the Drow or dark elves. His skin is black as coal and his hair is a "+
" stark white. His build is thin but muscular. He e twirls the sword in "+
" his hand like he was born with it.\n");
   set_level(13);
   set_hp(400);
   set_al(-1000);
    wep=clone_object("/players/nightshade/weap/lswd");
   move_object(wep,this_object());
   init_command("wield sword");
   set_wc(20);
   set_ac(12);
   set_chance(20);
   set_spell_dam(20);
   set_spell_mess1("A lightning bolt flys from the fingers of Dinin!");
   set_spell_mess2("You see Dinin point at you and let loose a lightning bolt!");
elf=clone_object("players/nightshade/armor/amulet");
move_object(elf, this_object());
   gold = clone_object("obj/money");
   gold->set_money(random(100)+300);
   move_object(gold, this_object());
  
}
