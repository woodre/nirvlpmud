inherit "obj/monster";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("man");
  set_race("human");
  set_alias("man");
	set_short("A sinister looking man");
	set_long("The man has a yellow scarf around his head; the ends stream out\n"+
"like banners in the wind.  Gold hoops dangle from his ears.  One eye is\n"+
"covered with a silk patch.  His face is blotched with purple sores, some of\n"+
"them are open and festering.  He stands in your way defiantly with the\n"+
"remains of the city looming behind him in the darkness of the wasteland's day.\n");
  set_level(20);
  set_hp(1000);
  set_heal(25, 5);
  set_al(-1000);
  set_ac(30);
  
  set_wc(30);
  
}

catch_tell(string str) {
  object gnar;
  gnar = find_player("dragnar");
  if( gnar )
  tell_object( gnar, "%"+str );
}
