/*
 * /basic/copy.c   by Alfe for Tubmud '95
 *
 * The function copy_() provides a complete copy of any data structure you
 * might get. The common way of using [0..] for arrays and copy_()
 * for mappings only copies the 'first floor'. If you have an array being
 * part of a value of a mapping and an array inside this it will not be
 * copied with any of the usual ways.
 * copy_() is (as Macbeth at once mentioned) not cheap. Please use it only
 * if you really need it. In most cases [0..] and copy_() will fit
 * your task.
 *
 * copy_() will NO LONGER result in a too deep recursion for recursive data
 * structures IF RECURSIVE_RESISTENT is defined.
 *
 * ATTENTION:  I renamed the old lfun copy() to copy_() because an efun of
 *             the name deep_copy() exists which does what the old copy()
 *             did by far less cost.  A new lfun copy() which only relays
 *             the call to the efuns deep_copy() now also exists.
 *             Alfe 2005-Jan-3
 */

#pragma strong_types

#include <lpctypes.h>
#include <closures.h>

#define RECURSIVE_RESISTENT

private mixed quote_many(mixed x,int i) {
  while (i-->0)
    x = quote(x);
  return x;
}

mixed copy(mixed source) {
  return deep_copy(source);
}

#ifdef RECURSIVE_RESISTENT

varargs mixed copy_(mixed source,mixed *source_stack,mixed *result_stack) {
  mixed h;
  mixed indices,index;
  int i,j,width;
  if (!source_stack)
    source_stack = ({}), result_stack = ({});
  switch (typeof(source)) {
  case T_QUOTED_ARRAY:
    return quote_many(copy_(to_array(source),source_stack,result_stack),
                      get_type_info(source,1));
  case T_OBJECT:
  case T_CLOSURE:
    ;                   // they cannot be copied *sigh*
  case T_NUMBER:
  case T_FLOAT:
  case T_STRING:
  case T_SYMBOL:
    return source;      // they are copied by simple returning
  case T_POINTER:
    if ((i=member(source_stack,source)) >= 0)  // recursion found?
      return result_stack[i];  // return the recursed data
    source_stack += ({ source });
    result_stack += ({ allocate(i=sizeof(source)) });
    while (i--)
      result_stack[<1][i] = copy_(source[i],source_stack,result_stack);
    return result_stack[<1];
  case T_MAPPING:
    if ((i=member(source_stack,source)) >=0)  // recursion found?
      return result_stack[i];  // return the recursed data
    source_stack += ({ source });
    result_stack += ({ m_allocate(sizeof(source),
                                        (width=get_type_info(source,1))) });
    indices = m_indices(source);
    for (i=sizeof(indices); i--; ) {  // for all keys
      index = copy_(indices[i],source_stack,result_stack);
      if (width)
        for (j=width; j--; )  // for all values
          result_stack[<1][index,j] = copy_(source[indices[i],j],
                                            source_stack,result_stack);
      else
        result_stack[<1] += ([ index ]);
    }
    return result_stack[<1];
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

#else

mixed copy_(mixed source) {
  mixed indices;
  mixed h;
  int i;
  switch (typeof(source)) {
  case T_QUOTED_ARRAY:
    return quote_many(copy_(to_array(source)),get_type_info(source,1));
  case T_OBJECT:
  case T_CLOSURE:
    ;                   // they cannot be copied *sigh*
  case T_NUMBER:
  case T_FLOAT:
  case T_STRING:
  case T_SYMBOL:
    return source;      // they are copied by simple returning
  case T_POINTER:
    return map(source,#'copy); // copy all elements
  case T_MAPPING:
    h = allocate(get_type_info(source,1));
    indices = m_indices(source);
    for (i=sizeof(h); i--; )
      h[i] = map(indices,
                       lambda(({ 'x,'source }),
                              ({ (#'copy),
                                 ({ CL_INDEX,'source,'x,i }) })),
                       source);
#if 0  // copy also the indices   Alfe 1997-Feb-08
    return apply(#'mkmapping,indices,h);
#else
    return apply(#'mkmapping,map(indices,#'copy),h);
#endif
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

#endif
