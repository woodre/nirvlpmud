coder(mess)
char mess[80];
 
{
 int i = 0;
     while(mess[i] != '\0'){
         if (mess[i] >= 'A' && mess[i] <= 'Z')
            mess[i] = 155 - mess[i];
         if (mess[i] >= 'a' && mess[i] <= 'z')
            mess[i] = 219 - mess[i];
         i++;
     }
    return mess;
}
