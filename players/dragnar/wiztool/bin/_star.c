#define PAIN "/players/pain/NEW/items/star_daemon"

int
cmd_star( string str ) {
  PAIN->star( str );
  return 1;
}
