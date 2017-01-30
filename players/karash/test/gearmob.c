
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  
  
  move_object(clone_object("/players/snow/WEAPONS/hon_sword"), this_object());
  move_object(clone_object("/players/snow/WEAPONS/hon_sword"), this_object());
  move_object(clone_object("/players/vertebraker/misc/cj/cj_face"), this_object());  
  move_object(clone_object("/players/dragnar/WalkingDead/armor/swat_vest"), this_object());
  move_object(clone_object("/players/valen/area/catacombs/armors/d_belt"), this_object());
  move_object(clone_object("/players/tallos/7tigers/objects/dragon_legs"), this_object());
  move_object(clone_object("/players/eurale/Chess/OBJ/ring"), this_object());
  move_object(clone_object("/players/zeus/desert/OBJ/cloak"), this_object());
  move_object(clone_object("/players/jareel/armor/humakt/humakt_necklace"), this_object());
  move_object(clone_object("/players/vertebraker/swamp/OBJ/denim_shorts"), this_object());
  move_object(clone_object("/players/angel/area/school/obj/flow_scarf_01"), this_object());
  move_object(clone_object("/players/jenny/wings/items/sblocker"), this_object());
  move_object(clone_object("/players/dragnar/WalkingDead/armor/boots"), this_object());
  move_object(clone_object("/players/jareel/armor/DWARFFORGE/demon/misc"), this_object());
  move_object(clone_object("/players/jareel/armor/DWARFFORGE/demon/amulet"), this_object());
  move_object(clone_object("/players/jareel/armor/DWARFFORGE/demon/earring"), this_object());
  move_object(clone_object("/players/maledicta/cont/rdragon/sbracers"), this_object());
  move_object(clone_object("/players/khrell/armors/skaven/warparmor"), this_object());
  move_object(clone_object("/players/karash/Outpost/items/daikatana_emp.c"), this_object());
  move_object(clone_object("/players/karash/Outpost/items/daikatana_emp.c"), this_object());
  move_object(clone_object("/players/guilds/dervish/objects/hourglass"), this_object());
  move_object(clone_object("/players/saber/stuff/mbag"), this_object());
  
  command("ready", this_object());
  
   
  set_name("gearmob");
    SetMultipleIds( ({ "gearmob", "mob"  }) );
  set_race("critter");
  set_short("gearmob");
  set_long(
    "  A indescribably NPC with gear.\n");
  set_level(18);
  set_al(-(random(200)));
  set_ac(15);
  set_wc(26);
  set_hp(350+(random(125)));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);

  }
  

