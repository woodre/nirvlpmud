/* filter all save_object calls and block them for development -Bp
*/
#pragma strict_types
#pragma save_types

#if 0 /* Rumplemintz - fixed call so that it saves in Amylaar file format
       *               without the #0.1 stuff at the top of the file
       */
varargs mixed save_object(string filename, int flag) {
  return 1;
}
#else
int save_object(string name) {
  // call save_object() in context of calling object,
  // use original Amylaar format
  string data=funcall(bind_lambda(#'efun::save_object, previous_object()),0);
  // strip first line
  // data=data[strstr(data,"\n")+1..];
  // OR
  data = implode(explode(data,"\n")[1..],"\n");
  // then write it with write_file, but do it in the context of the saving
  // object, and cut off any terminating .c from <name>
  name = implode(explode(name,".c")[0..<2],".c");
  funcall(bind_lambda(#'efun::write_file, previous_object()),
          name+".o", data, 1);
}
#endif
