#define ep environment(this_object())
#define eep environment(ep)
id(str) { return str == "finder"; }
int count;
drop() {return 1;}
get() { return 0;}

reset(arg) {
  if(arg) return;
  call_out("weather_check",3);
}

weather_check() {
if(ep) {
if(eep) {
if(present("weather",eep)) { count = 450; }
count = count - 1;
if(count < 1) { destruct(this_object()); return 1;} }}
call_out("weather_check",3);
return 1;}

query_shatter_proof() { return 1;}
