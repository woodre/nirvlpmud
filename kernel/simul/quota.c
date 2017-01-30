#define MAX_CALL_OUT 100

static mapping call_outs;

mixed call_out(mixed func, int delay, varargs mixed vargs) {
  mixed c;
  int n;

  if (!call_outs)
    call_outs = ([ ]);
  if (delay<=0)
    delay = 1;
  if (c = call_outs[previous_object()]) {
    c = order_alist(c + ({ time() +delay }) )[0];
    n = insert_alist(time(), c);
    if (n != sizeof(c)) {
      while (n && c[n] == time())
        n--;
    }
    c[0..n-1]=({ });
    if (sizeof(c) > MAX_CALL_OUT) {
      call_outs[previous_object()] = 1; // force errors
      raise_error("Too many call_outs, more errors may follow.\n");
    }
    else
      call_outs[previous_object()] = c;
  }
  else
    call_outs[previous_object()] = ({ time() + delay });
  return apply(bind_lambda(#'efun::call_out, previous_object()),
               func, delay, vargs);
}

