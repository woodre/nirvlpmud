// This file shows what every class inheriting both component and compound
// should overload (and how) to become a fully-fledged compound_component

inherit "basic/component";
inherit "basic/compound";

void init_component() {
  "basic/component"::init_component();
  "basic/compound"::init();
}

status id(string str) {
  return
    component::id(str) ||
    compound::id(str);
}

// These two don't _have_ to be overloaded, as long as component is
// inherited _before_! compound:
// void add_compound_action(varargs mixed args);
// void add_compound_action_rule(varargs mixed args);

// If you overload init(), don't forget to call compound::init();
// void init() { compound::init(); }

mixed receive_call_component(string name, string func, varargs args) {
  mixed h;

  if (h = get_component(&name))
    return apply(#'call_other,h,"receive_call_component",name,func,args);
  else
    return apply(#'call_other,this_object(),func,args);
}

mixed call_component(string name, string func, varargs mixed args) {
  mixed h;

  if (h = get_component(&name))
    return
      apply(#'call_other,h,"receive_call_component",name,func,args);
  else
    return
      apply(#'call_other,get_compound(),"call_component",name,func,args);
}
