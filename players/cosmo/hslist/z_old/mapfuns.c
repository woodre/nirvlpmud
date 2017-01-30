/*----------------------------------------------------------------------*/
/* This file contains mapping functions created by Cosmo, Wizardchild,  */
/* and Bastion.                                                         */

#pragma strict_types
#pragma save_types

/*
 * Function: m_values
 * Purpose : Return an array of the contents of mapping map.
 */
mixed *
m_values ( mapping map ) {
    mixed *values, *indices;
    int i, size;

    values = ({ });
    indices = keys(map);
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        values += map[indices[i]];
    return values + ({ });
}
    
/*-------------------------------------------------------------------*/
/* These functions were written by Cosmo.                            */
/*-------------------------------------------------------------------*/
/* Purpose: return 1 if key is in the mapping; 0 if not.             */
status member(mapping m, mixed key) {
int x;
mixed *indices;
  indices = keys(m);
  for (x=0; x<sizeof(m); x++) {
    if (indices[x]==key) return 1;
  }
  return 0;
}

/*-------------------------------------------------------------------*/
/* Purpose: Compare two integers. Return -1, 0, or 1 for <, =, or >. */
int intcmp(int a, int b) {
  if (a < b) return -1;
  else if (a = b) return 0;
    else  return 1;
}

/*-------------------------------------------------------------------*/
/* Purpose: Sort an array of integers and return the sorted array.   */
int *sort_array(int *nums) {
int x, y, temp;
  for (x=0; x < (sizeof(nums)-1); x++) {
    for (y=x+1; y < sizeof(nums); y++) {
      if (intcmp(nums[x], nums[y]) < 0) {
        temp = nums[x];
        nums[x] = nums[y];
        nums[y] = nums[x];
      }
    }
  }
  return nums;
}

/*-------------------------------------------------------------------*/
/* Purpose: write the keys and values of a mapping in tabular form.  */
void display_map(mapping m) {
int x, *values;
string *indices;
  indices = keys(m);
  values = m_values(m);
  values = sort_array(values);
  for (x=0; x<sizeof(indices); x++) {
    if (strlen(indices[x]) < 8)
      write(indices[x] + "\t\t" + values[x]] + "\n");
    else
      write(indices[x] + "\t" + values[x]] + "\n");
  }
}

/*-------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/* These functions were created by Wizardchild                          */
/*                                                                      */
/************************************************************/
/* mapping.c                                                */
/* functions to handle 'saveable' mappings in string format */
/* functions in this file:                                  */
/*  string store_mapping(mapping map)                       */
/*  map extract_mapping(string str)                         */
/* functions for internal use only:                         */
/*  string mixed_to_string(mixed m)                         */
/*  mixed string_to_mixed(string str)                       */
/*  string *mapping_sscanf(string src)                      */
/* an example of a string returned by store_mapping():      */
/* (["str":1,4:"xyz","player.c":"[OBJ]obj/player"])         */
/* type status will be converted to type int on restore     */
/* mapping_sscanf won't fuckup if ':' is in a string, and is*/
/* far from innefficient because of it                      */
/************************************************************/
 
/* convert type mixed to string */
string mixed_to_string(mixed m) {
  string out,tmp,foo;
  int n;
  if(objectp(m)) {
    foo = file_name(m);
    if(sscanf(foo, "%s#%d", tmp, n) != 2)
      tmp = "[NC]"+foo; /* so we don't clone rooms, etc */
    out = "[OBJ]"+tmp; /* distinctive header */
  } else if(stringp(m)) 
    out = "\""+m+"\"";
  else {
    tmp = ":"+m;
    sscanf(tmp, ":%s", out);
  }
  return out;
}
/* convert type string to mixed */
mixed string_to_mixed(string str) {
  mixed m;
  status nc;
  string tmp,fn;
  int i;
  object ob;
  if(sscanf(str, "%d", i))
    m = i;
  else if(sscanf(str, "[OBJ]%s", tmp)) {
    if(sscanf(tmp,"[NC]%s", fn))
      nc = 1;
    else
      fn = tmp;
    if(nc) {
      call_other(fn, "??");
      ob = find_object(fn);
    } else
      ob = clone_object(fn);
    if(ob) m = ob;
  } else {
    sscanf(str, "\"%s\"", tmp);
    m = tmp;
  }
  return m;
}
/* scan the mapping string and dump keys & members into string * */
string *mapping_sscanf(string src) {
  status in_string;
  string *out,tmp;
  int x,y,z,n,so;
  so = strlen(src);
  tmp = " ";
  for(x = 0; x < so; x++) {
    if(src[x] == '\"') in_string = !in_string;
    if((!in_string && src[x] == ':') || x == (so-1)) {
      if(!sizeof(out)) out = ({tmp});
      else out += ({tmp});
      tmp = 0;
    } else {
/*      tmp += " \b"; */
      tmp[y++] = src[x];
      write("pass "+x+": "+tmp+", "+src[x]+"\n");
    }
    if(y==2) sscanf(tmp,"0%s",tmp);
  }
  return out;
}    
/* store a mapping in a string */
string store_mapping(mapping map) {
  string out,p1,p2;
  mixed *key, *to;
  int x,so;
  key = keys(map);
  if(!key)
    return "";
  for(x=0,so=sizeof(key); x < so; x++) {
    if(x) to += ({ map[(key[x])] });
    else to = ({ map[(key[x])] });
  }
  out = "([";
  for(x = 0; x < so; x++) {
    p1 = mixed_to_string(key[x]);
    p2 = mixed_to_string(to[x]);
    out += p1+":"+p2+(x == (so-1) ? "])" : ",");
  }
  return out;
}
/* turn the string back into a mapping */
mapping extract_mapping(string str) {
  mapping map;
  mixed m1,m2;
  string tmp,*arr;
  int so,x,y;
  if(!sscanf(str, "([%s])", tmp)) 
    return ([]);
  /* muhahahahahahahahaha */
  arr = mapping_sscanf(tmp);
  for(x=0,y=1,so=sizeof(arr); x < so && y < so; x+=2,y+=2) {
    write(x+": "+arr[x]+", "+arr[y]+"\n");
    if(arr[x] == "" || arr[y] == "" || arr[x] == 0 || arr[y] == 0) continue;
    m1 = string_to_mixed(arr[x]);
    m2 = string_to_mixed(arr[y]);
    if(!x) map  = ([m1:m2]);
    else   map += ([m1:m2]);  
  }
  return map;
}

/*----------------------------------------------------------------------*/
/* These functions were created by Bastion.                             */
/*                                                                      */
/*
 * Some funs for manipulating mappings--like m_values which for some
 * reason DR doesn't have.
 * 
 * Bastian 07/26/95
 */

/*
 * Function: m_indices
 * Purpose : Return an array with the keys of mapping map.
 */
mixed *
m_indices ( mapping map ) {
    return keys(map);
}

/*
 * Function: make_mapping
 * Purpose : Take two arrays of keys and values and return a mapping made from
 *           them.
 */
mapping 
make_mapping ( mixed *indices, mixed *values ) {
    int i, size;
    mapping map;

    map = ([ ]);
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        map += ([ indices[i] : values[i] ]);
    return map + ([ ]);
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
    indices = keys(map);
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        savemap += ({ indices[i], map[indices[i]] });
    return savemap;
}

/*
 * Function: reconstruct_mapping
 * Purpose : Restore a mapping that was deconstructed with
 *           deconstruct_mapping.
 *           The array used to save the mapping will be zeroed upon
 *           completion.
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
/*----------------------------------------------------------------------*/
