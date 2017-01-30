mixed *Resources;

AResource(mixed *data){
   int i;
   int temp;
   if(!Resources)
      Resources = ({});
   for(i=0; i<sizeof(data); i++){
      temp = member_array(data[i], Resources);
      if(temp != -1){
         Resources[temp+1] += data[i+1];
       }
      else{
         Resources += ({ data[i], data[i+1] });
       }
      i = i+1;
   }
}

QResources(){
   return Resources;
}

QResource(string name){
   int temp;
   if(!Resources)
      Resources = ({});
   temp = member_array(name,Resources);
   if(temp != -1)
      return Resources[temp+1];
   else
      return 0;
}

UseResource(string name, int amount){
   int temp;
   if(!Resources)
      Resources = ({});
   temp = member_array(name,Resources);
   if(temp ==-1){
      write("There is none of that resource.\n");
      return 0;
   }
   else if(amount > Resources[temp+1]){
      write("There is not that much resource here.\n");
      return 0;
   }
   else {
      Resources[temp+1] -= amount;
      write("You have used "+amount+" parts of "+name+"\n");
      return 1;
   }
}

MonitorResources(){
   int i;
   int temp1, temp2;
   if(!Resources)
      return 0;
   for(i=0; i<sizeof(Resources); i++){
      if(sscanf(Resources[i], "%s|%s", temp1, temp2) == 2){
write(pad(temp1+" ("+temp2+")",30)+Resources[i+1]+"\n");
       }
      else{
write(pad(Resources[i],30)+Resources[i+1]+"\n");
       }
      i = i+1;
   }
}
