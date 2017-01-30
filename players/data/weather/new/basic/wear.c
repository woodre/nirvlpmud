/******************************************************************************
              basic/wear.c -- written by Ugh for Tubmud Jul-1997 
             an interface for objects that can wear other objects 
             this interface depends very much on basic/wearable.c
*******************************************************************************/
object get_user();

// We only record what we are wearing 
// We depend on the fact that the worn item records, where we wear it

private static mapping wearing;     // list of covers from in to out

object *get_wearing() {
  return wearing ? m_indices(wearing - ([0])) : ({});
}

private void set_wearing(object *h) {
  wearing = mkmapping(h);
}

status query_wearing(object thing) {
  return thing && member(get_wearing(),thing) >= 0;
}

string get_wear_location(object thing) {
  return
    thing && query_wearing(thing) &&
    (thing->get_worn_location(get_user(),this_object()) ||
     thing->query_name());
}

status can_wear(object thing) {
  int i;
  mixed w;

  if (!thing)
    return 0;
  // already wearing
  if (query_wearing(thing))
    return 0;
  if (!thing->query_wearable(get_user(),this_object()))
    return 0;
  if (sizeof(w = get_wearing()))
    for (i = sizeof(w); i--; ) 
      if (w[i]->prevent_overlay(get_wear_location(w[i]),
                                thing,get_wear_location(thing)))
        return 0;
  return 1;
}

void wear(object thing) {
  set_wearing(get_wearing()+({thing}));
  thing->notify_wear(get_user(),this_object());
}

status can_unwear(object thing) {
  int i;
  mixed h;

  if (!thing)
    return 0;
  if (!query_wearing(thing))
    return 0;
  if (thing->prevent_unwear(get_user(),this_object()))
    return 0;
  // ask all layers 'over' us, if they are overlaying us
  for (i = sizeof(h = get_wearing()); i--; )
    if (h[i] == thing)
      break;
    else if (h[i]->query_overlaying(get_wear_location(h[i]),
                                    thing,get_wear_location(thing)))
      return 0;
  return 1;
}

void unwear(object thing) {
  set_wearing(get_wearing()-({thing}));
  thing->notify_unwear(get_user(),this_object());
}

void notify_destruct() {
  map_objects(get_wearing(),"notify_unwear",get_user(),this_object());
}
