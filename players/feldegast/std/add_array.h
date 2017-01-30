string *add_array(string str,string *arr) {
  string *temp;
  int i,s;
  temp=({ });
  s=sizeof(arr);
  for(i=0; i < s; i++)
    temp+=({ arr[i] });
  temp+=({ str });
  return temp;
}


