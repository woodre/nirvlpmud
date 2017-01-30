#include "/players/dragnar/guild/defs/def.h"
clarknm() {
        int color_flag;
        color_flag = (present("shardak_mark", this_player())->query_color_flag());
        if(uhp < umhp/4 && color_flag == 1){
        tell_object(user, RED + MONITOR);
        }
        if(uhp < umhp/2 && uhp >= umhp/4 && color_flag ==1) {
	     tell_object(user, BOLD+YEL+MONITOR);
        }
        if(uhp >=  umhp/2 && uhp < umhp - 50 && color_flag == 1) {
        tell_object(user, GRE + MONITOR);
        }
        if(uhp >= umhp - 50 && color_flag == 1) {
        tell_object(user, CYA + MONITOR);
        }
        if(color_flag == 0) {
        tell_object(user, MONITOR);
        }
        if(!att) {
        tell_object(user, NOSTYLE+"\n");
        return 1; }
        if(att) {
        tell_object(user, "[ATT: "+((hp * 100)/mhp)+"%]"+NONE+"\n");
        return 1;
        }
}
