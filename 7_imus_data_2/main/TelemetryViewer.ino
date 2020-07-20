/*
 * Takes any number of variables and put them to serial
 */
void telemetry(int num_variables,...){
  va_list arguments;
  va_start(arguments,num_variables);
  String text=String(va_arg(arguments,double),10);
  for (int x=1; x<num_variables;x++){
    text+=",";
    text+=String(va_arg(arguments,double),10);
  }
      Serial.println(text);    
}
