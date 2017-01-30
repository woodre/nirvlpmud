inherit "obj/monster";

reset(arg){
           object gold;
           object armor;
           ::reset(arg);
           if(arg) return;
           set_name("Devil");
           set_race("monster");
           set_alias("devil");
           set_short("Devil");
           set_long("This is your worst nightmare! If you can kill\n"+
                    "him maybe it will help you on your quest.\n");
           set_level(20);
           set_hp(500);
           set_al(-1000);
           set_wc(30);
           set_ac(17);
           gold=clone_object("obj/money");
           gold->set_money(random(500)+500);
           move_object(gold,this_object());
           armor=clone_object("/players/sweetness/armor/hades_boots");
           move_object(armor,this_object());
          }
