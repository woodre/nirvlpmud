inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_short("Talinek Eaglemark");
  set_name("talinek");
  set_alias("shopkeeper");
  set_race("human");
  set_gender("male");
  set_long(
"Talinek is a former lieutenant of the town guard who\n"+
"has become a prominent merchant in his old age.  While\n"+
"you can still see the tall height and powerful build\n"+
"that made him the strongest guard in the city, he now\n"+
"has a prominent paunch and his hair has turned grey.\n"
  );
  set_level(19);
  set_wc(30);
  set_ac(15);
  set_hp(450);
  set_al(-50);
  add_money(2000);
}
