/*
 * Function: TelemetrySend
 *  Sends any number of variables in string format
 *  to plot in real time in the TelemetryViewer software
 * 
 * Parameters:
 *  num_variables (int): number of variables to send
 *  ... (double): variables to convert to string and send.
 *  
 *  Returns:
 *  
 */
void TelemetrySend(int num_variables,
                   ...)
{
  va_list arguments;
  va_start(arguments,num_variables);
  String text=String(va_arg(arguments,double),10);
  for (int x=1; x<num_variables;x++){
    text+=",";
    text+=String(va_arg(arguments,double),10);
  }
      Serial.println(text);    
}
