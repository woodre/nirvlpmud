#include <ansi.h>

#define EXP_OBJ "/players/cosmo/hslist/svds_new"
#define PRES "/room/pres_hologram"
#define TAB "/room/exlv_tablet"

id(str) { 
  str = lower_case( str );
  
  return str == "display" || str == "hud" || str == "virtual head-up display" ||
         str == "a virtual head-up display"; 
}

short() {
   return GRN+ "A Virtual Head-Up Display (HUD)" + NORM;
}

long() {
   write(
"The HUD looks like a TV stand that sits in the middle of the room.\n\
There are a bunch of electronics and lights on the top of the HUD\n\
that must be how it creates the images in the air that seem to\n\
float there like magic. You can change the display by using the\n\
view command. \n\n\
\n\
  You can view :\n\
    'exp', 'topexp', 'topsc', 'topqp', \n\
    'kills', 'tablet', 'hologram', 'logins'\n\
\n\
  exp can accept the year or alltime as parameters:\n\
    view exp 2015\n\
    view exp alltime\n");
  
   return 1;
}

init() {
   add_action("view","view");
}

int
view(string str) {
  int i;
  string type, param;
  
	if( !str ) {
    notify_fail( "What do you want to read?\n");
    return 0;
	}
  
  if( sscanf( str, "%s %s", type, param ) != 2)
    type = str;
    
  if( type == "exp" && !param )
    param = "current";
  
  
  switch( type ) {
    case "exp":
      EXP_OBJ->view( param );
      break;
    case "topsc":
      cat("/SORT_PRES");
      break;
    case "topexp":
      cat("/SORT_LEVEL");
      break;
    case "topqp":
      cat("/SORT_QP");
      break;
    case "kills":
      cat("/SORT_TKILLS");
      break;
    case "logins":
      cat("/SORT_LOGINS");
      break;
    case "hologram":
      PRES->long();
      break;
    case "tablet":
      TAB->long();
      break;
    default:
      notify_fail( "View what?\n");
      return 0;
      break;
  }
  
  say( this_player()->query_name()+" views the HUD.\n");
  return 1;
}

get() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
