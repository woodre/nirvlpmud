object player;
int i;

start_a_shadow(who) {
player = who;
shadow(player, 1);
return 1;}

stop_shadow_me() {
shadow(player, 0);
return 1;}

do_quit() {
   shadow(player, 0);
   player->do_quit();
return 1;}
   
quit() {
   shadow(player, 0);
   player->quit();
return 1;}

