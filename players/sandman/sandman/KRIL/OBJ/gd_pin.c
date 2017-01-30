id(str) { return str == "pin" || str == "guard's pin"; }

short() {
   return "A guard's pin";
}

long() {
write("This is the pin worn by all members of the Coral Watch. The pin is\n");
write("made of bronze with a carving of a balanced scale on its face. The\n");
write("scale symbolizes the guards 'neutrality' in all affairs. Although\n");
write("the towns people say the scale stands for the guards noted affinity\n");
write("for a gold coin.\n");
}

query_weight() {
   return 1;
}

query_value() {
   return 200;
}

get() {
   return 1;
}
