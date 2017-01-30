/*VARIABLES*/

int glevel, guild_xp, reserve_power;
int has_ghoul, has_dragon;
string title, dragon_name;
string tele_room; 
object drakyr;

query_glevel(){ return glevel; }
set_glevel(num){ glevel = num; }

query_guild_xp(){ return guild_xp; }
add_guild_xp(num){ guild_xp += num; }

query_reserve_power(){ return reserve_power; }
add_reserve_power(num){ reserve_power += num; }
delete_reserve_power(num){
 reserve_power -= num;
 if(reserve_power <= 0)
 reserve_power = 0;
}

query_dragon_name(){ return dragon_name;}
set_dragon_name(str){ dragon_name = str; }  

query_has_ghoul(){ return has_ghoul; }
set_has_ghoul(num){ has_ghoul = num; }

query_has_dragon(){ return has_dragon; }
set_has_dragon(num){ has_dragon = num; }
  
set_tele_room(str){ tele_room = str; }
query_tele_room(){ return tele_room; }

set_drakyr(ob) { drakyr = ob; }
query_drakyr() { return drakyr; }
