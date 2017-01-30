/*-------------------------------------------------------------------
 This file contains mapping functions for use with the virtual display
 screen (vds.c).
*/

/*-------------------------------------------------------------------*
 * Written by Bastion
 *-------------------------------------------------------------------*/
/*
 * Function: m_values
 * Purpose : Return an array of the contents of mapping map.
 */
mixed *
m_values ( mapping map ) {
    mixed *values, *indices;
    int i, size;

    values = ({ });
#ifndef __LDMUD__ /* Rumplemintz */
    indices = keys(map);
#else
    indices = m_indices(map);
#endif
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        values += ({ map[indices[i]] });
    return values + ({ });
}

/*
 * Function: deconstruct_mapping
 * Purpose : Takes the contents of map and places them in the array pointer
 *           provided. The fun also returns the new array.
 */
mixed *
deconstruct_mapping ( mapping map ) {
    int i, size;
    mixed *indices, *savemap;

    savemap = ({ });
#ifndef __LDMUD__ /* Rumplemintz */
    indices = keys(map);
#else
    indices = m_indices(map);
#endif
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        savemap += ({ indices[i], map[indices[i]] });
    return savemap;
}

/*
 * Function: reconstruct_mapping
 * Purpose : Restore a mapping that was deconstructed with
 *           deconstruct_mapping. The array used to save the
 *           mapping will be zeroed upon completion.
 */
mapping
reconstruct_mapping ( mixed *savemap ) {
    int i, size;
    mapping map;
    
    map = ([ ]);
    for ( i = 0, size = sizeof(savemap); i < size; i++ )
        map += ([ savemap[i] : savemap[++i] ]);
    savemap[0..size - 1] = ({ });
    return map;
}
    
/*-------------------------------------------------------------------*
 * Written by Cosmo
 *-------------------------------------------------------------------*/
/* 
 * Function: member
 * Purpose: return 1 if key is in the mapping; 0 if not.
 */
status member(mapping m, mixed key) {
int x;
mixed *indices;
#ifndef __LDMUD__ /* Rumplemintz */
  indices = keys(m);
#else
  indices = m_indices(m);
#endif
  for (x=0; x<sizeof(m); x++) {
    if (indices[x]==key) return 1;
  }
  return 0;
}

/*
 * Function: check_scores
 * Purpose: Compare amt to the all-time scores.  Return -1 if amt is 
 * less than all of the scores; otherwise, return the position in    
 * array where it belongs.
 */
int check_scores(int amt, int *scores) {
int x;
  for (x=0; x<sizeof(scores); x++) {
    if (amt >= scores[x]) return x;
  }
return -1;
}

/*
 * Function: update_array
 * Purpose: Add a new item in an array and bump the rest down one.
 */
mixed *update_array(int num, mixed item, mixed *tmparray) {
int x;
  for (x=sizeof(tmparray)-1; x>num; x--) 
    tmparray[x]=tmparray[x-1];
  tmparray[num]=item;
return tmparray;
}

/*
 * Function: intcmp
 * Purpose: Compare two integers. Return -1, 0, or 1 for <, =, or >.
 */
int intcmp(int a, int b) {
  if (a < b) return -1;
  else if (a = b) return 0;
    else  return 1;
}

/*
 * Function: sort_array
 * Purpose: Sort an array of integers and return the sorted array.
 */
int *sort_array(int *nums) {
int x, y, temp;
  for (x=0; x < (sizeof(nums)-1); x++) {
    for (y=x+1; y < sizeof(nums); y++) {
      if (intcmp(nums[x], nums[y]) < 0) {
        temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
      }
    }
  }
  return nums;
}

