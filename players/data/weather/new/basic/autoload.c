/*
    basic/autoload.c - general query_auto_load function
    Feb 1992 by marion@cs.tu-berlin.de
*/

public mixed *
query_auto_load ()
{
    return ({ load_name (this_object ()) });
}

public varargs int
drop (int silently)
{
  return 1;
}

