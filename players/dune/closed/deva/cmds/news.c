/*
 * NEWS command for Ascension
 * read guild news
 */
#include "../def.h"

status main() {
  write("\nYou catch up on the latest events.\n");
  write("----------------------------------\n");
  cat(PATH+"news");
  return 1;
}
