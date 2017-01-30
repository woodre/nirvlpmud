inherit "obj/treasure";
int orgwc,orgac;

reset(arg)
{   if (arg) return;
    call_out("dispell", 20);
    set_id("bind_mark");
    set_short();
    set_long("");
    set_weight(0);
    set_value(0);
}

drop()  { return 1; }
get()  { return 0; }
set_orgwc(arg) { orgwc=arg;}
set_orgac(arg) { orgac=arg;}
query_orgac() { return orgac; }
query_orgwc() { return orgwc; }
dispell() {
  environment(this_object())->set_wc(orgwc);
  environment(this_object())->set_ac(orgac);
  destruct(this_object());
 }
redo() {
  remove_call_out("dispell");
  call_out("dispell", 20);
  return 1;
}
