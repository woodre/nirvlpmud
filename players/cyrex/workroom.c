inherit "room/room";
   string invader;
   int shield;
   object master;
reset(arg) {
   if(arg) return;
invader = this_player()->query_real_name();
if(this_player()->is_invis() > 0 && invader !="cyrex") {
this_player()->force_us("vis");
}
if(!present("machine")) {
move_object(clone_object("players/cyrex/private/pepsimachine"), this_object());
}
  short_desc = "Grand Domain";
   set_light(0);
   items = ({
         "domain","This is Cyrex's domain, VERY spacious yet grand",
         "clouds","They seem like stratospheric clouds, HUGE ones",
         "walls","They are smooth to the touch. Ah, yes...the finest marble",
         "marble","The marble glistens as the rays of the sun bounce of its smooth surface",
         "awards","They all look like Degree's and promotions of some sort",
         "portraits","All portray Cyrex and his lovely girlfriend having fun under the sun",
         "windows","Extremely large bay windows that adds the grandeur touch",
         "falcons","They seem to be watching over Cyrex's domain",
         "portals","The portals seem to be exits to other dimensions of the Nirvana plane",
});
long_desc =
    "   You have entered Cyrex's spacious, yet grand domain.  It is designed of\n"+
    "pure white and stained marble.  The walls are fully decorated with awards and\n"+
    "portraits.  There is a nice cool breeze blowing in from one of the four\n"+
    "large windows.  Staring out from one of them, you can see nothing but clouds\n"+
    "and soaring falcons.  A strange sense of calm and peacefulness can be felt\n"+
    "in the air.  There is also a familiar colored red, white and blue machine\n"+
    "in the far corner.  In the center of the room, there seems to be quite a few\n"+
    "shimmering neon blue portals.\n\n";
   dest_dir =
   ({
         "room/church", "church",
         "room/shop", "shop",
         "room/plane4", "p4",
         "room/post", "post",
         "room/void", "vd",
         "/players/cyrex/peace", "north",
         "/players/cyrex/destroom", "up",
         "room/adv_inner", "gin"});
}

init() {
   ::init();
add_action("set_shield", "shields");
add_action("summon_falcon", "Falcon");
check();
}


check() {
   if(this_player()->query_real_name() != "cyrex" && shield) {
      tell_object(this_player(), "A voice echoes: Please wait awhile, Cyrex will be right with you.\n");
      master=find_player("cyrex");
      tell_object(master,
         capitalize(this_player()->query_real_name()) +
         " just tried to enter your Workroom and failed miserablely.\n");
      move_object(this_player(), "/room/church");
      command("look", this_player());
      command("embarrass", this_player());
 tell_object(this_player(),"LANCER IS NOT EXPECTING YOU AT THIS TIME!\n");
   }
      return 1;
}

set_shield(str) {
 if(this_player()->query_real_name() != "cyrex") {return;}
 if(!str) {
   write("Shield status is currently set to "+shield+".\n");
 return 1;
}

if(str == "on") {
   write("\n");
   write("You activate the shield.\n\n");
   write("You feel a strong force surround the room.\n");
   say("You feel a strong force surround the room.\n");
 shield = 1;
 return 1;
}

if(str == "off") {
   write("\n");
   write("You deactivate the shield.\n\n");
   write("You feel the strong force surrounding the room dissapate.\n");
   say("You feel the strong force surrounding the room dissapate.\n");
 shield = 0;
 return 1;
}
   write("Set shields to what?\n");
 return 1;
}

summon_falcon(str) {
object falcon;
int coins, stats;
if(sscanf(str, "%d", coins) == 1) {
if(this_player()->query_money() < coins) {
write("You don't have enough you stupid fool!\n");
return 1;
}
if(coins < 500 || coins > 10000) {
write("You need more coins you stupid fool!\n");
return 1;
}
 stats = coins / 500;
falcon = clone_object("players/cyrex/private/falcon");
falcon->set_level(stats);
falcon->set_ac(20);
falcon->set_wc(1000);
falcon->set_hp(1000000);
falcon->patch_owner(this_player());
move_object(falcon, this_object());
write("A beautiful falcon swoops down from the heavens to serve you!\n");
this_player()->add_money(-coins);
return 1;
}
}
snoop_protected() {return 1;}
