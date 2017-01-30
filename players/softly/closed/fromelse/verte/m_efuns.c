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
colour_pad(string text, int length)
{
    int i, s;
    string l, x, z;

    s = strlen(text);

    while(s --)
    {
       l = text[s..s];
        if((l == esc) &&
        sscanf(text, l + "%sm", x))
        {
          i += (2 + strlen(x));
        }
    }
    
    length += i;
    return (pad(text, length));
}

