object start_shadow(object what) {
  return shadow(what, 1);
}

object stop_shadow(object what) {
  return shadow(what, 0);
  destruct(this_object());
}

void init() { return; }

