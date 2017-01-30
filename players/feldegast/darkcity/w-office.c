#include "def.h"

inherit MYROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Det. Walenski's Office";
  long_desc=
"     Detective Walenski's office is cluttered with stacks of old\n\
newspapers, carelessly tossed file folders, and hundreds of pages of\n\
scribbled notes.\n";
  items=({
    "stacks","All of the circled articles in each of the newspapers\n"+
             "is related to a serial killer stalking streetwalkers",
    "newspapers","All of the circled articles in each of the newspapers\n"+
             "is related to a serial killer stalking streetwalkers",
    "folders","The folders are full of crime scene reports, crime photos and\n"+
              "other material related to Walenski's current case",
    "files","The folders are full of crime scene reports, crime photos and\n"+
              "other material related to Walenski's current case",
    "notes","The notes are almost hieroglyphic.  A central theme to the scribblings\n"+
             "seem to be a looping spiral, and men in black coats",
    "pages","The notes are almost hieroglyphic.  A central theme to the scribblings\n"+
            "seem to be a looping spiral, and men in black coats"
  });
  dest_dir=({
    PATH+"squadrm","south"
  });
}   
