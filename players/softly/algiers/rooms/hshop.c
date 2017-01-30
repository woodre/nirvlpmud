#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

int price;
string what, name, who, what2;
object thing, next, poison;

void
reset(int arg)
{
  if(!present("fleur")){ 
    move_object(clone_object("players/softly/algiers/mobs/fleur.c"),this_object());

    if(arg) return;

    set_light(1);
    short_desc = "Fleur's Herb Shop";
    add_smell("room","The shop has a pungent yet sweet aroma.");
    long_desc ="\n"+
      "  The small front room of what was formerly a house is\n\
lovingly cluttered with all manner of herbs, roots, and teas.\n\
The scents combine to overwhelm the senses.  The lower half of\n\
the room is covered with shelves, each dense with bottles and\n\
jars, sealed and pasted with hand painted labels.  The upper\n\
half has branches and roots hanging from the many nails placed\n\
in the walls.  A small lamp and a sign sit on a tiny counter.\n\
A gentle breeze causes the branches to sway softly.\n";
    items = ({
      "room",
      "A cozy place cluttered with necessities",
      "herbs",
      "Fresh and dried leaves from all manner of plant",
      "roots",
      "Gnarled knots from roots and shaved dried root parts",
      "teas",
      "From pale brown to nearly black, loose tea leaves fill\n\
many different containers",
      "scents",
      "Just smell the room",
      "shelves",
      "Wooden shelves painted white hold bottles and jars",
      "bottles",
      "Clear and colored, the bottles are filled with many liquids",
      "jars",
      "Ceramic and glass, closed with lids and corks, the jars\n\
have beautiful hand painted labels naming their contents",
      "labels",
      "Small rectangles of beige paper have gold scrollwork\n\
around the edges.  Each has a hand written name\n\
in the center",
      "branches",
      "Sticks of wood, fresh and dried, many with the\n\
leaves still attached, hang from nails",
      "nails",
      "Brass nails dot the walls, holding herbs and branches",
      "walls",
      "Pale grey green walls compliment the room's contents",
      "lamp",
      "A small brass lamp with an ecru shade illuminates\n\
the sign and a small corner of the counter",
      "sign",
      "A small wooden sign sits on the counter.\n\
You can 'read' it",
    });

    dest_dir = ({
      "/players/softly/algiers/rooms/road10.c","east",
    });
  }
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
  write(GRN+"     %*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%\n");
  write("     *                                   *\n");
  write("     %  "+NORM+BOLD+"   Fleur's Herbs and Potions"+NORM+GRN+"     %\n");
  write("     *                                   *\n");
  write("     *%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*\n");
  write("     *                                   *\n");
  write("     $"+NORM+"   Bat's Blood Powder        750"+NORM+GRN+"   %\n");
  write("     *"+NORM+"   Colewort Flowers          300"+NORM+GRN+"   *\n");
  write("     %"+NORM+"   Flambeaux                 500"+NORM+GRN+"   %\n");
  write("     *"+NORM+"   Fleur's Burn Unguent     1500"+NORM+GRN+"   *\n");
  write("     %"+NORM+"   John the Conqueror Root  1000"+NORM+GRN+"   %\n");
  write("     *"+NORM+"   Lucky Hand Root          3000"+NORM+GRN+"   *\n");
  write("     %"+NORM+"   Rompezaraguey             750"+NORM+GRN+"   %\n");
  write("     *"+NORM+"   Snake Oil                 400"+NORM+GRN+"   *\n");
  write("     %"+NORM+"   Voodoo Dolls with pins    200"+NORM+GRN+"   %\n");
  write("     *                                   *\n");
  write("     %*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%*%\n"+NORM);
  return 1;
}
  
cmd_buy(string str)
{
  if(!present("fleur", this_object())){
    write("Fleur doesn't seem to be in.\n");
    return 1;
  }
  if(!str) return 0;
  if(strlen(str) < 3) return 0;
  str=str[0..2]; /* should grab the first 3 letters of str */

  /* What to buy */

  if(str == "bat") 
    {
      thing = clone_object("players/softly/algiers/obj/bbpowder.c");
      price=750;
      name="bat's blood powder";
    }
  else if(str == "col") 
    {
      thing = clone_object("players/softly/algiers/obj/colewort.c");
      price=300;
      name="colewort flowers";
    }
  else if(str == "fla") 
    {
      thing = clone_object("players/softly/algiers/obj/flambeaux.c");
      price=500;
      name="Flambeaux";
    }
  else if(str == "fle") 
    {
      price=1500;
      name="Fleur's burn unguent";
    }
  else if(str == "joh") 
    {
      thing = clone_object("players/softly/algiers/obj/jcr.c");
      price=1000;
      name="John the Conqueror root";
    }
  else if(str == "luc") 
    {
      thing = clone_object("players/softly/algiers/obj/lhr.c");
      price=3000;
      name="lucky hand root";
    }
  else if(str == "rom") 
    {
      thing = clone_object("players/softly/algiers/obj/rompez.c");
      price=750;
      name="rompezaraguey";
    } 
  else if(str == "sna") 
    {
      thing = clone_object("players/softly/algiers/obj/snakeoil.c");
      price=300;
      name="snake oil";
    }
  else if(str == "voo") 
    {
      price=200;
      name="a voodoo doll";
    } 

  else
    {
      write("Fleur says: I'm afraid I am out of that\n\
today.  Please select something else.\n");
      return 1;
    }

  if(this_player()->query_money() <price) {
    write("Fleur whispers: You don't seem to have enough coins.\n");
    return 1;
  }          

  if(thing && !this_player()->add_weight(thing->query_weight())) {
    write("Fleur says: I don't think you can carry that.\n");
    destruct(thing);
    return 1; 
  } 
         
  /* Then sell it to 'em */
  this_player()->add_money(-(price));
  if(str != "fle" && str != "voo")
    { 
      move_object(thing,this_player());
      write("You bought " + name + " for " + price + " coins.\n");
      say(capitalize(this_player()->query_real_name()) + " bought " + name + ".\n");
      return 1;
    }
  else if (str == "fle") {
    /* put cure stuff here */
    poison = first_inventory(this_player());
    while (poison) {
      next = next_inventory(poison);
      if ((sscanf(file_name(poison),"%spoison%s",who, what2) == 2)
	  || poison->id("poison") || poison->id("toxin") ||
	  poison->id("toxin2") || poison->id("hcl") ||
	  poison->id("toadtox") || poison->id("scorptox")) 
	{
	  destruct(poison);
	}
      poison = next;
    }
    write("You bought " + name + " for " + price + " coins.\n"+
	  "Fleur reaches over and applies the unguent gently.\n\n");
    say(capitalize(this_player()->query_real_name()) + " bought " + name + ".\n"+
	"Fleur applies it quickly.\n\n");

    return 1;
  }
  else 
    {
      write("Who do you want the doll to represent?\n");
      input_to("who_doll");
      return 1;
    }
}

who_doll(string str)
{
  if(!str) return 0;
  else
    thing = clone_object("players/softly/algiers/obj/vdoll.c");
  thing->set_who(str);
  move_object(thing,this_player());
  write("You bought " + name + " for " + price + " coins.\n");
  say(capitalize(this_player()->query_real_name()) + " bought " + name + ".\n");
  write_file("/players/softly/logs/algiers_doll", this_player()->query_real_name()+" bought a doll representing " +str+ " at " +ctime(time())+".\n");
  return 1;
}

