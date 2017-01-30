object target;
shadow_target(str) {
   shadow(str,1);
   target = str;
     }
short() {
   string name;
   name = target->query_pretitle();
   name += "Gorgan";
   name += target->query_pretitle();
   return name;
   }
query_name() { return "The_incredible_edible_egg"; }
id(str) { return str == "bagera"; }
