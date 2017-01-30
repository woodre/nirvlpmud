inherit "obj/monster";
object fart, weap, ob, ring, boot, helm, cloak;
reset(arg)
{
::reset(arg);
if(arg) return;
set_name("vampire");
set_short("Count Magnus Lea");
set_alias("lea");
set_alias("count");
set_long(
"This vampire has been alive for 10000 years. He has been guarding\n"+
"this armor for half that time. It is very old and ancient but it\n"+
"still looks brand new and would make excelleent armor. The sword\n"+
"has been in the vampires possesion for some time now but that is\n"+
"a different story.\n");
set_level(15);
set_hp(600);
set_wc(22);
set_ac(13);
set_chance(40);
set_spell_dam(25);
set_spell_mess1("The vampire goes for a neck-bite!");
set_spell_mess2("The vampire manages to fang you in the neck!");
ob=clone_object("players/nightshade/weap/carp_sword");
move_object(ob, this_object());
weap=clone_object("players/nightshade/armor/carp_armor");
move_object(weap, this_object());
fart=clone_object("players/nightshade/armor/carp_shield");
move_object(fart, this_object());
ring=clone_object("players/nightshade/armor/carp_ring");
move_object(ring, this_object());
boot=clone_object("players/nightshade/armor/carp_boots");
move_object(boot, this_object());
helm=clone_object("players/nightshade/armor/carp_helm");
move_object(helm, this_object());
cloak=clone_object("players/nightshade/armor/carp_cloak");
move_object(cloak, this_object());
}
