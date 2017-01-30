/*
 * This file contains some functions that offer you the possibility to
 * find out easily what are the neighbour rooms (also which rooms are
 * reachable with a specific amount of steps) of one specific room.
 * Example call:
 * sur=query_surroundings("/room/church",5); // in sur are now the rooms
 *                                           // around the church which are
 *                                           // reachable with 5 steps or less
 * sur=query_surroundings(environment(find_living("harry")),4,1);
 *                                       // in sur are now the rooms which
 *                                       // are exactly 4 steps away from the
 *                                       // room harry is in
 */

#include <closures.h>

private mixed *neighbours(object room) {
  mixed *res;
  int i;
  object o;
  if (catch(res=room->query_exit())) {
    log_file("FLOODER",ctime()+": Cannot call query_exits() in "+
             object_name(room)+".\n");
    return ({ ({}),({}) });
  }
  if (pointerp(res) && sizeof(res)>1 && pointerp(res[1]))
    for (i=sizeof(res[1]); i--; ) {
      if (stringp(res[1][i]))
        if (!catch(o=load_object(res[1][i])))
          res[1][i] = o;
        else
          log_file("FLOODER",ctime()+": Cannot load "+res[1][i]+
                   " as wanted by "+object_name(room)+".\n");
      if (!objectp(res[1][i])) {
        res = transpose_array(res);
        res[i..i] = ({});
        res = transpose_array(res);
      }
    }
  else
    return ({ ({}),({}) });
  if (sizeof(res) < 2)  // all exits have been removed due to raising errors? 
    return ({ ({}),({}) });  // Alfe 1998-Sep-07
  return res;
}

private mixed *flood_further(object *black,object *gray) {
  object *white;
  int i,j;
  object s;
  white = ({});
  for (i=0; i<sizeof(gray); i++)
    white += (m_indices(mkmapping(neighbours(gray[i])[1])) -
              black - gray - white);
  return ({ black + gray,white });
}

varargs object *query_surroundings(mixed start,int distance,int only_farest) {
  object *gray,*black;
  mixed h;
  object s;
  if (stringp(start))
    if (!(start=load_object(start)))
      return ({});
    else if (!objectp(start))
      return ({});
  gray = ({ start });
  black = ({});
  while (distance--) {
    h = flood_further(black,gray);
    black = h[0];
    gray = h[1];
  }
  return only_farest? gray : black + gray;
}

private int busy;
private mixed result;
private closure fun;
private int depth;
private mixed *gray;
private object *black;

#define ROOMS 5

static void find_way_procedure() {
  object room;
  string *way;
  mixed *n;
  int i,j;
  for (i=(depth>ROOMS || depth<0? ROOMS : depth); i-- && sizeof(gray[0]); ) {
    room = gray[0][0];
    way = gray[1][0];
    if (funcall(fun,room)) {
      result = ({ room }) + way;
      busy = 0;
      return;
    }
    n = neighbours(room);
    for (j=sizeof(n[1]); j--; )
      if (member(black,n[1][j]) >= 0 ||
          member(gray[0],n[1][j]) >= 0 ||
          member(n[1][0..j-1],n[1][j]) >= 0)
        n[0][j..j] = n[1][j..j] = ({});
    gray = ({ gray[0][1..] + n[1],
              gray[1][1..] + map(n[0],
                                       lambda(({ 'x }),
                                              ({ (#'+),
                                                 quote(way),
                                                 ({ CL_ARRAY,'x }) }))) });
    black += ({ room });
  }
  if (!sizeof(gray[0])) {
    result = -1;            // could not be found
    busy = 0;
    return;
  }
  if (depth <= ROOMS && depth >= 0) {
    result = -2;            // depth reached
    busy = 0;
    return;
  }
  depth -= ROOMS;
  call_out("find_way_procedure",1);
}

int find_way(mixed start,int d,mixed f) {
  fun = f;
  depth = d;
  if (busy)
    return 0;
  if (stringp(start))
    if (!(start=load_object(start)))
      return 0;
    else if (!objectp(start))
      return 0;
  black = ({});
  gray = ({ ({ start }),({ ({}) }) });
  busy = 1;
  find_way_procedure();
  return 1;
}

object *query_black() { return black; } //  `.
mixed *query_gray() { return gray; }    //    > just for debugging purposes
int query_depth() { return depth; }     //  ,'

mixed query_result() { return !busy && result; }
int query_busy() { return busy; }

stop_search() {
  busy = 0;
  while (remove_call_out("find_way_procedure") != -1)
    ;
}
