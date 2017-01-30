inherit "obj/monster";
	object crossbow, gold;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("man");
  set_race("man");
  set_alias("man");
	set_short("A sinister looking man");
	set_long("The man has a yellow scarf around his head; the ends stream out\n"+
"like banners in the wind.  Gold hoops dangle from his ears.  One eye is\n"+
"covered with a silk patch.  His face is blotched with purple sores, some of\n"+
"them are open and festering.  He stands in your way defiantly with the\n"+
"remains of the city looming behind him in the darkness of the wasteland's day.\n");
  set_level(18);
  set_hp(1);
  set_al(-1000);
  set_wc(26);
  set_ac(15);
  gold = clone_object("obj/money");
	gold->set_money(random(2000)+1000);
  move_object(gold,this_object());
	crossbow=clone_object("/players/dragnar/test/soulbind.c");
	move_object(crossbow, this_object());
  set_dead_ob(this_object());

}

monster_died() {
  if( attacker_ob && crossbow ) {
    crossbow->set_binder( attacker_ob->query_real_name() );
    tell_room( environment(), "A flash of light flashes from the bow as it is soulbound to "+
      attacker_ob->query_name()+".\n" );
  }
}

