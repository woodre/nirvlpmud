#include <ansi.h>
#define PAIN "/players/pain/NEW/items/star_daemon"

int
cmd_blick( string str ) {
  object target;
  
  if( str ) {
    target = present(str, environment( this_player() ) );
    if( !target ) {
      write("Blick who?\n");
    }
    if( !living(target) ) {
      write(capitalize(str)+" is not alive.\n");
      return 1;
    }
    target->attacked_by( this_player() );
  }
  else
    target = (object) this_player()->query_attack();

  if(!target) {
    write("Blick unable to find a target.\n");
    return 1;
  }
  say(HIBLK+"'s finger turns black and he touches "+target->short()+".\n"+NORM);
  target->death();
  return 1;
}
