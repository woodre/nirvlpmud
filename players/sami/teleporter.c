#include <ansi.h>
inherit "obj/treasure";

void reset(int arg){
    if(arg) return;
    ::reset(arg);
        set_name("teleporter");
        set_alias("porter");
        set_short("A "+HIK+"T"+HIY+"e"+HIK+"l"+HIY+"e"+HIK+"p"+HIY+"o"+HIK+"r"+HIY+"t"+HIK+"e"+HIY+"r"+NORM+"");
        set_long("This shiny machine is very hi tech. Lights flash red, blue and green across the\n"+
                 "surface of the teleporter. All you know for sure is there is a pannel on it\n"+
				 "it could be possible to view it?\n");
        set_weight(10000);
        set_value(1);
}
void init() {
  ::init();


  add_action("view_panel", "view");
  add_action("teleport_GPO", "GPO");  
 }
 
 status teleport_GPO() {
  this_player()->move_player("GPO#players/sami/area/GPO/entrance.c");
  write("Your body feels strange as you step onto the teleporter. In a "+HIY+"flash"+NORM+"\n"+
        "of light you realise you have been teleported!\n");
  return 1;
}
status view_panel()  {
  write("**********~~~~~~~~~Teleporter~~~~~~~~~~~~~~~**********\n");
  write("       You may go to the following places.\n"+
        "      Simply type the following phrases to\n"+
        "             venture to new places.\n"+
        "                     GPO\n");
  write("**********~~~~~~~~~Teleporter~~~~~~~~~~~~~~~~**********\n");
return 1; }
  
  