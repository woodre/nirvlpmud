#include "/players/illarion/dfns.h"
inherit "obj/treasure";

string color,color_code;

void reset(int arg) {
  if(arg) return;

  if(!color) { color="red"; color_code= RED; }
  name= "balloon";
}
void init() {
  add_action("cmd_change","change_color");
}
int cmd_change(string str) {
  if(!str) FAIL("Change the balloon to what color?\n");
  switch(str) {
    case "red":
      color_code=RED;
      break;
    case "green":
      color_code=GRN;
      break;
    case "blue":
      color_code=BLU;
      break;
    case "cyan":
      color_code=CYN;
      break;
    case "purple":  case "magenta":
      str="purple";
      color_code=MAG;
      break;
    default: 
      FAIL("The color choices are: red, green, blue, cyan, and purple\n");
  }
  color=str;
  write("The balloon is now "+color_code+color+NORM+".\n");
  return 1;
}
short() { return "A large "+color_code+color+NORM+" balloon";}
long() { show_balloon(); }
void show_balloon() {
write(color_code+
"              ,,,,,,,,,,,,,\n"+
"          .;;;;;;;;;;;;;;;;;;;,.\n"+
"        .;;;;;;;;;;;;;;;;;;;;;;;;,\n"+
"      .;;;;;;;;;;;;;;;;;;;;;;;;;;;;.\n");
  write(
"      ;;;;;"+BOLD+"@"+color_code+";;;;;;;;;;;;;;;;;;;;;;;;'\n"+
"      ;;;;"+BOLD+"@@"+color_code+";;;;;;;;;;;;;;;;;;;;;;;;'\n"+
"      ;;;;"+BOLD+"@@"+color_code+";;;;;;;;;;;;;;;;;;;;;;;;'\n"+
"      `;;;;"+BOLD+"@"+color_code+";;;;;;;;;;;;;;;"+BOLD+"@"+color_code+";;;;;;;'\n");
  write(
"       `;;;;;;;;;;;;;;;;;;;"+BOLD+"@@"+color_code+";;;;;'\n"+
"         `;;;;;;;;;;;;;;;;"+BOLD+"@@"+color_code+";;;;'\n"+
"           `;;;;;;;;;;;;;"+BOLD+"@"+color_code+";;;;'\n"+
"              `;;;;;;;;;;;;'\n");
  write(
"                 `;;;;;;'\n"+
"                    ;;\n"+NORM+
"                    `\n"+
"                   `\n"+
"                  `\n"+
"                 `\n");
  write(
"                `\n"+
"               `\n"+
"              `\n"+
"              `\n"+
"              `\n"+
"               `.\n");
  return;
}
