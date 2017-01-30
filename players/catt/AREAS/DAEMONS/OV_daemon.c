/*******************************************
   This is the area daemon for the Orc Village
   area. It will control spawning npcs, environment
   noises, weather, etc.
   ->Catt
********************************************/

/*** Global Variables ***/
str weather;

/*** Weather Funcs ***/
   set_weather();
   query_weather();
   chat_weather();
   change_weather();

/*** Population Funcs ***/
   set_population();
   query_populace();
   set_spawn_rooms();

/*** Travel Funcs ***/
   set_travel_patterns();
   set_travel_random();
   perform_travel();

/*** Guard Funcs ***/
   set_guarding();
   query_guarding();
   set_guard_dirs();
   query_guard_dirs();

/*** Friend Funcs ***/
   set_friends();
   query_friends();

/*** Mappings ***/
maping populate;
   populate = ([
      "Guard1" : "OV_guard";1;set_guarding(1);set_travel(0),
      "Guard2" : "OV_guard";2;set_guarding(1);set_travel(0),
      "T_Warrior" : "OV_warrior";1;set_guarding(0);set_travel(1),
      "T_Peon" : "OV_peon";1;set_guarding(0);set_travel(1),
      "Shopkeeper" : "OV_shopkeeper";1;set_guarding(1);set_travel(0)
   ]);

mapping spawn_rooms;
   spawn_rooms = ([
      "village_1" : "Guard2";0,
      "village_2" : "Guard1";"Peon",
      "village_3" : "T_Peon";0,
   ]);

mapping weather_settings;
   weather_settings = ([
      "RAINSTORM" : "It begins to rain./n";
            "The rain beats down on you./n";
            "The downpour continues unabated./n";
            "The rain begins to lessen./n",
      "ICESTORM" : "A hard cold rain beats down on you./n";
            "The rain turns to sharp jagged ice./n";
            "The ice storm reaches an intense fury./n";
            "The storm begins to subside, its fury abated./n",
      "SNOWSTORM" : "It begins to snow./n";
            "The snow starts falling much thicker and harder./n";
            "You find if difficult to see as the snow blinds you./n";
            "You see slow falling snow flakes as the storm dwindles./n",
      "CLEARCOLD" : "It is a cool day./n";
            "You feel very cold./n";
            "You can't seem to warm up./n";
            "Everything around you looks to be covered in frost./n"
   ]);

/*** Primary Populate Function ***/
void populate() {

   if(query_populace()){
      call_population();
      set_travel_patterns();
      set_guard_dirs();
   }
return 1;
}

/*** Primary Weather Functions ***/

void set_weather() {
   if(!query_weather()) weather = RAINSTORM;
   if(query_weather()){
      call_out("chat_weather",50);
      call_out("change_weather",5000);
      return 1;
   }
   return 1;
}

str query_weather() {
   return weather;
}
int change_weather() {
   int i;
   if(!weather) {
      weather = "RAINSTORM";
      return 1;
   }
   switch(random(4)) {
      case 0 : weather = "RAINSTORM"; break;
      case 1 : weather = "ICESTORM"; break;
      case 2 : weather = "SNOWSTORM"; break;
      case 3 : weather = "CLEARCOLD"; break;
   }
return 1;
}
