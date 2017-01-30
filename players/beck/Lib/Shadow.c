
object player;

start_shadow(object ob){
   player = ob;
   shadow(player,1);
return 1;
}
stop_shadow(){
   shadow(player,0);
   destruct(this_object());
}
hit_player(dam1, zap, type1, dam2, type2){
   return DoDamage(({dam1,dam2}),({type1,type2}));
}
#include "/players/beck/Lib/DoDamage.c"
#include "/players/beck/Lib/Wear.c"
