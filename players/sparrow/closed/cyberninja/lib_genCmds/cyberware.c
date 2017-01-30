#include "../DEFS.h"

status main(string str) {
  /* method for players to see enhancement info */
  tell_object(TP, "You take out your handy CyberWare Manual.\n");
  move_object(clone_object(OBJDIR + "/cyberware_manual.c"), TP);
  say(TPN+" takes out a thick manual.\n");
  return 1;
}
