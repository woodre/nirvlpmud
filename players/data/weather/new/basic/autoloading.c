#pragma strong_types

private mixed *auto_loading;

void compute_auto_loading() {
  auto_loading = map_objects(all_inventory(),"query_auto_load") - ({ 0 });
}

mixed * query_auto_loading() {
  return auto_loading;
}

private void clone_auto_loading_object(mixed load_data) {
  string error;
  object ob;
  if (stringp(load_data))
    load_data = explode(load_data,":");
  if (!pointerp(load_data))
    return;
  if (error = catch(ob = clone_object(load_data[0])))
    return;
  move_object(ob, this_object());  // changed from move(), Coogan, 29-Mar-1999
  if (environment(ob) != this_object())
    move_object(ob,this_object());
  if (environment(ob) != this_object())
    return;
  ob->init_arg(load_data[1..]);
}

// made varargs, Coogan, 26-Sep-2010
varargs void load_auto_loading(mixed data) {
  int i;
  if (!data)
    data = auto_loading;
  if (!pointerp(data))
    return;
  // changed eval from 10k to 50k, c_o() from 0 to 2, Coogan, 03-Nov-2009
  for (i = sizeof(data); get_eval_cost() > 50000 && i--; )
    catch(clone_auto_loading_object(auto_loading[i]));
  if (i > 0)
    call_out(#'load_auto_loading,2,data[0..i-1]);
}

