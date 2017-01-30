#include <ansi.h>

#define PATH "players/snow/dervish/member/"
#define MAXSIZE 20
#define TESTCHAR_D "/obj/user/testchar-d"

int sand_points;
int level;
string name;

static mixed *unsorted;

id(string str) {
  return str == "mound" || str == "sand" || "mound of sand"; 
}

short() { 
  return "A swirling mound of "+YEL+"sand"+NORM;
}

long() {
  int i;
  
write("The mound of sand swirls and shifts and starts to form words in\n\
the side of the mound. You realize the sands are transcribing the\n\
Dervish that have been most dedicated to giving "+HIR+"blood"+NORM+" to the "+YEL+"Sands"+NORM+".\n\n");

  PrintList();

}

init() {
   add_action("DoSort","sort");
      
}
reset(arg){
  if(arg) return;
}

PrintList() {
  int i, max, cols;
  
  if(!unsorted)
    DoSort();
    
  if(unsorted)
  {
    max = unsorted[0][1];
      
    for( i = 0; i < sizeof(unsorted) && i <= MAXSIZE; i++ ) {
      cols = unsorted[i][1] * 100 / max;
      /** Adjust to a line limit of 70 **/
      cols = cols * 70 / 100;
      
      write( pad(capitalize(unsorted[i][0]),12, ' ')  +" " );
      
      write( YEL + pad("", cols, '#') );
      write( NORM+"\n" );
    }
  }
}

DoSort() {
  int x;
  int i;
  int siz;
  string dir, who, junk;
  
  dir = get_dir("/"+PATH+"*" );
  x = 0;
  if(this_player()->query_level() < 90) return 0;
  
  siz = sizeof(dir);
  unsorted = allocate( siz );
  
  while( x < siz ) 
  {
    unsorted[x] = allocate(2);
    unsorted[x][0] = "Noone";
    unsorted[x][1] = -100;
    if(sscanf(dir[x],"%s.o",who)) 
    {
      if(restore_object(PATH+who))
      {
        if(Verify(who) == 1 && sand_points > 1)
        {
          if( level > 19 )
            sand_points = 0;
          if(junk = (string)TESTCHAR_D->query_owner(name))
            sand_points = 0;
          unsorted[x][0] = who;
          unsorted[x][1] = sand_points;
        }
      }
    }
    x++;
  } /* end while */
  
  unsorted = sort_array(unsorted, "sp_sort", this_object());

   return 1;
}

int sp_sort(mixed *a, mixed *b) {
  return ( a[1]  < b[1] );
}


Verify(str) {
  /* Taken from Boltars /boltar/templar/verif.c and modified */

  if(restore_object("pfiles/" + extract(str,0,0) + "/" + str)) return 1;
  if(restore_object("players/inactive_saved/" + str)) return 2;
  return 0;
}

get() { return 0; }
drop() { return 1; }
query_weight() { return 1000; }
query_value() { return 0; }

