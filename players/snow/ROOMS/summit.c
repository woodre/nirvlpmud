/* 10/20/05 Earwax: Converted to land - 1.25 mil for Oz */

inherit "room/room";
inherit "/players/earwax/housing/land.c";
 
reset(arg){
 
if(!present("icingdeath"))  {
move_object(clone_object("/players/snow/MONSTERS/icingdeath3.c"),this_object());  }
 
 if(!arg){
 
 set_light(1);
  short_desc="Top of Snow Mountain";
 long_desc=
 "You have reached the top of the Mountain at long last. The bitter air\n\
chills you to the bone as you look around. A smell of ancient death is in\n\
the air, even though crisp snow lies all around. The wind blasts through\n\
your hair and into your face. Stars shine faintly overhead. This appears\n\
to be the summit of the mountain.\n";
 
items=({
 "mountain", "This is the top of Snow Mountain, the great fortress lies below you",
 "rock","A huge rock worn smooth from being layed upon",
 "coins","A glittering pile of gold coins",
 "pile","Many thousands of gold coins lie in the pile",
 "clouds","The clouds, far below you, shroud the distant plains",
 "sun","The sun shines brightly above you, the lack of atmosphere up here\n" + 
           "gives the sun an eerie glow",
 "stars","You can see the stars shining low on the horizon" });
 
  dest_dir=({
  "/players/snow/ROOMS/fortport3.c","back"});

  set_realm_name("Mountain");
  set_lot_size(-2);
  set_cost(1250000);
  setup_land();
  }
}
