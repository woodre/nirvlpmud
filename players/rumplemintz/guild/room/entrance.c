/* Entrance to druid guild area
* 1/12/2007 - Rumplemintz@Nirvana
*/

#include "../DEFS"

inherit DROOM;

void reset(int arg){
   if(arg) return;
   ::reset(arg);
   set_short(GRN, "At a clearing");
   set_long(GRN, "\n"+
"This is a clearing that was concealed from the south and west.  A large tree\n"+
"looms up to the north.  There are traces of footprints going straight into \n"+
"the tree.  To the south and west, the forest continues.\n");
   dest_dir = ({
         "/players/rumplemintz/Room/Forest/start", "south",
         "/players/rumplemintz/Room/Forest/d_forest", "west",
         DRUID+"guild_ent", "north"
         });
   items = ({
         "clearing", "It was hidden by the trees",
         "tree", "It is a large tree that could easily be a front for something else",
         "footprints", "They lead into the tree",
         "traces", "They lead into the tree",
         "forest", "The trees block your sight"
         });
   set_exit_color(CYN);
}

int druid_chec(){
   if(!this_player()->query_guild_name("druid")){
      write("You try to go north but fail miserably.\n");
      say(this_player()->query_name()+" tries to go north but fails miserably.\n");
      return 1;
   }
   return 0;
}

void init(){
   ::init();
   add_action("druid_chec", "north");
}
