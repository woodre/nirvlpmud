/* object.c: functions for handling objects */
/* by changing the type in sort_array from object * to any other, you */
/* can use these on another type */
add_element(arr, element) {
  int i;
  if(has_element(arr, element))
    return 1;
  for(i = 0; i < sizeof(arr); i++) {
    if(arr[i] == 0) {
      arr[i] = element;
      return arr;
    }
  }
  return ;
}
remove_element(arr, element) {
  int i;
  if(!has_element(arr, element))
    return 1;
  for(i = 0; i < sizeof(arr); i++) {
    if(arr[i] == element) {
      arr[i] = 0;
      arr = sort_arr(arr);
      return arr;
    }
  }
  return 0;
}
has_element(arr, element) {
  int i;
  for(i = 0; i < sizeof(arr); i++) {
    if(arr[i] == element)
      return 1;
  }
  return 0;
}
num_elements(arr) {
  int i, x;
  for(i = 0; i < sizeof(arr); i++) {
    if(arr[i] != 0)
      x++;
  }
  return x;
}
sort_arr(arr) {
  int i;
  object *newarr;
  for(i = 0; i < sizeof(arr); i++) {
    if(arr[i] != 0) {
      if(!newarr) newarr[0] = arr[i];
      else newarr += ({arr[i]});
    }
  }
  return newarr;
}
