#include "/players/laera/closed/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define NAME "laera"
inherit "room/room";
int shield;

reset(arg) {
   if(arg) return;

short_desc = MAG+"At Home"+OFF;
   long_desc = WHT+
   "Bright greens, yellows and reds set off the white background of this\n"+
   "warm and cheery kitchen.  Well stocked cupboards and counters span\n"+
   "the length of two walls, giving ample space to cook and create.  A\n"+
   "large country window sits above a shiny sink, letting cheerful sun-\n"+
   "shine into the room.  Modern appliances grace this little corner of\n"+
   "heaven.  To the right sits an oak table, surrounded by high backed\n"+
   "chairs.  Sliding doors open onto a wide patio.\n"+OFF;
   set_light(1);

   items = ({
         "cupboards","Well stocked, they are fastened comfortably against the wall",
         "counters","Hand carved wooden counters with white marble surfaces span the length of two walls",
         "walls","The walls are decorated in white ceramic tile with flowers stencilled into assorted tiles",
         "up","The ceiling is painted white",
         "ceiling","The ceiling is painted white",
         "down","A hardwood floor, shined and buffed to perfection",
         "floor","A hardwood floor, shined and buffed to perfection",
         "window","Friendly country curtains cover the window, which looks out into the backyard",
         "sink","Clean and shiny and made of stainless steel",
         "appliances","Many of the appliances you would expect in a kitchen, including a microwave, refrigerator and stove",
         "microwave","A large state-of-the-art microwave sits on the counter",
         "refrigerator","A two door refrigerator-freezer, almost big enough to be a walk-in",
         "fridge", "A two door refrigerator-freezer, almost big enough to be a walk-in",
         "stove","A modern gas stove and oven, that is used quite frequently when Laera bakes",
         "table","Large and oval, this table holds many loving memories of loved ones",
         "chairs","Comfortable high backed chairs sit neatly around the table",
         "chair","One of six comfortable chairs.  You are welcome to sit down in one",
         "doors","Sliding doors lead from the kitchen to the patio",
         "patio","A wide wooden patio, built for entertaining and for just lazing in the sun"
});

   dest_dir = ({
	 "room/church.c","church",
	 "post office#room/post.c","post",
	 "room/adv_guild","advance",
	 "players/boltar/sprooms/daycare.c","daycare"
	});

}

init()
{
   ::init();
   add_action("church","church");
   add_action("on"); add_verb("on");
   add_action("post"); add_verb("post");
   add_action("off"); add_verb("off");
   add_action("advance","advance");
   add_action("daycare","daycare");
   /*add_action("grotto","grotto");*/

   if(this_player()->query_real_name() != NAME && shield == 1)
   {
      write("You feel an electric shock and see a FLASH of white light\n"+
         "as you rebound off some surrounding shield.\n");
      this_player()->move_player("off the shields#room/church");
      return 1;
   }
}

church()
{
   TP->move_player("church#room/church.c");
   /*command("look",this_player());*/
   return 1;
}

/*grotto()
{*/
  /*if(TP->query_guild() != "shardak" || TPN != NAME)*/
  /*if(TP->query_guild() != "shardak" && TP->query_real_name() != NAME)
  {
	  say(TPN + " has tried to enter the grotto.\n");
	  write("You cannot enter there!!\n");
	  TP->move_player("church#room/church.c");
	  return 1;
  }
  else
  {
       TP->move_player("grotto#players/vertebraker/closed/shardak/room/grotto.c");
       /*command("look",this_player());*/
       /*return 1;
  }
}*/

advance()
{
	TP->move_player("advance#room/adv_guild.c");
	return 1;
}

post()
{
   TP->move_player("post office#room/post.c");
   return 1;
}

daycare()
{
	TP->move_player("daycare#players/boltar/sprooms/daycare.c");
	return 1;
}

static on()
{
   write("You "+BOLD+"activate"+NORM+" the shield.\n");
   shield = 1;
   return 1;
}

static off()
{
   if(TP->query_real_name() != NAME)
   {
      write("You are not allowed to do that!!!!!!!\n");
      return 1;
   }
   write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
   shield = 0;
   return 1;
}

