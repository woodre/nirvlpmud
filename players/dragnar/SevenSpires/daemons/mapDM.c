#include <ansi.h>
#include <regexp.h>

#include "../defs.h"
/******************************************************************************
 * Program: mapDM.c
 * Path: /players/dragnar/SevenSpires/daemons
 * Type: Daemon 
 * Created: March 25th, 2016 by Dragnar
 *
 * Purpose: A daemon object that assists with the map functions for the 
 *          Seven Spires area.
 * History:
 *          03/25/2016 - Dragnar
 *            Created
 ******************************************************************************/

#define DEBUG 1
#define LOGFILE LOGDIR + "/mapDM.log"

mapping map_key;
mixed *map_key_a;
string delimiter;

int row, col;
string directory, fi, map_file;

void clear_data() {
  row = 0;
  col = 0;
  directory = "";
  fi = "";
  map_file = "";
}

/******************************************************************************
 * Function: load_map
 *
 * Purpose: Loads the map object and sets the global variables.
 ******************************************************************************/
void load_map( string str ) {
  int i;
  string tmp_dir, file_name, color;
  string *file_path;
  
  /* Validate parameter */
  tmp_dir = "";
#ifdef __LDMUD__
  file_path = regexplode(str, "\/" );
#else
  file_path = explode(str, "/" );
#endif
  for( i=0; i < sizeof(file_path); i++ ) {
#if DEBUG
    write("["+i+"]"+file_path[i]+".\n");
#endif
    if( i == sizeof(file_path) - 1 )
      file_name = file_path[i];
    else
      tmp_dir += file_path[i] + "/";
  } 
#if DEBUG
  write("Dir: "+tmp_dir+".\n");
  write("FN:  "+file_name+".\n");
#endif
  
  sscanf( file_name, "r%dc%d", row, col );
#if DEBUG
  write( "row:"+row+" col:"+col+"\n");
#endif

  /** No need to reload if it matches restored map **/
  if( tmp_dir == directory )
    return;
  
  directory = tmp_dir;
  
  /* Get the key for the map */
#if DEBUG
  write( "Key: " +  directory + "map_key.\n");
#endif
  if( !restore_object( directory + "map_key") )
    return;
  
#ifndef __LDMUD__
  map_key = reconstruct_mapping( map_key_a );
#endif

  /* Read the file */
#if DEBUG
  write( "Map: " +  "/" + directory + "map.txt" + " size: "+file_size( "/" + directory + "map.txt" )+".\n");
#endif
  if( file_size( "/" + directory + "map.txt" ) < 1 )
    return;

  /* Check delimiter */
  if( !delimiter )
    return;

  map_file = read_file( "/" + directory + "map.txt");

}

/******************************************************************************
 * Function: get_map
 *
 * Purpose: Reads the map, adds color, sets the current room to an X and returns
 *          the string. Used by the rooms to set the long descriptions.
 ******************************************************************************/
string get_map(string str) {
  int i,j;
  string fi, color;
  string *line;
  mixed *matrix;

  load_map( str );

  if( !map_key ) {
    write_file( LOGFILE, ctime(time())+" Bad Key: "+directory+"map_key.\n" );
    return "";
  }

  /* Read the file */
  if( !map_file ) {
    write_file( LOGFILE, ctime(time())+ "Bad Map: "+directory+"map.txt"+".\n" );
    return "";
  }

  /* Check delimiter */
  if( !delimiter ) {
    write_file( LOGFILE, ctime(time())+ "Bad Delimiter: "+directory+".\n" );
    return "";
  }

  line = explode( map_file, "\n");
  fi = "";

  /* Set the number of rows in the matrix */
  matrix = allocate( sizeof(line) );
  for( i=0; i < sizeof(line); i++ ) {
    /* Generate the columns in the matrix */
    matrix[i] = explode( line[i], delimiter );
    for( j=0; j < sizeof( matrix[i] ); j++) {
      /* Current room so substitute an X at that location */
      if( i == row && j == col )
        matrix[i][j] = "X";
	
	  /* Add colors to the file based on the mapping key */
	  color = map_key[ matrix[i][j] ][0];
	  if( color )
		  matrix[i][j] = color + matrix[i][j] + NORM;
	
#if DEBUG
      write(matrix[i][j]);
#endif
    }
    fi += pad(" ", 10) + implode( matrix[i], delimiter ) + "\n";
#if DEBUG
    write("\n");
#endif
  }
#if DEBUG
  write("file:\n");
  write(fi);
  write("end file\n");
  write("search str:"+"[\\"+implode(m_indices(map_key), "")+"]\n");
#endif

#if 0  
  fi = regreplace(fi, "[\\"+implode(m_indices(map_key), " ")+"]",
  function string( string str ) {
    string color;
    color = map_key[ str ][0];
#if DEBUG
  write("Str: " + str+color+"COLOR"+NORM+"\n");
#endif
    if( color )
      return color+str+NORM;
    return str;
  }
, RE_GLOBAL);
#if DEBUG
  write(fi);
#endif
#endif
  return fi;
}

/******************************************************************************
 * Function: get_key
 *
 * Purpose: Reads the map to create the key. Used by the rooms.
 ******************************************************************************/
string get_key( string str ) {
  int i;
  string *symbols;
  string ret;
  
  load_map( str );
  
  symbols = m_indices(map_key);
  ret = "";
  
  for( i = 0; i < sizeof(symbols); i++ ) {
    ret += "   " + map_key[ symbols[i] ][0] + pad(symbols[i],5) + NORM + "- " + map_key[ symbols[i] ][1] + "\n";
  }
  return ret;
}

