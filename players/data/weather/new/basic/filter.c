#include <limits.h>

inherit "basic/copy";

private nosave mapping features;

void add_filter(string feature, int priority) {
  mixed *temp;
  int i;
  int cleanup;

  temp = features && features[feature];
  if (!temp) {
    if (features)
      features[feature]=({ priority, previous_object() });
    else
      features = ([ feature : ({ priority, previous_object() }) ]);
  }
  else {
    for (i=sizeof(temp)-2;i>=0;i-=2) {
      if (!temp[i+1])
        cleanup = 1;
      if (temp[i]<=priority) {
        temp = temp[0..i+1]+({ priority, previous_object() })+temp[i+2..];
        features[feature] = temp;
        return;
      }
    }
    features[feature] = ({ priority, previous_object() }) + temp;
    if (cleanup) {
      for (i=1;i<sizeof(temp);)
        if (temp[i])
          i+=2;
        else
          temp = temp[0..i-2] + temp[i+1..];
      features[feature]=temp;
    }
  }
}

void remove_filter(string feature) {
  mixed *temp;
  int i;

  temp = features && features[feature];
  if (!temp)
    return;
  for (i=1;i<sizeof(temp);) {
    if (temp[i]==previous_object() || !temp[i])
      temp = temp[0..i-2]+temp[i+1..];
    else
      i += 2;
  }
  if (!sizeof(temp))
    features = m_delete(features,feature);
  features[feature]=temp;
}

mixed query_filters(string feature) {
  mixed *temp;
  int i;

  if (!feature)
    return copy(features);
  temp = features && features[feature];
  if (!temp)
    return ({ });
  else {
    for (i=1;i<sizeof(temp);) {
      if (temp[i])
        i+=2;
      else
        temp = temp[0..i-2] + temp[i+1..];
    }
    return temp[0..];
  }
}

private static int upper_limit = INT_MAX, lower_limit = INT_MIN;

public mixed call_with_limited_filters(closure c,int low,int upp,
                                       varargs mixed extra) {
  mixed result,h;

  while (get_eval_cost() < 1000)  // endless loop if isn't enough time left
    ;
  lower_limit = low;
  upper_limit = upp;
  h = catch(result=apply(c,extra));
  // in any case: reset the limits
  lower_limit = INT_MIN;
  upper_limit = INT_MAX;
  if (h)  // now check if there was an error
    raise_error(h);  // and raise it
  return result;
}

mixed apply_filter(string feature,mixed arg) {
  mixed h;
  mixed *temp;
  int i;
  int cleanup;

  temp = features && features[feature];
  if (!temp || !sizeof(temp))
    return arg;
  for (i=1; i<sizeof(temp); i+=2) {
    if (temp[i-1] > upper_limit)  // prio already higher than our limit?
      break;
    if (temp[i] && temp[i-1] >= lower_limit) {
      if (h=catch(arg = ({ mixed })temp[i]->do_filter(feature,arg))) {
        // Alfe 1998-Mar-21
        __MASTER_OBJECT__->runtime_error(h + " in " + to_string(temp[i]) +
                                         "->do_filter(" + feature + ", ...)\n",
                                         __FILE__,object_name(this_object()),
                                         __LINE__);
        // c-o-delay changed to 1, Coogan, 03-Nov-2009
        call_out(#'call_other,1,temp[i],"do_filter",feature,arg);
        // this call_out (hopefully) will reproduce the error and thus give
        // us a nice error trace so finding the error should be easier.
        // Alfe 1997-Feb-25
      }
    }
    else
      cleanup = 1;
  }
  if (cleanup) {
    for (i=1;i<sizeof(temp);)
      if (temp[i])
        i+=2;
      else
        temp = temp[0..i-2] + temp[i+1..];
    if (features)
      features[feature]=temp;
    else
      features = ([ feature : temp ]);
  }
  return arg;
}

