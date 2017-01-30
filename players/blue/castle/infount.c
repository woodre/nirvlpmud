inherit "room/room";

int i;

reset(arg) {
   object coins, spirit, blade;
   if(!arg) {
   set_light(1);
   short_desc = "Inside the Fountain";
   long_desc = 
"The water begins to swirl violently and then takes a human shape!\n";

dest_dir = ({
   "players/blue/castle/fountain","out"
   });

if(!present("spirit",this_object())) {
        i=0;
   while(i<4) {
spirit=clone_object("obj/monster");
   spirit->set_short("water spirit");
   spirit->set_long("The water takes a human form.....\n");
   spirit->set_level(20);
   spirit->set_name("water spirit");
   spirit->set_alias("spirit");
   spirit->set_alt_name("water");
   spirit->set_ac(20);
   spirit->set_hp(1080);
   spirit->set_gender(0);
   coins = clone_object("obj/money");
      coins->set_money(2000);
   move_object( coins, spirit);
   move_object(spirit,this_object());

   blade=clone_object("obj/weapon");
   blade->set_name("blade");
   blade->set_type("sword");
   blade->set_short("spirit blade");
   blade->set_long( "This is the water spirit's blade.  It is a mist that"+
                     " moves like a sword.\nIt feels light and powerful.\n");
   blade->set_alias("spirit blade");
   blade->set_alt_name("sword");
   blade->set_class(16);
   blade->set_weight(4);
   blade->set_value(5000);
   move_object(blade, spirit);
   command("wield blade",spirit);
   spirit->set_wc(50);
   i +=1;
   }
   }
}
}
