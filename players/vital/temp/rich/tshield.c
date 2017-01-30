 id(str) {
     if(str=="shield"||str=="torpedo shield"||str=="ttoy") return 1;

return 0;
}
short() {
  return "Torpedo Shield";
  }
long() {
  return "Photon Torpedo Shield";
 }
query_value() {
   return 1500;
 }
query_weight() {return 2;}
get() {return 1;}
init() {}
reset() {}
