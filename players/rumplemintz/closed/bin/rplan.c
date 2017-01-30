#pragma strong_types

#include <ansi.h>

status
rplan() {
  string plan;
  plan = "";
  plan += HIG;
  plan += "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
  plan += "\n";
  plan += "@@                                                              @@";
  plan += "\n";
  plan += "@@                 "+HIB+"Rump's plans for Nirvana"+GRN;
  plan += "                     @@";
  plan += "\n";
  plan += "@@                                                              @@";
  plan += "\n";
  plan += "@@==============================================================@@";
  plan += "\n";
  plan += "@@                                                              @@";
  plan += "\n";
  plan += "@@  "+HIB+"Port current mudlib to latest LDmud branch"+GRN+"                  @@";
  plan += "\n";
  plan += "@@  "+HIB+"Renshai guild - dual wielding sword specialists"+GRN+"             @@";
  plan += "\n";
  plan += "@@                                                              @@";
  plan += "\n";
  plan += "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
  plan += NORM+"\n";
  rm("/players/rumplemintz/PLAN");
  write_file("/players/rumplemintz/PLAN", plan);
  return 1;
}
