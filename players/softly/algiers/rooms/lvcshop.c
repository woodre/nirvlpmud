#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";
inherit "/players/softly/closed/std/m_efuns";

mapping Armors, Ids, Costs;


void
reset(int arg)
{
  int s;
  string type, *m;
  if(!present("lloyd")){ 
    move_object(clone_object("players/softly/algiers/mobs/lloyd.c"),this_object());

    if(arg) return;

    set_light(1);
    short_desc = "Lloyd's Vintage Clothing";
    long_desc ="\n"+
      "  This vintage clothing emporium has shelves from floor\n\
to ceiling stacked with all manner of attire.  The colorful\n\
fabrics overwhelm the senses.  In the front of the shop is a\n\
clothing rack with a sign on it.  A worn recliner sits in one\n\
corner next to an ancient cash register.  A ceiling fan slowly\n\
moves the air.  A large, hand lettered sign shows the current\n\
sale items and their prices.\n";

    items = ({
      "ceiling",
      "Clothing stacked on the top shelves reaches the ceiling",
      "shelves",
      "Thick rough wooden shelves sit on sturdy standards.\n\
They are densely stacked with clothing",
      "floor",
      "The unpolished wooden floor is very worn",
      "attire",
      "Clothing of all sizes and hues cover the walls",
      "fabrics",
      "Wool, velvet, silk, polyester, and cottons\n\
weave throughout the shop",
      "shop",
      "The shop is quite small, but cheerful and colorful",
      "rack",
      "A stable rack hand made from plumbers pipe holds\n\
hanging clothing.  On the top is a sign that reads\n\
'special'",
      "recliner",
      "A brown leather recliner, well worn and very lumpy\n\
sits off to one corner",
      "register",
      "The drawer gold toned cash register is open.  It\n\
appears to be empty",
      "fan",
      "Four once-white fan blades slowly turn",
      "sign",
      "A large hand written sign on a posterboard is tacked\n\
on the only empty wall space.  You can 'read' it",
    });

    dest_dir = ({
      "/players/softly/algiers/rooms/road9.c","east",
    });

    Costs = ([ "amulet" : 100, "armor" : 825 , "boots" : 125, "helmet" : 150, "misc" : 100, "ring" : 100, "shield" : 200 ]);
    Armors = ([ ]);
    Ids = ([ ]);

    type = "amulet";
    switch(random(6))
      {
      case 0:
        Armors[type] = ({ "scarf", "paisley scarf", 
			  "A large "+MAG+"pa"+BOLD+BLK+"i"+MAG+"s"+BOLD+BLK+"le"+NORM+MAG+"y"+NORM+" scarf",
			  "A dark grey and burgundy paisley scarf with a\n\
long burgundy fringe all around.\n" });
        break;
      case 1:
        Armors[type] = ({ "vest", "hunting vest", 
			  "A fluorescent orange hunting vest",
			  "A puffy fluorescent orange hunting vest that\n\
could be seen from great distances.\n" });
        break;
      case 2:
        Armors[type] = ({ "license", "fishing license", 
			  "An expired fishing license",
			  "An expired fishing license in a leather case\n\
hanging on a string.  It looks like it was\n\
meant to be worn around the neck.\n" });
        break;
      case 3:
        Armors[type] = ({ "necktie", "painted necktie", 
			  "A hand painted necktie",
			  "A brown and green striped hand painted necktie\n\
sporting game birds, including ducks and geese.\n" });
        break;
      case 4:
        Armors[type] = ({ "necklace", "silver necklace", 
			  "A"+BLK+BOLD+" silver toned necklace"+NORM,
			  "A long silver toned chain with a small silver\n\
colored fish hanging from a point in the center.\n" });
        break;
      case 5:
        Armors[type] = ({ "beads", "gaudy beads", 
			  "A string of "+HIR+"g"+HIB+"a"+HIY+"u"+HIG+"d"+HIM+"y"+NORM+" beads",
			  "Glass beads of many bright colors are strung\n\
together in a single large circle.\n" });
        break;
      }

    type = "armor";
    switch(random(6))
      {
      case 0:
        Armors[type] = ({ "jacket", "snakeskin jacket", 
			  "A "+YEL+"snakeskin jacket"+NORM,
			  "A long glossy jacket roughly crafted from many\n\
snakes skins.\n" });
        break;
      case 1:
        Armors[type] = ({ "suit", "plaid suit", 
			  "A "+HIG+"pl"+HIY+"ai"+HIG+"d "+HIY+"su"+HIG+"it"+NORM,
			  "A green and yellow plaid suit with very wide lapels.\n" });
        break;
      case 2:
        Armors[type] = ({ "tuxedo", "blue tuxedo", 
			  "A "+HIB+"blue tuxedo"+NORM,
			  "A bright blue tuxedo that someone thought elegant.\n" });
        break;
      case 3:
        Armors[type] = ({ "bathrobe", "chenille bathrobe", 
			  "A "+HIM+"chenille bathrobe"+NORM,
			  "A huge pink chenille bathrobe with pockets.\n" });
        break;
      case 4:
        Armors[type] = ({ "coat", "trench coat", 
			  "A "+HIW+"trench coat"+NORM,
			  "A double breasted white polyester trench coat.\n" });
        break;
      case 5:
        Armors[type] = ({ "slicker", "yellow slicker", 
			  "A "+HIY+"yellow slicker"+NORM,
			  "A shiny bright yellow rain slicker.\n" });
        break;
      }

    type = "boots";
    switch(random(6))
      {
      case 0:
        Armors[type] = ({ "shoes", "tennis shoes", 
			  "A pair of "+BOLD+BLK+"tennis shoes"+NORM,
			  "A pair of black converse all-star high tops\n\
that still have some wear in them.\n" });
        break;
      case 1:
        Armors[type] = ({ "boots", "orange boots", 
			  "A pair of "+YEL+"work boots"+NORM,
			  "A pair of orange work boots spattered with\n\
many colors of paint.\n" });
        break;
      case 2:
        Armors[type] = ({ "loafers", "penny loafers", 
			  "A pair of "+RED+"penny loafers"+NORM,
			  "A pair of reddish-brown penny loafers with\n\
pennies in the slots..\n" });
        break;
      case 3:
        Armors[type] = ({ "flippers", "rubber flippers", 
			  "A pair of "+HIB+"rubber flippers"+NORM,
			  "A pair of bright blue rubber flippers that\n\
are only slightly cracked.\n" });
        break;
      case 4:
        Armors[type] = ({ "socks", "slipper socks", 
			  "A pair of"+GRN+" slipper socks"+NORM,
			  "A pair of cute bunny slippers.\n" });
        break;
      case 5:
        Armors[type] = ({ "sandals", "", 
			  "A pair of sandals",
			  "A pair of white tennis shoes.\n" });
        break;
      }

    type = "helmet";
    switch(random(7))
      {
      case 0: 
        Armors[type] = ({ "fedora", "grey fedora", 
			  "A "+BLK+BOLD+"grey fedora"+NORM, 
			  "A once elegant grey fedora that has seen\n\
many years of wear.\n" });
        break;
      case 1:
        Armors[type] = ({ "hat", "wool hat", 
			  "A "+BOLD+BLK+"black wool hat with a veil"+NORM,
			  "A small black wool hat with a veil.  A limp\n\
fabric flower is on the front.\n" });
        break;
      case 2:
        Armors[type] = ({ "beret", "black beret", 
			  "A "+BOLD+BLK+"black beret"+NORM,
			  "A limp but rakish black beret.\n" });
        break;
      case 3:
        Armors[type] = ({ "cap", "hunters cap", 
			  "A "+HIR+"hunters cap"+NORM,
			  "A red hunters cap with earflaps.\n" });
        break;
      case 4:
        Armors[type] = ({ "helmet", "motorcycle helmet", 
			  "A "+HIW+"motorcycle helmet"+NORM,
			  "A white motorcycle helmet with a crack\n\
across the top.\n" });
        break;
      case 5:
        Armors[type] = ({ "cap", "watch cap", 
			  "A "+BLU+"watch cap"+NORM,
			  "A blue watch cap.\n" });
        break;
      case 6:
        Armors[type] = ({ "eyeshade", "green eyeshade", 
			  "A "+HIG+"green eyeshade"+NORM,
			  "A green eyeshade from a retired accountant.\n" });
        break;
      }

    type = "misc";
    switch(random(7))
      {
      case 0:
        Armors[type] = ({ "eyeglasses", "broken eyeglasses", 
			  "A pair of eyeglasses",
			  "A pair of eyeglasses with thick black frames.\n\
The broken frames are held together with\n\
a safety pin.\n" });
        break;
      case 1:
        Armors[type] = ({ "cape", "black cape", 
			  "A "+BOLD+BLK+"black cape"+NORM,
			  "A black silk cape lined with red.  There are many\n\
dark stains on it.\n" });
        break;
      case 2:
        Armors[type] = ({ "neckerchief", "scout neckerchief", 
			  "A cub scout neckerchief",
			  "A yellow cub scout neckerchief with blue lettering\n\
and a picture of a wolf.\n" });
        break;
      case 3:
        Armors[type] = ({ "brace", "neck brace", 
			  "A neck brace",
			  "A white neck brace lined with terry cloth.\n" });
        break;
      case 4:
        Armors[type] = ({ "earrings", "enamel earrings", 
			  "American flag earrings",
			  "A pair of large enamel earrings in red, white, and\n\
blue, in the form of an American flag.\n" });
        break;
      case 5:
	Armors[type] = ({ "tights", "white tights", 
			  "A pair of "+BOLD+"white tights"+NORM,
			  "A worn pair of white tights with dirty smudged\n\
spots at the knees.\n" });
	break;
      case 6:
	Armors[type] = ({ "leg", "artificial leg", 
			  "An artifical leg",
			  "An artificial leg that can be attached with\n\
leather straps.\n" });
	break;
      }

    type = "ring";
    switch(random(6))
      {
      case 0:
        Armors[type] = ({ "ring", "school ring", 
			  "A school ring",
			  "A heavy school ring with a large bright\n\
blue stone in it.\n" });
        break;
      case 1:
        Armors[type] = ({ "mittens", "striped mittens", 
			  "A pair of"+HIM+" mi"+HIC+"ttens"+NORM,
			  "A pair pink and blue striped mittens\n\
held together with a cord.\n" });
        break;
      case 2:
        Armors[type] = ({ "bracelet", "copper bracelet", 
			  "A "+YEL+"copper bracelet"+NORM,
			  "An old copper bracelet, tarnished with time.\n" });
        break;
      case 3:
        Armors[type] = ({ "watch", "wind-up watch", 
			  "A wind-up watch",
			  "An old tank watch with a stem for winding it.\n" });
        break;
      case 4:
        Armors[type] = ({ "gloves", "fingerless gloves", 
			  "A pair of"+BLK+BOLD+" fingerless gloves"+NORM,
			  "A pair of silver fingerless Michael Jackson gloves.\n" });
        break;
      case 5:
        Armors[type] = ({ "handcuffs", "trick handcuffs", 
			  "A pair of handcuffs",
			  "A pair of trick handcuffs with an easy release.\n" });
        break;
      }

    type = "shield";
    switch(random(6))
      {
      case 0:
        Armors[type] = ({ "apron", "christmas apron", 
			  "A "+HIR+"c"+HIW+"h"+HIR+"r"+HIW+"i"+HIR+"s"+HIW+"t"+HIR+"m"+HIW+"a"+HIR+"s"+NORM+" apron",
			  "A white apron with a large picture of Santa on the front.\n" });
        break;
      case 1:
        Armors[type] = ({ "belt", "tool belt", 
			  "A tool belt",
			  "A leather tool belt with pockets for many items.\n" });
        break;
      case 2:
        Armors[type] = ({ "top", "tube top", 
			  "A "+HIG+"tube top"+NORM,
			  "A green elastic tube top.\n" });
        break;
      case 3:
        Armors[type] = ({ "undershirt", "sleeveless undershirt", 
			  "A sleeveless undershirt",
			  "A soiled white sleeveless undershirt.\n" });
        break;
      case 4:
        Armors[type] = ({ "protector", "pocket protector", 
			  "A pocket protector",
			  "A leather pocket protector marred with ink stains.\n" });
        break;
      case 5:
        Armors[type] = ({ "mask", "gas mask", 
			  "A gas mask",
			  "An industrial strength gas mask that is only missing\n\
a filter and neck strap.\n" });
        break;
      }

    m = m_indices(Armors);
    s = sizeof(m);

    while(s --)
      {
	Ids[Armors[m[s]][0]] = m[s];
	Ids[Armors[m[s]][1]] = m[s];
	Ids[Armors[m[s]][2]] = m[s];
	Ids[m[s]] = m[s];
      }
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
  string amulet, armor, boots, helmet, misc, ring, shield;
  write(HIC+"           Lloyd's Vintage Clothing\n\n"+NORM);
  write("      If you don't see it, we don't have it.\n");
  write(HIR+"-------------------------------------------------\n"+NORM);
  write(colour_pad(Armors["amulet"][2], 40) + "     " + (Costs["amulet"]) + "      \n");
  write(colour_pad(Armors["misc"][2], 40) + "     " + (Costs["misc"]) + "      \n");
  write(colour_pad(Armors["ring"][2], 40) + "     " + (Costs["ring"]) + "      \n");
  write(colour_pad(Armors["boots"][2], 40) + "     " + (Costs["boots"]) + "      \n");
  write(colour_pad(Armors["helmet"][2], 40) + "     " + (Costs["helmet"]) + "      \n");
  write(colour_pad(Armors["shield"][2], 40) + "     " + (Costs["shield"]) + "      \n");
  write(colour_pad(Armors["armor"][2], 40) + "     " + (Costs["armor"]) + "      \n");
  write(HIR+"-------------------------------------------------\n"+NORM);
  return 1;
}
    
status
cmd_buy(string str)
{
  int cost, weight, ac;
  string type, *data;
  object armor;

  if(!str) return 0;

  if(!member(Ids, str))
    {
      notify_fail("\
Lloyd says, I'm sorry but we don't have that in today.\n");
      return 0;
    }
    
  type = Ids[str];

  cost = Costs[type];
  if((int)this_player()->query_money() < cost)
    {
      notify_fail("\
You don't have enough money!\n");
      return 0;
    }

  if(type == "armor") weight = 3;
  else weight = 1;

  if(!this_player()->add_weight(weight))
    {
      notify_fail("\
You can't carry that.\n");
      return 0;
    }

  armor = clone_object("/obj/armor");

  armor->set_type(type);

  data = Armors[type];
  armor->set_name(data[0]);
  armor->set_alias(data[1]);
  armor->set_short(data[2]);
  armor->set_long(data[3]);

  if(type == "armor")
    armor->set_ac(3);
  else
    armor->set_ac(1);

  armor->set_value(cost);
  armor->set_weight(weight);

  this_player()->add_money(-cost);
  write("You buy " + data[2] + ".\n");
  move_object(armor, this_player());
  return 1;
}

