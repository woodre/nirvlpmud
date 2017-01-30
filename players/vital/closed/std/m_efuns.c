
/* m_efuns; ideas
    ripped off from bastion's shit in open */

#include "/players/boltar/things/esc.h"

mixed *
m_indices(mapping map)
{
     return keys(map);
}

mapping
reconstruct_mapping(mixed *saved_map)
{
    int c, s;
    mapping new;

    new = ([ ]);
    s = sizeof(saved_map);

    for(c = 0; c < s; c+=2)
      new += ([ saved_map[c] : saved_map[c + 1] ]);
    
    return new;
}

mixed *
deconstruct_mapping(mapping map)
{
    int c, s;
    mixed *i, *n;

    i = m_indices(map);
    n = ({ });
    s = sizeof(i);

    for(c = 0; c < s; c++)
      n += ({ i[c], map[i[c]] });

    return n;
}

/* nog that shiznola .. this one by me :) */
int
member(mixed arg, mixed element)
{
    int i;
    mixed *k;
    if(pointerp(arg))
      return (i  = member_array(element, arg));
    else
    {
      i = sizeof(k = keys(arg));
      while(i --)
        if(k[i] == element)
          return 1;
      return 0;
    }
}

/* a verte invention */

mixed
m_delete(mapping map, mixed key)
{
    int s;
    mixed *k, *new_map;
   
    if(!member(map, key))
      return 0;

    else
    {
      s = sizeof(k = keys(map));
      new_map = ({ });

      while(s --)
        if(k[s] != key)
          new_map += ({ k[s], map[k[s]], });

      map = reconstruct_mapping(new_map);
      return map;
    }
}

string
colour_pad(string str, int length) 
{
    int i, s, ansi, flag;
    
    s = strlen(str);
    while(i < s)
    {
      if(str[i..i] == esc) 
        flag = 1;
      if(flag) 
      {
        ansi ++;
        if(str[i..i] == "m") 
          flag = 0;
      }
      i ++;
    }

    length += ansi;
    return(pad(str, length));
}




mixed *
m_values(mapping map)
{
    int s, i;
    mixed *m, *n;

    s = sizeof(m = m_indices(map));
    n = ({ });

    while (i < s)
    {
      n += ({ map[m[i]] });
      i ++;
    }

    return n;
}

mixed
get_key(mapping map, mixed val)
{
    mixed *m, *v;
    int i, s;

    v = m_values(map);
  
    if((i = member_array(val, v)) == -1)
      return -1;

    m = m_indices(map);
    return m[i];
}
