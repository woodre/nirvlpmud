#include "../DEFS.h"


string type;

status id(string str) { 
  return str == "die" || 
         str == "set" || 
         str == type+"_set"; 
}

status get()          { return 1; }
status drop()         { return 1; }
int query_weight()    { return 0; }
int query_value()     { return 0; }

void init() { add_action("engineer","engineer"); }

string short() { 
  if(!type) return "A "+FUNKYNAME+" die set"; 
  return "A "+capitalize(type)+" die set";
}

void long() { 
write(
"     This die set is a collection of super hi-tech chip architecting\n"+
"hardware and software. It must be engineered into an actual neural\n"+
"chip before you can upgrade another member's chip to it. To engineer\n"+
"this die set into an actual chip, you must 'engineer <chipBrand>'.\n");
}

status engineer(string str) {
  if(!str) { write("Engineer what chip?\n"); return 1; }
  if(type) {
    write("This die set has already been transformed into a chip.\n");
    return 1; }
  write("You first model the microprocessor in a high-level hardware\n"+
        "description language. Next, you synthesize the description\n"+
        "into a netlist, which is then fed into a layout-router.\n"+
        "The output of this is input into a microlyzer-transmogrifer,\n"+
        "and, after a few pretty sparks and flashes, a brand new\n"+
        capitalize(str)+" neural processor is taped-out!\n");
  type = str;
  return 1;
}
