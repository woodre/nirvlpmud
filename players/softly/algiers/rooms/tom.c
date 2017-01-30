#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

int price;
string name;
object thing;

reset(arg){
  if(!present("rita")){ 
    move_object(clone_object("players/softly/algiers/mobs/rita.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Tom's Variety Store";
  long_desc ="\n"+
    "  This is a small shop with a central counter constructed of\n\
painted wood paneling.  There are shelves all around the\n\
room, each filled to overflowing with unique and wonderous\n\
things.  Standing in a neat line along the floor are barrels,\n\
some filled with raw materials and others containing objects\n\
for sale.  A few toys hang from the ceiling.  The overall effect\n\
is of a colorful melange of excitement.  A hand lettered sign\n\
hangs on the wall behind the counter.\n";    

  items = ({
    "counter",
    "A small central counter constructed of the\n\
same oak as the paneling holds a few papers\n\
and a small cash box",
    "paneling",
    "The shop's walls are covered with pale colored\n\
wood paneling on which shelves are attached",
    "shelves",
    "Wooden shelves which match the paneling\n\
display many toys and novelty items",
    "things",
    "Toys, novelties, and pretty gee-gaws are\n\
on display throughout the shop",
    "barrels",
    "New barrels hand made from oak staves and\n\
bound with copper hug the walls",
    "materials",
    "Pieces of wood and metal and rolls of fabric\n\
stick out of the top of many barrels",
    "objects",
    "Toys, novelties, and pretty gee-gaws are\n\
on display throughout the shop",
    "toys",
"stuff",
    "ceiling",
    "The high ceiling has kites, model airplanes,\n\
and stuffed birds hanging from it",
    "melange",
    "An eclectic collection of toys, novelties, and\n\
pretty gee-gaws meld to produce a unique effect",
    "sign",
"A beautifully constructed hand painted sign is\n\
anchored to the rear wall.  You could 'read' it",
    "wall",
    "The paneled wall holds a neatly constructed sign",
    "counter",
    "Thick slabs of glass are put together to create\n\
a counter combined with a glass case in which some\n\
of the more delicate items are displayed",
  });

  dest_dir = ({
    "/players/softly/algiers/rooms/road9.c","west",
  });
}

void
init()
{
  ::init();
  add_action("cmd_list", "list");
  add_action("cmd_list", "read");
  add_action("cmd_buy", "buy");
  add_action("cmd_buy", "purchase");
  add_action("cmd_buy", "order");
}

status
cmd_list()
{
  write(HIB+"\n     <+><+><+><+><+><+><+><+><+><+><+><+><+>\n");
  write("     <+>                                 <+>\n");
  write("     <+>"+HIY+"     Tom's Variety Presents"+HIB+"      <+>\n");
  write("     <+>                                 <+>\n");
  write("     <+>"+NORM+BOLD+"   Paddleball              100"+HIB+"   <+>\n");
  write("     <+>"+NORM+HIM+"   Bubblestuff[tm]         125"+HIB+"   <+>\n");
  write("     <+>"+NORM+BOLD+"   Slinky                   75"+HIB+"   <+>\n");
  write("     <+>"+NORM+HIM+"   Pink Glostick            50"+HIB+"   <+>\n");
  write("     <+>"+NORM+HIG+"   Green Glostick           50"+HIB+"   <+>\n");
  write("     <+>"+NORM+HIC+"   Lava Lamp               100"+HIB+"   <+>\n");
  write("     <+>                                 <+>\n");
  write("     <+>"+NORM+HIR+"     MORE !!  Coming Soon !!"+HIB+"     <+>\n");
  write("     <+>                                 <+>\n");
  write("     <+><+><+><+><+><+><+><+><+><+><+><+><+>\n\n"+NORM);
  return 1;
}

cmd_buy(string str)
{
if(!present("rita", this_object())){
  write("Rita isn't here right now.\n");
  return 1;
}
  if(!str) return 0;
  if(strlen(str) < 3) return 0;
    str=str[0..2]; /* should grab the first 3 letters of str */

/* What to buy */

      if(str == "pad") 
	{
	  thing = clone_object("players/vertebraker/misc/vshop/pad.c");
	  price=100;
	  name="Paddleball";
	}
      else if(str == "sli") 
	{
	  thing = clone_object("players/vertebraker/misc/vshop/slinky.c");
	  price=75;
	  name="Slinky";
	}
      else if(str == "pin") 
	{
	  thing = clone_object("players/vertebraker/misc/vshop/p-glo.c");
	  price=50;
	  name="Pink glostick";
	}
      else if(str == "gre") 
	{
	  thing = clone_object("players/vertebraker/misc/vshop/g-glo.c");
	  price=50;
	  name="Green glostick";
	}
      else if(str == "lav") 
	{
	  thing = clone_object("players/vertebraker/misc/vshop/lamp.c");
	  price=100;
	  name="Lava lamp";
	}
      else if(str == "bub") 
	{
	  thing = clone_object("players/vertebraker/misc/vshop/bottle.c");
	  price=125;
	  name="Bubblestuff";
	}
      else
	{
	write("Rita apologetically says: I'm afraid I don't have\n\
that in stock.  Can I show you something else?\n");
	return 1;
      }

    if(this_player()->query_money() <price) {
      write("Rita says: Honey, you can't even afford that!\n");
      return 1;
    }          

  if(thing && !this_player()->add_weight(thing->query_weight())) {
    write("Rita says: It doesn't seem like you can carry it.\n");
    destruct(thing);
    return 1; 
  } 
         
  /* Then sell it to 'em */
  this_player()->add_money(-(price));
  { 
    move_object(thing,this_player());
    write("You bought a " + name + " for " + price + " coins.\n");
    say(capitalize(this_player()->query_real_name()) + " bought a " + name + ".\n");
    return 1;
  }
}
