 /* A orb that is a light field */
id(str) { return str == "orb"; }
get() { return 1; }
short() { return "Small blue orb"; }
long() {
   write("A small blue orb. Usage: orb on/off\n");
   return 1;
       }
reset(arg) { if(arg) return; }
init() {
   add_action("orb","orb");
   }
orb(str) {
  if(str == "on") set_light(4);
   if(str == "off") set_light(0);
  return 1;
}
