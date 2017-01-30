#include "/players/guilds/bards/def.h"

status main(string str) {
  if (spell(-100, 2, 5) == -1)
    return 0;
  write("You play some chords upon your " + INST +
      ".\n");
  say(tp + " plays some chords upon " + POSS(TP) + " " + INST + ".\n");
  write("You detect that ");
  switch(random(6)) {
    default:
      write("there is a high chance of rain.\n");
      break;
    case 1:
      write("it will be a sunny day.\n");
      break;
    case 2:
      write("it will be a cloudy day.\n");
      break;
    case 3:
      write("there is a small chance of rain.\n");
      break;
    case 4:
      write("that it will be an unusually warm day.\n");
      break;
    case 5:
      write("that is will be an unusually cold day.\n");
      break;
  }

  call_other(TP, "add_spell_point", -5);
  return 1;
}