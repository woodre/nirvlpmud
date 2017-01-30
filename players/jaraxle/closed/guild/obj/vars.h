int gxp;
query_gxp(){ return gxp; }
set_gxp(int i){ gxp = i; }

int glvl;
query_glvl(){ return glvl; }
set_glvl(int i){ glvl = i; }

int skillpts;
query_skillpts(){ return skillpts; }
set_skillpts(int i){ skillpts = i; }

int fire_element;
query_fire_element(){ return fire_element; }
set_fire_element(int i){ fire_element = i; }

int water_element;
query_water_element(){ return water_element; }
set_water_element(int i){ water_element = i; }

int wind_element;
query_wind_element(){ return wind_element; }
set_wind_element(int i){ wind_element = i; }

int earth_element;
query_earth_element(){ return earth_element; }
set_earth_element(int i){ earth_element = i; }
 
int cost_toggle;
query_cost_toggle(){ return cost_toggle; }
set_cost_toggle(int i){ cost_toggle = i; saveme(1); }

int earth_shield;
query_earth_shield(){ return earth_shield; }
set_earth_shield(int i){ earth_shield = i; }

int fire_shield;
query_fire_shield(){ return fire_shield; }
set_fire_shield(int i){ fire_shield = i; }

int water_shield;
query_water_shield(){ return water_shield; }
set_water_shield(int i){ water_shield = i; }

int wind_shield;
query_wind_shield(){ return wind_shield; }
set_wind_shield(int i){ wind_shield = i; }

int fire_hands;
query_fire_hands(){ return fire_hands; }
set_fire_hands(int i){ fire_hands = i; }

static int delay;
set_delay(int i){ delay = i; }
query_delay(){ return delay; }
