/*
 * basic/program.c by Alfe for Tubmud 1996-Oct-10
 *
 * Inherit this program if you want to have an object which starts to do
 * something when it is loaded and destructes itself when it is finished.
 *
 * overload the function  void run();  with what you have to do and call
 * void finished();  when you have finished.
 */

inherit "basic/create";

void start() {
  write("Starting: "+object_name(this_object())+"\n");
}

void stop() {
  write("Finished: "+object_name(this_object())+" with "+get_eval_cost()+
        " eval_cost left\n");
}

varargs void run() {}

void create() {
  if (find_object(__FILE__) == this_object())
    return;
  start();
  run();
}

void finished() {
  stop();
  if (this_interactive())
    call_out(#'destruct,0,this_object());
  else
    destruct(this_object());
}
