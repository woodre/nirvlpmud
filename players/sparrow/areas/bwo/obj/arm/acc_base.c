/* Base object for my accessory generator bascially just allows me access
   to long {} and short {} so I can do custom descriptions based on skill 
   checks. (int, luc, mag) Yeah I know, I suckwiz. 
*/
#include "/sys/ansi.h"
inherit "/obj/armor.c";
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";
/* GLOBALS */
string Acc_slot;
int Acc_value;
string *Dtype_array;
int *Power_array;

void
store_info_vars(string *dtype, int *power, string slot, int value) {
  Dtype_array = dtype;
  Power_array = power;
  Acc_slot = slot;
  Acc_value = value;
}

string 
short() {
  object viewer;
  int viewer_int, viewer_luc, viewer_mag, lore, iden, luc_mod;
  string short_string;
  
  if (!query_short()) { return "ERROR - No query_short()"; }
  if(!this_player()) { return "Error - !this_player()"; }
  viewer = this_player();
  viewer_int = viewer->query_attrib("int");
  viewer_luc = viewer->query_attrib("luc");
  viewer_mag = viewer->query_attrib("mag");
  if(viewer_luc < 6) { luc_mod = -3; }
  if((viewer_luc < 9) && (viewer_luc > 5)) { luc_mod = -2; }
  if((viewer_luc < 13) && (viewer_luc > 8)) { luc_mod = -1; }
  if((viewer_luc < 18) && (viewer_luc > 12)) { luc_mod = 0; }
  if((viewer_luc < 24) && (viewer_luc > 17)) { luc_mod = 1; }
  if((viewer_luc < 30) && (viewer_luc > 23)) { luc_mod = 2; }
  if(viewer_luc == 30) { luc_mod = 3; }
  lore = viewer_int + luc_mod;
  iden = viewer_mag + luc_mod;
  if((lore > 27) && (Dtype_array[0])) {
    if(Power_array[0] < 9 && Power_array[0] > 0) 
    { 
      short_string = HIW+"Titanium "+capitalize(Acc_slot)+NORM;
    }
    if(Power_array[0] > 8 && Power_array[0] < 13)
    {
      short_string = HIK+"Mithril "+capitalize(Acc_slot)+NORM;
    }
    if(Power_array[0] > 12 && Power_array[0] < 19)
    {
      short_string = GRN+"Adamantite "+capitalize(Acc_slot)+NORM;  
    }
    if(Power_array[0] > 18)
    {
      short_string = CYAN+"Runite "+capitalize(Acc_slot)+NORM;  
    }
    if(iden > 27) {
      switch(sizeof(Dtype_array)) {
        case 1:
          short_string += " ["+gimmie_short(Dtype_array[0], iden)+"]";
          break;
        case 2:
          short_string += " ["+gimmie_short(Dtype_array[0], iden)+"]";
          short_string += " ["+gimmie_short(Dtype_array[1], iden)+"]";
          break;
        case 6:
          if(iden > 31) {
            short_string += " ["+YEL+"El"+CYAN+"e"+BLUE+"m"+RED+"e"+BLUE+
            "n"+CYAN+"t"+YEL+"al"+NORM+"]";
          }
          else {
            short_string += " [Rainbow]";
          }
          break;
        default:
          short_string += " [ERROR] Common got in dtype area";     
      } 
    }
    else {
      short_string = "A common "+Acc_slot; 
    }
    return short_string;  
  }
}