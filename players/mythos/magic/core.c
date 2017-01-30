/* this is a skeleton of what I am calling the magicitem
   the idea of the magic item is to generate a bunch of simple objects
   which when put together in various ways create various magic items
   NOTE: these magic items are NOT weapons, armor, or any other object that
   already exists in game.  These magic items are items that cover the range of
   other possible objects that are magical (such as potions, scrolls, staves,
   wands, amulets, rods, etc.
*/

static int autoload = 0;
static int shadyes = 0;
static int weight = 1;
static int value = 1;
static int gettable = 1;
static int droppable = 0;
static int gamespell = 0;
static int chargeshowshort = 1;
static int chargeshowlong = 1;
static int wait = 0;
static int destyes = 0;
static int weightchange = 0;
static string name = "item";
static string alias = "item";
static string altname = "item";
static string type = "item";
static string handle = "item";
static string spells = "magicitem";
int charges = -69;  /* -69 charges means infinate */
int maxcharges = -69; /* -69 means infinate */
string short_desc = "A Magic Item";
string long_desc = "A Magic Item";
object user;
string username;

id(str) {
	if(gamespell) spells = "nospell";
	if(spells != "nospell" && spells != "magicitem") spells = "magicitem";
	return str == name || str == alias || str == altname ||
	       str == handle || str == type ||str == spells;
}

get() { if(autoload) return 0; else return gettable; }

drop() { if(autoload) return 1; else return droppable; }

short() {
	string desc;
	desc = short_desc;
	if(charges != -69 && chargeshowshort) desc = desc + " <Uses: "+charges+">";
	return desc;
}

long() {
	string desc;
	desc = long_desc;
	if(charges != -69 && chargeshowlong) desc = desc + "Uses: "+charges;
	write(desc+"\n");
}

query_auto_load() {
	string fname, extn;
	if(autoload) {
	   if(sscanf(object_name(this_object()),"%s#%s",fname,extn) != 2)
	     fname = object_name(this_object());
	   fname = "/"+fname+".c:";
	   return fname;
	} else return 0;
}

query_weight() { if(autoload) return 0;
				 else if(charges != -69 && maxcharges != -69 && weightchange) return charges * weight;
				 else return weight; }

query_value() { if(autoload) return 0;
				else if(charges != -69 && maxcharges != -69) return charges * value;
				else return value; }

query_prevent_shadow() { if(shadyes) return 0; else return 1; }

query_charges() { if(charges != -69 && maxcharges != -69) return charges; else return 0; }

query_maxcharges() { if(charges != -69 && maxcharges != -69) return maxcharges; else return 0; }

usecharges(arg) {
int val;
 if(!arg) val = 1; else val = arg;
	if(val < 1) val = 1;
	if(charges != -69 && maxcharges != -69) {
	  charges = charges - val;
	  if(charges < 1) charges = 0;
      return charges;
	} else return 0;
}

addcharges(arg) {
int val;
 if(!arg) val = 1; else val = arg;
    if(val < 1) val = 1;
    if(charges != -69 && maxcharges != -69) {
		charges = charges + val;
    	if(charges < 1) charges = 0;
    	if(charges > maxcharges) charges = maxcharges;
    	return charges;
  	} else return 0;
}

#include "tell_say.h"
