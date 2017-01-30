object what;
string clap;
id(str) { return str == "climate_shadow"; } 

start_climate_shadow(what) {
shadow(what, 1);
call_out("stop_shadow_momomoo",100);
return 1;}

stop_shadow_momomoo() {
shadow(what, 0);
return 1;}

set_specs(string moo) { clap = moo; }

realm() { return clap; }
