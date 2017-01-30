/*
  guild_news.h
*/

#include "defs.h"

/* -------- Guild News---------- */
guild_news(str) {
  if (!str) return 0;
if(str != "news") return 0;
  cat(GUILD_NEWS);
  return 1;
}
