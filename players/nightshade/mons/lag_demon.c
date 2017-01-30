inherit "obj/monster";
object weap,ob,fart;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("demon");
set_short("Net Lag Demon");
set_alias("demon");
set_alias("count");
set_long(
"Yes folks this is the infamous net lag demon. He is responsible\n"+
"for all the lag you get when you are mudding. Now is your chance\n"+
"to take out your frustrations on him.\n");
set_level(15);
set_hp(225);
set_wc(20);
set_ac(12);
set_chat_chance(50);
load_chat("Connection closed by foreign host.\n");
ob=clone_object("players/nightshade/weap/lag_sword");
move_object(ob, this_object());
weap=clone_object("players/nightshade/armor/lag_armor");
move_object(weap, this_object());
fart=clone_object("players/nightshade/armor/lag_shield");
move_object(fart, this_object());
}
