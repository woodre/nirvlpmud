#include "/players/snow/dervish/def.h"

status dervish_sandcheck()
{
  object myob;
  int max;
  int cols;
  int sp;
  int bravery;
  
  myob = present(GID, TP);
  if(!TP || !myob) { write("Something is wrong.\n"); return 1; }
  if(TP->query_level() < 10 ) {
    write("You are not high enough level to use this ability yet.\n");
    return 1; }
  if(TP->query_ghost()) {
    write("You lack substance.\n"); return 1; }
  if(TP->query_attrib("pie") < 20) {
    write("You lack devotion.\n"); return 1; }
  
  write("You concentrate on your connection with the sands.\n");
  sp = (int) myob->query_sand_points();
  if( sp < 0 )
    sp = 1;
  bravery = (int) myob->query_bravery();
  
  if(!bravery) {
    max = 10000;
  }
  else{
    max = 100000;
  }
  
  cols = sp * 100 / max;

  /** Adjust to a line limit of 80 **/
  cols = cols * 80 / 100;
  
  if( cols <= 0 )
    cols = 1;
    
  if( cols > 80 )
    cols = 80;
  
  write( HIBLK );
  write( pad("", 80, '-') );
  write( "\n" );
     switch( cols ) {
    case 0..10:
      write(HIR);
      break;
    case 11..60:
      write(HIY);
      break;
    default:
      write(HIG);
      break;
  }
  write( pad("", cols, '#') );
  write( "\n" );
  write( HIBLK );
  write( pad("", 80, '-') );
  write( "\n" +NORM );
  return 1;
}