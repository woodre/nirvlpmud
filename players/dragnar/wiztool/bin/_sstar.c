#define PAIN "/players/pain/NEW/items/star_daemon"

int
cmd_sstar( string str ) {
  PAIN->star( "\n"+"/players/dragnar/daemons/ascii/a"->ascii_string("starwars",str  ));
  return 1;
}
