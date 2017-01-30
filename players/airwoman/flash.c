inherit "players/airwoman/lit";

reset(arg){
   if (arg) return;
   set_name("flashlight");
   set_fuel(200);
   set_weight(1);
}
