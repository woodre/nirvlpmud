/*
  guild_news.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Guild News---------- */
guild_news(str) {

  if (!str || str!="news") return 0;
  write(NORM+CYN);
  cat(ALCHEMIST_NEWS);
  write(NORM);
  return 1;

}
