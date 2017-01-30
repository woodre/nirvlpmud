
inherit "/obj/monster";

reset(arg) {
  object equip;
  if(!present("mail")) {
    move_object(clone_object("/players/feldegast/equip/anc_mail"),this_object());
    init_command("wear mail");
  }
  if(!present("shield")) {
    move_object(clone_object("/players/feldegast/equip/shield"),this_object());
    init_command("wear shield");
  }
  if(!present("sword")) {
    if(!random(2)) {
    move_object(clone_object("/players/feldegast/wep/ssword"),this_object());
    }
    else
      move_object(clone_object("/players/feldegast/wep/lsword"),this_object());
    init_command("wield sword");
  }
  ::reset(arg);
  if(arg) return;
  set_name("Skeleton Warrior");
  set_alt_name("skeleton");
  set_alias("warrior");
  set_short("Skeleton Warrior");
  set_long(
"This mighty warrior died long ago in the service of his king, and\n"+
"has been rewarded with eternal life of a sort.  His bleached white\n"+
"bones are garbed in tattered rags and bits of ancient chainmail.\n"
);
  set_gender("male");
  set_race("undead");
  set_level(14);
  set_wc(18);
  set_ac(11);
  set_hp(210);
  set_al(-400);
}
