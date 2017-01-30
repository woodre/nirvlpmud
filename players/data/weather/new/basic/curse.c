#include <message.h>

void reshape_with_messages(object who,closure reshape,
                           string stay_invis_message) {
  mixed darkness_prefix;
  string old_short,new_short,old_name,new_name;
#if 1  // Coogan, 05-Jun-1999, added '1' as silently, Coogan, 18-Dec-2000
  if (environment(who) && !who->test_sight(environment(who), 1))  // can't see?
#else
  if (environment(who) && query_light(environment(who)) <= 0)  // too dark?
#endif
    darkness_prefix = ({ M_TARGETS,who });
  else
    darkness_prefix = ({});
  old_short = who->short();
  old_name = who->query_name();
  if (old_short)  // visible?
    send_message(darkness_prefix +
                 ({ M_THE,who," ",M_CONTINUED }));  // start the message with
                                                    // the old appearance
  funcall(reshape);
  new_short = who->short();
  new_name = who->query_name();
  if (old_short == new_short &&
      old_name == new_name)  // no change of appearance?
    if (!new_short)  // was always invis?
      message(stay_invis_message,who);
    else  // not invis: no change, but visible; no output. cancel.
      send_message(darkness_prefix + ({ M_CANCEL }));
  else  // a change of appearance took place
    if (old_short)  // was visible?
      if (new_short)  // is he now visible?
        send_message(darkness_prefix + ({ M_VERB,"turn",who," into ",
                                          (old_name != new_name? "" : M_FULL),
                                          M_DESCRIBE,who,"." }));
      else  // became invis by change
        send_message(darkness_prefix +
                     ({ " suddenly ",M_VERB,"disappear",who,"." }));
    else  // became visible by change
      send_message(darkness_prefix +
                   ({ who," suddenly ",M_VERB,"appear",who,"." }));
}

void remove_curse(object from);
void apply_curse(object from);

void notify_move(object from, object to) {
  if (from)
    remove_curse(from);
  if (to)
    apply_curse(to);
}

void notify_destruct() {
  if (environment())
    remove_curse(environment());
}

status drop(status silently) {
  return 1;
}

void self_destruct() {
  destruct(this_object());
}

void set_curse_duration(int length) {
  while (remove_call_out("self_destruct") != -1)
    ;
  if (length < 0)
    return;
  call_out("self_destruct",length);
}

mixed *query_auto_load() {
  return ({ load_name(this_object()),find_call_out("self_destruct") });
}

void init_arg(mixed *arg) {
  set_curse_duration(arg[0]);
}

